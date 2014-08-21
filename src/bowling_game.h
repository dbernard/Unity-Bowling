#ifndef INCLUDED_BOWLING_GAME
#define INCLUDED_BOWLING_GAME

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration
typedef struct bowling_game_t bowling_game_t;

bowling_game_t *
bowling_game_create(void);
void bowling_game_destroy(bowling_game_t *g);

void bowling_game_roll(bowling_game_t *g, int pins);
int bowling_game_score(bowling_game_t *g);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_BOWLING_GAME */
