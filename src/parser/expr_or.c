/**
 *
 * @file expr_or.c
 *
 * @brief Parse grammar production expr_or.
 * This file was generated on Wed Aug 21 09:35:58 2024.
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
 * expr_or
 *     : expr_and 'or' expr_and
 *     ;
 */
ast_expr_or_t* parse_expr_or(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_expr_or_t* node = NULL;
    int state = 0;
    bool finished = false;
    void* post = post_token_queue();

    while(!finished) {
        switch(state) {
            case 0:
                // initial state
                TRACE_STATE(state);
                break;

            case 100:
                // production recognized
                TRACE_STATE(state);
                node = (ast_expr_or_t*)create_ast_node(AST_EXPR_OR);
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

