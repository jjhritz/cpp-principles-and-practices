//
// Continually doubles then prints them, telling the user when the number entered is the largest or smallest it has seen.
// Terminates when a non-double is received.
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    double val;             // Holds the received double
    double minVal = 0, maxVal = 0;

    while(cin >> val)
    {
        cout << val;

        if (val < minVal)
        {
            minVal = val;
            cout << "This is the smallest number received so far.";
        }
        else if (val > maxVal)
        {
            maxVal = val;
            cout << "This is the largest number received so far.";
        }
    }

    return 0;
}