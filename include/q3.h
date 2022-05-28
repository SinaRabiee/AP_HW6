#ifndef Q3_H
#define Q3_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream>
#include <string>

namespace q3 {

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
// herereeeeeeeeeeeeeeeeeeeeeee

inline std::priority_queue<Flight, std::vector<Flight>, decltype(comp)> gather_flights(std::string filename)
{
    // reading file
    std::vector<Flight> F {};
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();

    std::regex pattern(R"((\d-\sflight_number:)(\w+)(\s-\s)(duration:)(\d+)(\w)(\d*)(\w*)(\s-\sconnections:\d)(\s-\sconnection_times:)(\d)(\w)(\d*)(\w*)(,*)(\d*)(\w*)(\d*)(\w*)(,*)(\d*)(\w*)(\d*)(\w*)(\s-\sprice:)(\d*))"); // using raw string
    std::smatch match;
    while (std::regex_search(txt, match, pattern)) {
        std::string Fnum { match[2].str() };
        std::istringstream isDur { match[3].str() };
        std::istringstream isCon { match[6].str() };
        std::istringstream isCont { match[7].str() };
        std::istringstream isPr { match[8].str() };
        size_t Dur {};
        size_t Con {};
        size_t Cont {};
        size_t Pr {};
        isDur >> Dur;
        isCon >> Con;
        isCont >> Cont;
        isPr >> Pr;
        F.push_back(Flight(Fnum, Dur, Con, Cont, Pr));
        txt = match.suffix().str();
    }
    auto comp {
        [](const Flight& F1, const Flight& F2) { return (F1.duration) + (F1.connection_times) + 3 * (F1.price) > (F2.duration) + (F2.connection_times) + 3 * (F2.price); }
    };
    std::priority_queue<Flight, std::vector<Flight>, decltype(comp)> F_new { comp };
    for (auto& i : F)
        F_new.push(i);
    return F_new;
}
}

#endif // Q3_H