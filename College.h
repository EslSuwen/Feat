#pragma once
#include "stdafx.h"

using namespace std;
class College {
private:
	int collegegNo;
	char collegeName[31];
	char deanName[31];
public:
	void initCollege(int bh, char* s1, char* s2)
	{
		collegegNo = bh;
		strcpy(collegeName, s1);
		strcpy(deanName, s2);
	}
	void setCollegeName(char* s)
	{
		strcpy(collegeName, s);
	}

	void setDeanName(char* s)
	{
		strcpy(deanName, s);
	}
	int getCollegeNo()
	{
		return collegegNo;
	}
	char* getCollegeName()
	{
		return collegeName;
	}
	char* getDeanName()
	{
		return deanName;
	}
	void print()
	{
		cout << "\t\t  " << setw(4) << collegegNo << setw(30) << collegeName << setw(12) << deanName << endl;
	}
};

