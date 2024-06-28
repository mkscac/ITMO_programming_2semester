#include "cube.h"

void RubiksCube::install_random_condition_of_cube() {
    ColorsAll colors;
    int red_k = 0, yell_k = 0, green_k = 0, white_k = 0, blue_k = 0, orange_k = 0;
    int random;


    for(int face = 0; face < 6; face++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                random = rand() % 6;

                if(random == 0 && red_k < 9) {
                    copy(begin(colors.red_color), end(colors.red_color), begin(m_cube[face][i][j].color));
                    red_k++;
                }
                else if(random == 1 && yell_k < 9) {
                    copy(begin(colors.yellow_color), end(colors.yellow_color), begin(m_cube[face][i][j].color));
                    yell_k++;
                }
                else if(random == 2 && green_k < 9) {
                    copy(begin(colors.green_color), end(colors.green_color), begin(m_cube[face][i][j].color));
                    green_k++;
                }
                else if(random == 3 && white_k < 9) {
                    copy(begin(colors.white_color), end(colors.white_color), begin(m_cube[face][i][j].color));
                    white_k++;
                }
                else if(random == 4 && blue_k < 9) {
                    copy(begin(colors.blue_color), end(colors.blue_color), begin(m_cube[face][i][j].color));
                    blue_k++;
                }
                else if(random == 5 && orange_k < 9) {
                    copy(begin(colors.orange_color), end(colors.orange_color), begin(m_cube[face][i][j].color));
                    orange_k++;
                }
                else {
                    j--;
                }
            }
        }
    }
}



void RubiksCube::install_collected_condition_of_cube() {
    int i, j;
    ColorsAll colors;


    /// m_left
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.red_color), end(colors.red_color), begin(m_cube[0][i][j].color));

    /// m_top
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.yellow_color), end(colors.yellow_color), begin(m_cube[1][i][j].color));

    /// m_right
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.green_color), end(colors.green_color), begin(m_cube[2][i][j].color));

    /// m_botton
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.white_color), end(colors.white_color), begin(m_cube[3][i][j].color));

    /// m_front
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.blue_color), end(colors.blue_color), begin(m_cube[4][i][j].color));

    /// m_back
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            copy(begin(colors.orange_color), end(colors.orange_color), begin(m_cube[5][i][j].color));

    cout << "installed collected condition of cube\n";

}



void RubiksCube::draw_all_cube() {
    float x_start, y_start, y_buf, x_buf ;
    glBegin(GL_QUADS);


    for(int face = 0; face < 6; face++) {
        if(face == 0) {
            x_start = -0.32f, y_start = 0.04f, x_buf = x_start;
        }
        else if(face == 1) {
            x_start = -0.23f, y_start = 0.04f, y_buf = y_start;
        }
        else if(face == 2 || face == 5) {
            continue;
        }
        else if(face == 3) {
            x_start = 0.27f, y_start = 0.04f, y_buf = y_start;
        }
        else if(face == 4) {
            x_start = -0.23f, y_start = -0.21f, y_buf = y_start;
        }


        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(face == 0) {
                    glColor3f(m_cube[face][i][j].color[0], m_cube[face][i][j].color[1], m_cube[face][i][j].color[2]);
                    glVertex2f(x_start, y_start); // bottom left corner
                    x_start += 0.08f;
                    glVertex2f(x_start, y_start); // bottom right corner
                    y_start += 0.08f;
                    glVertex2f(x_start, y_start); // top right corner
                    x_start -= 0.08f;
                    glVertex2f(x_start, y_start); // top left corner

                    y_start -= 0.16f;
                }

                else if(face == 1 || face == 3 || face == 4) {
                    glColor3f(m_cube[face][i][j].color[0], m_cube[face][i][j].color[1], m_cube[face][i][j].color[2]);
                    glVertex2f(x_start, y_start); // bottom left corner
                    x_start += 0.08f;
                    glVertex2f(x_start, y_start); // bottom right corner
                    y_start += 0.08f;
                    glVertex2f(x_start, y_start); // top right corner
                    x_start -= 0.08f;
                    glVertex2f(x_start, y_start); // top left corner

                    x_start += 0.08f;
                    y_start -= 0.08f;
                }
            }

            if(face == 0) {
                y_start = 0.04f;
                x_start = x_buf - 0.08f;
                x_buf -= 0.08f;
            }
            else if(face == 1) {
                x_start = -0.23f;
                y_start = y_buf - 0.08f;
                y_buf -= 0.08f;
            }
            else if(face == 3) {
                x_start = 0.27f;
                y_start = y_buf - 0.08f;
                y_buf -= 0.08f;
            }
            else if(face == 4) {
                x_start = -0.23f;
                y_start = y_buf - 0.08f;
                y_buf -= 0.08f;
            }
        }
    }


    /// m_right = m_left только с конца
    x_start = 0.18f, y_start = 0.04f, x_buf = x_start;
    for(int i = 2; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {
            glColor3f(m_cube[2][i][j].color[0], m_cube[2][i][j].color[1], m_cube[2][i][j].color[2]);
            glVertex2f(x_start, y_start); // bottom left corner
            x_start += 0.08f;
            glVertex2f(x_start, y_start); // bottom right corner
            y_start += 0.08f;
            glVertex2f(x_start, y_start); // top right corner
            x_start -= 0.08f;
            glVertex2f(x_start, y_start); // top left corner

            y_start -= 0.16f;

        }
        y_start = 0.04f;
        x_start = x_buf - 0.08f;
        x_buf -= 0.08f;
    }


    /// m_back
    x_start = -0.23f, y_start = 0.29f, y_buf = y_start;
    for(int i = 2; i >= 0; i--) {
        for(int j = 2; j >= 0; j--) {
            glColor3f(m_cube[5][i][j].color[0], m_cube[5][i][j].color[1], m_cube[5][i][j].color[2]);
            glVertex2f(x_start, y_start); // bottom left corner
            x_start += 0.08f;
            glVertex2f(x_start, y_start); // bottom right corner
            y_start += 0.08f;
            glVertex2f(x_start, y_start); // top right corner
            x_start -= 0.08f;
            glVertex2f(x_start, y_start); // top left corner

            x_start += 0.08f;
            y_start -= 0.08f;
        }
        x_start = -0.23f;
        y_start = y_buf - 0.08f;
        y_buf -= 0.08f;
    }
    glEnd();
}



void RubiksCube::horizontally_turn_123_to_right(int numb) {
    numb--;
    small_part_color temp[3], temp2[3];

    copy(begin(m_cube[2][numb]), end(m_cube[2][numb]), begin(temp));
    copy(begin(m_cube[4][numb]), end(m_cube[4][numb]), begin(m_cube[2][numb]));

    copy(begin(m_cube[5][numb]), end(m_cube[5][numb]), begin(temp2));
    copy(begin(temp), end(temp), begin(m_cube[5][numb]));

    copy(begin(m_cube[0][numb]), end(m_cube[0][numb]), begin(temp));
    copy(begin(temp2), end(temp2), begin(m_cube[0][numb]));

    copy(begin(temp), end(temp), begin(m_cube[4][numb]));


    /// поворот top/botton если numb == 1/3
    if(numb == 1-1 || numb == 3-1) {
        numb++;
        small_part_color temp_top_bott[3][3];

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                temp_top_bott[i][j] = m_cube[numb][i][j];


        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                m_cube[numb][2-j][i] = temp_top_bott[i][j];
    }
}



void RubiksCube::horizontally_turn_123_to_left(int numb) {
    numb--;
    small_part_color temp[3], temp2[3];

    copy(begin(m_cube[0][numb]), end(m_cube[0][numb]), begin(temp));
    copy(begin(m_cube[4][numb]), end(m_cube[4][numb]), begin(m_cube[0][numb]));

    copy(begin(m_cube[5][numb]), end(m_cube[5][numb]), begin(temp2));
    copy(begin(temp), end(temp), begin((m_cube[5][numb])));


    copy(begin(m_cube[2][numb]), end(m_cube[2][numb]), begin(temp));
    copy(begin(temp2), end(temp2), begin(m_cube[2][numb]));

    copy(begin(temp), end(temp), begin(m_cube[4][numb]));


    /// поворот top/botton если numb == 1/3
    if(numb == 1-1 || numb == 3-1) {
        numb++;
        small_part_color temp_top_bott[3][3];

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                temp_top_bott[i][j] = m_cube[numb][i][j];


        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                m_cube[numb][j][2-i] = temp_top_bott[i][j];
    }
}



void RubiksCube::vertically_turn_456_to_up(int numb) {
    numb -= (3+1);
    int i;
    small_part_color temp[3], temp2[3];

    for(i = 0; i < 3; i++)
        temp[i] = m_cube[1][i][numb];

    for(i = 0; i < 3; i++)
        m_cube[1][i][numb] = m_cube[4][i][numb];


    for(i = 0; i < 3; i++)
        temp2[i] = m_cube[5][i][2-numb];

    for(i = 0; i < 3; i++)
        m_cube[5][i][2-numb] = temp[2-i];


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[3][i][numb];
    for(i = 0; i < 3; i++)
        m_cube[3][i][numb] = temp2[i];


    for(i = 0; i < 3; i++)
        m_cube[4][i][numb] = temp[2-i];



    /// поворот right/left если numb == 4/6
    numb += (3+1);
    if(numb == 4 || numb == 6) {
        small_part_color temp_right_left[3][3];

        if(numb == 4) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_right_left[i][j] = m_cube[0][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[0][i][j] = temp_right_left[j][2-i];
        }


        else if(numb == 6) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_right_left[i][j] = m_cube[2][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[2][i][j] = temp_right_left[2-j][i];
        }
    }
}



void RubiksCube::vertically_turn_456_to_down(int numb) {
    numb -= (3+1);
    int i;
    small_part_color temp[3], temp2[3];


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[4][i][numb];

    for(i = 0; i < 3; i++)
        m_cube[4][i][numb] = m_cube[1][i][numb];


    for(i = 0; i < 3; i++)
        temp2[i] = m_cube[3][i][numb];

    for(i = 0; i < 3; i++)
        m_cube[3][i][numb] = temp[2-i];


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[5][i][2-numb];

    for(i = 0; i < 3; i++)
        m_cube[5][i][2-numb] = temp2[i];


    for(i = 0; i < 3; i++)
        m_cube[1][i][numb] = temp[2-i];




    /// поворот right/left если numb == 4/6
    numb += (3+1);
    if(numb == 4 || numb == 6) {
        small_part_color temp_right_left[3][3];

        if(numb == 4) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_right_left[i][j] = m_cube[0][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[0][i][j] = temp_right_left[2-j][i];
        }


        else if(numb == 6) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_right_left[i][j] = m_cube[2][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[2][i][j] = temp_right_left[j][2-i];
        }
    }
}



void RubiksCube::lateral_turn_789_to_right(int numb) {
    numb -= (6+1);
    int i;
    small_part_color temp[3], temp2[3];

    for(i = 0; i < 3; i++)
        temp[i] = m_cube[1][2-numb][i];

    for(i = 0; i < 3; i++)
        m_cube[1][2-numb][i] = m_cube[0][2-i][2-numb];


    for(i = 0; i < 3; i++)
        temp2[i] = m_cube[2][2-i][numb];

    for(i = 0; i < 3; i++)
        m_cube[2][2-i][numb] = temp[2-i];


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[3][2-numb][i];

    for(i = 0; i < 3; i++)
        m_cube[3][2-numb][i] = temp2[i];


    for(i = 0; i < 3; i++)
        m_cube[0][2-i][2-numb] = temp[2-i];


    /// поворот front/back если numb == 7/9
    numb += (6+1);
    if(numb == 7 || numb == 9) {
        small_part_color temp_front_back[3][3];

        if(numb == 7) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_front_back[i][j] = m_cube[4][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[4][j][i] = temp_front_back[2-i][j];
        }


        else if(numb == 9) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_front_back[i][j] = m_cube[5][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[5][j][i] = temp_front_back[i][2-j];
        }
    }
}



void RubiksCube::lateral_turn_789_to_left(int numb) {
    numb -= (6+1);
    int i;
    small_part_color temp[3], temp2[3];


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[2][i][numb];


    for(i = 0; i < 3; i++)
        m_cube[2][2-i][numb] = m_cube[3][2-numb][i];


    for(i = 0; i < 3; i++)
        temp2[i] = m_cube[1][2-numb][i];

    for(i = 0; i < 3; i++) {
        m_cube[1][2-numb][i] = temp[i];
    }


    for(i = 0; i < 3; i++)
        temp[i] = m_cube[0][2-i][2-numb];

    for(i = 0; i < 3; i++)
        m_cube[0][2-i][2-numb] = temp2[i];


    for(i = 0; i < 3; i++)
        m_cube[3][2-numb][i] = temp[2-i];


    /// поворот front/back если numb == 7/9
    numb += (6+1);
    if(numb == 7 || numb == 9) {
        small_part_color temp_front_back[3][3];

        if(numb == 7) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_front_back[i][j] = m_cube[4][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[4][j][i] = temp_front_back[i][2-j];

        }


        else if(numb == 9) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    temp_front_back[i][j] = m_cube[5][i][j];

            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    m_cube[5][j][i] = temp_front_back[i][j];
        }
    }
}



void RubiksCube::save_condition_in_file() {
    string name = "rubiks_cube_condition_" + to_string(number_image_for_save);
    name += ".txt";
    number_image_for_save++;


    ofstream file(name);
    if(!file.is_open()) {
        cerr << "Unable to open file for writing\n";
        return;
    }


    for(int face = 0; face < 6; face ++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                small_part_color cur_color_coube = this->m_cube[face][i][j];
                string str_color = name_color_for_save(cur_color_coube);

                if(str_color == "error") {
                    cerr << "Error in save_condition_in_file() function: not to read the color" << endl;
                    exit(1);
                }
                file << str_color;
            }
            file << "\n";
        }
    }


    file.close();
    cout << "Condition saved in file\n";
}



void RubiksCube::read_condition_from_file(string &name_file_for_read) {
    ifstream file(name_file_for_read);

    if(!file.is_open()) {
        cerr << "Unable to open file for reading\n";
        return;
    }

    string line_input;


    for(int face = 0; face < 6; face++) {
        for(int i = 0; i < 3; i++) {
            getline(file, line_input);

            for(int j = 0; j < 3; j++) {
                this->m_cube[face][i][j] = get_index_color_from_file(line_input[j]);
            }
        }
    }


    file.close();
    cout << "Condition read from file\n";
}



bool RubiksCube::check_current_condition_correctness() {
    int red_k = 0, yell_k = 0, green_k = 0, white_k = 0, blue_k = 0, orange_k = 0;


    for(int face = 0; face < 6; face++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                check_color_for_correctness(m_cube[face][i][j], red_k, yell_k, green_k, white_k, blue_k, orange_k);
            }
        }
    }

    if(red_k == 9 && yell_k == 9 && green_k == 9 && white_k == 9 && blue_k == 9 && orange_k == 9)
        return true;
    else
        return false;
}



void check_color_for_correctness(small_part_color &color, int &red_k, int &yell_k, int &green_k, int &white_k, int &blue_k, int &orange_k) {
    if(name_color_for_save(color) == "R")
        red_k++;
    else if(name_color_for_save(color) == "Y")
        yell_k++;
    else if(name_color_for_save(color) == "G")
        green_k++;
    else if(name_color_for_save(color) == "W")
        white_k++;
    else if(name_color_for_save(color) == "B")
        blue_k++;
    else if(name_color_for_save(color) == "O")
        orange_k++;
    else {
        cerr << "Error in check_color_for_correctness() function: not to read the color\n";
        exit(1);
    }
}



string name_color_for_save(small_part_color &colorCoube) {
    ColorsAll pattern;
    if(colorCoube.color[0] == pattern.red_color[0] && colorCoube.color[1] == pattern.red_color[1] && colorCoube.color[2] == pattern.red_color[2])
        return "R";
    else if(colorCoube.color[0] == pattern.yellow_color[0] && colorCoube.color[1] == pattern.yellow_color[1] && colorCoube.color[2] == pattern.yellow_color[2])
        return "Y";
    else if(colorCoube.color[0] == pattern.green_color[0] && colorCoube.color[1] == pattern.green_color[1] && colorCoube.color[2] == pattern.green_color[2])
        return "G";
    else if(colorCoube.color[0] == pattern.white_color[0] && colorCoube.color[1] == pattern.white_color[1] && colorCoube.color[2] == pattern.white_color[2])
        return "W";
    else if(colorCoube.color[0] == pattern.blue_color[0] && colorCoube.color[1] == pattern.blue_color[1] && colorCoube.color[2] == pattern.blue_color[2])
        return "B";
    else if(colorCoube.color[0] == pattern.orange_color[0] && colorCoube.color[1] == pattern.orange_color[1] && colorCoube.color[2] == pattern.orange_color[2])
        return "O";
    else
        return "error";
}



small_part_color get_index_color_from_file(char color_char) {
    small_part_color colors{};

    if(color_char == 'R')
        colors = {1.0f, 0.0f, 0.0f};
    else if(color_char == 'Y')
        colors = {1.0f, 1.0f, 0.0f};
    else if(color_char == 'G')
        colors = {0.0f, 1.0f, 0.0f};
    else if(color_char == 'W')
        colors = {1.0f, 1.0f, 1.0f};
    else if(color_char == 'B')
        colors = {0.0f, 0.0f, 1.0f};
    else if(color_char == 'O')
        colors = {1.0f, 0.5f, 0.0f};
    else {
        cerr << "Not found color in available colors\n";
        exit(1);
    }

    return colors;
}