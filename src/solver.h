#ifndef SOLVER
#define SOLVER

#include "expr.h"
#include <vector>
using namespace std;

typedef vector<expr> v_expr;

/* stores solutions of 24 card game */
extern v_expr solutions;

/* save var <expr> to solutions <v_expr> if var.first is 24 and not undefined */
void save_solut(expr var);

/* prints solutions */
void display_solut();

/* arguments: perm <v_expr>; accepted argument is an ordered permutation of 4 numbers */
/* utility: find solutions to 24 game for given 4 number permutation */
void solve(v_expr perm);

/* saves solutions of 24 card game to a .txt file */
void save_to_file();

#endif