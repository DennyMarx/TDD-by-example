#pragma once

#include <DistanceSensor.hpp>
#include <functional>
#include <memory>
#include <vector>

class Fusion
{
public:
    Fusion(const std::vector<DistanceSensor*>& distance_sensors,
           std::function<double()> velocity_sensor);

    double calculateTimeToCollision();

private:
    std::vector<DistanceSensor*> _distance_sensors;
    std::function<double()> _velocity_sensor;
};
