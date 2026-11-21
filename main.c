#include "raylib.h"
#include "ui.h"
#include "snake.h"
#include "mechanics.h"

int main()
{
    int width = 800;
    int height = 600;

    InitWindow(width, height, "Snake Game");
    SetTargetFPS(60);

    Color retroGreen = {155, 188, 15, 255};

    int currentScreen = WELCOME;
    int selectedOption = START_GAME;
    int gameOverOption = RESTART;
    int isPaused = 0;
    int score = 0;
    int snakeDead = 0;

    Snake snake;
    Food food;
    setup_snake(&snake);
    InitFood(&food);

    int moveTimer = 0;

    while (!WindowShouldClose())
    {
        if (currentScreen == WELCOME)
        {
            if (IsKeyPressed(KEY_ENTER)) currentScreen = MENU;
        }
        else if (currentScreen == MENU)
        {
            if (IsKeyPressed(KEY_DOWN)) selectedOption++;
            if (IsKeyPressed(KEY_UP)) selectedOption--;
            if (selectedOption > 2) selectedOption = 0;
            if (selectedOption < 0) selectedOption = 2;

            if (IsKeyPressed(KEY_ENTER))
            {
                if (selectedOption == START_GAME)
                {
                    currentScreen = GAME;
                    score = 0;
                    isPaused = 0;
                    snakeDead = 0;
                    moveTimer = 0;
                    setup_snake(&snake);
                    InitFood(&food);
                    SpawnFood(&food, &snake);
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
        else if (currentScreen == INSTRUCTIONS)
        {
            if (IsKeyPressed(KEY_ENTER)) currentScreen = MENU;
        }
        else if (currentScreen == GAME)
        {
            if (IsKeyPressed(KEY_P))
            {
                if (isPaused == 0) isPaused = 1;
                else isPaused = 0;
            }

            if (isPaused == 0)
            {
                update_movement_intent(&snake);

                moveTimer++;
                if (moveTimer >= 8)
                {
                    moveTimer = 0;
                    advance_snake(&snake);
                    CheckFoodEaten(&snake, &food, &score);

                    if (CheckWallCollision(&snake) == 1 || CheckSelfCollision(&snake) == 1)
                    {
                        snakeDead = 1;
                    }
                }

                if (snakeDead == 1)
                {
                    currentScreen = GAMEOVER;
                    gameOverOption = RESTART;
                }
            }
        }
        else if (currentScreen == GAMEOVER)
        {
            if (IsKeyPressed(KEY_DOWN)) gameOverOption++;
            if (IsKeyPressed(KEY_UP)) gameOverOption--;
            if (gameOverOption > 1) gameOverOption = 0;
            if (gameOverOption < 0) gameOverOption = 1;

            if (IsKeyPressed(KEY_ENTER))
            {
                if (gameOverOption == RESTART)
                {
                    currentScreen = GAME;
                    score = 0;
                    isPaused = 0;
                    snakeDead = 0;
                    gameOverOption = RESTART;
                    moveTimer = 0;
                    setup_snake(&snake);
                    InitFood(&food);
                    SpawnFood(&food, &snake);
                }
                else if (gameOverOption == MAIN_MENU)
                {
                    currentScreen = MENU;
                    selectedOption = START_GAME;
                    gameOverOption = RESTART;
                }
            }
        }

        BeginDrawing();
        ClearBackground(retroGreen);

        if (currentScreen == WELCOME) DrawWelcomeScreen();
        if (currentScreen == MENU) DrawMenuScreen(selectedOption);
        if (currentScreen == INSTRUCTIONS) DrawInstructionsScreen();
        if (currentScreen == GAME)
        {
            DrawGameScreen(score, isPaused, &snake, &food);
        }
        if (currentScreen == GAMEOVER) DrawGameOverScreen(score, gameOverOption);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}