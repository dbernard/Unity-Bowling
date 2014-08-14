#include "bowling_game.h"
#include "string.h"

enum { max_rolls = 21 };
static int rolls[max_rolls];
static int current_roll;


void
bowling_game_init(void)
{
    current_roll = 0;
    // Initialize array to have all 0s
    memset(&rolls[0], 0, sizeof(rolls));
}


void
bowling_game_roll(int pins)
{
    rolls[current_roll] = pins;
    current_roll++;
}


int
bowling_game_score()
{
    int score = 0;

    int i = 0;
    for (int frame=0; frame<10; frame++)
    {
        if (rolls[i] + rolls[i+1] == 10)
        {
            score += 10 + rolls[i+2];
            i += 2;
        }
        else
        {
            score += rolls[i] + rolls[i+1];
            i += 2;
        }
    }

    return score;
}
