#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Function.h"
#include<Windows.h>
#include<cctype>

using namespace std;


bool check_char(const string& word, char ch)
{
    for (char c : word)
    {
        if (c == ch)
        {
            return true;
        }
    }
    return false;
}
char my_tolower(char ch)
{
    if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
    else if (ch == '�') return '�';
   
}

bool check_russian(char ch)
{    
    return (ch >= '�' && ch <= '�');
}
bool check_letter(vector<char> letters, char ch)
{
    for (int i = 0; i < letters.size(); i++)
    {
        if (letters[i] == ch)
        {
              return true;
        }
    }
    return false;
}
void show_letters(vector<char> letters)
{
    for (int i = 0; i < letters.size(); i++)
    {
        cout << letters[i] << "_";
    }
}


void updatedisplayword(const string& word, string& displayWord, char ch)
{
    for (int i = 0; i < word.length(); ++i)
    {
        if (word[i] == ch)
        {
            displayWord[i] = ch;
        }
    }
}

string encryptdecrypt(const string& input, const string& key)
{
    string output = input;
    for (int i = 0; i < input.size(); ++i)
    {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;

}


void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void SetColor(int textColor, int backgroundColor)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (WORD)((backgroundColor << 4) | textColor));
}