//
#include<random>
#include<iostream>
using std::cout;

#ifndef DIE_H
#define DIE_H

class Die
{
public:
    Die(){};
    Die(int num){roll_value = num;}
    void roll();
    int rolled_value() const{return roll_value;}

private:
    int roll_value;
    int sides{6};

    
};

#endif