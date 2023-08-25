#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int countWordsInFile(const string &filename)
{
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cout << "Error opening file: " << filename << endl;
        return -1; // Return a negative value to indicate an error
    }

    string line;
    int wordCount = 0;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string word;

        while (ss >> word)
        {
            wordCount++;
        }
    }

    inputFile.close();

    return wordCount;
}

int main()
{
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    int totalWords = countWordsInFile(filename);

    if (totalWords >= 0)
    {
        cout << "Total word count in " << filename << ": " << totalWords << endl;
    }

    return 0;
}
