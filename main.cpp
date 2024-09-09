#include "airplane.h"
#include "ticket.h"
#include <iostream>
#include <sstream>


int main()
{
    int amOfSeatsInRow = 11;
    int rows = 40;
    char NamingOfSeats[amOfSeatsInRow] = {'A', 'B', 'C', 'D', 'E', 'D', 'F', 'G', 'H', 'I', 'J'};

    Airplane AF12;
    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 0; j < amOfSeatsInRow; j++){
            std::string seat = std::to_string(i) + NamingOfSeats[j]; 
            if (AF12.IsSeatAvailable(seat)){
                continue;
            }
            std::cout << seat << "  ";
        }
    }


    return 0;
}