
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {

   class Numbers {
      double *m_nums;
      char* m_filename;
      bool m_original;
      unsigned int m_size;
      bool isEmpty() const;
      void setEmpty();
      void setFilename(const char* fname);
      int numberCount();
      bool load( const char* filename);
      void save();  
      unsigned int countLines(const char* filename); 
      void sort(double* collectionPtr, unsigned int size);  
   public:
      Numbers(); 


      Numbers(const char* filename); 
      
      Numbers(const Numbers& src); 
      ~Numbers(); 
      
      Numbers& operator=(const Numbers& src); 
      
      Numbers& operator+=(double num); 
      
      std::ostream& display(std::ostream& ostr = std::cout) const; 
      
      double max() const;
      double min() const;
      double average() const;
      operator bool() const;
      void sort();
   };
   std::ostream& operator<<(std::ostream& ostr, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);

}
#endif 

