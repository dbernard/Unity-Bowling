#ifndef INCLUDED_BOWLING_GAME
#define INCLUDED_BOWLING_GAME

#ifdef __cplusplus
extern "C" {
#endif

void bowling_game_init(void);
void bowling_game_roll(int pins);
int bowling_game_score();

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_BOWLING_GAME */
