#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE 100

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

#endif