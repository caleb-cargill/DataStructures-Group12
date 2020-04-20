#pragma once
#include <string> 
#include "LinkedList.h"

using namespace std;

class Graph {
private:
	int numberOfVertices;
	int topVertex = 0;

	// Node holding a linked list of edges
	struct GraphVertex {
		// Linked list of vertexes that this connects with
		LinkedList<int>* adjacents;

		// The integer vertex value of this vertex
		int i;
	};

	// Array of nodes to implement the adjacency list method
	GraphVertex* Vertices[500];
public:
	// Default constructor
	Graph() {
		// Set the number of vertices
		numberOfVertices = 50;

		// initialize the nodes in the array
		for (int i = 0; i < numberOfVertices; i++) {
			Vertices[i] = nullptr;
		}
	}

	// Overloaded constructor
	Graph(int numVertices) {
		// Set the number of vertices
		numberOfVertices = numVertices;

		// initialize the nodes in the array
		for (int i = 0; i < numberOfVertices; i++) {
			Vertices[i] = nullptr;
		}
	}

	// Destructor
	~Graph() {
		// Delete each item in array
		for (int i = 0; i < topVertex + 1; i++) {
			delete Vertices[i];
			Vertices[i] = nullptr;
		}
	}

	// Adds the edge to the graph
	void addEdge(int* i, int* j) {
		int arrayIndexI, arrayIndexJ;
		bool foundI = false;
		bool foundJ = false;

		// Find i and j in the graph		
		for (int x = 0; x < topVertex + 1; x++) {
			if (Vertices[x] != nullptr) {
				if (Vertices[x]->i == *i) {
					foundI = true;
					arrayIndexI = x;
				}
				else if (Vertices[x]->i == *j) {
					foundJ = true;
					arrayIndexJ = x;
				}
			}
		}

		// if i is not found, create it
		if (!foundI) {
			topVertex++;
			arrayIndexI = topVertex;
			GraphVertex gv;
			gv.i = *i;
			Vertices[topVertex] = &gv;
		}

		// if j is not found, create it
		if (!foundJ) {
			topVertex++;
			arrayIndexJ = topVertex;
			GraphVertex gv;
			gv.i = *j;
			Vertices[topVertex] = &gv;
		}



		// add j to i if it is not already in there
		if (!Vertices[arrayIndexI]->adjacents->IsInList(j)) {
			Vertices[arrayIndexI]->adjacents->AddItem(j);
		}

		// add i to j if it is not already in there
		if (!Vertices[arrayIndexJ]->adjacents->IsInList(i)) {
			Vertices[arrayIndexJ]->adjacents->AddItem(i);
		}
	}

	// Removes the edge from the graph
	void removeEdge(int* i, int* j) {
		int arrayIndexI, arrayIndexJ;
		bool foundI = false;
		bool foundJ = false;

		// Find i and j in the graph
		for (int x = 0; x < topVertex + 1; x++) {
			if (Vertices[x] != nullptr) {
				if (*i == Vertices[x]->i) {
					foundI = true;
					arrayIndexI = x;
				}
				else if (Vertices[x]->i == *j) {
					foundJ = true;
					arrayIndexJ = x;
				}
			}
		}

		// if i is not found, throw exception
		if (!foundI) {
			throw EdgeDNE();
		}

		// if j is not found, throw exception
		if (!foundJ) {
			throw EdgeDNE();
		}

		// remove j from i if it exists
		if (Vertices[arrayIndexI]->adjacents->IsInList(j)) {
			Vertices[arrayIndexI]->adjacents->GetItem(j);
		}
		else {
			throw EdgeDNE();
		}

		// remove i from j if it exists
		if (Vertices[arrayIndexJ]->adjacents->IsInList(i)) {
			Vertices[arrayIndexJ]->adjacents->GetItem(i);
		}
		else {
			throw EdgeDNE();
		}
	}

	// Checks to see if the edge exists in the graph
	bool hasEdge(int* i, int* j) {
		int arrayIndexI, arrayIndexJ;
		bool foundI = false;
		bool foundJ = false;

		// Find i and j in the graph
		if (Vertices[0] != nullptr) {
			for (int x = 0; x < topVertex + 1; x++) {
				if (Vertices[x]->i == *i) {
					foundI = true;
					arrayIndexI = x;
				}
				else if (Vertices[x]->i == *j) {
					foundJ = true;
					arrayIndexJ = x;
				}
			}
		}

		// if i is not found, return false
		if (!foundI) {
			return false;
		}

		// if j is not found, return false
		if (!foundJ) {
			return false;
		}

		// return whether the edge exists or not
		return Vertices[arrayIndexI]->adjacents->IsInList(i)
			&& Vertices[arrayIndexJ]->adjacents->IsInList(j);
	}

	// returns a list of all integers j that make edge (i, j)
	string outEdges(int* i) {
		int arrayIndexI = 0;
		bool foundI = false;
		string edges = "";

		// Find i and j in the graph
		if (Vertices[0] != nullptr) {
			for (int x = 0; x < topVertex + 1; x++) {
				if (Vertices[x]->i == *i) {
					foundI = true;
					arrayIndexI = x;
				}
			}
		}

		// if i is not found, return an empty list, otherwise retun vertices
		if (foundI) {
			LinkedList<int>::ListNode* temp = (Vertices[arrayIndexI]->adjacents->head);

			while (temp != nullptr) {
				edges = edges + ", (" + to_string(*i) + ", " + to_string(temp->value) + ")";
				temp = temp->next;
			}
		}

		return edges;
	}

	// returns a list of all integers j that make edge (j, i)
	string inEdges(int* i) {
		int arrayIndexI = 0;
		bool foundI = false;
		string edges = "";

		// Find i and j in the graph
		if (Vertices[0] != nullptr) {
			for (int x = 0; x < topVertex + 1; x++) {
				if (Vertices[x]->i == *i) {
					foundI = true;
					arrayIndexI = x;
				}
			}
		}

		// if i is not found, return an empty list, otherwise retun vertices
		if (foundI) {
			LinkedList<int>::ListNode* temp = (Vertices[arrayIndexI]->adjacents->head);

			while (temp != nullptr) {
				edges = edges + ", (" + to_string(temp->value) + ", " + to_string(*i) + ")";
				temp = temp->next;
			}
		}

		return edges;
	}

	class EdgeDNE : public exception {
	public:
		string Message = "The edge does not exist";
	};
};