#include <string.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main()
{
    char *buffer = new char[80];
    char *buffin = new char[80];
    char *buff;
    char *pos = new char[80];
    char handle;
    char i, ncpy = 0;
    int dummy = 0;
    char next = 0;
    cout << "\nType this for folding method (4176+5678+5469+1245+8907): ";

    cin.get(buffer, 80);
    pos[0] = 0;
    pos[1] = 0;
    i = 0;
    do
    {
        handle = buffer[i++];
        if (handle == '+')
        {
            pos[0]++;
            pos[pos[0] + 1] = i;
        }
    } while (handle);
    pos[0]++;
    pos[pos[0] + 1] = i;

    cout << "Type this to hash(41765678546912458907): ";
    cin.read(buffin, 1);
    cin.get(buffin, 80);
    
    if (strlen(buffin) - (i - pos[0]))
    {
        cout << "Hash not match!" << endl;
        return 1;
    }

    next = 0;
    dummy = 0;
    for (i = 0; i < pos[0]; i++)
    {
        ncpy = pos[i + 2] - pos[i + 1] - 1;
        buff = new char[ncpy + 1];
        strcpy(buff, "\0");
        strncat(buff, buffin + next, ncpy);
        cout << "Push buffer ";
        cout.setf(cout.right);
        cout.width(6);
        cout << buff << endl;
        next += pos[i + 2] - pos[i + 1] - 1;
        dummy += atoi(buff);
        delete buff;
    }
    
    cout << "Sum buffer return value = " << dummy
         << "\nRadix " << dummy % 100 << endl;

    return 0;
}