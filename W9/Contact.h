

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"
namespace sdds {
   class Contact : public Person {
      char* m_address{};
      char* m_city{};
      char* m_province{};
      char* m_postalCode{};
   public:
      Contact();
      
      Contact(const Contact& copyFrom);
      
      Contact& operator=(const Contact& RightOperand);
      ~Contact();
      
      std::istream& read(std::istream& istr);
      
      std::ostream& write(std::ostream& ostr)const;
      
      operator bool()const;
      
      void operator~();
      bool isValid()const;
   };
}
#endif