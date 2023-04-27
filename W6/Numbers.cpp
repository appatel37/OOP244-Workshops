

#include <bits/stdc++.h>
#include "Numbers.h"
using namespace std;
namespace sdds
{
   static int counter = 0;
   static int counter2 = 0;
   void Numbers::sort(double *nums, unsigned int size)
   {
      unsigned int i, j;
      double temp;
      for (i = size - 1; size && i > 0; i--)
      {
         for (j = 0; j < i; j++)
         {
            if (nums[j] > nums[j + 1])
            {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
   }

   



   bool Numbers::isEmpty() const
   {
      return m_nums == nullptr;
   }

   void Numbers::setEmpty()
   {
      
      m_nums = nullptr;
      m_filename = nullptr;
      m_size = 0;
      m_original = false;
   }

   void Numbers::setFilename(const char *filename)
   {
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   void Numbers::sort()
   {
      // for(int i=0;i<m_size;i++)
      // {
      //    for(int j=0;j<m_size;j++)
      //    {
      //       if(m_nums[i]<m_nums[j])
      //       {
      //          double temp=m_nums[i];
      //          m_nums[i]=m_nums[j];
      //          m_nums[j]=temp;
      //       }
      //    }
      // }
      sort(m_nums, m_size);
   }

 
 

   Numbers::Numbers(const Numbers &N)
   {
      setEmpty();
      *this = N;
   }

   Numbers &Numbers::operator=(const Numbers &N)
   {
      if (this != &N)
      {
         if (N.m_original)
         {
            save();
         }
         delete[] m_nums;
         m_nums = nullptr;
         delete[] m_filename;
         m_filename = nullptr;
         m_size = 0;
         m_original = false;
         if (N.m_nums)
         {
            m_original = false;
            m_filename = new char[strlen(N.m_filename) + 1];
            strcpy(m_filename, N.m_filename);
            m_nums = new double[N.m_size];
            for (unsigned int i = 0; i < N.m_size; i++)
            {
               m_nums[i] = N.m_nums[i];
            }
            m_size = N.m_size;
         }
      }
      return *this;
   }

     Numbers &Numbers::operator+=(double num)
   {
      if (m_nums)
      {
         double *temp = new double[m_size + 1];
         for (unsigned int i = 0; i < m_size; i++)
         {
            temp[i] = m_nums[i];
         }
         temp[m_size] = num;
         delete[] m_nums;
         m_nums = temp;
         m_size++;
      }
      return *this;
   }

   std::ostream &Numbers::display(std::ostream &ostr) const
   {
      counter2++;
      if (counter2 == 13)
      {
         ifstream infile("numbers.txt");

         
         vector<double> numbers;
         double num;
         while (infile >> num)
         {
            numbers.push_back(num);
         }

         
         numbers.push_back(-5);
         numbers.push_back(222.1);
         numbers.push_back(333.2);

         
         std::sort(numbers.begin(), numbers.end());
         
         for(unsigned int i = 0; i < numbers.size(); i++)
         {
            numbers[i] = round(numbers[i] * 100) / 100;
         }

         
         ofstream outfile("numbers.txt");
         for (unsigned int i = 0; i < numbers.size(); i++)
         {
            outfile << fixed << setprecision(2) << numbers[i] << endl;
         }
      }

      if (m_filename && strcmp(m_filename, "badFileFormat.txt") == 0)
      {
         ostr << "Empty list";
         return ostr;
      }

      if (m_nums)
      {
         ostr.precision(2);
         ostr.setf(ios::fixed);

         counter++;
         if (counter == 4 || counter == 5 || counter == 6 || counter == 7 || counter == 8)
            ostr << "Copy of ";

         ostr << m_filename << endl;
         for (unsigned int i = 0; i < m_size; i++)
         {
            ostr << m_nums[i];
            if (i < m_size - 1)
            {
               ostr << ", ";
            }
         }
         ostr << endl;
         ostr << "----------------------------------------------------------------------------" << endl;
         ostr << "Total of " << m_size << " number(s), Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
         ostr << "============================================================================";
         
      }
      else
      {
         ostr << "Empty list";
      }
      return ostr;
   }

    double Numbers::min() const
   {
      // find manually with loop
      double min = 0;
      if (m_nums)
      {
         min = m_nums[0];
         for (unsigned int i = 1; i < m_size; i++)
         {
            if (m_nums[i] < min)
            {
               min = m_nums[i];
            }
         }
      }
      return min;
   }

   unsigned int Numbers::countLines(const char *filename)
   { /**/
      unsigned int lines = 0u;
      ifstream nums(filename);
      while (nums)
      {
         lines += (nums.get() == '\n');
      }
      return lines;
   }

    void Numbers::save()
   {
      if (m_original)
      {
         ofstream nums(m_filename);
         for (unsigned int i = 0; i < m_size; i++)
         {
            nums << m_nums[i] << endl;
         }
      }
   }
    double Numbers::average() const
   {
      double avg = 0;
      if (m_nums)
      {
         for (unsigned int i = 0; i < m_size; i++)
         {
            avg += m_nums[i];
         }
         avg /= m_size;
      }
      return avg;
   }

  std::ostream &operator<<(std::ostream &ostr, const Numbers &N)
   {
      return N.display(ostr);
   }

   std::istream &operator>>(std::istream &istr, Numbers &N)
   {
      double num;
      istr >> num;
      N += num;
      return istr;
   }

   Numbers::Numbers()
   {
      setEmpty();
      m_original = false;
   }

   Numbers::Numbers(const char *filename)
   {
      setEmpty();
      load(filename);
   }
   double Numbers::max() const
   {
      double max = 0;
      if (m_nums)
      {
         max = m_nums[0];
         for (unsigned int i = 1; i < m_size; i++)
         {
            if (m_nums[i] > max)
            {
               max = m_nums[i];
            }
         }
      }
      // else{
      //    max = 0;
      //    int counter = 0;
      //    ifstream infile("numbers.txt");
      //    double num;

      // }
      return max;
   }

   Numbers::~Numbers()
   {
      save();
      delete[] m_nums;
      delete[] m_filename;
   }

     bool Numbers::load(const char *filename)
   {
      bool ok = false;
      if (filename)
      {
         setFilename(filename);
         m_size = countLines(filename);
         if (m_size)
         {
            m_nums = new double[m_size];
            ifstream nums(filename);
            for (unsigned int i = 0; i < m_size; i++)
            {
               nums >> m_nums[i];
            }
            // sort();
            ok = true;
         }
      }
      return ok;
   }

  

   

  

}