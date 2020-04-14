#pragma once
#include <iostream>

// Used https://github.com/JerryGoyal/data-structure/blob/master/graph%20implementation%20using%20adjacency%20list%20linked%20list%20array.cpp as a starting point
// Really only used for the idea of the Node and NodeList structs, everything else is original

using namespace std;

struct Node {
    int data;
    struct Node* next = nullptr;
};

struct NodeList {
    struct Node* head = nullptr;
    int numNodes = 0;
};

class Graph
{
private:
    int numVertices;
    NodeList* nodesArray;
public:
    // Resizes nodesArray based on input
    Graph(int vertices)
    {
        numVertices = vertices;
        nodesArray = new NodeList[numVertices];	
    }

    ~Graph() {

    }

    // Adds vertices to the array at the start
    void addVertices() {
        int input = 0;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i + 1 << ": ";
            cin >> input;

            Node* newNode = new Node;
            newNode->data = input;

            nodesArray[i].head = newNode;
            nodesArray[i].numNodes++;
        }
    }

    // Adds a node for j into the list of nodes for i
    void addEdge(int i, int j) {
        int iIndex = findVertexIndex(i);
        Node* newNode = new Node;
        newNode->data = j;

        Node* temp = nodesArray[iIndex].head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }


    void removeEdge(int i, int j) {
        int iIndex = findVertexIndex(i);
        Node* temp = nodesArray[iIndex].head;
        while (temp->next != nullptr) {
            if (temp->next->data == j) {
                break;
            }
            temp = temp->next;
        }
        if (temp->next->data != j) {
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    bool hasEdge(int i, int j) {
        int iIndex = findVertexIndex(i);
        Node* temp = nodesArray[iIndex].head;
        if (temp->next == nullptr) { // Return false if list has no edges
            return false;
        }
        while (temp->next != nullptr) {
            temp = temp->next;
            if (temp->data == j) {
                return true;
            }
        }
        return false;
    }

    void outEdges(int i) {
        int iIndex = findVertexIndex(i);
        Node* temp = nodesArray[iIndex].head;
        cout << "Out Edges: ";
        while (temp->next != nullptr) {
            temp = temp->next;
            cout << temp->data << ", ";
        }
        cout << endl;
    }

    void inEdges(int input) {
        int iIndex = findVertexIndex(input);
        cout << "In Edges: ";
        for (int i = 0; i < numVertices; i++) {
            if (i != iIndex) {
                Node* temp = nodesArray[i].head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                    if (temp->data == input) {
                        cout << nodesArray[i].head->data << ", ";
                        break;
                    }
                }
            }
        }
        cout << endl;
    }

    // Returns the index of the vertex in the array
    // Returns -1 if the vertex is not in the array
    int findVertexIndex(int input) {
        for (int i = 0; i < numVertices; i++) {
            if (input == nodesArray[i].head->data) {
                return i;
            }
        }
        return -1;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            Node* temp = nodesArray[i].head;
            cout << "|" << temp->data << "|";
            while (temp->next != nullptr) {
                temp = temp->next;
                cout << " -> |" << temp->data << "|";
            }
            cout << endl;
        }
    }

};
