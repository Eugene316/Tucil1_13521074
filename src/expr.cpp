#include "expr.h"

/* return expr type from int type */
expr create_expr (int number) {
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
    if (e1.second == "~" || e2.second == "~") {
        result.first = 0;
        result.second = "~";
    } else {
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
                if (e2.first == 0) {
                    result.first = 0;
                    result.second = "~";
                    return result;
                } else {
                    result.first = e1.first / e2.first;
                }
                break;
            }
        }
        result.second = '(' + e1.second + op + e2.second + ')';
    }
    return result;
}