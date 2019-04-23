#include<stdio.h>
#include <iostream>

using namespace std;
int main()
{
    long int seed = 6897; //take any 4 digit Number without trailing 00
    int i, n;
    cout << "Array size you want to insert : ";
    cin >> n;

    int random[n] , record[n];
    for(i = 0; i < n; i++)
    {
        cout << "\nEnter record# "<< i+1<<  ": ";
        cin >> record[i];
        seed = seed * seed;
        seed = seed / 100;       //Take the dividend
        seed = seed % 10000;    // Take the reminder
        random[i] = seed;
        cout << "With randon# " << random[i] << " Record has been saved= " << record[i];
    }

    cout << endl;
    return 0;
}