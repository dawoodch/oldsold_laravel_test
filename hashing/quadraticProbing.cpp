#include <iostream>
using namespace std;
int find(int);
bool insert(int);
const int size = 10;
int load = 0;
int A[10];
/**
*returns the array index where the integer key x is found. 
* If x is not in the hash table, return -1  
*/
int find(int searchKey)
{
    int size = 10;
    int hash = searchKey % size; //hash formula
    if (A[hash] == searchKey)
        return hash;
    else
        return -1;
}

bool insert(int newItem)
{
    int size = 10;
    int h = newItem % size;
    for (int step = 1; A[h] != NULL; step++)
    {
        // Check for a duplicate (if not allowed)
        if (newItem == A[h])
            return false;
        // Quadratic step to the next slot
        h = (h + (step * step - step) / 2) % size;
    }
    // Insert the new item
    A[h] = newItem;
    ++load;
    return true;
}

int main()
{
    int choice,value;
    while (1)
    {
        cout << "\n1.Insert element into the table" << endl;
        cout << "2.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be inserted: ";
            cin >> value;
            if(insert(value))
                cout << "Data has been Inserted\n";
            else
                cout << "Error insertion in data\n";
            break;
        case 2:
            exit(1);
        default:
            cout << "\nEnter correct option\n";
        }
    }
}