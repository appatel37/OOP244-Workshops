

#ifndef SDDS_EGGCARTON_H__
#define SDDS_EGGCARTON_H__

#include <iostream>
using namespace std;

const int RegularEggWieght = 50;
const int JumboEggWieght = 75;

namespace sdds{
    class EggCarton {
        int m_size;
        int m_egs;
        bool jmboo;

        
        void setBroken();
        ostream& displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const;
    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        operator bool() const;
        operator int() const;
        operator double() const;
        EggCarton& operator=(int value);


        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);
        bool operator==(const EggCarton& right) const;
        ostream& display(ostream& ostr = cout) const;
        istream& read(istream& istr = cin);
    };
    int operator+(int left, const EggCarton& right);
    ostream& operator<<(ostream& ostr, const EggCarton& right);
    istream& operator>>(istream& istr, EggCarton& right);
}

#endif