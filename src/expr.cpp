#include "expr.h"

/* return expr type from long type */
expr create_expr (long number) {
    expr result;
    result.first = number;
    result.second = to_string(number);
    return result;
}

/* display expr */
void display_expr (expr var) {
    cout << "Value = " << var.first << endl;
    cout << "Expression = " << var.second << endl;
}

/* returns expr result, result = e1 <op> e2 */
expr evaluate (expr e1, char op, expr e2) {
    expr result;
    switch (op) {
        case '+': {
            result.first = e1.first + e2.first;
            break;
        }
        case '-': {
            result.first = e1.first - e2.first;
            break;
        }
        case '*': {
            result.first = e1.first * e2.first;
            break;
        }
        case '/': {
            result.first = e1.first / e2.first;
            break;
        }
    }
    result.second = '(' + e1.second + op + e2.second + ')';
    return result;
}