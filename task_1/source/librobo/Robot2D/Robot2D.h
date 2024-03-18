#pragma once

#include "../IRobot.h"

class Robot2D : public IRobot {
private:
    double x, y;

public:
    Robot2D();
    Robot2D(const Point& position);

    void setPosition(const Point& position) override;
    void setMotion(const Point& motion) override;
    Point getPosition() const override;
};