#include "bowling_game.h"


static int s_score;


void
bowling_game_init(void)
{
    s_score = 0;
}


void
bowling_game_roll(int pins)
{
    s_score += pins;
}


int
bowling_game_score()
{
    return s_score;
}
