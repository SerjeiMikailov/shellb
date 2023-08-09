#include <cstdlib>

#include "script.hpp"

Lexer::Lexer(const std::string& source) : source_(source), current_(0) {}

Token Lexer::getNextToken() {
    skipWhitespace();

    if (isAtEnd()) {
        return {END_OF_FILE, ""};
    }

    char c = advance();

    switch (c) {
        case 'H':
            if (source_[current_] == 'I') {
                advance(); 
                return {KEYWORD_HI, "HI"};
            }
            break;
        case 'C':
            if (source_[current_] == 'L' &&
                source_[current_ + 1] == 'E' &&
                source_[current_ + 2] == 'A' &&
                source_[current_ + 3] == 'R') 
                {
                current_ += 4; 
                return {KEYWORD_CLEAR, "CLEAR"};
                }
        default:
            break;
    }
    return {END_OF_FILE, ""};
}

char Lexer::advance() {
    return source_[current_++];
}

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
        if (token.type == KEYWORD_HI) {
            std::cout << "HI" << std::endl;
        }
        if (token.type == KEYWORD_CLEAR) { 
            system("clear");
        }
    } while (token.type != END_OF_FILE);
}
