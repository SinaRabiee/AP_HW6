#ifndef Q1_H
#define Q1_H

#include <cmath>
#include <functional>
#include <iostream>

namespace q1 {

// template <typename T>
// inline double gradient_descent(double ivalue, double step, T func)
inline double gradient_descent(double ivalue, double step, std::function<double(double)> func)
{
    size_t i {};
    while (true) {
        double x { func(ivalue + i * step) };
        double y { func(ivalue + (i + 1) * step) };
        if (x < y) {
            return x;
            break;
        }
        i++;
    }
}

}

#endif // Q1_H
