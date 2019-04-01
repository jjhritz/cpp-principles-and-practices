cmake_minimum_required(VERSION 3.13)
project(Principles_and_Practices)

set(CMAKE_CXX_STANDARD 17)

add_executable(ClassicFirstProgram "Chapter 2 Hello, World!/2.2 Classic First Program/classicfirstprogram.cpp")
add_executable(InputBasics "Chapter 3 Objects, Types, and Values/3.1 Input/inputbasics.cpp")
add_executable(InputAndType "Chapter 3 Objects, Types, and Values/3.3 Input and type/inputandtype.cpp")
add_executable(ComputationDrill "Chapter 4 Computation/C4 Drill/computationdrill.cpp")

set(SimpleCalculatorSources "Chapter 6 Writing a Program/Simple Calculator/simplecalculator.cpp"
        "Chapter 6 Writing a Program/Simple Calculator/calcparser.cpp"
        "Chapter 6 Writing a Program/Simple Calculator/Token.cpp")
add_executable(SimpleCalculator ${SimpleCalculatorSources})

set(BetterCalculatorSources "Chapter 7 Completing a Program/Simple Calculator Mk II/bettercalculator.cpp"
        "Chapter 7 Completing a Program/Simple Calculator Mk II/calcparser.cpp"
        "Chapter 7 Completing a Program/Simple Calculator Mk II/Token.cpp")
add_executable(BetterCalculator ${BetterCalculatorSources})