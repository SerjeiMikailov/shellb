#ifndef INTERPRETER_H
#define INTERPRETER_H

#ifdef __cplusplus
extern "C" {
#endif

// Token types
enum TokenType {
    KEYWORD_HI,
    END_OF_FILE,
};

// Token struct
typedef struct {
    enum TokenType type; // Add 'enum' before TokenType
    const char* lexeme;
} Token;

// Lexer struct (opaque forward declaration)
typedef struct Lexer Lexer;

// Interpreter struct (opaque forward declaration)
typedef struct Interpreter Interpreter;

// Lexer functions
Lexer* create_lexer(const char* source);
void destroy_lexer(Lexer* lexer);
Token getNextToken(Lexer* lexer);


void createCFile(const char* filename, const char* content);


// Interpreter functions
Interpreter* create_interpreter(const char* source);
void destroy_interpreter(Interpreter* interpreter);
void execute(Interpreter* interpreter);

#ifdef __cplusplus
}
#endif

#endif // INTERPRETER_H

// void createCFile(const char* filename, const char* content);
