# Simple
The **Simple** programming language.

This is a very simple object-oriented programming language compiler which is written in C. It's a fun hobby project. See the grammar below. It's pretty complete and I am actively working on a parser and AST for it. (January, 2024)

The language is a synthesis or Python and C. It has the object model of Python but shares a lot of syntax with both C and C++.

General features in no particular order.
* Curly braces to delimit blocks. Semicolons are used to introduce single-line comments. Whitespace is completely ignored except to separate some tokens.
* Simplified type system, but is strongly typed with casting.
* Durable typing. Once a type is specified, it cannot be changed. Casting is supported and a different var can be created with the different type. The exception to this is the ``nothing`` type. This allows the type to be assigned at runtime, and once it is assigned, then the type of the variable becomes durable and is enforced at runtime.
* Function overloads by parameter type. Functions have a syntax of ``name(input parameters)(output parameters)``. Input parameters are passed to the function by value and output parameters are passed as references. Outputs not assigned in the function is a warning. Outputs accessed by value in a function is a syntax error, and duplicate names are a syntax error. This means that a function does not "return" anything. A syntax such as ``name.name.func()().name`` makes no sense. Use exceptions to communicate errors and such.
* Functions can be overridden by the signature, including the return values.
* Functions can be assigned to variables using a syntax such as ``nothing varname = func_name()()``.
* The ``nothing`` type takes the place of the ``void`` type in C. This is used to allow an data object to have a type assigned at run time.
* Classes with single inheritance only. Class definitions can contain no assignments or function definitions. The parent attributes and methods are accessed by name with the '.' operator. The scope operators set the scope of subsequent lines of code. The default scope is ``private``.
* Membership is given by the '.' operator and spaces are allowed before or after it.
* Virtual functions. If a virtual function has a definition in its class and a child class inherits it, then the child can still access the parent method using the membership '.' operator. Overriding a virtual function is optional. Defining a virtual function is optional. Accessing a virtual function that has not been defined is a runtime error.
* Supports dictionaries and lists natively.
* String is a native data type and all strings can be formatted without an explicit method call.
* The compiler and the runtime library both use managed memory implemented by the Boehm-Demers-Weiser Garbage Collector found here: https://www.hboehm.info/gc/
* Exceptions using the non-local goto feature of ANSI C. A string error message is passed back to the exception handler.
* Support for external libraries using an ``inline`` keyword that causes literal code to be copied directly to the output without any checking. This is implemented as a scanner feature.
* Constant values cannot be changed once they are assigned, but they are assigned at runtime.

Features that are specifically not supported.

* Pointers.
* Multiple inheritance.
* Monkey patching.

This multi-pass compiler accepts Simple source code and outputs C source code. The output should be compilable by any modern ANSI C compiler. The output is not really intended to be human readable, but the #line directives are used to aid debugging. The generated code favors efficiency over readability. The goal is that there should be no way for the compiler to output incorrect code. All semantic errors are caught before emitting any output, except for the inline functionality. No checking or parsing is done on that whatsoever.

# This repo
(assuming you know how to use github)
This repo has not nor ever will be built by me under any version of Windows. It should be usable on other operating systems. I don't have a MAC, so I can't test anything. In general it should build under Linux without problems. There are a couple of files to make it easier to use. After you clone it, take a look at the .project_env file to see if it matches your setup. If it does, then you can just run ``./setup`` to check out the sub projects and create a sub-shell with some paths set up. To make the repo perfectly clean, run the ``./clean`` script or delete the docs/out, build, and bin directories.

## required packages
This requires an ANSI C compiler, GNU Flex, cmake, graphiz, and doxygen. No other libraries or tools should be required.

## Feedback is most welcome
I would also welcome some help. Compilers are such a slog....

# Grammar
This is the complete and updated grammar for **Simple**:
```

#####################
#
# This is a simplified grammar that is based upon BNF. It is intended to
# illustrate the physical syntax of the Simple programming language. It
# is not expected that this grammar will change very much. This is not
# intended to be a "regular" grammar. There are several conflicts that include
# a big one between a compound_name and a compound_reference. This is most
# easily resolved using a hand coded parser, so no effort has been put into
# making this grammar conform to any parser generator input syntax.
#
# Note that comments are introduced with a ';' character and extend to the
# first newline encountered.
#
# The items that are in parentheses are followed by a '?', '+', or a '*'.
# These are used to simplify the text of the grammar and represent what would
# be normally expected in a regular expression. I.e. '?' represents "zero or
# one", '+' represents "one or more", and '*' represents "zero or more". The
# slash character '/' should be read as the word 'or'.
#
# Keywords a shown as string literals and are NOT case-sensitive. Constructed
# (such as a IDENT = [a-zA-Z_][A-Za-z0-9_]*) terminal symbols are in
# all-caps.
#
#####################

module
    : ( module_item )+
    ;

module_item
    : namespace_item
    | import_statement
    | start_definition
    ;

start_definition
    : 'start' function_body
    ;

import_statement
    : 'import' IDENT ('as' IDENT)?
    ;

namespace_item
    : scope_operator
    | namespace_definition
    | class_definition
    | function_definition
    | create_definition
    | destroy_definition
    | var_definition
    ;

scope_operator
    : 'private'
    | 'public'
    | 'protected'
    ;

literal_type_name
    : 'float'
    | 'integer'
    | 'string'
    | 'boolean'
    | 'nothing'
    | 'list'
    | 'dict'
    ;

type_name
    : literal_type_name
    | compound_name
    ;

type_name_list
    : '(' ( type_name (',' type_name )* )? ')'
    ;

formatted_strg
    : LITERAL_DSTR ( expression_list )?
    ;

string_literal
    : LITERAL_SSTR
    | formatted_strg
    ;

literal_value
    : LITERAL_FLOAT
    | LITERAL_INTEGER
    | LITERAL_BOOL
    | string_literal
    ;

var_decl
    : type_name IDENT
    ;

var_decl_list
    : '(' ( var_decl ( ',' var_decl )* )? ')'
    ;

function_assignment
    : compound_reference type_name_list type_name_list
    ;

assignment_item
    : expression
    | list_init
    | function_assignment
    ;

var_definition
    : ( 'const' )? var_decl ( '=' assignment_item )?
    ;

list_init_str
    : LITERAL_DSTR
    | LITERAL_SSTR
    ;

list_init_element
    : list_init_str ':' assignment_item
    | assignment_item
    ;

list_init
    : '[' list_init_element ( ',' list_init_element )* ']'
    ;

array_param_item
    : expression
    | string_literal
    ;

array_param
    : '[' array_param_item ']'
    ;

array_param_list
    : array_param (array_param)*
    ;

array_reference
    : IDENT array_param_list
    ;

function_reference
    : compound_reference expression_list compound_name_list
    ;

create_reference
    : create_name expression_list
    ;

destroy_reference
    : destroy_name
    ;

compound_name
    : IDENT ( '.' IDENT )*
    ;

compound_name_list
    : '(' ( compound_name (',' compound_name )* )? ')'
    ;

compound_ref_item
    : IDENT
    | array_reference
    ;

compound_reference
    : compound_ref_item ( '.' compound_ref_item )*
    ;

cast_statement
    : type_name ':' expression
    ;

expression
    : expr_or
    ;

expr_or
    : expr_and
    | OR expr_and
    ;

expr_and
    : expr_equality
    | AND expr_equality
    ;

expr_equality
    : expr_compare
    | EQUALS expr_compare
    | NOTEQUALS expr_compare
    ;

expr_compare
    : expr_term
    | LESS_THAN expr_term
    | GREATER_THAN expr_term
    | LESS_OR_EQUAL expr_term
    | GREATER_OR_EQUAL expr_term
    ;

expr_term
    : expr_factor
    | PLUS expr_factor
    | MINUS expr_factor
    ;

expr_factor
    : expr_unary
    | STAR expr_unary
    | SLASH expr_unary
    | PERCENT expr_unary
    ;

expr_unary
    : expr_primary
    | MINUS expr_primary
    | BANG expr_primary
    ;

expr_primary
    : literal_value
    | compound_reference
    | cast_statement
    | '(' expression ')'
    ;

expression_list
    : '(' (expression ( ',' expression )*)? ')'
    ;

namespace_definition
    : 'namespace' IDENT '{' ( namespace_item )+ '}'
    ;

class_definition
    : 'class' IDENT ( '(' ( type_name )? ')' )?
        '{' ( class_item )+ '}'
    ;

class_item
    : scope_operator
    | var_decl
    | function_declaration
    | create_declaration
    | destroy_declaration
    ;

function_declaration
    : ('virtual' )? IDENT type_name_list type_name_list
    ;

create_declaration
    : ('virtual' )? 'create' type_name_list
    ;

destroy_declaration
    : ('virtual' )? 'destroy'
    ;

function_definition
    : ('virtual' )? compound_name var_decl_list var_decl_list function_body
    ;

create_name
    : IDENT ('.' IDENT)? '.' 'create'
    ;

create_definition
    : ('virtual' )? create_name var_decl_list function_body
    ;

destroy_name
    : IDENT ('.' IDENT)? '.' 'destroy'
    ;

destroy_definition
    : ('virtual' )? destroy_name function_body
    ;


function_body
    : '{' ( function_body_element )* '}'
    ;

assign_eq_item
    : assignment_item
    | compound_reference
    ;

assign_inc_item
    : expression
    | string_literal
    ;

assignment
    : compound_reference EQUAL assign_eq_item
    | compound_reference PLUS_EQUAL assign_inc_item
    | compound_reference MINUS_EQUAL expression
    | compound_reference STAR_EQUAL expression
    | compound_reference SLASH_EQUAL expression
    | compound_reference PERCENT_EQUAL expression
    ;

function_body_element
    : var_definition
    | function_reference
    | create_reference
    | destroy_reference
    | assignment
    | while_clause
    | do_clause
    | for_clause
    | if_clause
    | try_clause
    | switch_clause
    | break_statement
    | continue_statement
    | INLINE
    | yield_statement
    | type_statement
    | return_statement
    | raise_statement
    | trace_statement
    | print_statement
    | function_body
    ;

break_statement
    : 'break'
    ;

continue_statement
    : 'continue'
    ;

yield_statement
    : 'yield' '(' compound_reference ')'
    ;

type_statement
    : 'type' '(' compound_reference ')'
    ;

return_statement
    : 'return'
    ;

raise_statement
    : 'raise' '(' IDENT ',' string_literal ')'
    ;

trace_statement
    : 'trace' '(' string_literal ')'
    ;

print_statement
    : 'print' ( expression_list )?
    ;

exit_statement
    : 'exit' '(' expression ')'
    ;

while_definition
    : 'while' ( '(' ( expression )? ')' )?
    ;

while_clause
    : while_definition function_body
    ;

do_clause
    : 'do' function_body while_definition
    ;

for_clause
    : 'for' ( '(' ( (type_name)? IDENT 'in' expression )? ')' )? function_body
    ;

if_clause
    : 'if' '(' expression ')' function_body ( else_clause )* ( final_else_clause )?
    ;

else_clause
    : 'else' '(' expression ')' function_body
    ;

final_else_clause
    : 'else' ( '(' ')' )? function_body
    ;

try_clause
    : 'try' function_body ( except_clause )* ( final_clause )?
    ;

except_clause
    : 'except' '(' IDENT ',' IDENT ')' function_body
    ;

final_clause
    : 'final' '(' IDENT ')' function_body
    ;

```
