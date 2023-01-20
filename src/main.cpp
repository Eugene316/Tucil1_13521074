#include <iostream>
#include <time.h>
#include <random>
using namespace std;

#include "expr.h"
#include "solver.h"
#include "utils.h"

int main() {
    int card_inputs[4];

    /* input method selection & validation */
    cout << "Metode masukan kartu:\n" << "1. Input manual.\n" << "2. 4 kartu acak.\n";
    string choice;
    cout << "Pilihan: ";
    do {
        cin >> choice;
        if (choice != "1" && choice != "2") {
            cout << "Masukan tidak sesuai!" << endl;
        }
    } while (choice != "1" && choice != "2");
    
    /* input 4 cards */
    if (choice == "1") {
        input_cards(card_inputs);
    } else {
        random_cards(card_inputs);
    }

    /* chore: permute cards*/

    v_expr perms;   /* perm: abcd */
    for (int i = 0; i < 4; i++) {
        perms.push_back(create_expr(card_inputs[i]));
    }


    /* solve & view solutions */
    cout << "\nSolusi:" << endl;

    start_timer();
    solve(perms);
    cout << "Waktu pencarian: ";
    stop_timer();
    cout << endl;

    display_solut();
    cout << "Banyak solusi: " << solutions.size() << endl;

    /* chore: save to file */

    return 0;
}