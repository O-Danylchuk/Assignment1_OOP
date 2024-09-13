#include <string>
#include <iostream>
#include <stdio.h>
#include "./headers/airplane.h"
#include <vector>
#include <iostream>

Airplane::Airplane(const int& seatsInRow, const int& seatsAmount)
         : seatsInRow(seatsInRow), seatsAmount(seatsAmount)
{
    for (int i = 1; i < seatsAmount; i++) {
        for (int j = 0; j <= seatsInRow; j++) {
            std::string seat = std::string(1, 'A' + j) + std::to_string(i);
            seats.push_back(std::make_tuple(seat, false));
        }
    }
}
Airplane::~Airplane() {}

bool Airplane::isSeatAvailable(const std::string& seatNumber) const {
    for (const auto& seat : seats) {
        if (std::get<0>(seat) == seatNumber) {
            return !std::get<1>(seat);
        }
    }
    return false;
}

bool Airplane::hasFlight(const std::string& flightNo) const {
    return flightNo == flightNo;
}



bool Airplane::bookSeat(const std::string& seatNumber) {
    for (auto& seat : seats) {
        if (std::get<0>(seat) == seatNumber) {
            if (!std::get<1>(seat)) {
                std::get<1>(seat) = true;
                return true;
            }
            return false;
        }
    }
    return false;
}

bool Airplane::unbookSeat(const std::string& seatNumber) {
    for (auto& seat : seats) {
        if (std::get<0>(seat) == seatNumber) {
            if (std::get<1>(seat)) {
                std::get<1>(seat) = false;
                return true;
            }
            return false;
        }
    }
    return false;
}
bool Airplane::returnSeat(const std::string& seatNumber) {
    for (auto& seat : seats) {
        if (std::get<0>(seat) == seatNumber) {
            if (std::get<1>(seat)) {
                std::get<1>(seat) = false;
                return true;
            }
            return false;
        }
    }
    return false;
}

void Airplane::printAvailableSeats() const {
    for (const auto& seat : seats) {
        if (!std::get<1>(seat)) {
            std::cout << "Seat " << std::get<0>(seat) << " is available\n";
        }
    }
}
