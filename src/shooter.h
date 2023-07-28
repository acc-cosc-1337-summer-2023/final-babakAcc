//
#include "die.h"
#include "roll.h"
#include <iostream>
#include <vector>

using std::ostream;

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter 
{
    public:
        Roll* throw_die(Die& die1, Die& die2);
        friend ostream& operator<<(ostream& os, const Shooter& shooter);
        ~Shooter();

    private:
        std::vector<Roll*> rolls;

};

#endif