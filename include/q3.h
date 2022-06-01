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
struct comp {
    bool operator()(const Flight& F1, const Flight& F2)
    {
        return (F1.duration) + (F1.connection_times) + 3 * (F1.price) > (F2.duration) + (F2.connection_times) + 3 * (F2.price);
    }
};

inline std::priority_queue<Flight, std::vector<Flight>, comp> gather_flights(std::string filename)
{
    // reading file
    std::priority_queue<Flight, std::vector<Flight>, comp> F {};
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();

    std::regex pattern(R"((\d-\s)(flight_number)(:)(\w+)(\s-\s)(duration:)(\d+)(\w)(\d*)(\w*)(\s-\sconnections:)(\d)(\s-\sconnection_times:)(\d)(\w)(\d*)(\w*)(,*)(\d*)(h*)(\d*)(m*)(,*)(\d*)(h*)(\d*)(m*)(\s-\sprice:)(\d*))"); // using raw string
    std::smatch match;
    while (std::regex_search(txt, match, pattern)) {
        std::string Fnum { match[4].str() };
        std::istringstream isDurh { match[7].str() };
        std::istringstream isDurm { match[9].str() };
        std::istringstream isCon { match[12].str() };
        std::istringstream isCont1h { match[14].str() };
        std::istringstream isCont1m { match[16].str() };
        std::istringstream isCont2h { match[19].str() };
        std::istringstream isCont2m { match[21].str() };
        std::istringstream isCont3h { match[24].str() };
        std::istringstream isCont3m { match[26].str() };
        std::istringstream isPr { match[29].str() };
        size_t Durh {};
        size_t Durm {};
        size_t Con {};
        size_t Cont1h {};
        size_t Cont1m {};
        size_t Cont2h {};
        size_t Cont2m {};
        size_t Cont3h {};
        size_t Cont3m {};
        size_t Pr {};
        isDurh >> Durh;
        isDurm >> Durm;
        isCon >> Con;
        isCont1h >> Cont1h;
        isCont1m >> Cont1m;
        isCont2h >> Cont2h;
        isCont2m >> Cont2m;
        isCont3h >> Cont3h;
        isCont3m >> Cont3m;
        isPr >> Pr;
        F.push(Flight(Fnum, (Durh * 60) + Durm, Con, (Cont1h + Cont2h + Cont3h) * 60 + Cont1m + Cont2m + Cont3m, Pr));
        txt = match.suffix().str();
    }
    return F;
}
}

#endif // Q3_H