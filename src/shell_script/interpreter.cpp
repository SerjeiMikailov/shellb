#include "SBscript.h"
#include <iostream>
#include <string>

// Lexer implementation details...
struct Lexer {
    std::string source_;
    size_t current_;

    Lexer(const std::string& source) : source_(source), current_(0) {}

    void skipWhitespace();
    char advance();
    bool isAtEnd() const;
};

void Lexer::skipWhitespace() {
    while (!isAtEnd() && (source_[current_] == ' ' || source_[current_] == '\n')) {
        current_++;
    }
}

char Lexer::advance() {
    return source_[current_++];
}

bool Lexer::isAtEnd() const {
    return current_ >= source_.size();
}

// Interpreter implementation details...
struct Interpreter {
    Lexer* lexer_;

    Interpreter(const char* source) {
        lexer_ = create_lexer(source);
    }

    ~Interpreter() {
        destroy_lexer(lexer_);
    }
};

Lexer* create_lexer(const char* source) {
    return new Lexer(source);
}

void destroy_lexer(Lexer* lexer) {
    delete lexer;
}

Token getNextToken(Lexer* lexer) {
    lexer->skipWhitespace();

    if (lexer->isAtEnd()) {
        return {END_OF_FILE, nullptr};
    }

    char c = lexer->advance();

    switch (c) {
        case 'H':
            if (lexer->source_[lexer->current_] == 'I') {
                lexer->advance(); // consume 'I'
                return {KEYWORD_HI, "HI"};
            }
            break;
        default:
            // Invalid token, skip it.
            break;
    }

    return {END_OF_FILE, nullptr};
}

Interpreter* create_interpreter(const char* source) {
    return new Interpreter(source);
}

void destroy_interpreter(Interpreter* interpreter) {
    delete interpreter;
}

void execute(Interpreter* interpreter) {
    Token token;
    do {
        token = getNextToken(interpreter->lexer_);
        if (token.type == KEYWORD_HI) {
            std::cout << "HI" << std::endl;
        }
    } while (token.type != END_OF_FILE);
}
