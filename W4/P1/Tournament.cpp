

#include "SoccerTeam.h"
#include "Tournament.h"
#include <bits/stdc++.h>
using namespace std;

namespace sdds{
   // static int counter = 0;
    void Tournament::setTournament(const char* name, int noOfteam,const SoccerTeam* soccer){
        if(name != nullptr && name[0] != '\0' && noOfteam > 0 && soccer != nullptr){
            m_num = noOfteam;
            m_name = new char[strlen(name)+1];
            strcpy(m_name,name);
            m_soccer = new SoccerTeam[m_num];
            for(int i = 0; i < m_num; i++){
                m_soccer[i].setTeam(soccer[i]);
            }
        }else{
            setEmpty();
        }
    }
Tournament::Tournament(){
        setEmpty();
    }
    Tournament::~Tournament(){
        delete[] m_name;
        delete[] m_soccer;
    }
    // void Tournament::setEmpty(){
    //     m_name = nullptr;
    //     m_soccer = nullptr;
    //     m_num = 0;
     Tournament::Tournament(const char* name, int noOfteam,const SoccerTeam* soccer){
        if(name != nullptr && name[0] != '\0' && noOfteam > 0 && soccer != nullptr){
            m_num = noOfteam;
            m_name = new char[strlen(name)+1];
            strcpy(m_name,name);
            m_soccer = new SoccerTeam[m_num];
            for(int i = 0; i < m_num; i++){
                m_soccer[i].setTeam(soccer[i]);
            }
        }else{
            setEmpty();
        }
    }
  

    Tournament& Tournament::match(const SoccerTeam* ls){
        if(ls != nullptr){
            if(m_soccer[0].fouls() < m_soccer[1].fouls()){
                m_soccer[1].setFine(m_soccer[1].m_fines,m_soccer[1].m_noFouls*2);
                m_soccer[0].m_golas++;
            }else{
                m_soccer[0].setFine(m_soccer[0].m_fines,m_soccer[0].m_noFouls*2);
                m_soccer[1].m_golas++;
            }
            if(m_soccer[1].fouls() > MAX_FOUL){
                m_soccer[1].setEmpty();
            }
        }
        return *this;
    }
  void Tournament::setEmpty(){
        m_name = nullptr;
        m_soccer = nullptr;
        m_num = 0;
    }

    bool Tournament::isEmpty() const{
        return m_name != nullptr && m_soccer != nullptr && m_num > 0;
    }
    ostream& Tournament::display() const{
        if(isEmpty()){
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl;
            cout << setw(45) << "Fines" << setw(10) << "Fouls" << setw(10) << "Goals" << endl;
            for(int i = 0; i < m_num; i++){
                cout << "Team[" << i+1 << "] :";
                m_soccer[i].display();
            }
        }else{
            cout <<"Invalid Tournament" ;
        }
        return cout;
    }

    
}

