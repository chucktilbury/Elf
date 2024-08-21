#ifndef _TOKEN_DEFS_H_
#define _TOKEN_DEFS_H_

typedef enum {
    TOK_START,
    TOK_IMPORT,
    TOK_AS,
    TOK_IDENT,
    TOK_INCLUDE,
    TOK_PRIVATE,
    TOK_PUBLIC,
    TOK_PROTECTED,
    TOK_FLOAT,
    TOK_INTEGER,
    TOK_STRING,
    TOK_BOOLEAN,
    TOK_NOTHING,
    TOK_LIST,
    TOK_DICT,
    TOK_OPAREN,
    TOK_COMMA,
    TOK_CPAREN,
    TOK_LITERAL_DSTR,
    TOK_LITERAL_SSTR,
    TOK_LITERAL_FLOAT,
    TOK_LITERAL_INTEGER,
    TOK_LITERAL_BOOL,
    TOK_CONST,
    TOK_EQUAL,
    TOK_COLON,
    TOK_OSBRACE,
    TOK_CSBRACE,
    TOK_DOT,
    TOK_OR,
    TOK_AND,
    TOK_BANG_EQUAL,
    TOK_OPBRACE,
    TOK_CPBRACE,
    TOK_OPBRACE_EQUAL,
    TOK_CPBRACE_EQUAL,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,
    TOK_PERCENT,
    TOK_BANG,
    TOK_NAMESPACE,
    TOK_OCBRACE,
    TOK_CCBRACE,
    TOK_CLASS,
    TOK_VIRTUAL,
    TOK_CREATE,
    TOK_DESTROY,
    TOK_PLUS_EQUAL,
    TOK_MINUS_EQUAL,
    TOK_STAR_EQUAL,
    TOK_SLASH_EQUAL,
    TOK_PERCENT_EQUAL,
    TOK_INLINE,
    TOK_BREAK,
    TOK_CONTINUE,
    TOK_YIELD,
    TOK_TYPE,
    TOK_RETURN,
    TOK_RAISE,
    TOK_TRACE,
    TOK_PRINT,
    TOK_EXIT,
    TOK_WHILE,
    TOK_DO,
    TOK_FOR,
    TOK_IN,
    TOK_IF,
    TOK_ELSE,
    TOK_TRY,
    TOK_EXCEPT,
    TOK_FINAL,
} TokenType;

typedef struct {
    const char* str;
    TokenType type;
} token_database_t;

const char* token_type_to_str(TokenType type);
token_database_t* find_keyword(const char* str);

#endif /* _TOKEN_DEFS_H_ */

