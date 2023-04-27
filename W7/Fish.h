

#ifndef SDDS_FISH_H
#define SDDS_FISH_H

#include "Pet.h"

namespace sdds
{
    class Fish : public Pet
    {
        const double COST_FEED = 0.10;
        const double COST_REVIVE = 0.50;
        const double COST_BASE = 2.00;
    public:
        Fish(const char* name, int age = 0);
        void feed();
        void reSpawn();
       
        void operator++ (int num);
        
        Fish& operator=(const Fish& rhs);
    };
    std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif