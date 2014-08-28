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
    int all_pins = 10;

    int i = 0;
    for (int frame=0; frame<10; frame++)
    {
        // Strikes
        if (rolls[i] == all_pins)
        {
            // Strike is 10pts + sum of next two rolls
            score += 10 + rolls[i+1] + rolls[i+2];
            // Increment the entire FRAME... We rolled a strike, so we're done.
            i += 1;
        }

        // Spares
        else if (rolls[i] + rolls[i+1] == all_pins)
        {
            score += 10 + rolls[i+2];
            i += 2;
        }

        // Other
        else
        {
            score += rolls[i] + rolls[i+1];
            i += 2;
        }
    }

    return score;
}
