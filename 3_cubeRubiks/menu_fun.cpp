#include "menu.h"

int Menu::print_all_menu() {
    cout << "\nSelect the command:\n";
    cout << "0 - finish installation the cube\n";

    cout << "1 - turn horizontally top face (numb 1) the cube to the right\n";
    cout << "2 - turn horizontally middle face (numb 2) the cube to the right\n";
    cout << "3 - turn horizontally low face (numb 3) the cube to the right\n";
    cout << "4 - turn horizontally top face (numb 1) the cube to the left\n";
    cout << "5 - turn horizontally middle face (numb 2) the cube to the left\n";
    cout << "6 - turn horizontally low face (numb 3) the cube to the left\n";

    cout << "7 - turn vertically left face (numb 4) of the cube upward\n";
    cout << "8 - turn vertically middle face (numb 5) of the cube upward\n";
    cout << "9 - turn vertically right face (numb 6) of the cube upward\n";
    cout << "10 - turn vertically left face (numb 4) of the cube down\n";
    cout << "11 - turn vertically middle face (numb 5) of the cube down\n";
    cout << "12 - turn vertically right face (numb 6) of the cube down\n";


    cout << "13 - turn lateral (numb 7) the cube to the left\n";
    cout << "14 - turn lateral (numb 8) the cube to the left\n";
    cout << "15 - turn lateral (numb 9) the cube to the left\n";
    cout << "16 - turn lateral (numb 7) the cube to the right\n";
    cout << "17 - turn lateral (numb 8) the cube to the right\n";
    cout << "18 - turn lateral (numb 9) the cube to the right\n";



    cout << "19 - print condition in window\n";
    cout << "20 - save current condition in file\n";
    cout << "21 - read condition from file\n";
    cout << "22 - install random condition of cube\n";
    cout << "23 - install collected condition of cube\n";

    cout << "24 - check current condition\n";
    cout << "25 - random installation cube\n";
    cout << "26 - install mode draw cube\n";


    int command;
    cout << "The selected command >>> ";
    cin >> command;
    return command;
}




void Menu::ALL_WORK_MENU(RubiksCube &currentCube) {
    int command, count_for_25_case, mode_draw;
    int number_window_for_multiplate_draw = 1;
    string name_file_for_21_case_read;



    command = this->print_all_menu();
    while(command != 26) {
        cerr << "Select a mode images OpenGL (command = 26)\n" << endl;
        command = this->print_all_menu();
    }
    mode_draw = install_draw_cube();



    command = this->print_all_menu();
    while(command != 21 && command != 22 && command != 23) {
        cerr << "Initial position of the cube is not selected (command = 21 or 22 or 23)\n" << endl;
        command = this->print_all_menu();
    }


    do {
        switch(command) {
            case 1:
                currentCube.horizontally_turn_123_to_right(1);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 2:
                currentCube.horizontally_turn_123_to_right(2);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 3:
                currentCube.horizontally_turn_123_to_right(3);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;

            case 4:
                currentCube.horizontally_turn_123_to_left(1);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 5:
                currentCube.horizontally_turn_123_to_left(2);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 6:
                currentCube.horizontally_turn_123_to_left(3);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;


            case 7:
                currentCube.vertically_turn_456_to_up(4);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 8:
                currentCube.vertically_turn_456_to_up(5);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 9:
                currentCube.vertically_turn_456_to_up(6);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;

            case 10:
                currentCube.vertically_turn_456_to_down(4);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 11:
                currentCube.vertically_turn_456_to_down(5);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 12:
                currentCube.vertically_turn_456_to_down(6);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;


            case 13:
                currentCube.lateral_turn_789_to_left(7);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 14:
                currentCube.lateral_turn_789_to_left(8);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 15:
                currentCube.lateral_turn_789_to_left(9);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 16:
                currentCube.lateral_turn_789_to_right(7);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 17:
                currentCube.lateral_turn_789_to_right(8);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 18:
                currentCube.lateral_turn_789_to_right(9);
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;


            case 19:
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 20:
                currentCube.save_condition_in_file();
                break;
            case 21:
                cout << "Enter name input file for reading >>> ";
                cin >> name_file_for_21_case_read;


                currentCube.read_condition_from_file(name_file_for_21_case_read);
                if(currentCube.check_current_condition_correctness() == 0) {
                    cerr << "Condition is not correct (some color is more/less than 9 quantity) ==> break\n";
                    exit(1);
                }

                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 22:
                currentCube.install_random_condition_of_cube();
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;
            case 23:
                currentCube.install_collected_condition_of_cube();
                if(mode_draw == 1)
                    open_one_window(currentCube);
                else if(mode_draw == 2)
                    open_multiple_windows(currentCube, number_window_for_multiplate_draw);
                break;

            case 24:
                if(currentCube.check_current_condition_correctness() == 1)
                    cout << "Condition is correct, all colors 9 pieces\n";
                else {
                    cerr << "Condition is not correct (some color is more/less than 9 quantity) ==> break\n";
                    exit(1);
                }
                break;
            case 25:
                cout << "Enter the number of face rotations >>> ";
                cin >> count_for_25_case;
                random_installation_cube(currentCube, count_for_25_case, mode_draw, number_window_for_multiplate_draw);
                cout << '\n';
                break;

            default:
                cerr << "No such command\n";
                break;
        }

        command = this->print_all_menu();
        if(command == 0)
            cout << "Finish installation the cube\n";


    } while(command != 0);
}