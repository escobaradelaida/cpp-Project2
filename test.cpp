#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

void count_frequencies(const string& file_name, int lowercase[], int uppercase[])
{
    //setting up arrays for both lower and upper letters
    int lowercase[26] = {0};
    int uppercase[26] = {0};

    ifstream file(file_name);
    if(!file.is_open())
    {
        cout << "Invalid file name. Please enter a valid file name.";
        return;
    }

    /*char ch;
    if (ch >= 'A' && ch <= 'Z')
        ++uppercase[ch - 'A'];
    else if (ch >= 'a' && ch <= 'z')
        ++lowercase[ch - 'a'];

    file.close();*/

    char ch;
    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            if (ch >= 'A' && ch <= 'Z')
                ++uppercase[ch - 'A'];
            else if (ch >= 'A' && ch <= 'z')
                ++lowercase[ch - 'a'];
        }
    }

    file.close();

    cout << "The letter frequencies:" << endl;
    for (int i = 0; i < 26; ++i)
    {
        char letter = 'A' + i;
        cout << letter << "(lowercase): " << lowercase[i] << endl;
        letter = 'a' + i;
        cout << letter << "(uppercase): " << uppercase[i] << endl;
    }
}

//sorting the frequencies by ascending...hopefully

void sort_frequencies(int lowercase[], int uppercase[])
{
    // Sort lowercase letters by frequency
    for (int i = 0; i < 25; ++i)
    {
        for (int j = i + 1; j < 26; ++j)
        {
            if (lowercase[j] > lowercase[i])
            {
                swap(lowercase[i], lowercase[j]);
                swap(uppercase[i], uppercase[j]);
            }
        }
    }

    // Sort uppercase letters by frequency
    for (int i = 0; i < 25; ++i)
    {
        for (int j = i + 1; j < 26; ++j)
        {
            if (uppercase[j] > uppercase[i])
            {
                swap(lowercase[i], lowercase[j]);
                swap(uppercase[i], uppercase[j]);
            }
        }
    }
}

int main()
{
    string file_name = "Project02-input.txt";
    cout << "Enter the name of the file: ";
    cin >> file_name;

    count_frequencies(file_name);
    sort_frequencies(lowercase, uppercase);

    cout << "Letters sorted by frequency: " << endl;
    for (int i = 0; i < 26; ++i)
    {
        if (lowercase[i] > 0)
            cout << static_cast<char>('a' + i) << ": " << lowercase[i] << endl;
    }
    for (int i = 0; i < 26; ++i)
    {
        if (uppercase[i] > 0)
            cout << static_cast<char>('A' + i) << ": " << uppercase[i] << endl;
    }

    return 0;
}
