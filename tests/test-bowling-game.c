#include "unity.h"
#include "test-bowling-game.h"
#include "bowling_game.h"


static bowling_game_t *game;

void
setUp(void)
{
    game = bowling_game_create();
}


void
tearDown(void)
{
    if (game)
        bowling_game_destroy(game);

    game = NULL;

    return;
}


void
roll_many(bowling_game_t *g, int rolls, int pins)
{
    int i;

    for (i = 0; i < rolls; i++)
    {
        bowling_game_roll(g, pins);
    }
}


void
test_gutter_game(void)
{
    roll_many(game, 20, 0);

    TEST_ASSERT_EQUAL(0, bowling_game_score(game));
}


void
test_all_ones_game(void)
{
    roll_many(game, 20, 1);

    TEST_ASSERT_EQUAL(20, bowling_game_score(game));
}


void test_one_spare(void)
{
    bowling_game_roll(game, 5);
    bowling_game_roll(game, 5);
    bowling_game_roll(game, 3);
    roll_many(game, 17, 0);

    TEST_ASSERT_EQUAL(16, bowling_game_score(game));
}

