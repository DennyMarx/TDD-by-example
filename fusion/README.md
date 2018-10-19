# TDD by example - Fusion

Suppose your boss wants you to develop a software component that calculates the TTC (time to collision) of a car based on a couple of distance sensors and a velocity sensor. The sensors are supplied by a third-party supplier, you only have the interfaces of these sensors. You find them in `./extern`. As you can see, the velocity sensor is a retro-C-style interface whereas distance sensors are conveniently accessible via C++-interface.

The TTC is defined by the following formula: 

    TTC = distance_of_closest_object / velocity

Be a good developer and fill this directory with code in a test-driven way. Enjoy!