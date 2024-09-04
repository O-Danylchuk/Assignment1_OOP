#pragma once
#include <string>
#include <vector>
#include "ticket.h"

class Airplane
{
private:
    int nOfSeats;
    std::unordered_set<std::string> bookedFlights;
public:
    Airplane(/* args */);
    ~Airplane();
    bool IsSeatAvailable(const std::string& seatNo) const ;
};