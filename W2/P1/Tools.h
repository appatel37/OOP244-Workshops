

#ifndef SDDS_TOOLS_H_
#define SDDS_TOOLS_H_

namespace sdds
{
	int openFile_r(const char filename[]); // Provided
	void closefile();					   // Provided
	int noOfTraces();					   // Provided

	
	bool read(char *name);

	bool read(int &id);

	bool read(double &time);

	bool read(char &day);

	void strCpy(char *des, const char *src); // Provided
	int strLen(const char *s);				 // Provided
}
#endif
