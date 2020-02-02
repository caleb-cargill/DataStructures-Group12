#include "HW01.h"
using namespace std;

void fileOpenTask(ifstream& FileObj);

void fileRWTask(ifstream& inp, fstream& out);

// Sets up I/O streams
// Creates a feedback loop for asking whether or not the user wants the letter frequency
// Once a valid input is entered, it will do the specified task
// Gives the option to open new files until the user enters 'n' in which case the program will end
int main()
{
    ifstream inputFileObj;
    fstream outputFileObj;
    char prompt = 'y';

    while (prompt == 'y') {
        fileOpenTask(inputFileObj);
        fileRWTask(inputFileObj, outputFileObj);
        prompt = 'n';
        while (prompt != 'y') {
            cout << "Would you like to process another book? (y/n)" << endl;
            cin >> prompt;
            if (prompt == 'y') {
                break;
            }
            else if (prompt == 'n') {
                break;
            }
            else {
                cout << "Please enter a valid option." << endl;
            }
        }

        if (prompt == 'n') {
            break;
        }
    }
}

// Gets the letter frequency of each letter
// Loops through all letter in letfreq[] and outputs them in approproate format
// Also return the total letter count
int CardCatalog::getLetFreq(fstream& out) {
    char let = 'a';
    for (int i = 0; i < 26; ++i) {
        let = 'a' + i;
        cout << let << ": " << letfreq[i] << " times" <<
            " (" << (static_cast<float>(letfreq[i]) / totLet) * 100 << "%)" << endl;
        out << let << ": " << letfreq[i] << " times" <<
            " (" << (static_cast<float>(letfreq[i]) / totLet) * 100 << "%)" << "\n";
    }

    cout << "Total Letters: ";
    return totLet;
}


// Runs a while loop until the end of the input file that checks every character
// If the character isn't punctuation or a space, then it will increase the frequency counter of the appropriate charater from the for loop
void CardCatalog::LetCount(ifstream& inp) {
    int wc = 0;
    int lc = 0;
    int abc = 26;
    char ch;
    string word;
    inp.clear();
    inp.seekg(0, ios::beg);
    getline(inp, word);
    getline(inp, word);
    getline(inp, word);
    while (!inp.eof()) {
        inp.get(ch);
        if (!(ispunct(ch) || isspace(ch))) {
            for (int i = 0; i <= abc; ++i) {
                if ('a' + i == ch) {
                    letfreq[i]++;
                    lc++;
                }
            }
        }
    }
    totLet = lc;
}


// Runs a while loop until the end of the input file that increases the word count for every word
void CardCatalog::CountWords(ifstream& inp) {
    string word;
    int count = 0;

    while (!inp.eof()) {
        inp >> word;
        count++;
    }
    wordCount = count - 1;
}


// Runs a while loop until the end of the input file and increases lineCount if the assoicaited line is not empty
void CardCatalog::LineCount(ifstream& inp) {
    string line;
    int count = 0;
    inp.clear();
    inp.seekg(0, ios::beg);
    getline(inp, line);
    getline(inp, line);
    getline(inp, line);
    while (!inp.eof()) {
        getline(inp, line);
        if (line != " ") {
            count++;
        }
    }

    lineCount = count - 1;
}


// Creates a feedback loop to make sure a valid file name is entered
// Will keep running until the file name is valid
void fileOpenTask(ifstream& FileObj) {
    string fileName;
    bool exists = false;
    while (!exists) {
        cout << "Please enter the NAME (with file extension) of the file to be processed: " << endl;
        cin >> fileName;
        FileObj.open(fileName, ios::in);
        if (FileObj.fail()) {
            cout << "File Open FAILED" << endl;
        }
        else {
            exists = true;
        }
    }
}


// First opens up CardCatalog.txt if it exists. If it doesn't, it creates the file
// Will append new information to the end of CardCatalog.txt
// Creates a CardCatalog struct
// Creates a feedback loop for asking whether or not the user wants the letter frequency
// Once a valid input is entered, it will do the specified task
// Gives the option to open new files until the user enters 'n' in which case the program will end
void fileRWTask(ifstream& inp, fstream& out) {

    string title;
    string firstName;
    string lastName;
    string line;

    out.open("CardCatalog.txt", ios::in);
    if (out.fail()) {
        out.close();
        out.open("CardCatalog.txt", ios::app);
    }
    else {
        out.close();
        out.open("CardCatalog.txt", ios::app);
        out << "\n";
    }

    getline(inp, title);
    inp >> firstName;
    inp >> lastName;

    CardCatalog card(title, firstName, lastName);
    out << "Title: " << card.getTitle() << "\n";
    out << "Full Author: " << card.getFullName() << "\n";
    out << "Author First Name: " << card.getFirstName() << "\n";
    out << "Author Last Name: " << card.getLastName() << "\n";

    getline(inp, line);

    getline(inp, line);

    card.CountWords(inp);
    out << "Word count: " << card.getWordCount() << "\n";

    card.LineCount(inp);
    out << "Line count: " << card.getLineCount() << "\n";

    char prompt = 'n';
    while (prompt != 'y') {
        cout << "Would you like to see the letter frequency? (y/n)" << endl;
        cin >> prompt;
        if (prompt == 'y') {
            card.LetCount(inp);
            cout << card.getLetFreq(out) << endl;
        }
        else if (prompt == 'n') {
            break;
        }
        else {
            cout << "Please enter a valid option." << endl;
        }
    }

    out.close();
    inp.close();

}

