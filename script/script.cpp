#include <iostream>
#include <string>
#include <vector>

enum TokenType {
    KEYWORD_HI,
    END_OF_FILE,
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    explicit Lexer(const std::string& source) : source_(source), current_(0) {}
    Token getNextToken();

private:
    char advance();
    bool isAtEnd() const;
    void skipWhitespace();

    std::string source_;
    size_t current_;
};

Token Lexer::getNextToken() {
    skipWhitespace();

    if (isAtEnd()) {
        return {END_OF_FILE, ""};
    }

    char c = advance();

    switch (c) {
        case 'H':
            if (source_[current_] == 'I') {
                advance(); // consume 'I'
                return {KEYWORD_HI, "HI"};
            }
            break;
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

class Interpreter {
public:
    explicit Interpreter(const std::string& source) : lexer_(source) {}

    void execute();

private:
    Lexer lexer_;
};

void Interpreter::execute() {
    Token token;
    do {
        token = lexer_.getNextToken();
        if (token.type == KEYWORD_HI) {
            std::cout << "HI" << std::endl;
        }
    } while (token.type != END_OF_FILE);
}

int main() {
    std::string source_code = "HI HI HI";
    Interpreter interpreter(source_code);
    interpreter.execute();
    return 0;
}

