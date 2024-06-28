#ifndef PRG_LABA8_CUBERUBIKS_CUBE_H
#define PRG_LABA8_CUBERUBIKS_CUBE_H

#include "structures.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;


class RubiksCube {
private:
    small_part_color m_cube[6][3][3];
    int number_image_for_save;

public:
    RubiksCube() {number_image_for_save = 1;}

    void install_random_condition_of_cube();
    void install_collected_condition_of_cube();

    void draw_all_cube();


    void horizontally_turn_123_to_right(int numb);
    void horizontally_turn_123_to_left(int numb);

    void vertically_turn_456_to_up(int numb);
    void vertically_turn_456_to_down(int numb);

    void lateral_turn_789_to_right(int numb);
    void lateral_turn_789_to_left(int numb);


    void save_condition_in_file();
    void read_condition_from_file(string &name_file_for_read);

    bool check_current_condition_correctness();
};


void check_color_for_correctness(small_part_color &color, int &red_k, int &yell_k, int &green_k, int &white_k, int &blue_k, int &orange_k);
string name_color_for_save(small_part_color &color);
small_part_color get_index_color_from_file(char color_char);

#endif