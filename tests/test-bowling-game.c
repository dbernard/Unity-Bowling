#include "unity.h"
#include "test-bowling-game.h"
#include "bowling_game.h"


void
setUp(void)
{
    bowling_game_init();
}


void
tearDown(void)
{
    return;
}


void
roll_many(int rolls, int pins)
{
    int i;

    for (i = 0; i < rolls; i++)
    {
        bowling_game_roll(pins);
    }
}


void
test_gutter_game(void)
{
    roll_many(20, 0);

    TEST_ASSERT_EQUAL(0, bowling_game_score());
}


void
test_all_ones_game(void)
{
    roll_many(20, 1);

    TEST_ASSERT_EQUAL(20, bowling_game_score());
}


void test_one_spare(void)
{
    bowling_game_roll(5);
    bowling_game_roll(5);
    bowling_game_roll(3);
    roll_many(17, 0);

    TEST_ASSERT_EQUAL(16, bowling_game_score());
}

