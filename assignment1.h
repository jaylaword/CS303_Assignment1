// assignment1.h

// Function declarations

const int array_size = 100;

int readDataFromFile(int arr[]);
int findNumber(int arr[], int size, int number);
void modifyValue(int arr[], int size, int index, int &oldValue, int &newValue);
void addElement(int arr[], int &size, int element);
void removeElement(int arr[], int &size, int index);
