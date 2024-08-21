/**
 *
 * @file cast_statement.c
 *
 * @brief Traverse AST for node cast_statement.
 * This file was generated on Wed Aug 21 09:35:58 2024.
 *
 */
#include "common.h"
#include "trace.h"
#include "errors.h"
#include "ast.h"

/**
 *
 * Grammar production:
 *
 * cast_statement
 *     : type_name ':' expression
 *     ;
 */
void traverse_cast_statement(ast_cast_statement_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}

