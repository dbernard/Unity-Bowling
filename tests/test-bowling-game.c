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
test_gutter_game(void)
{
    int i;

    for (i = 0; i < 20; i++)
    {
        bowling_game_roll(0);
    }

    TEST_ASSERT_EQUAL(0, bowling_game_score());
}


void
test_all_ones_game(void)
{
    int i;

    for (i = 0; i < 20; i++)
    {
        bowling_game_roll(1);
    }

    TEST_ASSERT_EQUAL(20, bowling_game_score());
}

