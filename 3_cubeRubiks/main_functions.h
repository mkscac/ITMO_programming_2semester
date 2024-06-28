#ifndef PRG_LABA8_CUBERUBIKS_MAIN_FUNCTIONS_H
#define PRG_LABA8_CUBERUBIKS_MAIN_FUNCTIONS_H

#include "cube.h"

void open_one_window(RubiksCube &currentCube);
void open_multiple_windows(RubiksCube &currentCube, int &number_window);


void random_installation_cube(RubiksCube &currentCube, int &count, int &mode_draw, int &number_window);
int install_draw_cube();

#endif
