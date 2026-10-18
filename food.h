#ifndef FOOD_H
#define FOOD_H

typedef struct {
    int x;
    int y;
    int board_width;
    int board_height;
} Food;

Food generate_food(int board_width, int board_height);
Food respawn_food(Food *food);

#endif
