#include "Tree.h"
#include "Word.h"
#include <fstream>

using namespace std;

void fileOpen(fstream& FileObj);
void addFileDataToTree(fstream& FileObj, Tree<Word>& wordTree);
char getMenuChoice();

int main() {
	Tree<Word> tree;
	fstream inputFile;
    char prompt = '0';

    fileOpen(inputFile);
    addFileDataToTree(inputFile, tree);

    while (prompt != '4') {
        prompt = getMenuChoice();
        switch(prompt) {
        case '1': { // Search
            string searchWord = "";
            cout << "Enter a word you would like to search for: ";
            cin >> searchWord;
            cout << endl;
            if (tree.Find(searchWord)) {
                cout << tree.Find(searchWord)->data << endl << endl;
            }
            else {
                cout << "That word was not in the tree" << endl << endl;
            }
            break;
        }
        case '2': { // Ascending
            tree.GetAllAscendingPrint();
            cout << endl;
            break;
        }
        case '3': { // Descending
            tree.GetAllDescendingPrint();
            cout << endl;
            break;
        }
        case '4': { // Quit
            break;
        }
        }
    }

	return 0;
}

// Creates a feedback loop to make sure a valid file name is entered
// Will keep running until the file name is valid
void fileOpen(fstream& FileObj) {
    string fileName;
    bool exists = false;
    while (!exists) {
        cout << "Please enter the NAME (with file extension) of the file to be processed" << endl << endl;
        cout << "File name: ";
        cin >> fileName;
        cout << endl;
        FileObj.open(fileName, ios::in);
        if (FileObj.fail()) {
            cout << "File Open FAILED" << endl << endl;
        }
        else {
            exists = true;
        }
    }
}

// Reads the file and adds the words to the tree
void addFileDataToTree(fstream& FileObj, Tree<Word>& wordTree) {
    string word;

    while (!FileObj.eof()) {
        FileObj >> word;
        // http://www.cplusplus.com/forum/beginner/62933/ for how to remove punctuation from a string
        for (int i = 0; i < word.size(); i++) {
            if (ispunct(word[i])) { // Removes punctuation
                word.erase(word.begin() + i); // http://www.cplusplus.com/reference/string/string/erase/ for how to remove a character from a string
            }
            if (isupper(word[i])) { // Makes all words lowercase since strings consider uppercase > lowercase
                word[i] = tolower(word[i]);
            }
            if (word[i] == '"') { // ispunct() doesnt catch the " character
                word.erase(word.begin() + i);
            }
        }
        if (wordTree.Find(word) != nullptr) { // If the word is already in the tree, just add to the wordCount
            wordTree.Find(word)->data.increaseWordCount();
        }
        else { // If the word is not in the tree, add the word and add to the wordCount
            wordTree.Insert(word);
            wordTree.Find(word)->data.increaseWordCount();
        }
    }
}

char getMenuChoice() {
    char input = ' ';
    cout << "          Tree Menu" << endl;
    cout << "--------------------------------" << endl;
    cout << "1: Search for a word" << endl;
    cout << "2: Print tree in ascending order" << endl;
    cout << "3: Print tree in descending order" << endl;
    cout << "4: Quit" << endl << endl;
    cin >> input;
    cout << endl;
    return input;
}


