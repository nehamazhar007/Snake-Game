#include "ui.h"
#include "raylib.h"

void DrawWelcomeScreen()
{
    DrawRectangle(150, 120, 500, 350, GREEN);
    DrawRectangle(150, 120, 500, 350, DARKGREEN);
    DrawRectangle(160, 130, 480, 330, GREEN);
    DrawText("SNAKE GAME", 250, 180, 50, DARKGREEN);
    DrawText("Welcome to the Game", 270, 260, 25, BLACK);
    DrawText("Eat - Grow - Survive", 280, 300, 20, DARKGRAY);
    DrawText("Press ENTER to Continue", 240, 380, 22, BLACK);
}

void DrawMenuScreen(int selectedOption)
{
    DrawText("MAIN MENU", 300, 100, 40, DARKGREEN);
    DrawLine(300, 150, 500, 150, DARKGREEN);

    if (selectedOption == START_GAME)
    {
        DrawRectangle(270, 200, 260, 45, GREEN);
        DrawText("Start Game", 300, 210, 30, WHITE);
    }
    else
    {
        DrawText("Start Game", 300, 210, 30, BLACK);
    }

    if (selectedOption == INSTRUCTIONS_OPTION)
    {
        DrawRectangle(270, 270, 260, 45, GREEN);
        DrawText("Instructions", 300, 280, 30, WHITE);
    }
    else
    {
        DrawText("Instructions", 300, 280, 30, BLACK);
    }

    if (selectedOption == EXIT_GAME)
    {
        DrawRectangle(270, 340, 260, 45, GREEN);
        DrawText("Exit", 300, 350, 30, WHITE);
    }
    else
    {
        DrawText("Exit", 300, 350, 30, BLACK);
    }

    DrawText("Use UP and DOWN keys to select", 220, 470, 20, DARKGRAY);
    DrawText("Press ENTER to confirm", 250, 500, 20, DARKGRAY);
}

void DrawInstructionsScreen()
{
    DrawRectangle(100, 80, 600, 430, LIGHTGRAY);
    DrawText("HOW TO PLAY", 300, 110, 35, DARKGREEN);
    DrawText("1. Use Arrow Keys to Move", 180, 190, 22, BLACK);
    DrawText("2. Eat Food to Grow Longer", 180, 230, 22, BLACK);
    DrawText("3. Dont Hit Walls", 180, 270, 22, BLACK);
    DrawText("4. Dont Bite Yourself", 180, 310, 22, BLACK);
    DrawText("5. Press P to Pause the Game", 180, 350, 22, BLACK);
    DrawText("Press ENTER to Go Back", 240, 440, 20, DARKGRAY);
}

void DrawGameScreen(int score, int isPaused, Snake *snake, Food *food)
{
    DrawRectangle(0, 0, 800, 50, DARKGREEN);
    DrawText(TextFormat("Score: %d", score), 20, 12, 25, WHITE);
    DrawText("Press P to Pause", 550, 12, 20, WHITE);
    // Issue 10 + 31: Border ab game area ke barabar hai
    DrawRectangleLines(BOARD_X, BOARD_Y, GRID_COLS * CELL_SIZE, GRID_ROWS * CELL_SIZE, DARKGREEN);

    // Issue 29 + 30: Snake aur Food border ke andar draw honge
    DrawFood(food);
    DrawSnake(snake);

    if (isPaused == 1)
    {
        DrawRectangle(200, 200, 400, 180, LIGHTGRAY);
        DrawText("GAME PAUSED", 280, 230, 30, BLACK);
        DrawText("Take a Break!", 300, 275, 20, DARKGRAY);
        DrawText("Press P to Resume", 280, 320, 20, BLACK);
    }
}

void DrawGameOverScreen(int score, int gameOverOption)
{
    DrawRectangle(150, 100, 500, 380, MAROON);
    DrawText("GAME OVER", 280, 140, 45, WHITE);
    DrawText("Oh No! Snake Crashed", 250, 210, 22, LIGHTGRAY);
    DrawText(TextFormat("Final Score: %d", score), 280, 260, 25, YELLOW);

    if (gameOverOption == RESTART)
    {
        DrawRectangle(280, 310, 240, 40, WHITE);
        DrawText("Restart", 340, 318, 25, BLACK);
    }
    else
    {
        DrawText("Restart", 340, 318, 25, WHITE);
    }

    if (gameOverOption == MAIN_MENU)
    {
        DrawRectangle(280, 360, 240, 40, WHITE);
        DrawText("Main Menu", 320, 368, 25, BLACK);
    }
    else
    {
        DrawText("Main Menu", 320, 368, 25, WHITE);
    }
}