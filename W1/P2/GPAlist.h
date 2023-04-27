#ifndef GPA_LIST_H
#define GPA_LIST_H
#include <bits/stdc++.h>
namespace sdds{
    struct data{
        int id;
        double gpa;
        std::string name;
    };
    bool gpaQuery(const char* fileName);
}
#endif