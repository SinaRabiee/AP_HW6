#include <gtest/gtest.h>
#include <iostream>

#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"

struct Flight {
    Flight(std::string _flight_number, size_t _duration, size_t _connections, size_t _connection_times, size_t _price)
        : flight_number { _flight_number }
        , duration { _duration }
        , connections { _connections }
        , connection_times { _connection_times }
        , price { _price }
    {
    }
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};

int main(int argc, char** argv)
{
    if (0) // make false to run unit-tests
    {
        std::vector<Flight> F {};
        std::ifstream file("flights.txt");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string txt = buffer.str();

        std::regex pattern(R"((\d-\s)(flight_number)(:)(\w+)(\s-\s)(duration:)(\d+)(\w)(\d*)(\w*)(\s-\sconnections:)(\d)(\s-\sconnection_times:)(\d)(\w)(\d*)(\w*)(,*)(\d*)(h*)(\d*)(m*)(,*)(\d*)(h*)(\d*)(m*)(\s-\sprice:)(\d*))"); // using raw string
        std::smatch match;
        while (std::regex_search(txt, match, pattern)) {
            for (size_t i {}; i < 30; i++)
                std::cout << i << " : " << match[i] << std::endl;
            txt = match.suffix().str();
        }
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}