#pragma once

class DistanceSensor {
public:
    struct DistanceMeasurement {
        double distance;
        double certainty;
    };

    virtual ~DistanceSensor () = default;
    virtual DistanceMeasurement getDistanceToClosestObject() =0;
};
