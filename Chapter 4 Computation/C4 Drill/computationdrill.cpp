//
// Reads two ints then prints them.  Terminates when a non-int is received
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    int valA, valB;             // Holds the received integers

    while(cin >> valA)
    {
        cin >> valB;

        cout << valA << " " << valB;
    }

    return 0;
}