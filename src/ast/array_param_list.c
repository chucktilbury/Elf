/**
 *
 * @file array_param_list.c
 *
 * @brief Traverse AST for node array_param_list.
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
 * array_param_list
 *     : array_param (array_param)*
 *     ;
 */
void traverse_array_param_list(ast_array_param_list_t* node, AstFuncPtr pre, AstFuncPtr post) {

    ENTER;
    CALL_NODE_FUNC(pre);

    ast_array_param_t* pa;
    int mark = 0;

    while(NULL != (pa = iterate_ptr_lst(node->ptr, &mark)))
        traverse_array_param(pa, pre, post);

    CALL_NODE_FUNC(post);
    RET;
}
