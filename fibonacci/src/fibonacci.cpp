
#include <fibonacci.hpp>

int fibonacci(int input)
{
    if (input > 2)
    {
        return fibonacci(input - 1) + fibonacci(input - 2);
    }
    else
    {
        return 1;
    }
}
