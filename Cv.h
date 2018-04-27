#pragma once
#include "stdafx.h"
class Cv {
private:
	int studNo;                //学生学号
	int courseNo;              //课程编号
	float grade;               //课程成绩
public:
	void initCv(int sNo, int cNo)
	{
		studNo = sNo;
		courseNo = cNo;
		grade = 0.0;
	}
	int getStudNo()
	{
		return studNo;
	}
	int getCourseNo()
	{
		return courseNo;
	}
	float getGrade()
	{
		return grade;
	}
	void setGrade(float g)
	{
		grade = g;
	}
	void print(StudentSet s, CourseSet cs)
	{
		cout << "\t\t      "<<setw(6) << s.findStudName(studNo);
		cout << setw(10) << studNo;
		cout << setw(12) << courseNo;
		cout << setw(10) << cs.findCourseName(courseNo);
		cout << setw(6) << grade;
		cout << setw(10) << cs.findCourseType(courseNo);
		cout << setw(8) << cs.findCourseCredit(courseNo);
		cout << setw(8) << cs.findCourseSumPeriod(courseNo);
		cout << endl;
	}
};

