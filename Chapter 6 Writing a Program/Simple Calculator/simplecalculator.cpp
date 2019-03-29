//
// A simple command line calculator
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

#include "simplecalculator.h"


int main()
{
    try
    {
        while (cin)
            cout << expression() << '\n';
        keep_window_open();
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open();
        return 2;
    }

}