#ifndef EXPR
#define EXPR
#include <utility>
#include <string>
#include <iostream>
using namespace std;

typedef pair<double, string> expr;

/* return expr type from long type */
expr create_expr (long number);

/* display expr */
void display_expr (expr var);

/* returns expr result, result = e1 <op> e2 */
expr evaluate (expr e1, char op, expr e2);

#endif