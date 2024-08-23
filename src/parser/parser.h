/**
 *
 * @file parser.h
 *
 * @brief Parse grammar public interface.
 * This file was generated on Wed Aug 21 11:39:59 2024.
 *
 */
#ifndef _PARSER_H_
#define _PARSER_H_

#include "ast.h"

typedef struct {
    int mode;
} parser_state_t;

#include "parser_prototypes.h"

void recover_error(void);
ast_module_t* parse(void);

#endif  /* _PARSER_H_ */

