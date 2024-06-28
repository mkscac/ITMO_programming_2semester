#include "main_functions.h"


void open_one_window(RubiksCube &currentCube) {
    static GLFWwindow* currentWindow = nullptr;
    if(currentWindow) {
        glfwDestroyWindow(currentWindow);
        currentWindow = nullptr;
    }


    glfwInit();
    if(!glfwInit()) {
        cerr << "Error init GLFW\n";
        return;
    }

    GLFWwindow *window = glfwCreateWindow(700, 700, "OpenGL Rubik's cube", NULL, currentWindow);
    if(!window) {
        cerr << "Error create window\n";
        glfwTerminate();
        return;
    }

    currentWindow = window;
    glfwSetWindowPos(window, 0, 0);

    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT);

    currentCube.draw_all_cube();

    glfwSwapBuffers(window);
    glfwPollEvents();
}



void open_multiple_windows(RubiksCube &currentCube, int &number_window) {
    string name_window = "OpenGL Rubik's cube " + to_string(number_window);
    number_window++;

    glfwInit();
    if(!glfwInit()) {
        cerr << "Error init GLFW\n";
        return;
    }


    GLFWwindow *window = glfwCreateWindow(700, 700, name_window.c_str(), NULL, NULL);
    if(!window) {
        cerr << "Error create window\n";
        glfwTerminate();
        return;
    }

    glfwSetWindowPos(window, 0, 0);

    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT);

    currentCube.draw_all_cube();

    glfwSwapBuffers(window);
    glfwPollEvents();
}




void random_installation_cube(RubiksCube &currentCube, int &count, int &mode_draw, int &number_window) {
    int random_numb;

    for(int i = 0; i < count; i++) {
        random_numb = rand() % 18;

        if(random_numb == 0)
            currentCube.horizontally_turn_123_to_right(1);
        else if(random_numb == 1)
            currentCube.horizontally_turn_123_to_right(2);
        else if(random_numb == 2)
            currentCube.horizontally_turn_123_to_right(3);

        else if(random_numb == 3)
            currentCube.horizontally_turn_123_to_left(1);
        else if(random_numb == 4)
            currentCube.horizontally_turn_123_to_left(2);
        else if(random_numb == 5)
            currentCube.horizontally_turn_123_to_left(3);

        else if(random_numb == 6)
            currentCube.vertically_turn_456_to_up(4);
        else if(random_numb == 7)
            currentCube.vertically_turn_456_to_up(5);
        else if(random_numb == 8)
            currentCube.vertically_turn_456_to_up(6);

        else if(random_numb == 9)
            currentCube.vertically_turn_456_to_down(4);
        else if(random_numb == 10)
            currentCube.vertically_turn_456_to_down(5);
        else if(random_numb == 11)
            currentCube.vertically_turn_456_to_down(6);

        else if(random_numb == 12)
            currentCube.lateral_turn_789_to_left(7);
        else if(random_numb == 13)
            currentCube.lateral_turn_789_to_left(8);
        else if(random_numb == 14)
            currentCube.lateral_turn_789_to_left(9);

        else if(random_numb == 15)
            currentCube.lateral_turn_789_to_right(7);
        else if(random_numb == 16)
            currentCube.lateral_turn_789_to_right(8);
        else if(random_numb == 17)
            currentCube.lateral_turn_789_to_right(9);


        if(mode_draw == 1)
            open_one_window(currentCube);
        else if(mode_draw == 2)
            open_multiple_windows(currentCube, number_window);
    }

    cout << "Random installation is over";
}



int install_draw_cube() {
    int mode;
    cout << "Select a mode images OpenGL\n";
    cout << "1 - draw in one window\n";
    cout << "2 - draw in multiple windows\n";
    cout << ">>> ";
    cin >> mode;

    while(mode != 1 && mode!= 2) {
        cerr << "Wrong mode (mode = 1 or 2)\n";
        cout << "Select a mode images OpenGL\n";
        cout << "1 - draw in one window\n";
        cout << "2 - draw in multiple windows\n";
        cout << ">>> ";
        cin >> mode;
    }
    return mode;
}