
#ifndef SDDS_PACAGE_H_
#define SDDS_PACKAGE_H_

#define filename_r "Filtered_Dataset.csv"

namespace sdds
{

    struct Customers
    {
        char *Package_Name;
        char dayofweek;
        
        int user_id;
        int dayofyear;
        int Fwifitime;
        int Fctime;
        
        double timeinhours;
        
        
    };

    int loadTraces();
    int loadTraces(Customers &user); 
    void grouptTraces(); 
    void display();
    void deallocateMemory();

}
#endif