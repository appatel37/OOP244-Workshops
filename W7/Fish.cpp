
#include "Fish.h"
#include "Pet.h"
#include <bits/stdc++.h>
using namespace std;
namespace sdds{
    
    Fish::Fish(const char* name, int age):Pet(name,age,0){
    }
     std::ostream& operator<<(std::ostream& os, Fish& fish){
        os<<"** Generic Fish **"<<endl;
        fish.outputData(os);
        return os;
    }
    Fish& Fish::operator=(const Fish& rhs){
        if(this!=&rhs){
            Pet::operator=(rhs);
            Pet::m_totalCharges+=COST_BASE;
        }
        return *this;
    }

     void Fish::reSpawn(){
        //while(Pet::m_healthLvl<1)
        //for(int i=0;i<Pet::m_healthLvl;i++)
        Pet::reSpawn();
        Pet::m_totalCharges+=COST_REVIVE;
    }

      void Fish::operator++(int num){
        if(Pet::isAlive()){
            double healthDelta = 0;
            healthDelta += 0.20 * (getFeeds() - 1);
            Pet::applyHealthDelta(healthDelta);
            Pet::operator++(num);
        }
    }
    
    void Fish::feed(){
        Pet::feed();
        if(Pet::isAlive()){
            Pet::m_totalCharges+=COST_FEED;
        }
    }
   
  
 

}