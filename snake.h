#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE 100
#define CELL_SIZE 20
#define BOARD_X 10
#define BOARD_Y 60
#define GRID_COLS 39  // 780 / 20
#define GRID_ROWS 26  // 520 / 20

typedef struct {
    int x;
    int y;
} Vector2Grid;

typedef struct {
    Vector2Grid body[MAX_SNAKE];
    int length;
    Vector2Grid direction;
} Snake;

void setup_snake(Snake *snake_ptr);
void advance_snake(Snake *snake_ptr);
void update_movement_intent(Snake *player);
void DrawSnake(Snake *s);

#endif