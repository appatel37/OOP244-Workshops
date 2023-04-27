

#include "Video.h"
#include <bits/stdc++.h>
using namespace std;
namespace sdds {
    int& Video::getLength() {
        return m_length;
    }

    Video::Video() : m_length(0) {}
    void Video::setEmpty(){
        m_length = 0;
    }

    bool Video::isEmpty() const {
        return m_length == 0;
    }

    int Video::getLength() const {
        return m_length;
    }
    void Video::load(std::istream& is) {
        string temp;
        getline(is, temp, ',');
        m_length = stoi(temp);
        is.ignore();
    }
 //Video(int length);
    Video::Video(int length) {
        if (length < 0) {
            setEmpty();
        }
        else {
            m_length = length;
        }
    }
    
}
