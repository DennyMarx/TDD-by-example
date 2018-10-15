#include <GUnit.h>
#include <Fusion.hpp>

using namespace testing;

GTEST("Testing Time to Collision")
{
    NiceGMock<DistanceSensor> distance_sensor_1{};
    NiceGMock<DistanceSensor> distance_sensor_2{};
    NiceGMock<DistanceSensor> distance_sensor_3{};

    std::vector<DistanceSensor*> distance_sensors = {
        &distance_sensor_1.object(), &distance_sensor_2.object(), &distance_sensor_3.object()};

    SHOULD("Return TTC = 0.02s when closest distance measurement is 5.0m with velocity of 50 m/s")
    {
        std::function<double()> velocity_sensor = []() { return 10; };

        EXPECT_CALL(distance_sensor_1, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_2, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_3, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{5.0, 0.9}));

        auto fusion = Fusion(distance_sensors, velocity_sensor);
        EXPECT_EQ(0.5, fusion.calculateTimeToCollision());
    }

    SHOULD("Return TTC = 1.0s when closest plausible (certainty > 70 % ) distance measurement is "
           "10.0m with velocity of 50 m/s")
    {
        std::function<double()> velocity_sensor = []() { return 10; };

        EXPECT_CALL(distance_sensor_1, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{12.0, 0.9}));
        EXPECT_CALL(distance_sensor_2, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_3, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{5.0, 0.4}));

        auto fusion = Fusion(distance_sensors, velocity_sensor);
        EXPECT_EQ(1.0, fusion.calculateTimeToCollision());
    }
}
