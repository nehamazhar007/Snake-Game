#include "raylib.h"
#include "ui.h"

int main()
{
    int width = 800;
    int height = 600;

    InitWindow(width, height, "Snake Game");
    SetTargetFPS(60);

    int currentScreen = WELCOME;
    int selectedOption = START_GAME;
    int gameOverOption = RESTART;
    int isPaused = 0;
    int score = 0;

    while (!WindowShouldClose())
    {
        if (currentScreen == WELCOME)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = MENU;
            }
        }

        if (currentScreen == MENU)
        {
            if (IsKeyPressed(KEY_DOWN))
            {
                selectedOption++;
            }
            if (IsKeyPressed(KEY_UP))
            {
                selectedOption--;
            }
            if (selectedOption > 2)
            {
                selectedOption = 0;
            }
            if (selectedOption < 0)
            {
                selectedOption = 2;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                if (selectedOption == START_GAME)
                {
                    currentScreen = GAME;
                    score = 0;
                    isPaused = 0;
                }
                else if (selectedOption == INSTRUCTIONS_OPTION)
                {
                    currentScreen = INSTRUCTIONS;
                }
                else if (selectedOption == EXIT_GAME)
                {
                    break;
                }
            }
        }

        if (currentScreen == INSTRUCTIONS)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = MENU;
            }
        }

        if (currentScreen == GAME)
        {
            if (IsKeyPressed(KEY_P))
            {
                if (isPaused == 0)
                {
                    isPaused = 1;
                }
                else
                {
                    isPaused = 0;
                }
            }

            if (isPaused == 0)
            {
                score++;
            }
        }

        if (currentScreen == GAMEOVER)
        {
            if (IsKeyPressed(KEY_DOWN))
            {
                gameOverOption++;
            }
            if (IsKeyPressed(KEY_UP))
            {
                gameOverOption--;
            }
            if (gameOverOption > 1)
            {
                gameOverOption = 0;
            }
            if (gameOverOption < 0)
            {
                gameOverOption = 1;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                if (gameOverOption == RESTART)
                {
                    currentScreen = GAME;
                    score = 0;
                    isPaused = 0;
                }
                else if (gameOverOption == MAIN_MENU)
                {
                    currentScreen = MENU;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentScreen == WELCOME)
        {
            DrawWelcomeScreen();
        }
        if (currentScreen == MENU)
        {
            DrawMenuScreen(selectedOption);
        }
        if (currentScreen == INSTRUCTIONS)
        {
            DrawInstructionsScreen();
        }
        if (currentScreen == GAME)
        {
            DrawGameScreen(score, isPaused);
        }
        if (currentScreen == GAMEOVER)
        {
            DrawGameOverScreen(score, gameOverOption);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}