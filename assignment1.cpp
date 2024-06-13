/* 
Assignment 1
Jayla Word  
*/


#include "assignment1.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

// This function reads data from a file into an array
int readDataFromFile(int arr[]) {
    ifstream inFile("A1input.txt"); 
    if (!inFile.is_open()) { 
        cout << "Error: Could not open file." << endl;
        return -1; 
    }

    int size = 0; // Initialize size of the array
    // Need to read data from file into array until the end of file or array is full
    while (inFile >> arr[size] && size < array_size) {
        size++;
    }
    inFile.close(); 
    return size; 
}

// This function finds the index of a number in the array
int findNumber(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) { 
        if (arr[i] == number) { // Checks if the current element is the number the user entered
            return i; // Return the index if found
        }
    }
    return -1; 
}

// Modify the value of an element in the array
void modifyValue(int arr[], int size, int index, int &oldValue, int &newValue) {
    if (index < 0 || index >= size) { 
        throw out_of_range("Invalid index."); // Throw an exception if index is invalid
    }
    oldValue = arr[index]; // Store the old value
    cout << "Enter new value: ";
    cin >> newValue; // Read the new value from the user
    arr[index] = newValue; // Update the array with the new value
}

// Add an element to the array
void addElement(int arr[], int &size, int element) {
    if (size == array_size) { // Check if the array is full
        throw out_of_range("Array is full.");
    }
    arr[size] = element; // Add the new element to the array
    size++; // Increment the size of the array
}

// Remove an element from the array
void removeElement(int arr[], int &size, int index) {
    if (index < 0 || index >= size) { 
        throw out_of_range("Invalid index."); 
    }

    // Shift the elements to the left to fill the gap created by the removed element
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Decrement the size of the array
}

int main() {
    int arr[array_size]; 
    int size = readDataFromFile(arr); // Read data from file into array

    if (size == -1) { // Check if there was an error reading the file
        return 1; 
    }

    int choice, number, index, oldValue, newValue;
    int element;

    do {
        // The menu options
        cout << "\nMenu:" << endl;
        cout << "1. Find a number" << endl;
        cout << "2. Modify element value" << endl;
        cout << "3. Add element" << endl;
        cout << "4. Remove element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // I will use a switch statement
        switch (choice) {
            case 1:
                cout << "Enter number to find: ";
                cin >> number;
                index = findNumber(arr, size, number);
                if (index == -1) {
                    cout << "Number not found." << endl;
                } else {
                    cout << "Number found at index " << index << endl;
                }
                break;
            case 2:
                try {
                    cout << "Enter index: ";
                    cin >> index;
                    modifyValue(arr, size, index, oldValue, newValue);
                    cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: Invalid index." << endl;
                }
                break;
            case 3:
                try {
                    cout << "Enter element to add: ";
                    cin >> element;
                    addElement(arr, size, element);
                    cout << "Element added." << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: Array is full." << endl;
                }
                break;
            case 4:
                try {
                    cout << "Enter index to remove: ";
                    cin >> index;
                    removeElement(arr, size, index);
                    cout << "Element removed." << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: Invalid index." << endl;
                }
                break;
            case 5:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0; 
}