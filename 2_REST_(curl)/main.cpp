#include <cstring>
#include "functions.h"



int main(int argc, char *argv[]) {
    if(argc < 2) {
        cerr << "Недопустимое количество аргументов\n";
        return 1;
    }


    string money_name, v_nome, date_date, fileName;
    string date = current_date();
    int nominal = 1;


    for(int i = 1; i < argc; i++) {
        string input = argv[i];

        if(input.find("--Vname=") != string::npos) {
            int ind = 0;
            while(input[ind] != '=' && ind < input.size()) {
                ind++;
            }

            if(ind < input.size()-1)
                money_name = input.substr(ind+1);
            else {
                cerr << "Не введен параметр Vname";
                return 1;
            }
        }

        else if(input.find("--Vnom=") != string::npos) {
            int ind = 0;
            while(input[ind] != '=' && ind < input.size()) {
                ind++;
            }

            if(ind < input.size()-1) {
                v_nome = input.substr(ind+1);
                nominal = stoi(v_nome);
            }
            else {
                cerr << "Не введен параметр Vnome";
                return 1;
            }
        }

        else if(input.find("--Date=") != string::npos) {
            int ind = 0;
            while(input[ind] != '=' && ind < input.size()) {
                ind++;
            }

            if(ind < input.size()-1)
                date = input.substr(ind+1);
            else {
                cerr << "Не введен параметр Date";
                return 1;
            }
        }

        else if(input.find("--DateDate=") != string::npos) {
            int ind = 0;
            while(input[ind] != '=' && ind < input.size()) {
                ind++;
            }

            if(ind < input.size()-1)
                date_date = input.substr(ind+1);
            else {
                cerr << "Не введен параметр DateDate";
                return 1;
            }
        }

        else if(input.find("--FileName=") != string::npos) {
            int ind = 0;
            while(input[ind] != '=' && ind < input.size()) {
                ind++;
            }

            if(ind < input.size()-1)
                fileName = input.substr(ind+1);
            else {
                cerr << "Не введен параметр FileName";
                return 1;
            }
        }

        else {
            cerr << "Неккоректно введено название аргумента\n";
            return 1;
        }
    }


    if(date.length() != 10 && !date.empty()) {
        cerr << "Неправильно введен параметр Date. Размер даты превыщает/недостает допустимый";
        return 1;
    }
    if(date_date.length() != 21 && !date_date.empty()) {
        cerr << "Неправильно введен параметр DateDate. Размер даты превыщает/недостает допуcтимый";
        return 1;
    }
    if(fileName.find('.') == std::string::npos && !fileName.empty()) {
        cerr << "Некорректно указано расширение файла, куда сохранить информацию";
        return 1;
    }





    date = convert_date_to_dateREST(date);


    if(date_date.empty() && fileName.empty() && !money_name.empty()) { /// вывод в консоль на 1 дату
        print_one_date_money_to_RUB(money_name, date, nominal);
    }
    else if(!date_date.empty() && fileName.empty() && !money_name.empty()) { /// вывод в консоль периода
        vector<Node_money_charCode_and_id> arrayID;
        fill_array_charCode_and_id(arrayID);
        print_period_date_money_to_RUB(money_name, date_date, nominal, arrayID);
    }
    else if(date_date.empty() && !fileName.empty() && !money_name.empty()) { /// сохранение инфы в файл - 1 дата
        save_in_file_one_date_money_to_RUB(money_name, date, nominal, fileName);
    }
    else if(!date_date.empty() && !fileName.empty() && !money_name.empty()) { /// сохранение инфы в файл - период
        vector<Node_money_charCode_and_id> arrayID;
        fill_array_charCode_and_id(arrayID);
        save_in_file_period_date_money_to_RUB(money_name, date_date, nominal, arrayID, fileName);
    }
    else {
        cerr << "Не указано наименование валюты, которую необходимо найти (параметр --Vname)\n";
    }
    return 0;
}