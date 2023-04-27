

#include <bits/stdc++.h>

#include "GPAlist.h"
using namespace std;
namespace sdds
{

    bool gpaQuery(const char *fileName)
    {
        std::ifstream file(fileName);
        if (!file.is_open())
        {
            return false;
        }
        std::string line, name, id;
        double gpa;
        // int count = 0;



        std::cout << "Enter GPA query..." << std::endl;
        std::string query;
        while (true)
        {
            std::cout << "? ";
            std::cin >> query;
            if (query[0] == '@')
            {
                std::cout << "Syntax error: ? [Op][value]<ENTER>\nOp: [>,<,~,!]\nvalue: GPA value\n\n";
                continue;
            }
            // if(query[0] != '>' && query[0] != '<' && query[0] != '~' && query[0] != '!'){
            //     std::cout << "Syntax error: ? [Op][value]<ENTER>\nOp: [>,<,~,!]\nvalue: GPA value\n\n";
            //     continue;
            // }
            if (query == "!")
            {
                std::cout << "Exit the program? (Y)es/(N)o: ";
                char exit;
                std::cin >> exit;
                if (exit == 'Y' || exit == 'y')
                {
                    break;
                }
                continue;
            }
            char op = query[0];
            double value = std::stod(query.substr(1));
            file.clear();
            file.seekg(0, std::ios::beg);
            
            vector<data> v;
            
            while (std::getline(file, line))
            {
                std::stringstream ss(line);
                std::getline(ss, name, ',');
                std::getline(ss, id, ',');
                ss >> gpa;
                if (op == '>' && gpa > value)
                {
                    data d;
                    d.name = name;
                    d.id = stoi(id);
                    d.gpa = gpa;
                    v.push_back(d);
                }
                else if (op == '<' && gpa < value)
                {
                    data d;
                    d.name = name;
                    d.id = stoi(id);
                    d.gpa = gpa;
                    v.push_back(d);
                }
                // else if(op == '~' && gpa != value)
                // {
                //     data d;
                //     d.name = name;
                //     d.id = stoi(id);
                //     d.gpa = gpa;
                //     v.push_back(d);
                // }
                else if (op == '~' && gpa == value)
                {
                    data d;
                    d.name = name;
                    d.id = stoi(id);
                    d.gpa = gpa;
                    v.push_back(d);
                }
            }
            // while(v.size() == 0){
            //     std::cout << "No students found with the given criteria!\n\n";
            //     break;
            // }
            sort(v.begin(), v.end(), [](data a, data b)
                 { return a.gpa < b.gpa; });

            for (unsigned int i = 0; i < v.size(); i++)
            {
                cout << "[" << i + 1 << "] " << v[i].id << ": ";
                if (v[i].gpa != 4)
                    cout << v[i].gpa;
                else
                    cout << "4.0";
                cout << " (" << v[i].name << ")" << endl;
            }
        }
        file.close();
        return true;
    }

}