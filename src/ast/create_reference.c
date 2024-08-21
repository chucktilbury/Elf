/**
 *
 * @file create_reference.c
 *
 * @brief Traverse AST for node create_reference.
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
 * create_reference
 *     : create_name expression_list
 *     ;
 */
void traverse_create_reference(ast_create_reference_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    CALL_NODE_FUNC(post);
    RET;
}

