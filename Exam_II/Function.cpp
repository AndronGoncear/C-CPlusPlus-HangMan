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
    if (ch == 'À') return 'à';
    else if (ch == 'Á') return 'á';
    else if (ch == 'Â') return 'â';
    else if (ch == 'Ã') return 'ã';
    else if (ch == 'Ä') return 'ä';
    else if (ch == 'Å') return 'å';
    else if (ch == '¨') return '¸';
    else if (ch == 'Æ') return 'æ';
    else if (ch == 'Ç') return 'ç';
    else if (ch == 'È') return 'è';
    else if (ch == 'É') return 'é';
    else if (ch == 'Ê') return 'ê';
    else if (ch == 'Ë') return 'ë';
    else if (ch == 'Ì') return 'ì';
    else if (ch == 'Í') return 'í';
    else if (ch == 'Î') return 'î';
    else if (ch == 'Ï') return 'ï';
    else if (ch == 'Ð') return 'ð';
    else if (ch == 'Ñ') return 'ñ';
    else if (ch == 'Ò') return 'ò';
    else if (ch == 'Ó') return 'ó';
    else if (ch == 'Ô') return 'ô';
    else if (ch == 'Õ') return 'õ';
    else if (ch == 'Ö') return 'ö';
    else if (ch == '×') return '÷';
    else if (ch == 'Ø') return 'ø';
    else if (ch == 'Ù') return 'ù';
    else if (ch == 'Ú') return 'ú';
    else if (ch == 'Û') return 'û';
    else if (ch == 'Ü') return 'ü';
    else if (ch == 'Ý') return 'ý';
    else if (ch == 'Þ') return 'þ';
    else if (ch == 'ß') return 'ÿ';
   
}

bool check_russian(char ch)
{    
    return (ch >= 'à' && ch <= 'ÿ');
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