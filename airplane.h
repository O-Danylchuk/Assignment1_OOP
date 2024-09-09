#pragma once
#include <string>
#include <vector>
#include "ticket.h"

class Airplane
{
private:
    int amOfSeatsInRow;
    int rows;
    std::unordered_set<std::string> bookedFlights;
public:
    Airplane(int amOfSeats, int amOfRows);
    ~Airplane();
    bool IsSeatAvailable(const std::string& seatNo) const ;
};