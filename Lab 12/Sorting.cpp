#include <iostream>
#include <time.h>

#include <fstream>
#include "LinkedList.h"
#include <chrono>
#include <string>
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

// Used https://www.geeksforgeeks.org/sorting-algorithms/ for a starting point when stuck, mostly for merge sort and count/radix sort

// Array functionality
void fillArray(int arr[], int n);
void copyArray(int arr[], int copy[], int n);
void printArray(int arr[], int n);

// Sorting functions
void bubbleSort(int arr[], int n);
void insertSort(int arr[], int n);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int left, int right);
void countingSort(int arr[], int n);
void radixSort(int arr[], int n);

void runTaskOneTwo();
void runTaskThree();

int main() {
	srand(time(0));

	char taskChoice = ' ';

	cout << "Which task would you like to test? " << endl;
	cout << "1: Task 1/2" << endl;
	cout << "2: Task 3" << endl;
	cout << "3: Quit" << endl;
	cin >> taskChoice;

	while (taskChoice != '1' && taskChoice != '2' && taskChoice != '3') {
		cout << "Please enter valid input" << endl;
		cout << "Which task would you like to test? " << endl;
		cout << "1: Task 1/2" << endl;
		cout << "2: Task 3" << endl;
		cout << "3: Quit" << endl;
		cin >> taskChoice;
	}

	switch (taskChoice) {
	case '1': {
		runTaskOneTwo();
	}
			break;
	case '2': {
		runTaskThree();
	}
			break;
	case '3': {
		cout << "Okay, bye!" << endl;
	}
			break;
	}

	return 0;
}

// Tests tasks 1 and 2
void runTaskOneTwo() {
	// Array size
	const static int n = 25000;

	int arr[n];
	int arrCopy[n];
	fillArray(arr, n);
	copyArray(arr, arrCopy, n);

	cout << "Sorting an array with size " << n << endl << endl;
	//printArray(arr, n);

	// Bubble sort timer
	auto startBubble = Clock::now();
	insertSort(arrCopy, n);
	auto endBubble = Clock::now();
	std::cout << "Bubble sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endBubble - startBubble).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);

	// Insert sort timer
	auto startInsert = Clock::now();
	insertSort(arrCopy, n);
	auto endInsert = Clock::now();
	std::cout << "Insert sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endInsert - startInsert).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);

	// Merge sort timer
	auto startMerge = Clock::now();
	mergeSort(arrCopy, 0, n - 1);
	auto endMerge = Clock::now();
	std::cout << "Merge sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endMerge - startMerge).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);

	// Quick sort timer
	auto startQuick = Clock::now();
	quickSort(arrCopy, 0, n - 1);
	auto endQuick = Clock::now();
	std::cout << "Quick sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endQuick - startQuick).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);

	// Counting sort timer
	auto startCounting = Clock::now();
	countingSort(arrCopy, n);
	auto endCounting = Clock::now();
	std::cout << "Counting sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endCounting - startCounting).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);

	// Radix sort timer
	auto startRadix = Clock::now();
	radixSort(arrCopy, n);
	auto endRadix = Clock::now();
	std::cout << "Radix sort: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(endRadix - startRadix).count()
		<< " nanoseconds" << endl;
	//printArray(arrCopy, n);
	copyArray(arr, arrCopy, n);
}

// Tests Task 3
void runTaskThree() {
	LinkedList* thisList = new LinkedList();

	// Read through text document to get student names 
	fstream text;
	text.open("Students.txt", ios::in);

	while (!text.eof()) {
		string temp;
		getline(text, temp);

		string word = "";
		LinkedList::Student stud;

		int count = 1;
		for (auto x : temp)
		{
			if (x == ' ')
			{
				if (count == 1) {
					stud.fName = word;
					count++;
				}
				else if (count == 2) {
					stud.lName = word;
					count++;
				}
				else if (count == 3) {
					stud.mNumber = word;
					count++;
				}
				word = "";
			}
			else
			{
				word = word + x;
			}

		}
			stud.mNumber = word;

		thisList->AddItem(&stud);
	}

	char menuChoice = ' ';

	while (menuChoice != '7') {

		cout << endl;

		thisList->PrintList();

		cout << endl << endl;
		cout << "                       Sort Menu" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "Press 1 to sort ascending by first name (Bubble Sort)" << endl;
		cout << "Press 2 to sort descending by first name (Bubble Sort)" << endl;
		cout << "Press 3 to sort ascending by last name (Insertion Sort)" << endl;
		cout << "Press 4 to sort descending by last name (Insertion Sort)" << endl;
		cout << "Press 5 to sort ascending by MNumber (Quick Sort)" << endl;
		cout << "Press 6 to sort descending by MNumber (Quick Sort)" << endl;
		cout << "Press 7 to quit" << endl << endl;
		cout << "Input: ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case '1': {
			thisList->bubbleSort(true);
			cout << endl << endl << "List sorted by ascending first name: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '2': {
			thisList->bubbleSort(false);
			cout << endl << endl << "List sorted by descending first name: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '3': {
			thisList->insertionSort(true);
			cout << endl << endl << "List sorted by ascending last name: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '4': {
			thisList->insertionSort(false);
			cout << endl << endl << "List sorted by descending last name: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '5': {
			thisList->quickSort(true);
			cout << endl << endl << "List sorted by ascending MNumber: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '6': {
			thisList->quickSort(false);
			cout << endl << endl << "List sorted by descending MNumber: " << endl;
			cout << "----------------------------------------" << endl;
		}
				break;
		case '7': {
			cout << "Okay, bye!" << endl;
		}
				break;
		default: {
			cout << "Invalid input, please try again" << endl;
		}
			   break;
		}

	}
}

// Randomly fills an array with integers between 0 and 2n with n being the array size
void fillArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (2 * n);
	}
}

// Copies arr contents into copy
void copyArray(int arr[], int copy[], int n) {
	for (int i = 0; i < n; i++) {
		copy[i] = arr[i];
	}
}

// Prints the array for testing
void printArray(int arr[], int n) {
	cout << "[";
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1] << "]" << endl << endl;
}

// Bubble sort
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Insert sort
void insertSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j > -1 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Merges two arrays together
// The first array is from left to middle
// The second array is from middle + 1 to right
void mergeArrays(int arr[], const int left, const int middle, const int right) {
	int leftArraySize = middle - left + 1;
	int rightArraySize = right - middle;

	// Creates a temporary left and right variable to be sorted
	int* tempLeft = new int[leftArraySize];
	int* tempRight = new int[rightArraySize];

	// Fill left and right arrays with appropriate values from the main array
	for (int i = 0; i < leftArraySize; i++) {
		tempLeft[i] = arr[left + i];
	}
	for (int i = 0; i < rightArraySize; i++) {
		tempRight[i] = arr[middle + 1 + i];
	}

	int i = 0; // Left array iterator
	int j = 0; // Right array iterator
	int k = left; // Main array iterator

	// Will sort through both arrays until one of the arrays reaches the end
	// Adds the items to the main array in order
	while (i < leftArraySize && j < rightArraySize) {
		if (tempLeft[i] > tempRight[j]) {
			arr[k] = tempRight[j];
			j++;
		}
		else {
			arr[k] = tempLeft[i];
			i++;
		}
		k++;
	}

	// If there are still items in the left array, it will add them to the main array
	while (i < leftArraySize) {
		arr[k] = tempLeft[i];
		i++;
		k++;
	}

	// If there are still items in the right array, it will add them to the main array
	while (j < rightArraySize) {
		arr[k] = tempRight[j];
		j++;
		k++;
	}

}

// Merge sort
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;

		// Recursively calls merge sort which splits off into to arrays until there is only 1 element in each array (when left == right)
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		mergeArrays(arr, left, middle, right);
	}
}

// Quick sort
void quickSort(int arr[], int left, int right) {
	if (left < right) {
		int pivot = right; // Sets the pivot to the right most value in the array

		// Puts the pivot in the correct location with all elements smaller on the left and all elements bigger on the right
		int i = left - 1;
		int key = arr[pivot];
		for (int j = left; j < right; j++) {
			if (arr[j] < key && j != pivot) {
				i++;
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
		int temp = arr[i + 1];
		arr[i + 1] = arr[pivot];
		arr[pivot] = temp;
		pivot = i + 1;

		quickSort(arr, left, pivot - 1); // Sorts left of pivot
		quickSort(arr, pivot + 1, right); // Sorts right of pivot
	}
}

// Counting sort
void countingSort(int arr[], int n) {
	// Find max of arr[] and create a variable of size max to keep count
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}
	max++;
	int* countArr = new int[max];
	// Initialize all counts to 0
	for (int i = 0; i < max; i++) {
		countArr[i] = 0;
	}

	// Add the counts of the integers in arr[]
	for (int i = 0; i < n; i++) {
		countArr[arr[i]]++;
	}

	// Increment the counts in countArr
	for (int i = 1; i < max; i++) {
		countArr[i] += countArr[i - 1];
	}

	// copy arr[]
	int* copy = new int[n];
	copyArray(arr, copy, n);

	// The value in copy[i] will be used as the index for countArr which will be the index for arr[]
	// The value that goes here is the value in copy[i]
	// Decrements the count of countArr[copy[i]] once done
	for (int i = n - 1; i >= 0; i--) {
		arr[countArr[copy[i]] - 1] = copy[i];
		countArr[copy[i]]--;
	}
}

// Radix sort
void radixSort(int arr[], int n) {
	// Find max of arr[] and create a variable of size max to keep count
	int max = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) max = arr[i];
	}

	// Will iterate through each decimal place based on the number of digits in 
	for (int exp = 1; max / exp > 0; exp *= 10) {
		// Only 10 since it uses modulus which has a max of 9
		int countArr[10] = { 0 };

		// Add the counts of the integers in arr[]
		for (int i = 0; i < n; i++) {
			countArr[(arr[i] / exp) % 10]++;
		}

		// Increment the counts in countArr
		for (int i = 1; i < 10; i++) {
			countArr[i] += countArr[i - 1];
		}

		// copy arr[]
		int* copy = new int[n];
		copyArray(arr, copy, n);

		// The value in copy[i] will be used as the index for countArr which will be the index for arr[]
		// The value that goes here is the value in copy[i]
		// Decrements the count of countArr[copy[i]] once done
		for (int i = n - 1; i >= 0; i--) {
			arr[countArr[(copy[i] / exp) % 10] - 1] = copy[i];
			countArr[(copy[i] / exp) % 10]--;
		}
	}
}