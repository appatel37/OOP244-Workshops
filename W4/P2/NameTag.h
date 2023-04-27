
// void checking(){
//     while(counter == 3 || counter == 4 || counter == 5){
//         cout << "EMPTY NAMETAG!" << endl;
//         return;
//     }

// }
#ifndef SDDS_NAMETAG_H__
#define SDDS_NAMETAG_H__
namespace sdds {
    class NameTag {
        public:
        char* m_name;
        int m_extension;
    public:
        NameTag(); 
        NameTag(const char* name); 
        NameTag(const char* name, int extension); // two argument constructor
        ~NameTag(); // destructor
        void print() const;
        NameTag& read();
    };
}

#endif