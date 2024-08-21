/**
 *
 * @file module_item.c
 *
 * @brief Parse grammar production module_item.
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
 * module_item
 *     : namespace_item
 *     | import_statement
 *     | include_statement
 *     | start_definition
 *     ;
 */
ast_module_item_t* parse_module_item(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_module_item_t* node = NULL;
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
                node = (ast_module_item_t*)create_ast_node(AST_MODULE_ITEM);
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

