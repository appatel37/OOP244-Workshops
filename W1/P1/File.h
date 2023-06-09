
#ifndef SDDS_FILE_H__
#define SDDS_FILE_H__
namespace sdds{
    
bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);
}
#endif