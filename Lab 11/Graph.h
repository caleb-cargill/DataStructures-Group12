#pragma once
#include <iostream>
#include "Queue.h"
#include "Stack.h"

// Used https://github.com/JerryGoyal/data-structure/blob/master/graph%20implementation%20using%20adjacency%20list%20linked%20list%20array.cpp as a starting point
// Really only used for the idea of the Node and NodeList structs, everything else is original

using namespace std;

template <class T>
class Graph
{
private:
    struct Node {
        T data;
        struct Node* next = nullptr;
    };

    struct NodeList {
        struct Node* head = nullptr;
        int numNodes = 0;
    };

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
    void addEdge(T i, T j) {
        int iIndex = findVertexIndex(i);
        Node* newNode = new Node;
        newNode->data = j;

        Node* temp = nodesArray[iIndex].head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Assigns temp to the head
    // If the list is empty, it will return
    // If not, it will stop when temp->next has the desired node to delete
    // Reassigns temp->next and deletes the desired node
    // Just returns if the desired node is not in the source node's output
    void removeEdge(T i, T j) {
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

    // Looks through the output vertices and returns true if the destination vertex is in there
    // Returns false if not
    bool hasEdge(T i, T j) {
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

    // Looks through the inputted vertex and outputs all of its output vertex data
    void outEdges(T i) {
        int iIndex = findVertexIndex(i);
        Node* temp = nodesArray[iIndex].head;
        cout << "Out Edges: ";
        while (temp->next != nullptr) {
            temp = temp->next;
            cout << temp->data << ", ";
        }
        cout << endl << endl;
    }

    // Looks through the lists of all the vertices besides the one inputted
    // If the inputted vertex appears in the output of another vertex, output the vertex
    void inEdges(T input) {
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
        cout << endl << endl;
    }

    // Returns the index of the vertex in the array
    // Returns -1 if the vertex is not in the array
    int findVertexIndex(T input) {
        for (int i = 0; i < numVertices; i++) {
            if (input == nodesArray[i].head->data) {
                return i;
            }
        }
        return -1;
    }

    // Prints out a visualization of the graph for testing
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

    //https://www.geeksforgeeks.org/difference-between-bfs-and-dfs/ used for understanding more for DFS vs BFS

    // Searches the graph in a depth first manner
    // Outputs the nodes in the order they are searched
    // Uses a stack
    void depthFirstSeach() {

    }

    // Searches the graph in a breadth first manner
    // Outputs the nodes in the order they are searched
    // Uses a queue
    void breadthFirstSeach() {
        Queue<T> breadthSearch(numVertices);
        for (int i = 0; i < numVertices; i++) {
            Node* temp = nodesArray[i].head;
            if (!breadthSearch.isInQueue(temp->data)) {
                breadthSearch.Enqueue(temp->data);
            }
            while (temp->next != nullptr) {
                temp = temp->next;
                if (!breadthSearch.isInQueue(temp->data)) {
                    breadthSearch.Enqueue(temp->data);
                }
            }
            if (breadthSearch.isFull()) {
                break;
            }
        }
        cout << "Breadth first search: ";
        for (int i = 0; i < numVertices; i++) {
            cout << breadthSearch.Dequeue() << ", ";
        }
        cout << endl << endl;
    }

};
