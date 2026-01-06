#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- TEST 1: Normal Bureaucrat ---" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Grade Too High (Constructor) ---" << std::endl;
    try
    {
        Bureaucrat god("Zeus", 0);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Grade Too Low (Constructor) ---" << std::endl;
    try
    {
        Bureaucrat slave("Peon", 151);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Increment Error (1 -> 0) ---" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.incrementGrade(); 
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: Decrement Error (150 -> 151) ---" << std::endl;
    try
    {
        Bureaucrat noob("Noob", 150);
        std::cout << noob << std::endl;
        noob.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}