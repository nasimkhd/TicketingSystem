
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"
#include "account.h"
#include "accountTicketingUI.h"


#define MAX_RANGE 11
#define MIN_RANGE -3

int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}

int getInteger(void) {
	int num = 0;
	char name = 'e';
	while (name != '\n') {
		scanf(" %d%c", &num, &name);
		if (name != '\n') {
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	}
	return num;
}

int getPositiveInteger(void) {
	int positiveNum = 0;
	while (positiveNum <= 0) {
		positiveNum = getInteger();
		if (positiveNum <= 0) {
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	}
	return positiveNum;
}
int getIntFromRange(int lower_bound, int upper_bound) {
	int rangeNum = upper_bound + 1;
	while (rangeNum < lower_bound || rangeNum > upper_bound) {
		rangeNum = getInteger();
		if (rangeNum < lower_bound || rangeNum > upper_bound)
			printf("ERROR: Value must be between %d and %d inclusive: ", lower_bound, upper_bound);
	}
	return rangeNum;
}

double getDouble() {
	double doubleNum;
	char name = 'e';
	while (name != '\n') {
		scanf(" %lf%c", &doubleNum, &name);
		if (name != '\n') {
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	}
	return doubleNum;
}

double getPositiveDouble() {
	double positiveDouble = 0;
	while (positiveDouble <= 0) {
		positiveDouble = getDouble();
		if (positiveDouble <= 0) {
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
	}
	return positiveDouble;
}

char getCharOption(const char* list)
{
	char input = 0;
	char option = 0;
	int flag = 0;
	int i = 0;
	do
	{
		scanf("%c%c", &input, &option);
		if (option == '\n')
		{
			i = 0;
			while (list[i] != 0 && flag == 0)
			{
				if (list[i] == input)
				{
					flag = 1;
				}
				else
				{
					i++;
				}
			}
		}
		else
		{
			clearStandardInputBuffer();
		}
		if (flag == 0)
		{
			printf("ERROR: Character must be one of [%s]: ", list);
		}
	} while (flag == 0);
	return input;
}


int length(char* string) {
	int i = 0;
	while (string[i] != 0) {
		i++;
	}
	return i;
}
int copy(char* to, char* from) {
	int i = 0;
	while (from[i] != 0) {
		to[i] = from[i];
		i++;
	}
	to[i] = 0;
	return 0;
}
void getCString(char* cString, int minNumChar, int maxNum) {
	char string[50];
	int lengthChar ;
	scanf("%[^\n]", string);
	clearStandardInputBuffer();
	lengthChar = length(string);
	while (lengthChar > maxNum || lengthChar < minNumChar) {
		if (minNumChar == maxNum)
			printf("ERROR: String length must be exactly %d chars: ", maxNum);
		else if (lengthChar > maxNum)
			printf("ERROR: String length must be no more than %d chars: ", maxNum);
		else 
			printf("ERROR: String length must be between %d and %d chars: ", minNumChar, maxNum);
		
		scanf("%[^\n]", string);
		clearStandardInputBuffer();
		lengthChar = length(string);


		
	}
	copy(cString, string);
	return;
}


