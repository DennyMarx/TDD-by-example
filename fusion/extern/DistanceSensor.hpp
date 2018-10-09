#pragma once

class DistanceSensor {
public:
    struct DistanceMeasurement {
        double distance;
        double certainty;
    };

    virtual ~DistanceSensor ();
    virtual DistanceMeasurement getDistanceToClosestObject() =0;
};
