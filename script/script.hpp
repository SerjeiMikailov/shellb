#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <iostream>
#include <string>

enum TokenType {
    KEYWORD_HI,
    KEYWORD_CLEAR,
    KEYWORD_LS,
    KEYWORD_CD,
    KEYWORD_CF,
    END_OF_FILE,
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    explicit Lexer(const std::string& source);
    Token getNextToken();

private:
    char advance();
    bool isAtEnd() const;
    void skipWhitespace();
    bool match(const std::string& expected);

    std::string source_;
    size_t current_;
};

class Interpreter {
public:
    explicit Interpreter(const std::string& source);

    void execute();

private:
    Lexer lexer_;
};

#endif 
