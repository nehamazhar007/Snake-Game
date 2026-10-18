#include <stdlib.h>
#include "food.h"

Food generate_food(int board_width, int board_height) {
    Food f;
    f.board_width = board_width;
    f.board_height = board_height;
    f.x = rand() % board_width;
    f.y = rand() % board_height;
    return f;
}

Food respawn_food(Food *food) {
    food->x = rand() % food->board_width;
    food->y = rand() % food->board_height;
    return *food;
}
