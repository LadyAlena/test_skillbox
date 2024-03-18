#include <stdexcept>
#include "Robot3D.h"

Robot3D::Robot3D() : x(0), y(0), z(0) {}
Robot3D::Robot3D(const Point& position) {

    if (position.size() != 3) {
        throw std::invalid_argument("Invalid dimension for 3D robot position");
    }

    x = position[0];
    y = position[1];
    z = position[2];
}

void Robot3D::setPosition(const Point& position) {

    if (position.size() != 3) {
        throw std::invalid_argument("Invalid dimension for 3D robot position");
    }

    x = position[0];
    y = position[1];
    z = position[2];
}

void Robot3D::setMotion(const Point& motion) {

    if (motion.size() != 3) {
        throw std::invalid_argument("Invalid dimension for 3D robot motion");
    }

    auto dx = motion[0];
    auto dy = motion[1];
    auto dz = motion[2];

    Matrix matrix_motion = {
        {1, 0, 0, dx},
        {0, 1, 0, dy},
        {0, 0, 1, dz},
        {0, 0, 0, 1}
    };

    Point new_position(3);

    new_position[0] = matrix_motion[0][0] * x + matrix_motion[0][1] * y + matrix_motion[0][2] * z + matrix_motion[0][3];
    new_position[1] = matrix_motion[1][0] * x + matrix_motion[1][1] * y + matrix_motion[1][2] * z + matrix_motion[1][3];
    new_position[2] = matrix_motion[2][0] * x + matrix_motion[2][1] * y + matrix_motion[2][2] * z + matrix_motion[2][3];

    x = new_position[0];
    y = new_position[1];
    z = new_position[2];
}

Point Robot3D::getPosition() const {
    return { x, y, z };
}