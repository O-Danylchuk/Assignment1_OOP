#include <vector>
#include <string>
#include <unordered_map>
#include "ticket.h"
#include "airplane.h"

#pragma once

class AirplaneTicketMGR 
{ 
private:
    std::vector<Airplane> allAirplanes;
    std::vector<Ticket> allTickets;
    std::unordered_map<int, Ticket> bookedTicketsById; // For managing bookings by confirmation ID
    std::unordered_map<std::string, std::unordered_map<std::string, int>> userBookings; // For tracking bookings by username

public:
    AirplaneTicketMGR() = default;
    ~AirplaneTicketMGR() = default;
    void addAirplane(Airplane& airplane);
    void addTicket(Ticket& ticket);
    const int generateConfirmationID() const;

    std::string checkSeatAvailability(const std::string& date, const std::string& flightNo); // returns list of free seats
    int bookSeat(const std::string& date, const std::string& flightNo, const std::string& seat, const std::string& username);// returns confirmation ID
    std::string returnSeat(const int& confirmationID); // returns confirmation message with price of the seat and username
    std::string viewBookingInfoID(const int& confirmationID); // show Flight number, date, seat, and the ticket’s price
    std::string viewBookingInfoUserName(const std::string& username); //For each flight that user booked: flight number, date, seat, and the ticket’s price
    std::string viewBookingInfoDateFlightNo(const std::string& date, const std::string& fNo); //For the chosen flight: seat, username, price
};