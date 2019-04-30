#pragma once
#include "stdafx.h"

using namespace std;
class Major {
private:
	int majorNo;               //专业编号
	int collegeNo;             //专业所属学院编号
	char majorName[31];        //专业名称
	int majorYear;             //专业学制
public:
	void initMajor(int mno, int cno, char *n, int my)
	{
		majorNo = mno;
		collegeNo = cno;
		strcpy(majorName, n);
		majorYear = my;
	}
	void setCollegeNo(int n)
	{
		collegeNo = n;
	}
	void setMajorName(char *n)
	{
		strcpy(majorName, n);
	}
	void setMajorYear(int n)
	{
		majorYear = n;
	}
	int getMajorNo()
	{
		return majorNo;
	}
	char* getMajorName()
	{
		return majorName;
	}
	int getCollegeNo()
	{
		return collegeNo;
	}
	int getMajorYear()
	{
		return majorYear;
	}
	void print(CollegeSet c, int bh)
	{
		cout << "\t\t " << setw(5) << majorNo << setw(20) << majorName << setw(18) << majorYear;
		cout << setw(22) << c.findCollegeName(bh) << endl;
	}

};

