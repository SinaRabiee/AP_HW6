#ifndef Q1_H
#define Q1_H

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

namespace q1 {

template <typename T, typename FUNC>
T gradient_descent(T ivalue, T step, std::function<double(double)> func)
{
    double x { ivalue };
    double min {};
    while (true) {
        double p_pre { func(x - step) };
        double p_now { func(x) };
        double p_nex { func(x + step) };
        min = std::min({ p_pre, p_now, p_nex });
        if (min == p_pre)
            x -= step;
        else if (min == p_nex)
            x += step;
        else
            return x;
    }
}

// std::finction
inline double gradient_descent(double ivalue, double step, std::function<double(double)> func)
{
    double x { ivalue };
    double min {};
    while (true) {
        double p_pre { func(x - step) };
        double p_now { func(x) };
        double p_nex { func(x + step) };
        min = std::min({ p_pre, p_now, p_nex });
        if (min == p_pre)
            x -= step;
        else if (min == p_nex)
            x += step;
        else
            return x;
    }
}
}

#endif // Q1_H
