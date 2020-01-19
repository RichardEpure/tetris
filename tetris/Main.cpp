#include "Tetromino.h"
#include <iostream>


int main()
{
    Tetromino T(Shape::L);
    T.print();
    std::cout << std::endl;
    T.rotate(false);
    T.print();
    std::cout << std::endl;
    T.rotate(false);
    T.print();
    std::cout << std::endl;
    T.rotate(false);
    T.print();
    std::cout << std::endl;
    T.rotate(false);
    T.print();
    int x;
    std::cin >> x;
    return 0;
}