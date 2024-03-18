#pragma once

#include "../IRobot.h"

class Robot3D : public IRobot {
private:
    double x, y, z;

public:
    Robot3D();
    Robot3D(const Point& position);

    void setPosition(const Point& position) override;
    void setMotion(const Point& motion) override;
    Point getPosition() const override;
};