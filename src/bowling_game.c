#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "bowling_game.h"

enum { max_rolls = 21 };

struct bowling_game_t
{
    int rolls[max_rolls];
    int current_roll;
};


bowling_game_t *
bowling_game_create(void)
{
    bowling_game_t *g = calloc(1, sizeof(*g));

    return g;
}

void
bowling_game_destroy(bowling_game_t *g)
{
    free(g);
}


void
bowling_game_roll(bowling_game_t *g, int pins)
{
    assert(g);
    g->rolls[g->current_roll++] = pins;
}


int
bowling_game_score(bowling_game_t *g)
{
    int score = 0;

    int i = 0;
    for (int frame=0; frame<10; frame++)
    {
        if (g->rolls[i] + g->rolls[i+1] == 10)
        {
            score += 10 + g->rolls[i+2];
            i += 2;
        }
        else
        {
            score += g->rolls[i] + g->rolls[i+1];
            i += 2;
        }
    }

    return score;
}
