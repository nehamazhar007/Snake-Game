#include "mechanics.h"
#include <raylib.h>

void InitFood(Food *f) {
    f->size = CELL_SIZE;
    f->x = 20;
    f->y = 13;
}

void SpawnFood(Food *f, Snake *s) {
    int onSnake;
    int tries = 0;
    do {
        onSnake = 0;
        f->x = GetRandomValue(0, GRID_COLS - 1);
        f->y = GetRandomValue(0, GRID_ROWS - 1);

        for (int i = 0; i < s->length; i++) {
            if (f->x == s->body[i].x && f->y == s->body[i].y) {
                onSnake = 1;
                break;
            }
        }
        tries++;
    } while (onSnake == 1 && tries < 500);
}

int CheckFoodEaten(Snake *s, Food *f, int *score) {
    if (s->body[0].x == f->x && s->body[0].y == f->y) {
        *score = *score + 10;
        if (s->length < MAX_SNAKE) {
            s->length = s->length + 1;
        }
        SpawnFood(f, s);
        return 1;
    }
    return 0;
}

int CheckWallCollision(Snake *s) {
    int hx = s->body[0].x;
    int hy = s->body[0].y;
    if (hx < 0 || hx >= GRID_COLS || hy < 0 || hy >= GRID_ROWS) {
        return 1;
    }
    return 0;
}

int CheckSelfCollision(Snake *s) {
    int hx = s->body[0].x;
    int hy = s->body[0].y;
    for (int i = 1; i < s->length; i++) {
        if (hx == s->body[i].x && hy == s->body[i].y) {
            return 1;
        }
    }
    return 0;
}

void DrawFood(Food *f) {
    DrawRectangle(BOARD_X + f->x * CELL_SIZE,
                  BOARD_Y + f->y * CELL_SIZE,
                  f->size, f->size, GREEN);
}