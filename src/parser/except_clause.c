/**
 *
 * @file except_clause.c
 *
 * @brief Parse grammar production except_clause.
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
 * except_clause
 *     : 'except' '(' IDENT ',' IDENT ')' function_body
 *     ;
 */
ast_except_clause_t* parse_except_clause(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_except_clause_t* node = NULL;
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
                node = (ast_except_clause_t*)create_ast_node(AST_EXCEPT_CLAUSE);
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

