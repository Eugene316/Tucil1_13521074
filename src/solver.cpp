#include "solver.h"

/* stores solutions of 24 card game */
v_expr solutions = {};

/* save var <expr> to solutions <v_expr> if var.first is 24 and not undefined */
void save_solut(expr var) {
    if (var.first == 24 && var.second != "~") {
        solutions.push_back(var);
    }
}

/* prints solutions */
void display_solut() {
    for (int i = 0; i < solutions.size(); i++) {
        cout << solutions[i].second << endl;
    }
}

/* arguments: perm <v_expr>; accepted argument is an ordered permutation of 4 numbers */
/* utility: find solutions to 24 game for given 4 number permutation */
void solve(v_expr perm) {
    char ops[] = {'+', '-', '*', '/'};
    char op1, op2, op3;
    for (int i = 0; i < 4; i++) {
        op1 = ops[i];
        for (int j = 0; j < 4; j++) {
            op2 = ops[j];  
            for (int k = 0; k < 4; k++) {
                op3 = ops[k];
                save_solut(evaluate(evaluate(perm[0], op1, perm[1]), op2, evaluate(perm[2], op3, perm[3])));    /* (a o b) o (c o d) */
                save_solut(evaluate(evaluate(evaluate(perm[0], op1, perm[1]), op2, perm[2]), op3, perm[3]));    /* ((a o b) o c) o d */
                save_solut(evaluate(evaluate(perm[0], op1, evaluate(perm[1], op2, perm[2])), op3, perm[3]));    /* (a o (b o c)) o d */
                save_solut(evaluate(perm[0], op1, evaluate(evaluate(perm[1], op2, perm[2]), op3, perm[3])));    /* a o ((b o c) o d) */
                save_solut(evaluate(perm[0], op1, evaluate(perm[1], op2, evaluate(perm[2], op3, perm[3]))));    /* a o ((b o c) o d) */
            }
        }
    }
    
}

/* saves solutions of 24 card game to a .txt file */
void save_to_file(int * cards, double search_time) {
    ofstream solver;
    string filename = "../test/24game.txt";

    solver.open(filename);

    solver << "Kartu terpilih: ";
    for (int i = 0; i < 4; i++) {
        solver << value_to_card(cards[i]) << " ";
    }
    solver << endl << endl;
    
    solver << "Solusi: " << endl;
    if (solutions.size() == 0) {
        solver << "Tidak ada solusi" << endl;
    } else {
        solver << "Banyak solusi: " << solutions.size() << endl;
        for (int i = 0; i < solutions.size(); i++) {
            solver << solutions[i].second << endl;
        }
    }
    solver << "Waktu pencarian: " << search_time << " detik" << endl;
    solver.close();
}
