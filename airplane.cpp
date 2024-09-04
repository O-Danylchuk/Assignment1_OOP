#include <string>
#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include "airplane.h"
#include "seat.cpp"

Airplane::Airplane(/* args */)
{
}

Airplane::~Airplane()
{
}

bool Airplane::IsSeatAvailable(const std::string& seat) const {
    auto found = bookedFlights.find(seat);
    return found == bookedFlights.end();
}