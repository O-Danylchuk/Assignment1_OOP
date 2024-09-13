#include "./headers/fileHandling.h"
#include "./headers/ticket.h"
#include "./headers/airplaneTicketMGR.h"
#include <sstream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iostream>


FileHandler::FileHandler(const std::string& filePath) : m_filename(filePath) {
    readFromFile();
}


FileHandler::~FileHandler() {
    if (fd >= 0)
    close(fd);
}

void FileHandler::addLine(const std::string& line) {
    lines.push_back(line);
}

void FileHandler::readFromFile() {
    int fd = open(m_filename.c_str(), O_RDONLY);
    if (fd < 0) {
        throw std::runtime_error("Failed to open file");
    }

    const size_t bufferSize = 1024;
    char buffer[bufferSize];
    ssize_t bytesRead;
    std::string line;

    while ((bytesRead = read(fd, buffer, bufferSize - 1)) > 0) {
        buffer[bytesRead] = '\0';
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {
                addLine(line);
                line.clear();
            } else {
                line += buffer[i];
            }
        }
    }

    if (bytesRead < 0) {
        close(fd);
        throw std::runtime_error("Error reading from file");
    }

    if (!line.empty()) {
        addLine(line);
    }

    
}

AirplaneTicketMGR FileHandler::parseData() {
    AirplaneTicketMGR mgr;

    for (const std::string& line : lines) {
        std::stringstream ss(line);
        Ticket ticket;
        std::string date, flightNo;
        int seatsInRow;
        ss >> date >> flightNo >> seatsInRow;
        ticket.setDate(date);
        ticket.setFlightNo(flightNo);

        std::string segment;
        std::string price;
        int lastSeat = 0;

        while (ss >> segment >> price) {
            size_t dashPos = segment.find('-');

            SeatPriceSegment priceSegment;
            priceSegment.start = std::stoi(segment.substr(0, dashPos));
            priceSegment.end = std::stoi(segment.substr(dashPos + 1));
            priceSegment.price = std::stoi(price.substr(0, price.size() - 1));
            ticket.addPriceSegment(priceSegment);

            lastSeat = priceSegment.end;
        }

        mgr.addTicket(ticket);
        Airplane airplane(seatsInRow, lastSeat);
        mgr.addAirplane(airplane);
    }

    return mgr;
}
