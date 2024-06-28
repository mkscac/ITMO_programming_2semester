#ifndef PRG_9LABA_REST__CURL__FUNCTIONS_H
#define PRG_9LABA_REST__CURL__FUNCTIONS_H

#include <iostream>
#include <string>
#include "cmake-build-debug/_deps/curl-src/include/curl/curl.h"
#include <ctime> // для текущей даты
#include <sstream> // для текущей даты
#include <iomanip> // для утсановки формата даты
#include <algorithm> // для replace
#include <vector>
#include <fstream> // для создания файла
using namespace std;


struct Node_money_charCode_and_id {
    string id;
    string charCode;
};


size_t fun(char *p, size_t s, size_t n, std::string *d);
string curl_work(string &url);


// получение курса валюты к российскому рублю на выбранную дату
void print_one_date_money_to_RUB(string &money_name, string &date, int &nominal);

void save_in_file_one_date_money_to_RUB(string &money_name, string &date, int &nominal, string &fileName);

string find_website_moneyName_and_course(string &answer_website, string &name_currency, int &nominal);



// получение курса валюты к российскому рублю на выбранный период
void print_period_date_money_to_RUB(string &money_name, string &date_date, int &nominal, vector<Node_money_charCode_and_id> &arrayID);

void save_in_file_period_date_money_to_RUB(string &money_name, string &date_date, int &nominal, vector<Node_money_charCode_and_id> &arrayID, string &fileName);

vector<string> parsing_date_money_value(string &money_name, string &answer_website, int &nominal);



string current_date();

string convert_date_to_dateREST(string &date);

void convert_DateDate_to_rest(string &date_date, string &date_start, string &date_end);

void fill_array_charCode_and_id(vector<Node_money_charCode_and_id> &arrayID);

#endif
