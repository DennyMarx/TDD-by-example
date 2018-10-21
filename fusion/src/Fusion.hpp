#ifndef FUSION_H
#define FUSION_H

#include "DistanceSensor.hpp"
#include <functional>
#include <memory>
#include <vector>

class Fusion
{
public:
    // constants
    const static double kThresholdCertainy;

    // c'tor
    Fusion(const std::vector<DistanceSensor*>& distance_sensors,
           std::function<double()> velocity_sensor);

    // method to calculate the time to collision
    double calculateTimeToCollision();

private:
    std::vector<DistanceSensor*> _distance_sensors;
    std::function<double()> _velocity_sensor;
};

#endif // FUSION_H
