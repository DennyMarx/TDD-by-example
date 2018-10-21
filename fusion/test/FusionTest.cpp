#include <GUnit.h>
#include "Fusion.hpp"
#include <limits>

using namespace testing;

GTEST("Testing Time to Collision")
{
    // test setup
    NiceGMock<DistanceSensor> distance_sensor_1{};
    NiceGMock<DistanceSensor> distance_sensor_2{};
    NiceGMock<DistanceSensor> distance_sensor_3{};

    std::vector<DistanceSensor*> distance_sensors = {
        &distance_sensor_1.object(), &distance_sensor_2.object(), &distance_sensor_3.object()};

    SHOULD("Return TTC = 0.5s when closest distance measurement is 5.0m with velocity of 50 m/s")
    {
        // test expectations
        std::function<double()> velocity_sensor = []() { return 10; };

        EXPECT_CALL(distance_sensor_1, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_2, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_3, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{5.0, 0.9}));

        // test execution
        auto fusion = Fusion(distance_sensors, velocity_sensor);
        EXPECT_EQ(0.5, fusion.calculateTimeToCollision());
    }

    SHOULD("Return TTC = 1.0s when closest plausible (certainty > 70 % ) distance measurement is "
           "10.0m with velocity of 50 m/s")
    {
        EXPECT_FALSE(true);
    }

    SHOULD("Return ??? when velocity < 0")
    {
        EXPECT_FALSE(true);
    }
}

GTEST("Testing TTC is car is standing still")
{
    // test setup
    NiceGMock<DistanceSensor> distance_sensor_1{};
    NiceGMock<DistanceSensor> distance_sensor_2{};
    NiceGMock<DistanceSensor> distance_sensor_3{};

    std::vector<DistanceSensor*> distance_sensors = {
        &distance_sensor_1.object(), &distance_sensor_2.object(), &distance_sensor_3.object()};

    SHOULD("Return TTC = double.max() if velocity is 0")
    {
        // test expectations
        std::function<double()> velocity_sensor = []() { return 0; };

        EXPECT_CALL(distance_sensor_1, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_2, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{10.0, 0.9}));
        EXPECT_CALL(distance_sensor_3, (getDistanceToClosestObject)())
            .WillOnce(Return(DistanceSensor::DistanceMeasurement{5.0, 0.9}));

        // test execution
        auto fusion = Fusion(distance_sensors, velocity_sensor);
        double result = 0;
        EXPECT_NO_THROW(result = fusion.calculateTimeToCollision());
        EXPECT_EQ(result, std::numeric_limits<int>::min());
    }
}

GTEST("Testing null pointer robustness")
{
    // test setup
    std::vector<DistanceSensor*> distance_sensors;

    for (uint8_t i = 0U; i < 3; i++)
    {
        distance_sensors.push_back(nullptr);
    }

    auto fusion = Fusion(distance_sensors, nullptr);

    // test expectations & test execution
    EXPECT_NO_THROW(fusion.calculateTimeToCollision());
}
