

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

    // complete
    void EmptyRecord(Customers& c_rec) {
        c_rec.user_name[0] = '\0';
        c_rec.likes_count = 0;
        c_rec.retweets_count = 0;
        c_rec.replies_count = 0;
        c_rec.share_videos = '\0';
    }

// complete
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << endl;
    }

    void EmptyRecord(CustomersRecord& t_rec) {
        t_rec.ptr_rec = nullptr;
        t_rec.noOfRecords = 0;
    }
    // void display(const CustomersRecord& t_rec){
    //     cout << "Displaying the CustomersRecord object" << endl;

    // }
// int loadTraces(Customers &user){
//     int noOfRecords = 0;
//     char filename[20];
//     char dayofweek;
//     int user_id;

    // complete
    bool read(Customers& c_rec) {
        bool ok = false;
        cout << " Enter User name: ";
        read(c_rec.user_name, 20);
        if (c_rec.user_name[0] != '\0') {
            cout << " Enter likes_count: ";
            cin >> c_rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> c_rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> c_rec.replies_count;
            cout << " Enter share videos (y/n): ";
            cin >> c_rec.share_videos;
            ok = true;
        }
        return ok;
    }
    void display(const CustomersRecord& t_rec) {
      
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
     
    }

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }


    // complete
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        Customers* temp = nullptr;
        temp = new Customers[t_rec.noOfRecords + 1];
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            temp[i] = t_rec.ptr_rec[i];
        }
        temp[t_rec.noOfRecords] = c_rec;
        t_rec.noOfRecords++;
        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = temp;
    }

    
    
   
   

  }

