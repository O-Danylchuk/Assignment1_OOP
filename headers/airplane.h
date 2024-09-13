#pragma once
#include <string>
#include <vector>
#include <tuple>


class Airplane
{
private:
    std::vector<std::tuple<std::string, bool>> seats;
    int seatsAmount;
    int seatsInRow;
public:
    Airplane() = delete;
    Airplane(const int& seatsInRow, const int& seatsAmount);
    ~Airplane();

    bool isSeatAvailable(const std::string& seatNumber) const;
    bool hasFlight(const std::string& flightNo) const;
    bool bookSeat(const std::string& seatNumber);
    bool unbookSeat(const std::string& seatNumber);
    bool returnSeat(const std::string& seatNumber);
    void printAvailableSeats() const;
};