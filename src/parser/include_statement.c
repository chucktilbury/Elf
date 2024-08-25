/**
 *
 * @file include_statement.c
 *
 * @brief Parse grammar production include_statement.
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
 * include_statement
 *     : 'include' formatted_strg
 *     ;
 */
ast_include_statement_t* parse_include_statement(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_include_statement_t* node = NULL;
    int state = 0;
    bool finished = false;
    void* post = post_token_queue();

    ast_formatted_strg_t* str;

    while(!finished) {
        switch(state) {
            case 0:
                TRACE_STATE(state);
                if(TOK_INCLUDE == TTYPE) {
                    consume_token();
                    state = 1;
                }
                else
                    state = 101;
                break;

            case 1:
                TRACE_STATE(state);
                if(NULL == (str = parse_formatted_strg(pstate))) {
                    EXPECTED("a formatted string");
                    state = 102;
                }
                else
                    state = 100;
                break;

            case 100:
                // production recognized
                TRACE_STATE(state);
                node = (ast_include_statement_t*)create_ast_node(AST_INCLUDE_STATEMENT);
                node->str = str;
                finished = true;
                break;

            case 101:
                // not a match, not an error
                TRACE_STATE(state);
                reset_token_queue(post);
                finished = true;
                break;

            case 102:
                // error found
                TRACE_STATE(state);
                recover_error();
                finished = true;
                break;

            default:
                FATAL("unknown state: %d", state);
        }
    }

    RETURN(node);
}

