//
#include "die.h"
#include <cstdlib>

void Die::roll()
{
    roll_value = rand() % sides + 1;
}
