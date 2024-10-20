/**
 *
 * @file start_definition.c
 *
 * @brief Parse grammar production start_definition.
 * This file was generated on Wed Aug 21 11:39:59 2024.
 *
 */
#include "common.h"
#include "errors.h"
#include "parser.h"
#include "tokens.h"

/**
 *
 * Grammar production:
 *
 * start_definition
 *     : 'start' function_body
 *     ;
 */
ast_start_definition_t* parse_start_definition(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_start_definition_t* node = NULL;
    int state = 0;
    bool finished = false;
    void* post = post_token_queue();

    ast_function_body_t* body = NULL;

    while(!finished) {
        switch(state) {
            case 0:
                TRACE_STATE;
                if(TOK_START == TTYPE) {
                    consume_token();
                    state = 1;
                }
                else
                    state = 101;
                break;

            case 1:
                TRACE_STATE;
                if(NULL != (body = parse_function_body(pstate)))
                    state = 100;
                else {
                    EXPECTED("a function body");
                    state = 102;
                }
                break;

            case 100:
                // production recognized
                TRACE_STATE;
                node = (ast_start_definition_t*)create_ast_node(AST_START_DEFINITION);
                node->body = body;
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
