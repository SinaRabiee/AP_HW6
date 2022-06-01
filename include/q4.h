#ifndef Q4_H
#define Q4_H

#include <numeric>

namespace q4 {

struct Vector2D {
    Vector2D() = default;
    Vector2D(double _x, double _y)
        : x(_x)
        , y(_y) {};

    double x {};
    double y {};
};

struct Sensor {
    Sensor(q4::Vector2D _pos, double _accuracy)
        : pos(_pos)
        , accuracy(_accuracy) {};

    Vector2D pos;
    double accuracy;
};

struct mulx {
    double operator()(double result, Sensor& s)
    {
        return result + s.pos.x * s.accuracy;
    }
};

struct muly {
    double operator()(double result, Sensor& s)
    {
        return result + s.pos.y * s.accuracy;
    }
};

inline q4::Vector2D kalman_filter(std::vector<Sensor> sensors)
{
    double size { std::accumulate(sensors.begin(), sensors.end(), 0.0, [](double result, Sensor& s) { return result + s.accuracy; }) };
    double weighted_sum_x = std::accumulate(sensors.begin(), sensors.end(), 0.0, mulx()) / size;
    double weighted_sum_y = std::accumulate(sensors.begin(), sensors.end(), 0.0, muly()) / size;
    q4::Vector2D v(weighted_sum_x, weighted_sum_y);
    return v;
}
}

#endif // Q4_H