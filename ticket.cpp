#include "./headers/ticket.h"

Ticket::Ticket(const std::string& pName, const std::string& sNumber, const std::string& date, const std::string& flightNo) 
        : passangerName(pName), seatNumber(sNumber), date(date), flightNo(flightNo) {}

std::string Ticket::getPassangerName() const {
    return passangerName;
}
std::string Ticket::getSeatNumber() const {
    return seatNumber;
}
std::string Ticket::getDate() const {
    return date;
}
std::string Ticket::getFlightNo() const {
    return flightNo;
}
void Ticket::setPassangerName(const std::string& pName) {
    this->passangerName = pName;
}
void Ticket::setSeatNumber(const std::string& sNumber) {
    this->seatNumber = sNumber;
}
void Ticket::setDate(const std::string& date) {
    this->date = date;
}
void Ticket::setFlightNo(const std::string& flightNo) {
    this->flightNo = flightNo;
}
void Ticket::printTicket() const {
    std::cout << "Passanger: " << passangerName << ", Seat: " << seatNumber << ", Date: " << date << ", Flight No: " << flightNo << "\n";
}
void Ticket::addPriceSegment(const SeatPriceSegment& priceSegments) {
    seatPriceSegments.push_back(priceSegments);
}

int Ticket::getSeatPrice(std::string& seatNo) const {
    std::string seatNumber;
    try {
        seatNumber = seatNo.substr(1);  // Assuming seatNo is like "A10"
    } catch (const std::invalid_argument&) {
        throw std::runtime_error("Invalid seat number format: " + seatNo);
    }
    for (const SeatPriceSegment& segment : seatPriceSegments) {
        if (segment.start <= std::stoi(seatNumber) && segment.end >= std::stoi(seatNumber)) {
            return segment.price;
        }
    }
    return -1;
}