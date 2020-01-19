#include "Tetromino.h"
#include "Board.h"
#include <iostream>
#include <time.h>

const double NUM_SECONDS = 1;
const int rows = 16, cols = 11;
std::vector<Tetromino> tetroList = {};

int main()
{
    Tetromino T1(Shape::L, std::vector<int> {cols / 2, 5});
    Tetromino T2(Shape::L, std::vector<int> {cols / 2, 0});

    tetroList.push_back(T1);
    tetroList.push_back(T2);

    Board B(rows, cols);




    double time_counter = 0;

    clock_t this_time = clock();
    clock_t last_time = this_time;

    while (true)
    {
        this_time = clock();

        time_counter += (double)(this_time - last_time);

        last_time = this_time;

        if (time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC))
        {
            time_counter -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);


            std::cout << std::endl;
            B.clearBoard();

            for (int i = 0; i < tetroList.size(); i++)
            {
                auto& tetro = tetroList.at(i);
                tetro.move(0, 1);

                if (!B.superImpose(tetro))
                {
                    tetro.move(0, -1);
                    B.superImpose(tetro);
                }
            }
            B.print();
        }
    }


    return 0;
}