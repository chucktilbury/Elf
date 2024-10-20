/**
 *
 * @file continue_statement.c
 *
 * @brief Traverse AST for node continue_statement.
 * This file was generated on Wed Aug 21 11:39:59 2024.
 *
 */
#include "ast.h"
#include "common.h"
#include "errors.h"
#include "trace.h"

/**
 *
 * Grammar production:
 *
 * continue_statement
 *     : 'continue'
 *     ;
 */
void traverse_continue_statement(ast_continue_statement_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}
