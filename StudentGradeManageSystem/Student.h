#pragma once
#include "stdafx.h"
class Student {
private:
	int studNo;                 //学号
	int majorNo;                //专业编号
	char name[31];              //学生姓名
	char sex[8];               //学生性别
	char phoneNumber[31];       //学生联系电话
	float cvCredit;                  //（必修/限选）选课学分
	float avgGrade;            //平均成绩
public:
	void initStudent(int sn, int ms, char*n, char*s, char*pn)
	{
		studNo = sn;
		majorNo = ms;
		strcpy(name, n);
		strcpy(sex, s);
		strcpy(phoneNumber, pn);
		cvCredit = 0.0;
		avgGrade = 0.0;

	}
	int getStudNo()
	{
		return studNo;
	}
	int getMajorNo()
	{
		return majorNo;
	}
	char *getStudName()
	{
		return name;
	}
	char *getSex()
	{
		return sex;
	}
	char *getPhoneNumber()
	{
		return phoneNumber;
	}
	float getAvgGrade()
	{
		return avgGrade;
	}
	void setMajorNo(int n)
	{
		majorNo = n;
	}
	void setName(char*n)
	{
		strcpy(name, n);
	}
	void setSex(char*n)
	{
		strcpy(sex, n);
	}
	void setPhnoeNumber(char*n)
	{
		strcpy(phoneNumber, n);
	}
	void setAvgGrade(float g, float c)
	{
		avgGrade += (g*c);
		cvCredit += c;
	}
	void computeGrade()
	{
		avgGrade /= cvCredit;
	}
	void print(CollegeSet c, MajorSet m)
	{
		cout << "\t\t" << setw(6) << studNo;
		cout << setw(10) << name;
		cout << setw(4) << sex;
		cout << setw(20) << m.findMajorName(majorNo);
		cout << setw(20) << c.findCollegeName(m.findCollegeNo(majorNo));
		cout << setw(12) << phoneNumber;
		cout << endl;
	}
};

