//
// Read and write a first name
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/28/2019.
//

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    string firstName;       // definition of variable of type string

    cout << "Please enter your first name (followed by 'enter'):\n";
    cin >> firstName;                               // read characters into firstName
    cout << "Hello, " << firstName << "!\n";        // Greet the user with their first name

    return 0;
}