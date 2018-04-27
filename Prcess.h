#pragma once
#include "stdafx.h"

using namespace std;
class Process {
private:
	CollegeSet College;
	MajorSet Major;
	StudentSet Student;
	CourseSet Course;
	CvSet Cv;
public:
	void mainMenuControl()
	{
		int sel;
		while (1)
		{
			menu::menu0();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1:collegeManage();   break;
			case 2:majorManage();     break;
			case 3:studentManage();   break;
			case 4:courseManage();   break;
			case 5:cvManage();   break;
			case 6:gradeManage(); break;
			}
			if (sel == 0)
				break;
		}
	}

	void collegeManage()


	{
		int sel;

		while (1)
		{
			menu::menu1();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: College.input(); break;
			case 2: College.print(); break;
			case 3: College.findCollege(); break;
			case 4: College.modifyCollege(); break;
			case 5:int bh;
				cout << "请输入需要删除的学院编号：" << endl;
				cin >> bh;
				if (Major.findBH(bh))
					cout << "学院还存在专业数据，不能删除！！" << endl;
				else College.deleteCollege(bh); break;
			case 6:break;
			}
			if (sel == 0)

				break;
		}
	}
	void majorManage()
	{
		int sel;

		while (1)
		{
			menu::menu2();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: Major.input(); break;
			case 2: Major.print(College); break;
			case 3: Major.findMajor(College); break;
			case 4: Major.modifyMajor(College); break;
			case 5: int bh;
				cout << "请输入需要删除的专业编号：" << endl;
				cin >> bh;
				if (Student.findBH(bh))
					cout << "专业还存在学生数据，不能删除！！" << endl;
				else Major.deleteMajor(bh); break;
			case 6: break;
			}
			if (sel == 0)
				break;
		}
	}
	void studentManage()
	{
		int sel;
		while (1)
		{
			menu::menu3();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: Student.input(); break;
			case 2: Student.print(College, Major); break;
			case 3: Student.findStudent(College, Major); break;
			case 4: Student.modifyStudent(College, Major); break;
			case 5:int bh;
				cout << "请输入需要删除的学生学号：" << endl;
				cin >> bh;
				if (Cv.findStudBH(bh))
					cout << "学生还存在学生数据，不能删除！！" << endl;
				else
					Student.deleteStudent(bh); break;
			}
			if (sel == 0)
				break;
		}
	}
	void courseManage()
	{
		int sel;
		while (1)
		{
			menu::menu7();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: Course.input(); break;
			case 2: Course.print(); break;
			case 3: Course.findCourse(); break;
			case 4: Course.modifyCourse(); break;
			case 5: int bh;
				cout << "请输入需要删除的课程编号：" << endl;
				cin >> bh;
				if (Cv.findCourseBH(bh))
					cout << "课程还存在选课数据，不能删除！！" << endl;
				else
					Course.deleteCourse(bh); break;
			}
			if (sel == 0)
				break;
		}
	}
	void cvManage()
	{
		int sel;
		while (1)
		{
			menu::menu9();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: Cv.input(); break;
			case 2: Cv.print(Student, Course); break;
			case 3: Cv.findCv(College, Major, Student, Course); break;
			case 4: Cv.deleteCv(); break;
			}
			if (sel == 0)
				break;
		}
	}
	void gradeManage()
	{
		int sel;
		while (1)
		{
			menu::menu11();
			cout << "请输入你的选择：";
			cin >> sel;
			switch (sel)
			{
			case 1: Cv.gradeIn(College, Major, Student, Course); break;
			case 2: Cv.courseGradeOut(Student, Course); break;
			case 3: Cv.studGradeOut(Student, Course); break;
			case 4: Cv.rankGradeOut(Student, Course); break;
			}
			if (sel == 0)
				break;
		}
	}
};
