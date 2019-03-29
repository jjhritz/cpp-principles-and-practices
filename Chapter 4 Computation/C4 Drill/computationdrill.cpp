//
// Continually doubles then prints them, telling the user when the number entered is the largest or smallest it has seen.
// Rejects non-supported units and keeps a running sum of accepted values.
// Stores all accepted values in a vector, then sorts and prints them upon termination.
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
    double minVal = 0, maxVal = 0, runningSum = 0;
    constexpr double cmPerM = 100, cmPerIn = 2.54, inPerF = 12;

    string unit;                // Tracks the unit of the input for evaluation.
    vector<double> inputs;      // Stores all inputs in cm

    while(cin >> val >> unit)
    {
        bool accepted = true;       // Flag that's set to false if the received unit is not recognized. Prevents evaluation.
        double valAsCm = 0;         // Stores the input value converted to centimeters

        cout << val << unit;

        // Convert everything to centimeters
        if (unit == "cm" || unit == " cm")
        {
            valAsCm = val;
        }
        else if(unit == "m" || unit == " m")
        {
             valAsCm = val * cmPerM;
        }
        else if(unit == "in" || unit == " in")
        {
            valAsCm = val * cmPerIn;
        }
        else if(unit == "ft" || unit == " ft")
        {
            valAsCm = val * inPerF * cmPerIn;
        }
        else
        {
            accepted = false;
        }

        if(accepted)
        {
            inputs.push_back(valAsCm);

            runningSum += valAsCm;

            cout << "The running sum is: " << runningSum;

            if (valAsCm < minVal)
            {
                minVal = valAsCm;
                cout << "This is the smallest number (" << valAsCm << "cm) received so far.";
            }
            else if (valAsCm > maxVal)
            {
                maxVal = valAsCm;
                cout << "This is the largest number (" << valAsCm << "cm) received so far.";
            }
        }
        else
        {
            cout << "Sorry, unit " << unit << " is not supported.";
        }

    }

    sort(inputs);

    for(double x : inputs)
    {
        cout << x << ", ";
    }

    return 0;
}