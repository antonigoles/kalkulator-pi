#include "./montecarlo.hpp"
#include "./simpson.hpp"
#include <iostream>
#include <conio.h>  


void performAlgorithm(std::string &choice) 
{
    if ( choice == "MonteCarlo" ) {
        MonteCarlo::performUserDialog();
    } else if ( choice == "Simpson" ) { 
        Simpson::performUserDialog();
    } else {
        std::cout << "Niepoprawny wybor!\n";
    }   
}

void continueIOLoop() 
{
    std::string algorithmChoice;
    std::cout << "Wybierz algorytm (po nazwie)" << std::endl;
    std::cout << "1) MonteCarlo" << std::endl;
    std::cout << "2) Simpson" << std::endl;
    std::cout << "-> ";
    std::cin >> algorithmChoice;
    performAlgorithm(algorithmChoice);
    std::cout << "Czy chcesz rozpoczac ponownie?" << std::endl <<
    "(ESC by wyjsc / Cokolwiek by kontynuowac) " << std::endl;
    char c;
    if (_getch() != 27) continueIOLoop(); 
}

int main() 
{
    continueIOLoop();
}