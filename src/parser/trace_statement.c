/**
 *
 * @file trace_statement.c
 *
 * @brief Parse grammar production trace_statement.
 * This file was generated on Wed Aug 21 11:39:59 2024.
 *
 */
#include "common.h"
#include "tokens.h"
#include "errors.h"
#include "parser.h"

/**
 *
 * Grammar production:
 *
 * trace_statement
 *     : 'trace' '(' string_literal ')'
 *     ;
 */
ast_trace_statement_t* parse_trace_statement(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_trace_statement_t* node = NULL;
    int state = 0;
    bool finished = false;
    void* post = post_token_queue();

    ast_string_literal_t* str = NULL;

    while(!finished) {
        switch(state) {
            case 0:
                TRACE_STATE;
                if(TOK_TRACE == TTYPE) {
                    consume_token();
                    state = 1;
                }
                else 
                    state = 101;
                break;

            case 1:
                TRACE_STATE;
                if(TOK_OPAREN == TTYPE) {
                    consume_token();
                    state = 2;
                }
                else {
                    EXPECTED("a '('");
                    state = 102;
                }
                break;

            case 2:
                TRACE_STATE;
                if(NULL != (str = parse_string_literal(pstate)))
                    state = 3;
                else {
                    EXPECTED("a literal string");
                    state = 102;
                }
                break;

            case 3:
                TRACE_STATE;
                if(TOK_CPAREN == TTYPE) {
                    consume_token();
                    state = 100;
                }
                else {
                    EXPECTED("a ')'");
                    state = 102;
                }
                break;

            case 100:
                // production recognized
                TRACE_STATE;
                node = (ast_trace_statement_t*)create_ast_node(AST_TRACE_STATEMENT);
                node->str = str;
                finished = true;
                break;

            case 101:
                // not a match, not an error
                TRACE_STATE;
                reset_token_queue(post);
                finished = true;
                break;

            case 102:
                // error found
                TRACE_STATE;
                recover_error();
                finished = true;
                break;

            default:
                FATAL("unknown state: %d", state);
        }
    }

    RETURN(node);
}

