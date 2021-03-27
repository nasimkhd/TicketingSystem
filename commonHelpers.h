// ===================================================================================
//  Assignment: 1 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Nasim Khodapanah
//  Student ID    : 131929200
//  Student Email : nkhodapanah@myseneca.ca
//  Course Section: NGG
// ===================================================================================

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

int currentYear(void);
void clearStandardInputBuffer(void);
int getInteger(void);
int getPositiveInteger(void);
int getIntFromRange(int lower_bound, int upper_bound);
double getDouble();
double getPositiveDouble();
char getCharOption(const char* list);
int copy(char* to, char* from);
int length(char* line);
void getCString(char* cString, int minNumChar, int maxNumChar);

#endif // !COMMON_HELPERS_H_