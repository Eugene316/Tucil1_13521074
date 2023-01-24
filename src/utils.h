#ifndef UTILS
#define UTILS

#include <random>
#include <time.h>
#include <iostream>
using namespace std;

extern clock_t checkpoint;
extern double recorded_time;

/* records current clock */
void start_timer();

/* saves time elapsed since last checkpoint */
void stop_timer();

/* get card value (1-10) of input string */
int card_value(string input);

/* input 4 cards by user */
void input_cards(int * cards);

/* randomize 4 cards */
void random_cards(int * cards);

#endif