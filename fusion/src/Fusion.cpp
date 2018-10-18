
#include <Fusion.hpp>
#include <algorithm>

Fusion::Fusion(const std::vector<DistanceSensor*>& distance_sensors,
               std::function<double()> velocity_sensor)
    : _distance_sensors(distance_sensors), _velocity_sensor(velocity_sensor)
{
}

double Fusion::calculateTimeToCollision()
{
    auto velocity = _velocity_sensor();
    std::vector<DistanceSensor::DistanceMeasurement> distance_measurements;
    distance_measurements.reserve(_distance_sensors.size());

    for (auto sensor : _distance_sensors)
    {
        auto measurement = sensor->getDistanceToClosestObject();
        if (measurement.certainty > 0.7)
        {
            distance_measurements.push_back(measurement);
        }
    }

    std::sort(distance_measurements.begin(),
              distance_measurements.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.distance < rhs.distance; });
    auto min_distance = distance_measurements.front().distance;
    auto time_to_collision = min_distance / velocity;
    return time_to_collision;
}
