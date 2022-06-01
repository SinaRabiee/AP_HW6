#ifndef Q2_H
#define Q2_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

namespace q2 {

struct Patient {
    Patient(std::string _name, size_t _age, size_t _smokes, size_t _area_q, size_t _alkhol)
        : name { _name }
        , age { _age }
        , smokes { _smokes }
        , area_q { _area_q }
        , alkhol { _alkhol }
    {
    }

    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};

inline std::vector<Patient> read_file(std::string filename)
{
    std::vector<Patient> P {};
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string txt = buffer.str();

    std::regex pattern(R"((\w+)(\s*),(\w+)(\s*),(\d+),(\d+),(\d+),(\d+))"); // using raw string
    std::smatch match;
    while (std::regex_search(txt, match, pattern)) {
        std::string Fname { match[1].str() };
        std::string Lname { match[3].str() };
        std::istringstream isag { match[5].str() };
        std::istringstream issm { match[6].str() };
        std::istringstream isar { match[7].str() };
        std::istringstream isal { match[8].str() };
        size_t ag {};
        size_t sm {};
        size_t ar {};
        size_t al {};
        isag >> ag;
        issm >> sm;
        isar >> ar;
        isal >> al;
        P.push_back(Patient(Fname + " " + Lname, ag, sm, ar, al));
        txt = match.suffix().str();
    }
    return P;
}

inline bool comp(const Patient& P1, const Patient& P2)
{
    size_t x { 3 * (P1.age) + 5 * (P1.smokes) + 2 * (P1.area_q) + 4 * (P1.alkhol) };
    size_t y { 3 * (P2.age) + 5 * (P2.smokes) + 2 * (P2.area_q) + 4 * (P2.alkhol) };
    return x > y;
}

inline void sort(std::vector<Patient>& P)
{
    std::sort(P.begin(), P.end(), comp);
}
}

#endif // Q2_H