#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void count_frequencies(const string& file_name)
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

int main()
{
    string file_name = "Project02-input.txt";
    cout << "Enter the name of the file: ";
    cin >> file_name;

    count_frequencies(file_name);

    return 0;
}
