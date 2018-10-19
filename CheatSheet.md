# CheatSheet for TDD-by-example 

**Repository:** https://github.com/MatthiasU/TDD-by-example.git

Open **Terminal**: Press `ctrl` + `alt` + `t`

**Change** into `TDD-by-example/fusion` **directory**:

    ~$ cd TDD-by-example/fusion

Open **Visual Studio Code** in current directory:

    ~/TDD-by-example/fusion$ code .

Create and change into **build directory**:

    ~/TDD-by-example/fusion$ mkdir build && cd build

Let CMake **create a build config**:

    ~/TDD-by-example/fusion/build$ cmake ..

**Build**:

    ~/TDD-by-example/fusion/build$ make

**Run tests**:

    ~/TDD-by-example/fusion/build$ ./FusionTest

**Write test expectations**:

    // Macros for testing equalities and inequalities.

    EXPECT_EQ(v1, v2); // Tests that v1 == v2
    EXPECT_NE(v1, v2); // Tests that v1 != v2
    EXPECT_LT(v1, v2); // Tests that v1 < v2
    EXPECT_LE(v1, v2); // Tests that v1 <= v2
    EXPECT_GT(v1, v2); // Tests that v1 > v2
    EXPECT_GE(v1, v2); // Tests that v1 >= v2

    // Macros for verifying boolean expressions:

    EXPECT_TRUE(boolean); 
    EXPECT_FALSE(boolean);

    // Macros for comparing floating-point numbers:
    EXPECT_FLOAT_EQ(val1, val2); // Tests that two float values are almost equal.
    EXPECT_DOUBLE_EQ(val1, val2); // Tests that two double values are almost equal.
    EXPECT_NEAR(v1, v2, abs_error); // Tests that v1 and v2 are within the given distance to each other.


It is also possible to **use Visual Studio Code commands to build and run tests**. To execute any command in Visual Studio code, hit `F1` and begin typing `CMake`. YOu will then be presented with useful commands. The following ones are especially useful:

* `CMake: Build`. Shortcut: `F7`
* `CMake: Execute the current target without a debugger` (Select the test executable to run the tests). Shortcut: `shift` + `F5`
* `CMake: Debug target`. Shortcut: `ctrl` + `F5`
