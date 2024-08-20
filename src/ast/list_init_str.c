

/*
    Production being parsed:

 */
#include "common.h"
#include "trace.h"
#include "errors.h"
#include "ast.h"

void traverse_list_init_str(ast_list_init_str_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}

