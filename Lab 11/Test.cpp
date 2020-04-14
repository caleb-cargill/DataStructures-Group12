#include "Graph.h"
#include <iostream>

using namespace std;

int main() {
	int numVertices = 0;
	int nodeValue = 0;

	cout << "How many vertices would you like to add: ";
	cin >> numVertices;
	cout << endl;
	
	Graph<int> graph(numVertices);
	graph.addVertices();

	char input = ' ';

	while (input != '8') {
		cout << "              Graph Menu" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Press 1 to add an edge to the graph" << endl;
		cout << "Press 2 to remove an edge from the graph" << endl;
		cout << "Press 3 to find an edge in the graph" << endl;
		cout << "Press 4 to find the out edges of a vertex" << endl;
		cout << "Press 5 to find the in edges of a vertex" << endl;
		cout << "Press 6 to depth first search the graph" << endl;
		cout << "Press 7 to breadth first search the graph" << endl;
		cout << "Press 8 to quit" << endl << endl;
		cout << "Input: ";
		cin >> input;
		cout << endl;

		switch (input) {
		case '1': { // Add edge
			int source = 0;
			int destination = 0;
			cout << "Enter source node value: ";
			cin >> source;
			cout << "Enter destination node value: ";
			cin >> destination;
			cout << endl;

			int sourceIndex = graph.findVertexIndex(source);
			int destinationIndex = graph.findVertexIndex(destination);
			if (sourceIndex == -1 || destinationIndex == -1) {
				if (sourceIndex == -1 && destinationIndex != -1) {
					cout << "There is not a source node in the graph with that value you inputted" << endl << endl;
				}
				else if (sourceIndex != -1 && destinationIndex == -1) {
					cout << "There is not a destination node in the graph with that value you inputted" << endl << endl;
				}
				else {
					cout << "There is not a source node or destination node in the graph with that values you inputted" << endl << endl;
				}
			}
			else {
				graph.addEdge(source, destination);
				graph.printGraph();
			}
			break;
		}
		case '2': { // Remove edge
			int source = 0;
			int destination = 0;
			cout << "Enter source node value: ";
			cin >> source;
			cout << "Enter destination node value: ";
			cin >> destination;
			cout << endl;

			int sourceIndex = graph.findVertexIndex(source);
			int destinationIndex = graph.findVertexIndex(destination);
			if (sourceIndex == -1 || destinationIndex == -1) {
				if (sourceIndex == -1 && destinationIndex != -1) {
					cout << "There is not a source node in the graph with that value you inputted" << endl << endl;
				}
				else if (sourceIndex != -1 && destinationIndex == -1) {
					cout << "There is not a destination node in the graph with that value you inputted" << endl << endl;
				}
				else {
					cout << "There is not a source node or destination node in the graph with that values you inputted" << endl << endl;
				}
			}
			else {
				graph.removeEdge(source, destination);
				graph.printGraph();
			}
			break;
		}
		case '3': { // Find edge
			int source = 0;
			int destination = 0;
			cout << "Enter source node value: ";
			cin >> source;
			cout << "Enter destination node value: ";
			cin >> destination;
			cout << endl;

			int sourceIndex = graph.findVertexIndex(source);
			int destinationIndex = graph.findVertexIndex(destination);
			if (sourceIndex == -1 || destinationIndex == -1) {
				if (sourceIndex == -1 && destinationIndex != -1) {
					cout << "There is not a source node in the graph with that value you inputted" << endl << endl;
				}
				else if (sourceIndex != -1 && destinationIndex == -1) {
					cout << "There is not a destination node in the graph with that value you inputted" << endl << endl;
				}
				else {
					cout << "There is not a source node or destination node in the graph with that values you inputted" << endl << endl;
				}
			}
			else {
				bool inGraph = graph.hasEdge(source, destination);
				if (inGraph) {
					cout << source << " DOES have an edge with " << destination << endl << endl;
				}
				else {
					cout << source << " DOES NOT have an edge with " << destination << endl << endl;
				}
			}
			break;
		}
		case '4': { // Out edge list
			int source = 0;
			cout << "Enter source node value: ";
			cin >> source;
			cout << endl;

			int sourceIndex = graph.findVertexIndex(source);
			if (sourceIndex == -1) {
				cout << "There is not a source node in the graph with that value you inputted" << endl << endl;
			}
			else {
				graph.outEdges(source);
			}
			break;
		}
		case '5': { // In edge list
			int source = 0;
			cout << "Enter source node value: ";
			cin >> source;
			cout << endl;

			int sourceIndex = graph.findVertexIndex(source);
			if (sourceIndex == -1) {
				cout << "There is not a source node in the graph with that value you inputted" << endl << endl;
			}
			else {
				graph.inEdges(source);
			}
			break;
		}
		case '6': { // DFS
			graph.depthFirstSeach();
			break;
		}
		case '7': { // BFS
			graph.breadthFirstSeach();
			break;
		}
		case '8': { // Quit
			break;
		}
		default: {
			cout << "Not a valid input" << endl << endl;
			break;
		}
		}
	}



	return 0;
}