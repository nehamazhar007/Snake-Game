#ifndef MECHANICS_H
#define MECHANICS_H

#include "snake.h"

typedef struct {
    int x;
    int y;
    int size;
} Food;

void InitFood(Food *f);
void SpawnFood(Food *f, Snake *s);
int CheckFoodEaten(Snake *s, Food *f, int *score);
int CheckWallCollision(Snake *s);
int CheckSelfCollision(Snake *s);
void DrawFood(Food *f);

#endif