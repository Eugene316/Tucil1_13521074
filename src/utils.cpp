#include "utils.h"

clock_t checkpoint;
double recorded_time;

/* records current clock */
void start_timer() {
    checkpoint = clock();
}

/* saves time elapsed since last checkpoint */
void stop_timer() {
    recorded_time = (double)(clock() - checkpoint) / CLOCKS_PER_SEC;
}

/* get card value (1-10) of input string */
int card_value(string input) {
    if (input == "A") {
        return 1;
    } else if (input == "10") {
        return 10;
    } else if (input == "J") {
        return 11;
    } else if (input == "Q") {
        return 12;
    } else if (input == "K") {
        return 13;
    } else if (input == "2") {
        return 2;
    } else if (input == "3") {
        return 3;
    } else if (input == "4") {
        return 4;
    } else if (input == "5") {
        return 5;
    } else if (input == "6") {
        return 6;
    } else if (input == "7") {
        return 7;
    } else if (input == "8") {
        return 8;
    } else if (input == "9") {
        return 9;
    } else {
        return -1;
    }
}

/* input 4 cards by user */
void input_cards(int * cards) {
    cout << "Masukkan nilai keempat kartu! cth. A 2 10 Q" << endl;
    string inputs[4];
    do {
        cin >> inputs[0] >> inputs[1] >> inputs[2] >> inputs[3];

        for (int i = 0; i < 4; i++) {
            cards[i] = card_value(inputs[i]);
        }
        
        if (cards[0] == -1 || cards[1] == -1 || cards[2] == -1 || cards[3] == -1) {
            cout << "Masukan tidak sesuai!" << endl;
        }
    } while (cards[0] == -1 || cards[1] == -1 || cards[2] == -1 || cards[3] == -1);
}

/* randomize 4 cards */
void random_cards(int * cards) {
    srand(time(NULL));
    int random;
    cout << "Kartu terpilih:" << endl;
    for (int i = 0; i < 4; i++) {
        random = rand() % 13 + 1;
        switch (random) {
            case 1: {
                cards[i] = 1;
                cout << "A ";
                break;
            } case 11: {
                cards[i] = 10;
                cout << "J ";
                break;
            } case 12: {
                cards[i] = 10;
                cout << "Q ";
                break;
            } case 13: {
                cards[i] = 10;
                cout << "K ";
                break;
            } default:
                cards[i] = random;
                cout << to_string(random) + ' ';
                break;
        }
    }
    cout << endl;
}