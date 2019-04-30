#pragma once
#include "stdafx.h"
class Course {
private:
	int No;                    //�γ̱��
	char name[21];             //�γ�����
	char type[10];             //�γ����ʣ����ޡ���ѡ����ѡ��
	float credit;              //�γ�ѧ��
	int sumPeriod;             //�γ���ѧʱ
	int thPeriod;              //�γ�����ѧʱ
	int expPeriod;             //�γ�ʵ��ѧʱ
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
