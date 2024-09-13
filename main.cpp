#include "./headers/airplane.h"
#include "./headers/ticket.h"
#include <iostream>
#include <sstream>
#include "./headers/fileHandling.h"
#include "./headers/airplaneTicketMGR.h"

void processInput(AirplaneTicketMGR& mgr, const std::string& command);

int main()
{
    FileHandler fileHandler("./fileToReadFrom.txt");
    AirplaneTicketMGR mgr = fileHandler.parseData();
    
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }

        processInput(mgr, command);
    }
    
    return 0;
}

void processInput(AirplaneTicketMGR& mgr, const std::string& command) {
    std::stringstream ss(command);
    std::string cmd;
    ss >> cmd;
    if (cmd == "check") {
        std::string date, flightNo;
        ss >> date >> flightNo;
        mgr.checkSeatAvailability(date, flightNo);
    } else if (cmd == "book") {
        std::string date, flightNo, seat, username;
        ss >> date >> flightNo >> seat >> username;
        std::cout << "Seat: " << seat << " is booked succesfully, ID: " << mgr.bookSeat(date, flightNo, seat, username) << std::endl;
    } else if (cmd == "return") {
        int confirmationID;
        ss >> confirmationID;
        std::cout << mgr.returnSeat(confirmationID) << std::endl;
    } else if (cmd == "viewID") {
        int confirmationID;
        ss >> confirmationID;
        std::cout << mgr.viewBookingInfoID(confirmationID) << std::endl;
    } else if (cmd == "viewUser") {
        std::string username;
        ss >> username;
        std::cout << mgr.viewBookingInfoUserName(username) << std::endl;
    } else if (cmd == "viewFlight") {
        std::string date, flightNo;
        ss >> date >> flightNo;
        std::cout << mgr.viewBookingInfoDateFlightNo(date, flightNo) << std::endl;
    } 
    else {
        std::cout << "Invalid command. Type 'help' for a list of commands.\n";
    }
}
