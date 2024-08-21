

/*
    Production being parsed:

try_clause
    : 'try' function_body ( except_clause )* ( final_clause )?
    ;

 */
#include "common.h"
#include "trace.h"
#include "errors.h"
#include "ast.h"

void traverse_try_clause(ast_try_clause_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}

