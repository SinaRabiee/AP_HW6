#ifndef Q1_H
#define Q1_H

#include <cmath>
#include <functional>
#include <iostream>
namespace q1 {

using Func = double (*)(const double);

double gradient_descent(double ivalue, double step, Func func)
{
    for (size_t i {};; i++) {
        double x { func(ivalue + i * step) };
        double y { func(ivalue + (i + 1) * step) };
        }
    std::cout << "Gradient Descent" << std::endl;
    return 2.0;
}
}

#endif // Q1_H
