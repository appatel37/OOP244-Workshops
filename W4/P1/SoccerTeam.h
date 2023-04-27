

#ifndef SDDS_SOCCERTEAM_H__
#define SDDS_SOCCERTEAM_H__

#include <bits/stdc++.h>
using namespace std;

namespace sdds{
    const int MAX_FOUL = 4;
    struct SoccerTeam{
        public:

        char m_teamName[41];
        int m_noFouls;
        double m_fines;
        int m_golas;
        
        void setTeam(const SoccerTeam& team);
        void setName(const char* tname);

        
        void setFine(double fines,int foul);
        void setEmpty();
        // void setGolas(int golas){
        //     m_golas = golas;

        // }
        
        
        
        bool isEmpty() const; // returns true if the object is in a safe empty state
        void calFines(); // adds 20% to the fines 
        int fouls() const; // returns the number of fouls
        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);
        std::ostream& display()const;
    };
}


#endif