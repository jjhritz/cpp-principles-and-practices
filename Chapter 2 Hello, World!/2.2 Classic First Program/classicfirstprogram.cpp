// This program outputs the message “Hello, World!” to the monitor
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

int main()
{
    std::cout << "Hello, programming!\nHere we go!\n";     // output "Hello, programming!\nHere we go!"
    keep_window_open();                                    // wait for a character to be entered
    return 0;
}