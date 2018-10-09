#pragma once

#include <DistanceSensor.hpp>
#include <vector>
#include <functional>
#include <memory>

class Fusion {
public:
    Fusion(const std::vector<DistanceSensor*>& distance_sensors, std::function<double()> velocity_sensor);
    
    double calculateTimeToCollision();
    
private:
    std::vector<DistanceSensor*> _distance_sensors;
    std::function<double()> _velocity_sensor;
};
