#pragma once
#include <iostream>
#include <string>
#include <vector>

struct SeatPriceSegment {
    int start;
    int end;
    int price;
};

class Ticket
{
private:
    std::string passangerName;
    std::string seatNumber;
    std::string date;
    std::string flightNo;
    std::vector<SeatPriceSegment> seatPriceSegments;
public: 
    Ticket() = default;
    Ticket(const std::string& passangerName, const std::string& seatNumber, const std::string& date, const std::string& flightNo);
    ~Ticket() = default;
    std::string getPassangerName() const;
    std::string getSeatNumber() const;
    std::string getDate() const;
    std::string getFlightNo() const;
    void setPassangerName(const std::string& passangerName);
    void setSeatNumber(const std::string& seatNumber);
    void setDate(const std::string& date);
    void setFlightNo(const std::string& flightNo);
    void printTicket() const;
    void addPriceSegment(const SeatPriceSegment& priceSegments);
    int getSeatPrice(std::string& seatNo) const;
};