#include <iostream>
#include <fstream>
#include <cctype> // helps in determining whether a character is a number or letter, and whether it is upper or lower case
using namespace std;

//making a function for counting letters frequencies
void letter_freq(const string& file_name)
{
    unsigned int frequencies[26] = {0}; // Initializing an array to store the letter frequencies

    ifstream file(file_name);
    if (!file.is_open())
    {
        cout << "This file does not exist. Please provide a valid file name.";
        return;
    }

    char ch;
    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            ch = tolower(ch); // will turn the letters to lowercase
            int index = ch - 'a';
            frequencies[index]++;
        }
    }

    file.close();
    cout << "Frequencies for lowercase letters: ";

    //Display the frequencies
    for (int i = 0; i < 26; i++)
    {
        char letter = 'a' + i; //convert index back to letter
        cout << letter << ": " << frequencies[i] << endl;
    }
}

// a function for finding frequencies of uppercase letters

void upper_freq(const string& file_name)
{
    unsigned int upper_frequencies[26] = {0};

    ifstream file(file_name);

    if (!file.is_open())
    {
        cout <<"Unable to open the file. Please enter a valid file name.";
        return;
    }

    char ch;
    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            ch = toupper(ch); //convert letter to uppercase
            int index = ch - 'A';
            upper_frequencies[index]++;
        }
    }

    file.close();

    cout << "Letter Frequencies for uppercase letters: " << endl;
    for (int i = 0; i < 26; i++)
    {
        char letter = 'A' + i;
        cout << letter << ": " << upper_frequencies[i] << endl;
    }
}

int main()
{
    string file_name = "Project02-input.txt";
    cout << "Enter the file name: ";
    cin >> file_name;

    letter_freq(file_name);
    upper_freq(file_name);

    return 0;
}