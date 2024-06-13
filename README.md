# CS303_Assignment1

This program performs basic array operations such as reading data from a file, finding an element, modifying an element, adding a new element, and removing an element. The array operations are performed based on user input through a menu. 

Upon running the program, a menu will be displayed with the following options:

Find a number: Prompts the user to enter a number to search for in the array. If found, the index is displayed; otherwise, a message indicating the number was not found is shown.
Modify element value: Prompts the user to enter the index of the element they want to modify. The user is then prompted to enter a new value for that element. If the index is invalid, an error message is displayed.
Add element: Prompts the user to enter a new element to add to the array. If the array is full, an error message is displayed.
Remove element: Prompts the user to enter the index of the element they want to remove from the array. If the index is invalid, an error message is displayed.
Exit: Exits the program.

Function Descriptions: 

int readDataFromFile(int arr[]): Reads integers from data.txt and populates the array arr. Returns the number of elements read.
int findNumber(int arr[], int size, int number): Searches for number in the array arr and returns its index if found, otherwise returns -1.
void modifyValue(int arr[], int size, int index, int &oldValue, int &newValue): Modifies the value at index in the array arr. If the index is invalid, throws an out_of_range exception.
void addElement(int arr[], int &size, int element): Adds element to the array arr. If the array is full, throws an out_of_range exception.
void removeElement(int arr[], int &size, int index): Removes the element at index from the array arr. If the index is invalid, throws an out_of_range exception.

The program handles various errors such as:

File opening failure: Displays an error message if A1Input.txt cannot be opened.
Invalid index for modification or removal: Throws and catches out_of_range exceptions, displaying appropriate error messages.
Adding an element to a full array: Throws and catches out_of_range exceptions, displaying appropriate error messages.
