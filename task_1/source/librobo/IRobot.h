#pragma once

#include <vector>

using Point = std::vector<double>;
using Matrix = std::vector<std::vector<double>>;

class IRobot {
public:
    virtual void setPosition(const Point& position) = 0;
    virtual void setMotion(const Point& motion) = 0;
    virtual Point getPosition() const = 0;
    virtual ~IRobot() {};
};