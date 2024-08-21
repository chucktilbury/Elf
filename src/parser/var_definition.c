

/*
    Production being parsed:

 var_definition
    : ( 'const' )? var_decl ( '=' assignment_item )?
    ;

*/
#include "common.h"
#include "tokens.h"
#include "errors.h"
#include "parser.h"

ast_var_definition_t* parse_var_definition(void) {

    ENTER;

    ast_var_definition_t* node = NULL;
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
                node = (ast_var_definition_t*)create_ast_node(AST_VAR_DEFINITION);
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

