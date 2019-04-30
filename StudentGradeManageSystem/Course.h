#pragma once
#include "stdafx.h"
class Course {
private:
	int No;                    //课程编号
	char name[21];             //课程名称
	char type[10];             //课程性质（必修、限选、任选）
	float credit;              //课程学分
	int sumPeriod;             //课程总学时
	int thPeriod;              //课程理论学时
	int expPeriod;             //课程实验学时
public:
	void initCourse(int bh, char *n, char *t, float c, int s, int tP, int eP)
	{
		No = bh;
		strcpy(name, n);
		strcpy(type, t);
		credit = c;
		sumPeriod = s;
		thPeriod = tP;
		expPeriod = eP;
	}
	void setName(char *n)
	{
		strcpy(name, n);
	}
	void setType(char *t)
	{
		strcpy(type, t);
	}
	void setCredit(float c)
	{
		credit = c;
	}
	void setSumPeriod(int s)
	{
		sumPeriod = s;
	}
	void setThPeiod(int tP)
	{
		thPeriod = tP;
	}
	void setExpPeriod(int eP)
	{
		expPeriod = eP;
	}
	int getCourseNo()
	{
		return No;
	}
	char *getCourseName()
	{
		return name;
	}
	char *getCourseType()
	{
		return type;
	}
	float getCourseCredit()
	{
		return credit;
	}
	int getSumPeriod()
	{
		return sumPeriod;
	}
	int getThPeriod()
	{
		return thPeriod;
	}
	int getExpPeriod()
	{
		return expPeriod;
	}
	void print()
	{
		cout<<"\t\t "<<setw(6) <<No<<setw(12) << name << setw(15) << type << setw(10) <<credit<< setw(10) << sumPeriod << setw(10) << thPeriod << setw(10) << expPeriod << endl;
	}
};
