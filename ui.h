#ifndef UI_H
#define UI_H

#include "raylib.h"

enum Screen
{
    WELCOME,
    MENU,
    GAME,
    INSTRUCTIONS,
    GAMEOVER
};

enum MenuOption
{
    START_GAME,
    INSTRUCTIONS_OPTION,
    EXIT_GAME
};

enum GameOverOption
{
    RESTART,
    MAIN_MENU
};

void DrawWelcomeScreen();
void DrawMenuScreen(int selectedOption);
void DrawInstructionsScreen();
void DrawGameScreen(int score, int isPaused);
void DrawGameOverScreen(int score, int gameOverOption);

#endif