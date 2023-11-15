#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <conio.h>
#include<string>
#include"Function.h"
#include <chrono>
#include <fstream>
#include<cctype>
#include <clocale>
#include<Windows.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define DEFAULT "\033[0m"



using namespace std;

int main()
{
    setlocale(LC_CTYPE, " ");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	srand(time(NULL));
    string key = "Andron";
    vector<string> encrypwords, encrypwords2, decrypwords;

    ifstream fin("EncryptedWord.txt", ios::binary);
    if (fin)
    {
        size_t s2;
        fin.read(reinterpret_cast<char*>(&s2), sizeof(s2));
        encrypwords2.resize(s2);
        for (int i = 0; i < s2; i++)
        {
            fin >> encrypwords2[i];
        }
        fin.close();
       
    }
    else
    {
        cout << "\nEror read from the file" << endl;
    }

    for (const string& encrypword2 : encrypwords2)
    {
        string decrypword = encryptdecrypt(encrypword2, key);
        decrypwords.push_back(decrypword);
    }


    vector<char> letters;
    string word = decrypwords[rand() % decrypwords.size()];
    string displayword(word.length(), '_');
    int incorrectattempts = 0;
    int attempt = 0;
    const int maxincorrectattempts = 7;
 
    cout <<RED<< "\t\t\t\tWelcome to PLAY HANGMAN!" <<DEFAULT<< endl<<endl<<endl;
  
    auto start = chrono::high_resolution_clock::now();
    while (incorrectattempts < maxincorrectattempts && displayword != word)
    {
        cout << "\t\t\t\tIncorrect guesses left: " << maxincorrectattempts - incorrectattempts << endl;
        cout << "\t\t\t\tCurrent word: " << displayword << endl<<endl;
        cout << "\t\t\t\tCurrent word lenght: " << word.length() << endl << endl;
        char ch, ch1;
        exit1:
        cout << "\t\t\t\tGuess a letter in the word. Words are in RUSSIAN: ";
        cin >> ch1;
        ch = my_tolower(ch1);
        if (check_letter(letters, ch))
        {
            cout << "\t\t\t\tYou have already entered this letter. Enter another one " << endl;
            goto exit1;
        }
        if (!check_russian(ch))
        {
            cout << "\t\t\t\tLetter must be from Russian alphabet " << endl;
            goto exit1;
        }
        letters.push_back(ch);
        attempt += 1;

        if (check_char(word, ch))
        {
            updatedisplayword(word, displayword, ch);
            cout << "\t\t\t\tCorrect attempt!" << endl;
            cout << "\t\t\t\tLettes introduced               " << endl;
            cout << "\t\t\t\t";
            show_letters(letters);
            cout << endl;
        }
        else 
        {
            cout << "\t\t\t\tIncorrect attemmpt!" << endl;
            cout << "\t\t\t\tLettes introduced               " << endl;
            cout << "\t\t\t\t";
            show_letters(letters);
            cout << endl;
            ++incorrectattempts;
            if (incorrectattempts == 1)
            {
                cout << GREEN << "\t\t\t\t\t   +---+" << endl;
                cout <<          "\t\t\t\t\t   |   |" << endl;
                cout <<          "\t\t\t\t\t       |" << endl;
                cout <<          "\t\t\t\t\t       |" << endl;
                cout <<          "\t\t\t\t\t       |" << endl;
                cout <<          "\t\t\t\t\t       |" << DEFAULT<<endl;
            }

            else if (incorrectattempts == 2)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t       |" << endl;
                cout <<         "\t\t\t\t\t       |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
            else if (incorrectattempts == 3)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t       |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
            else if (incorrectattempts == 4)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t  /|   |" << endl;
                cout <<         "\t\t\t\t\t       |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
            else if (incorrectattempts == 5)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t  /|\\  |" << endl;
                cout <<         "\t\t\t\t\t       |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
            else if (incorrectattempts == 6)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t  /|\\  |" << endl;
                cout <<         "\t\t\t\t\t  /    |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
            else if (incorrectattempts == 7)
            {
                cout << GREEN<< "\t\t\t\t\t   +---+" << endl;
                cout <<         "\t\t\t\t\t   |   |" << endl;
                cout <<         "\t\t\t\t\t   O   |" << endl;
                cout <<         "\t\t\t\t\t  /|\\  |" << endl;
                cout <<         "\t\t\t\t\t  / \\  |" << endl;
                cout <<         "\t\t\t\t\t       |" <<DEFAULT<< endl;
            }
        }

        cout << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start);
    if (displayword == word)
    {
        cout <<RED<< "\t\t\t\tCongratulations!!!              YOU WIN!!!!!!" << DEFAULT<<endl;
        cout <<RED<< "\t\t\t\tSpent time:                     " <<duration.count()<<" seconds!"<< DEFAULT<< endl;
        cout <<RED<< "\t\t\t\tCount of attempts:              " << attempt << DEFAULT<< endl;
        cout <<RED<< "\t\t\t\tSearch word :                   " << word << DEFAULT << endl;
        cout <<RED<< "\t\t\t\tLettes introduced               " << endl;
        cout << "\t\t\t\t";
        show_letters(letters);
        cout << DEFAULT<<endl;
    }
    else
    {
        cout << GREEN << "\t\t\t\tYOU LOST!!!!    The word was:   " << word << DEFAULT<< endl;
        cout << GREEN << "\t\t\t\tSpent time:                     " << duration.count() << " seconds!" << DEFAULT<< endl;
        cout << GREEN <<"\t\t\t\tCount of attempts:               " << incorrectattempts << DEFAULT<< endl;
        cout << GREEN << "\t\t\t\tLettes introduced               " << endl;
        cout << "\t\t\t\t";
        show_letters(letters);
        cout <<DEFAULT<< endl;
    }

	_getch();
	return 0;

}