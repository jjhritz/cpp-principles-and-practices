//
// Reads two doubles then prints them, telling the user which is bigger and which smaller, or if both are equal.
// If the numbers differ by less than 0.01, the user is told they are "almost equal".
// Terminates when a non-int is received.
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    double valA, valB;             // Holds the received doubles

    while(cin >> valA)
    {
        cin >> valB;

        if (valA == valB)
        {
            cout << "You entered " << valA << " both times.";
        }
        else
        {
            cout << "The smaller number is: " << min(valA, valB) << ".  The larger number is: " << max(valA, valB);

            double diff = abs(valA - valB);

            if(diff < 1.0/100)
            {
                cout << "These numbers are almost equal!";
            }
        }

    }

    return 0;
}