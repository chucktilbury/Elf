/**
 *
 * @file start_definition.c
 *
 * @brief Traverse AST for node start_definition.
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
 * start_definition
 *     : 'start' function_body
 *     ;
 */
void traverse_start_definition(ast_start_definition_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}

