#include <stdexcept>
#include "Robot2D.h"

Robot2D::Robot2D() : x(0), y(0) {}
Robot2D::Robot2D(const Point& position) {

    if (position.size() != 2) {
        throw std::invalid_argument("Invalid dimension for 2D robot position");
    }

    x = position[0];
    y = position[1];
}

void Robot2D::setPosition(const Point& position) {

    if (position.size() != 2) {
        throw std::invalid_argument("Invalid dimension for 2D robot position");
    }

    x = position[0];
    y = position[1];
}

void Robot2D::setMotion(const Point& motion) {

    if (motion.size() != 2) {
        throw std::invalid_argument("Invalid dimension for 2D robot motion");
    }

    auto dx = motion[0];
    auto dy = motion[1];

    Matrix matrix_motion = {
        {1, 0, dx},
        {0, 1, dy},
        {0, 0, 1}
    };

    Point new_position(2);

    new_position[0] = matrix_motion[0][0] * x + matrix_motion[0][1] * y + matrix_motion[0][2];
    new_position[1] = matrix_motion[1][0] * x + matrix_motion[1][1] * y + matrix_motion[1][2];

    x = new_position[0];
    y = new_position[1];
}

Point Robot2D::getPosition() const {
    return { x, y };
}