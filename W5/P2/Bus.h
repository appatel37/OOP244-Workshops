

#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
namespace sdds
{
    const double ticketPrice = 125.34;
    class Bus
    {
        int noofseats;
        int b_numPassengers;
        void setBroken();
        void drawBus(std::ostream &ostr, int seats, int psng) const;
    public:
    void setOutOfService();
        Bus(int m_noOfSeats = 20, int m_noOfPassengers = 0); 
        std::ostream &display(std::ostream &) const; 
        
        std::istream &read(std::istream &); 

        operator bool() const; 
        operator int() const;
        operator double() const;
        bool operator--();
        bool operator++(); 
        bool operator--(int);
        bool operator++(int);
        Bus &operator=(int value); 
        Bus &operator+=(int value);
        Bus &operator+=(Bus &right); // += operator 
        bool operator==(const Bus &right) const; // == operator 
    };
    int operator+(int left, const Bus &right);
    std::ostream &operator<<(std::ostream &ostr, const Bus &right);
    std::istream &operator>>(std::istream &istr, Bus &right);
}
#endif
