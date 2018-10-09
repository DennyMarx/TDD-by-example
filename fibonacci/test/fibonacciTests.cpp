
#include <GUnit.h>
#include <fibonacci.hpp>

GTEST("fibonacci testing")
{
    EXPECT_EQ(fibonacci(1), 1);
    EXPECT_EQ(fibonacci(2), 1);
    EXPECT_EQ(fibonacci(3), 2);
    EXPECT_EQ(fibonacci(4), 3);
    EXPECT_EQ(fibonacci(21), 10946);
}
