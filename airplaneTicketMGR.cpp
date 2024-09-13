#include "./headers/airplaneTicketMGR.h"
#include <iostream>
#include <sstream>

void AirplaneTicketMGR::addAirplane(Airplane& airplane) {
    allAirplanes.push_back(airplane);
}
void AirplaneTicketMGR::addTicket(Ticket& ticket) {
    allTickets.push_back(ticket);
}

std::string AirplaneTicketMGR::checkSeatAvailability(const std::string& date, const std::string& flightNo)
{
    std::stringstream result;
    for (const Airplane& airplane : allAirplanes) {
        if (airplane.hasFlight(flightNo)) {
            airplane.printAvailableSeats();
            return result.str();
        }
    }
    return "Flight not found.";
}


int AirplaneTicketMGR::bookSeat(const std::string& date, const std::string& flightNo, const std::string& seat, const std::string& username)
{
    for (Airplane& airplane : allAirplanes) {
        if (airplane.hasFlight(flightNo) && airplane.isSeatAvailable(seat)) {
            if (airplane.bookSeat(seat)) {
                int confirmationID = generateConfirmationID();
                for (Ticket& ticket : allTickets) {
                    if (ticket.getFlightNo() == flightNo && ticket.getDate() == date) {
                        ticket.setSeatNumber(seat);
                        ticket.setPassangerName(username);
                        bookedTicketsById[confirmationID] = ticket;
                        userBookings[username][flightNo] = confirmationID;
                    }
                }
                return confirmationID;
            } else {
                throw std::runtime_error("Failed to book seat: Seat is already booked.");
            }
        }
    }
    throw std::runtime_error("Flight not found or seat not available.");
}



std::string AirplaneTicketMGR::returnSeat(const int& confirmationID)
{
    if (bookedTicketsById.find(confirmationID) != bookedTicketsById.end()) {
        Ticket& ticket = bookedTicketsById[confirmationID];
        std::string seatNo = ticket.getSeatNumber();
        for (auto& airplane : allAirplanes) {
            if (airplane.hasFlight(ticket.getFlightNo()) && airplane.returnSeat(seatNo)) {
                int price = ticket.getSeatPrice(seatNo);
                std::stringstream response;
                response << "Confirmed " << price << "$ refund for: " << ticket.getPassangerName();
                bookedTicketsById.erase(confirmationID);
                airplane.unbookSeat(seatNo);
                return response.str();
            }
        }
        throw std::runtime_error("Flight not found or seat cannot be returned.");
    }
    throw std::runtime_error("Invalid confirmation ID.");
}



std::string AirplaneTicketMGR::viewBookingInfoID(const int& confirmationID)
{
    if (bookedTicketsById.find(confirmationID) != bookedTicketsById.end()) {
        const Ticket& ticket = bookedTicketsById.at(confirmationID);
        std::stringstream info;
        std::string seatNo = ticket.getSeatNumber();
        info << "Flight No: " << ticket.getFlightNo()
                << ", Date: " << ticket.getDate()
                << ", Seat: " << seatNo
                << ", Price: " << ticket.getSeatPrice(seatNo); 
        return info.str();
    }
    return "Invalid confirmation ID.";
}



std::string AirplaneTicketMGR::viewBookingInfoUserName(const std::string& username){
    auto userInfo = userBookings.find(username);
    if (userInfo != userBookings.end()) {
        const auto& bookings = userInfo->second;
        std::string result;
        for (const auto& booking : bookings) {
            int ID = booking.second;
            result += viewBookingInfoID(ID) + "\n"; // Append each booking info with a newline.
        }
        return result.empty() ? "No bookings found." : result; // Return all collected booking information.
    }
    return "Invalid confirmation ID.";
}

std::string AirplaneTicketMGR::viewBookingInfoDateFlightNo(const std::string& date, const std::string& fNo) {
    std::ostringstream resultStream;
    bool found = false;

    for (const Ticket& ticket : allTickets) {
        if (ticket.getDate() == date && ticket.getFlightNo() == fNo) {
            std::string seatNo = ticket.getSeatNumber();
            resultStream << "Seat: " << seatNo
                         << ", Username: " << ticket.getPassangerName()
                         << ", Price: $" << ticket.getSeatPrice(seatNo) << "\n";
            found = true;
        }
    }

    if (!found) {
        return "No bookings found for this flight on the specified date.";
    }

    return resultStream.str();
}

const int AirplaneTicketMGR::generateConfirmationID() const {
    return rand();
}