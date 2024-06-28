#include "functions.h"

size_t fun(char *p, size_t s, size_t n, std::string *d) {
    d->append(p, s*n);
    return s*n;
}

string curl_work(string &url) {
    CURL *curl; // переменная curl типа указат на CURL

    CURLcode c; // переменная, CURL CODE - псевданим int, с - код правильности взаимодействия экзампляра библиотеки с внешним миром
    string s; // ответ от сервера

    curl_global_init(CURL_GLOBAL_ALL); // функция в curl/h - инициализация библиотеки - режим работы с библ
    curl = curl_easy_init(); // гененирует объект типа курл и возвращает ссылку на него - работа с http


    if(curl) { // ссылка не null - то есть все хорошо
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); // устанавл параметры объекта - параметр адреса CURLOPT_URL должен быть "example.com" - загоняем адрес сайт

        // получаем ответ от сайта в виде html странички большой
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fun); // в переменную  curl занеси ссылку на функцию, кот будет записывать в s (fun - 7 стр)

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s); // метод из этого ответа будет записывать в s
        c = curl_easy_perform(curl); // с = 0/1


        if(c != CURLE_OK) { // CURL_OK псевдоним 1
            // если что-то пошло не так
            cerr << "Ошибка получения ответа от сайта\n";
            curl_easy_cleanup(curl);
            return "";
        }
        curl_easy_cleanup(curl);
        return s;
    }
    else {
        cerr << "Ошибка получения ответа от сайта\n";
        curl_easy_cleanup(curl);
        return "";
    }
}



void print_one_date_money_to_RUB(string &money_name, string &date, int &nominal) {
    string url = "http://cbr.ru/scripts/XML_daily.asp?date_req=" + date;
    string s_answer_website = curl_work(url);

    string result_web = find_website_moneyName_and_course(s_answer_website, money_name, nominal);
    if(result_web.empty()) {
        cerr << "На данную дату нет курса данной валюты на сайте ЦБ. Измените дату!\n";
        exit(1);
    }
    cout << result_web << "\n";
}



void save_in_file_one_date_money_to_RUB(string &money_name, string &date, int &nominal, string &fileName) {
    string url = "http://cbr.ru/scripts/XML_daily.asp?date_req=" + date;
    string s_answer_website = curl_work(url);
    string result_web = find_website_moneyName_and_course(s_answer_website, money_name, nominal);
    if(result_web.empty()) {
        cerr << "На данную дату нет курса валюты " << money_name << " на сайте ЦБ. Измените дату! Информация не будет сохранена файл\n";
        exit(1);
    }

    ofstream FIlE(fileName);

    if(FIlE.is_open()) {
        FIlE << result_web;
        FIlE.close();
        cout << "Результат сохранен в файл " << fileName << "\n";
    }
    else {
        cerr << "Ошибка создания файла\n";
    }
}



string find_website_moneyName_and_course(string &answer_website, string &money_name, int &nominal) {
    int i;

    /// поиск даты с сайта
    string str_date_website;
    for(i = 50; i < answer_website.size()-3; i++) {
        if(answer_website[i] == 'D' && answer_website[i+1] == 'a' && answer_website[i+2] == 't') {
            i += 6;
            while(answer_website[i] != '"') {
                str_date_website += answer_website[i];
                i++;
            }
            break;
        }
    }


    /// поиск текущей валюты
    bool flag_find = 0;
    for(i; i < answer_website.size()-2; i++) {
        if (answer_website[i] == money_name[0] && answer_website[i + 1] == money_name[1] && answer_website[i + 2] == money_name[2]) {
            flag_find = 1;
            break;
        }
    }

    if(flag_find == 0) {
        cerr << "Не найдена текущая валюта на сайте ЦБ. Проверьте корректность указанной валюты!\n";
        exit(1);
    }


    /// поиск номинала с сайта
    string str_nominal_website;
    int nominal_website;
    int flag_count_galka = 0;

    for(i; i < answer_website.size(); i++) {
        if(answer_website[i] == '>') {
            flag_count_galka++;
        }

        if(flag_count_galka == 2) {
            i++;
            while(answer_website[i] != '<') {
                str_nominal_website += answer_website[i];
                i++;
            }
            nominal_website = stoi(str_nominal_website);
            break;
        }
    }


    /// поиск значения (цены) валюты с сайта
    flag_count_galka = 0;
    string str_value_website;
    float value_website;

    for(i; i < answer_website.size(); i++) {
        if(answer_website[i] == '>') {
            flag_count_galka++;
        }

        if(flag_count_galka == 4) {
            i++;
            while(answer_website[i] != '<') {
                str_value_website += answer_website[i];
                i++;
            }
            replace(str_value_website.begin(), str_value_website.end(), ',', '.');
            value_website = stof(str_value_website);
            break;
        }
    }

    string result_web;
    result_web += money_name;
    result_web += " ";
    result_web += to_string(nominal);
    result_web += " ";
    result_web += str_date_website;
    result_web += " ";
    result_web += to_string(value_website/(float)nominal_website*(float)nominal);
    return result_web;
}



void print_period_date_money_to_RUB(string &money_name, string &date_date, int &nominal, vector<Node_money_charCode_and_id> &arrayID) {
    string date_start, date_end;
    convert_DateDate_to_rest(date_date, date_start, date_end);

    string id_money;
    for(int i = 0; i < arrayID.size(); i++) {
        if(arrayID[i].charCode == money_name) {
            id_money = arrayID[i].id;
            break;
        }
    }

    if(id_money.empty()) {
        cerr << "Не найдена указанная валюта на сайте ЦБ. Проверьте корректность названия валюты!\n";
        return;
    }


    string url = "http://cbr.ru/scripts/XML_dynamic.asp?date_req1=" + date_start + "&date_req2=" + date_end + "&VAL_NM_RQ=" + id_money;
    string s_answer_website = curl_work(url);

    vector<string> result_web = parsing_date_money_value(money_name, s_answer_website, nominal);
    if(result_web.size() == 0) {
        cerr << "На данный период дат нет курса данной валюты на сайте ЦБ. Измените дату!\n";
        return;
    }


    for(int i = 0; i < result_web.size(); i++) {
        cout << result_web[i] << "\n";
    }
}



void save_in_file_period_date_money_to_RUB(string &money_name, string &date_date, int &nominal, vector<Node_money_charCode_and_id> &arrayID, string &fileName) {
    string date_start, date_end;
    convert_DateDate_to_rest(date_date, date_start, date_end);

    string id_money;
    for(int i = 0; i < arrayID.size(); i++) {
        if(arrayID[i].charCode == money_name) {
            id_money = arrayID[i].id;
            break;
        }
    }

    string url = "http://cbr.ru/scripts/XML_dynamic.asp?date_req1=" + date_start + "&date_req2=" + date_end + "&VAL_NM_RQ=" + id_money;
    string s_answer_website = curl_work(url);
    vector<string> result_web_array = parsing_date_money_value(money_name, s_answer_website, nominal);
    if(result_web_array.empty()) {
        cerr << "На данный период дат нет курса данной валюты на сайте ЦБ. Измените дату! Информация не будет сохранена файл\n";
        exit(1);
    }



    ofstream FIlE(fileName);

    if(FIlE.is_open()) {
        for(int i = 0; i < result_web_array.size(); i++) {
            FIlE << result_web_array[i] << "\n";
        }

        FIlE.close();
        cout << "Результат сохранен в файл " << fileName << "\n";
    }
    else {
        cerr << "Ошибка создания файла\n";
    }
}


vector<string> parsing_date_money_value(string &money_name, string &answer_website, int &nominal) {
    int i;
    string str_date_website, str_value_website, str_nominal_website;
    float value_website = 0;
    int nominal_website = 1;
    bool flag_value = 0, flag_nominal = 0;

    vector<string> result_web;

    for(i = 160; i < answer_website.size()-3; i++) {
        if(answer_website[i] == 'N' && answer_website[i+1] == 'o' && answer_website[i+2] == 'm' && flag_nominal == 0) {
            i += 8;
            while(answer_website[i] != '<') {
                str_nominal_website += answer_website[i];
                i++;
            }
            nominal_website = stoi(str_nominal_website);
            flag_nominal = 1;
        }


        else if(answer_website[i] == 'D' && answer_website[i+1] == 'a') {
            i += 6;
            while(answer_website[i] != '"') {
                str_date_website += answer_website[i];
                i++;
            }
        }

        else if(answer_website[i] == 'V' && answer_website[i+1] == 'a' && answer_website[i+2] == 'l' && answer_website[i+3] == 'u' && flag_value == 0) {
            i += 6;
            while(answer_website[i] != '<') {
                str_value_website += answer_website[i];
                i++;
            }
            replace(str_value_website.begin(), str_value_website.end(), ',', '.');
            value_website = stof(str_value_website);
            flag_value = 1;
        }

        else if(answer_website[i] == 'V' && answer_website[i+1] == 'a' && answer_website[i+2] == 'l' && answer_website[i+3] == 'u' && flag_value == 1) {
            flag_value = 0;
        }


        if(!str_date_website.empty() && !str_value_website.empty()){
            string web;
            web += money_name;
            web += " ";
            web += to_string(nominal);
            web += " ";
            web += str_date_website;
            web += " ";
            web += to_string(value_website/(float)nominal_website*(float)nominal);

            result_web.push_back(web);

            str_date_website = "";
            str_value_website = "";
        }
    }
    return result_web;
}



string current_date() {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    stringstream ss;
    ss << setfill('0') << setw(2) << localTime->tm_mday << "." << setw(2) << (localTime->tm_mon + 1) << "." << (localTime->tm_year + 1900);
    string date = ss.str();
    return date;
}


string convert_date_to_dateREST(string &date) {
    string new_date;

    for(int i = 0; i < date.size(); i++) {
        if(date[i] != '.') {
            new_date += date[i];
        }
        else {
            new_date += '/';
        }
    }
    return new_date;
}



void convert_DateDate_to_rest(string &date_date, string &date_start, string &date_end) {
    bool flag_dash = 0;

    for(int i = 0; i < date_date.size(); i++) {
        if(date_date[i] == '-')
            flag_dash = 1;
        else if(flag_dash == 0)
            date_start += date_date[i];
        else if(flag_dash == 1)
            date_end += date_date[i];
    }
    date_start = convert_date_to_dateREST(date_start);
    date_end = convert_date_to_dateREST(date_end);
}




void fill_array_charCode_and_id(vector<Node_money_charCode_and_id> &arrayID) {
    string url = "http://cbr.ru/scripts/XML_daily.asp?date_req=10/01/2022";
    string answer_website = curl_work(url);

    Node_money_charCode_and_id buf;
    bool flag_char_code = 0;

    for(int i = 0; i < answer_website.size()-1; i++) {
        if(answer_website[i] == 'I' && answer_website[i+1] == 'D') {
            i += 4;
            while(answer_website[i] != '"') {
                buf.id += answer_website[i];
                i++;
            }
        }


        else if(answer_website[i] == 'C' && answer_website[i+1] == 'h' && answer_website[i+2] == 'a' && flag_char_code == 0) {
            i += 9;

            while(answer_website[i] != '<') {
                buf.charCode += answer_website[i];
                i++;
            }
            flag_char_code = 1;
        }


        else if(answer_website[i] == 'C' && answer_website[i+1] == 'h' && answer_website[i+2] == 'a' && flag_char_code == 1) {
            flag_char_code = 0;
            continue;
        }


        if(!buf.id.empty() && !buf.charCode.empty()) {
            arrayID.push_back(buf);
            buf.id = "";
            buf.charCode = "";
        }
    }
}