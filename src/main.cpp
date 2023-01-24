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

    v_expr perms = {};   /* perm: abcd */

    string curr_perm;   /* current permutation */
    vector<string> processed = {};  /* processed perms */
    bool is_new_perm;
        
    /* solve & view solutions */
    cout << "\nSolusi:" << endl;

    start_timer();
    // solve(perms);
    for (int i = 0; i < 4; i++) {       /* permutation loop */
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (i != j && i != k && i != l && j != k && j != l && k != l) {     /* process if i,j,k,l indices are unique */
                        curr_perm = to_string(card_inputs[i]) + to_string(card_inputs[j]) + to_string(card_inputs[k]) + to_string(card_inputs[l]);

                        is_new_perm = true;         /* check if permutation is previously processed */
                        for (int a = 0; a < processed.size(); a++) {
                            if (curr_perm == processed[a]) {
                                is_new_perm = false;
                                break;
                            }
                        }

                        if (is_new_perm) {      /* process if permutation is new */
                            processed.push_back(curr_perm);
                            
                            perms.clear();      /* create permutation v_expr */
                            perms.push_back(create_expr(card_inputs[i]));
                            perms.push_back(create_expr(card_inputs[j]));
                            perms.push_back(create_expr(card_inputs[k]));
                            perms.push_back(create_expr(card_inputs[l]));

                            solve(perms);
                        }
                    }
                }
            }
        }   
    }
    stop_timer();

    int total_solut = solutions.size();

    if (total_solut > 0) {
        cout << "Banyak solusi: " << total_solut << endl;
        display_solut();
        /* chore: save to file */
    } else {
        cout << "Tidak ada solusi" << endl;
    }

    cout << "Waktu pencarian: " << recorded_time << " detik" << endl;
    

    return 0;
}