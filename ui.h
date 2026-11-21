#ifndef UI_H
#define UI_H

#include "mechanics.h"

enum { WELCOME, MENU, INSTRUCTIONS, GAME, GAMEOVER };
enum { START_GAME, INSTRUCTIONS_OPTION, EXIT_GAME };
enum { RESTART, MAIN_MENU };

void DrawWelcomeScreen();
void DrawMenuScreen(int selectedOption);
void DrawInstructionsScreen();
void DrawGameScreen(int score, int isPaused, Snake *snake, Food *food);
void DrawGameOverScreen(int score, int gameOverOption);

#endif