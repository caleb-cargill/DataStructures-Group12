#include "Graph.h"
#include <string>

using namespace std;

char getMenuChoice();

int main() {
	char menuInput = ' ';
	int i, j, k, l;
	int numVerts;

	cout << "Enter number of vertices: ";
	cin >> numVerts;
	cout << endl;

	Graph thisGraph = *(new Graph(numVerts));

	// Run until the user chooses to quit
	while (menuInput != '6') {
		menuInput = getMenuChoice();
		system("CLS");

		switch (menuInput) {
		case '1': { // user chose to add an edge
			cout << "Enter edge to add: " << endl;
			cout << "i = ";
			cin >> i;
			cout << endl << "j = ";
			cin >> j;

			thisGraph.addEdge(&i, &j);
		}
				break;
		case '2': { // user chose to remove an edge
			cout << "Enter edge to remove: " << endl;
			cout << "i = ";
			cin >> k;
			cout << endl << "j = ";
			cin >> l;

			try
			{
				thisGraph.removeEdge(&k, &l);

				cout << "Edge successfully removed!" << endl;
			}
			catch (Graph::EdgeDNE ex) {
				cout << ex.Message << endl;
			}
		}
				break;
		case '3': { // user chose to find if an edge exists
			cout << "Enter edge: " << endl;
			cout << "i = ";
			cin >> i;
			cout << endl << "j = ";
			cin >> j;

			if (thisGraph.hasEdge(&i, &j)) {
				cout << endl << endl << "The edge does exist!" << endl;
			}
			else {
				cout << endl << endl << "The edge does not exist!" << endl;
			}
		}
				break;
		case '4': { // user chose to find out edges
			cout << "Which vertices would you like to find out edges for? " << endl;
			cout << "i = ";
			cin >> i;

			cout << thisGraph.outEdges(&i) << endl;
		}
				break;
		case '5': { // user chose to find in edges
			cout << "Which vertices would you like to find in edges for? " << endl;
			cout << "i = ";
			cin >> i;

			cout << thisGraph.inEdges(&i) << endl;
		}
				break;
		case '6': { // user quit
			cout << "Thanks, Bye!";
		}
				break;
		default: { // user entered invalid input
			cout << "Not a valid input. Please try again!" << endl << endl;
		}
			   break;
		}

		cout << endl << endl;
	}

	return 0;
}

char getMenuChoice() {
	char input;
	cout << "Graph Menu:" << endl << endl;
	cout << "1: Add an edge to the graph" << endl;
	cout << "2: Remove an edge from the graph" << endl;
	cout << "3: Find an edge in the graph" << endl;
	cout << "4: Find the out edges of a vertices" << endl;
	cout << "5: Find the in edges of a vertices" << endl;
	cout << "6: Quit";
	cout << "Input: ";
	cin >> input;
	return input;
}