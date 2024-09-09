#include <string>
#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include "airplane.h"
#include "seat.cpp"

Airplane::Airplane(int amOfSeats, int amOfRows) : amOfSeatsInRow(amOfSeats), rows(amOfRows)
{
}

Airplane::~Airplane()
{
}

bool Airplane::IsSeatAvailable(const std::string& seat) const {
    return bookedFlights.find(seat) == bookedFlights.end();
}