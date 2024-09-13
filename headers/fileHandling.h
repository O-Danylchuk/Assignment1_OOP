#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "airplaneTicketMGR.h"

class FileHandler {
public:
    FileHandler(const std::string& filename);
    ~FileHandler();
    void readFromFile();
    AirplaneTicketMGR parseData();
    void addLine(const std::string& line);

private:
    int fd = -1;
    std::string m_filename;
    std::vector<std::string> lines;
};