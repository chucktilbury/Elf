/**
 *
 * @file function_assignment.c
 *
 * @brief Parse grammar production function_assignment.
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
 * function_assignment
 *     : compound_reference type_name_list type_name_list
 *     ;
 */
ast_function_assignment_t* parse_function_assignment(parser_state_t* pstate) {

    ASSERT(pstate != NULL);
    ENTER;

    ast_function_assignment_t* node = NULL;
    int state = 0;
    bool finished = false;
    void* post = post_token_queue();

    ast_compound_reference_t* name;
    ast_type_name_list_t* inp;
    ast_type_name_list_t* outp;

    while(!finished) {
        switch(state) {
            case 0:
                TRACE_STATE;
                if(NULL != (name = parse_compound_reference(pstate))) 
                    state = 1;
                else
                    state = 101;
                break;

            case 1:
                TRACE_STATE;
                if(NULL != (inp = parse_type_name_list(pstate)))
                    state = 2;
                else 
                    state = 101;
                break;
            
            case 2:
                TRACE_STATE;
                if(NULL != (outp = parse_type_name_list(pstate)))
                    state = 100;
                else {
                    EXPECTED("a type name list");
                    state = 102;
                }
                break;

            case 100:
                // production recognized
                TRACE_STATE;
                node = (ast_function_assignment_t*)create_ast_node(AST_FUNCTION_ASSIGNMENT);
                node->name = name;
                node->inp = inp;
                node->outp = outp;
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

