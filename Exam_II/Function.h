#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<cctype>

using namespace std;

bool check_char(const string& word, char ch);

bool check_russian(char ch);

char my_tolower(char ch);


bool check_letter(vector<char> letters, char ch);

void show_letters(vector<char> letters);

void updatedisplayword(const string& word, string& displayWord, char ch);

string encryptdecrypt(const string& input, const string& key);


void SetColor(int ForgC);

void SetColor(int textColor, int backgroundColor);

