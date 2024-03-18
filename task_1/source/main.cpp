#include <iostream>

#include "../source/librobo/IRobot.h"
#include "../source/librobo/Robot2D/Robot2D.h"
#include "../source/librobo/Robot3D/Robot3D.h"

int main() {
    try {
        Robot2D robot2d;
        robot2d.setPosition({1.0, 2.0});
        
        std::cout << "Initial position of Robot2D: ";
        for (const auto& coord : robot2d.getPosition()) {
            std::cout << coord << " ";
        }
        std::cout << "\n";

        Point motion2d = {2.0, 103.0};
        robot2d.setMotion(motion2d);
        
        std::cout << "New position of Robot2D after motion: ";
        for (const auto& coord : robot2d.getPosition()) {
            std::cout << coord << " ";
        }
        std::cout << "\n";

        Robot3D robot3d;
        robot3d.setPosition({1.0, 2.0, 3.0});
        
        std::cout << "Initial position of Robot3D: ";
        for (const auto& coord : robot3d.getPosition()) {
            std::cout << coord << " ";
        }
        std::cout << "\n";

        Point motion3d = {2.0, 3.0, -4.0};
        robot3d.setMotion(motion3d);
        
        std::cout << "New position of Robot3D after motion: ";
        for (const auto& coord : robot3d.getPosition()) {
            std::cout << coord << " ";
        }
        std::cout << "\n";
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}