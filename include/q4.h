#ifndef Q4_H
#define Q4_H

namespace q4 {

struct Vector2D {
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

inline q4::Vector2D kalman_filter(std::vector<Sensor> sensors)
{
}

}

#endif // Q4_H