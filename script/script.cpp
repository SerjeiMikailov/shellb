#include <cstdlib>

#include "script.hpp"

extern "C" {
// #include "App.h"
#include "../src/App.h"
}

Lexer::Lexer(const std::string& source) : source_(source), current_(0) {}

Token Lexer::getNextToken() {
    skipWhitespace();

    if (isAtEnd()) {
        return {END_OF_FILE, ""};
    }

    char c = advance();

    switch (c) {
        case 'H':
            if (source_[current_]  == 'I') {
                advance(); 
                return {KEYWORD_HI, "HI"};
            }
            break;
        case 'l':
            if (match("s")) {
                current_ += 1;
                return {KEYWORD_LS, "ls"};
            }
              break;
        case 'c':
            if (match("lear")) {
                current_ += 4; 
                return {KEYWORD_CLEAR, "clear"};
            }
            break;
        default:
            break;
    }
    return {END_OF_FILE, ""};
}

bool Lexer::match(const std::string& expected) {
    if (current_ + expected.size() > source_.size()) {
        return false;  
    }

    for (size_t i = 0; i < expected.size(); ++i) {
        if (source_[current_ + i] != expected[i]) {
            return false;  
        }
    }
    return true;  
}

/////
char Lexer::advance() {
    return source_[current_++];
}
////

bool Lexer::isAtEnd() const {
    return current_ >= source_.size();
}

void Lexer::skipWhitespace() {
    while (!isAtEnd() && (source_[current_] == ' ' || source_[current_] == '\n')) {
        current_++;
    }
}

Interpreter::Interpreter(const std::string& source) : lexer_(source) {}

void Interpreter::execute() {
    Token token;
    do {
        token = lexer_.getNextToken();
        if(token.type == KEYWORD_HI) 
        {
            std::cout << "HI" << std::endl;
        }
        if(token.type == KEYWORD_CLEAR) 
        { 
            system("clear");
            //clear(); 
        }
        if(token.type == KEYWORD_LS)
        {
            system("ls");  
        }
    } while (token.type != END_OF_FILE);
}
