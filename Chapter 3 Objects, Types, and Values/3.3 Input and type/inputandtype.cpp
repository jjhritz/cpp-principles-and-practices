//
// Read and write a first name and age.
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/28/2019.
//

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    string firstName = "???";       // string variable
    string lastName = "!!!";
    int age = -1;                   // integer variable

    cout << "Please enter your first name, last name, and age\n";

    cin >> firstName;       // read a string
    cin >> lastName;
    cin >> age;             // read an integer

    cout << "Hello, " << firstName  << " " << lastName << " (age " << age << ")\n";

    return 0;
}