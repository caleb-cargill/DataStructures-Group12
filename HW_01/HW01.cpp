// HW01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "HW01.h"
using namespace std;

string fileName;

void fileOpenTask(ifstream &FileObj) {
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

void fileRWTask(ifstream &inp, fstream &out) {
    
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

    /*cout << "- " << firstName << " -" << endl;
    cout << "- " << lastName << " -" << endl;
    cout << "- " << card.getFullName() << " -" << endl;*/

    getline(inp, line);
    //cout << line << endl;

    getline(inp, line);
    //cout << line << endl;


    
    card.CountWords(inp);
    //cout << card.getWordCount() << endl;
    out << "Word count: " << card.getWordCount() << "\n";

    card.LineCount(inp);
    //cout << card.getLineCount() << endl;
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
