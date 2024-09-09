#include <vector>
#include <tuple>
#include <string>

class CLI 
{
public:
    std::vector<std::tuple<std::string, std::string>&> checkAvailable(const std::string dateOfFlight, const std::string flightNo) const;
    std::string& book(const std::string dateOfFlight, const std::string flightNo, std::string place, std::string username) const;

private:
    std::vector<std::tuple<std::string, int>&> bookedSeat_ID; 

};