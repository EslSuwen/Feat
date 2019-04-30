#pragma once
#include "stdafx.h"

class CvSet {
private:
	Cv cvData[100];
	int num;
public:
	CvSet()
	{
		num = 0;
		ifstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CvData.dat", ios::binary);			//打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&cvData[num], sizeof(Cv));	// 将数组中的数据元素一个一个地写入文件
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//关闭文件，断开 f2与具体文件的关联
	}
	~CvSet()
	{
		ofstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CvData.dat", ios::binary);            //打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&cvData[i], sizeof(Cv));    // 将数组中的数据元素一个一个地写入文件
		}
		f2.close();                                         //关闭文件，断开 f2与具体文件的关联
	}
	void input()
	{
		char sel = 'y';
		int sNo, cNo;
		while (sel == 'y' || sel == 'Y')
		{
			cout << "学生学号："; cin >> sNo;
			cout << "课程编号："; cin >> cNo;
			cvData[num].initCv(sNo, cNo);
			num++;
			cout << "是否继续输入（Y/N）：" << endl;
			cin >> sel;
		}

	}
	void print(StudentSet s, CourseSet cs)
	{
		cout << "\n\n\t\t                                选课列表" << endl;
		cout << "\t\t    ---------------------------------------------------------------------------" << endl;
		cout << "\t\t      学生姓名   学生学号   课程编号   课程名称  课程成绩   性质  学分   总学时" << endl;
		cout << "\t\t    ---------------------------------------------------------------------------" << endl;
		for (int i = 0; i < num; i++)
		{
			cvData[i].print(s, cs);
		}
		cout << "\t\t    --------------------------------------------------------------------------\n\n" << endl;
	}
	void findCv(CollegeSet c, MajorSet m, StudentSet s, CourseSet cs)
	{
		int sel;
		while (1)
		{
			menu::menu10();
			cin >> sel;
			if (sel == 1)
			{
				int i = 0, flag = 0, bh;
				cout << "请输入课程编号：";
				cin >> bh;
				if (cs.findBH(bh))
				{
					cout << "\t\t    ---------------------------------------------------------------------------" << endl;
					cout << "\t\t      学生姓名   学生学号   课程编号   课程名称  课程成绩   性质  学分   总学时" << endl;
					cout << "\t\t    ---------------------------------------------------------------------------" << endl;
					cout << "\t\t  " << setw(6) << bh;
					cout << setw(6) << cs.findCourseName(bh);
					cout << setw(4) << cs.findCourseType(bh);
					cout << setw(8) << cs.findCourseCredit(bh);
					cout << setw(8) << cs.findCourseSumPeriod(bh);
					cout << setw(8) << cs.findCourseThPeriod(bh);
					cout << setw(8) << cs.findCourseExpPeriod(bh);
					cout << endl;
					cout << "\t\t    ---------------------------------------------------------------------------" << endl;
					cout << "\t\t                                学生列表" << endl;
					cout << "\t\t  ------------------------------------------------------------------------" << endl;
					cout << "\t\t   学号    姓名   性别        专业                学院          联系方式" << endl;
					cout << "\t\t  ------------------------------------------------------------------------" << endl;
					for (int i = 0; i < num; i++)
					{
						if (bh == cvData[i].getCourseNo())
							s.studentFind(c, m, cvData[i].getStudNo());
					}
					cout << "\t\t  ------------------------------------------------------------------------\n\n" << endl;
					flag = 1;
				}
				if (flag == 0)
					cout << "没找到该课程！";
			}
			if (sel == 2)
			{
				int bh;
				int flag = 0;
				cout << "请输入学生学号：";
				cin >> bh;
				cout << "\t\t    ---------------------------------------------------------------------------" << endl;
				cout << "\t\t      学生姓名   学生学号   课程编号   课程名称  课程成绩   性质  学分   总学时" << endl;
				cout << "\t\t    ---------------------------------------------------------------------------" << endl;
				for (int i = 0; i < num; i++)
				{
					if (bh == cvData[i].getCourseNo())
					{
						s.studentFind(c, m, cvData[i].getStudNo());
						flag = 1;
						break;
					}
				}
				cout << "\t\t    ---------------------------------------------------------------------------" << endl;
				for (int i = 0; i < num; i++)
				{
					if (bh == cvData[i].getStudNo())
					{
						cvData[i].print(s, cs);
					}
				}
				if (flag == 0)
					cout << "没找到该学生！";
			}
			if (sel == 0)
				break;
		}
	}
	void deleteCv()
	{
		int bh, zh;
		cout << "请输入学号："; cin >> bh;
		cout << "请输入课程编号："; cin >> zh;
		int i = 0, flag = 0;
		for (; i < num; i++)
		{
			if ((bh == cvData[i].getStudNo()) && (zh == cvData[i].getCourseNo()))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			for (; i < num; i++)
			{
				cvData[i] = cvData[i + 1];
			}
			num--;
		}
		else
			cout << "未找到该选课信息！";
	}
	int findStudBH(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == cvData[i].getStudNo())
				return 1;
		}
		return 0;
	}
	int findCourseBH(int bh)
	{
		for (int i = 0; i<num; i ++)
		{
			if (bh == cvData[i].getCourseNo())
				return 1;
		}
		return 0;
	}
	void gradeIn(CollegeSet c, MajorSet m, StudentSet s, CourseSet cs)
	{
		int i = 0, flag = 0, bh;
		cout << "请输入课程编号：";
		cin >> bh;
		if (cs.findBH(bh))
		{
			cout << "\n\n\t\t                                课程信息" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t " << setw(2) << bh;
			cout << setw(10) << cs.findCourseName(bh);
			cout << setw(10) << cs.findCourseType(bh);
			cout << setw(10) << cs.findCourseCredit(bh);
			cout << setw(12) << cs.findCourseSumPeriod(bh);
			cout << setw(12) << cs.findCourseThPeriod(bh);
			cout << setw(12) << cs.findCourseExpPeriod(bh);
			cout << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t                                学生列表" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t 学号       姓名     性别           专业            学院        联系方式" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			for (int i = 0; i < num; i++)
			{
				float grade;
				if (bh == cvData[i].getCourseNo())
				{
					s.studentFind(c, m, cvData[i].getStudNo());
					cout << "请输入该生该课程成绩：" << endl; cin >> grade;
					cvData[i].setGrade(grade);
				}
			}
			cout << "\t\t------------------------------------------------------------------------\n\n" << endl;
			flag = 1;
		}
		if (flag == 0)
			cout << "没找到该课程！";
	}
	void courseGradeOut(StudentSet s,CourseSet cs)
	{
		int bh;
		cout << "请输入课程编号：";
		cin >> bh;
		if (cs.findBH(bh))
		{
			cout << "\n\n\t\t                                课程信息" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t 编号    名称         性质    学分        总学时    理论学时    实验学时" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t " << setw(2) << bh;
			cout << setw(10) << cs.findCourseName(bh);
			cout << setw(10) << cs.findCourseType(bh);
			cout << setw(10) << cs.findCourseCredit(bh);
			cout << setw(12) << cs.findCourseSumPeriod(bh);
			cout << setw(12) << cs.findCourseThPeriod(bh);
			cout << setw(12) << cs.findCourseExpPeriod(bh);
			cout << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			gradeSort();
			cout << "\n\t\t                              学生成绩列表" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t学生姓名   学生学号        课程编号   课程名称  课程成绩    性质  学分 " << endl;
			cout << "\t\t------------------------------------------------------------------------\n" << endl;
			for (int i = 0; i < num; i++)
			{
				if (bh == cvData[i].getCourseNo())
				{
					cout <<"\t\t"<< setw(8) << s.findStudName(cvData[i].getStudNo()) << setw(10) << cvData[i].getStudNo() << setw(16) << cvData[i].getCourseNo() << setw(12) << cs.findCourseName(cvData[i].getCourseNo());
					cout << setw(8) << cvData[i].getGrade() << setw(10) << cs.findCourseType(cvData[i].getCourseNo()) << setw(4) << cs.findCourseCredit(cvData[i].getCourseNo()) << endl;
				}
			}
		}
		else
			cout << "未找到该课程！" << endl;
	}
	void studGradeOut(StudentSet s,CourseSet cs)
	{
		int bh,flag = 0;
		cout << "请输入学生学号：";
		cin >> bh;
		cout << "\n\t\t                              学生成绩列表" << endl;
		cout << "\t\t------------------------------------------------------------------------" << endl;
		cout << "\t\t学生姓名   学生学号        课程编号   课程名称  课程成绩    性质  学分 " << endl;
		cout << "\t\t------------------------------------------------------------------------\n" << endl;
		for (int i = 0; i < num; i++)
		{
			if (bh == cvData[i].getStudNo())
			{
				cout << "\t\t" << setw(8) << s.findStudName(cvData[i].getStudNo()) << setw(10) << cvData[i].getStudNo() << setw(16) << cvData[i].getCourseNo() << setw(12) << cs.findCourseName(cvData[i].getCourseNo());
				cout << setw(8) << cvData[i].getGrade() << setw(10) << cs.findCourseType(cvData[i].getCourseNo()) << setw(4) << cs.findCourseCredit(cvData[i].getCourseNo()) << endl;
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "没找到该学生！";
	}
	void rankGradeOut(StudentSet s,CourseSet cs)
	{
		char str1[10] = { "必修" };
		char str2[10] = { "限选" };
		for (int i = 0; i < num; i++)
		{
			if (!strcmp(cs.findCourseType(cvData[i].getCourseNo()), str1) || !strcmp(cs.findCourseType(cvData[i].getCourseNo()), str2))
			{
				s.gradeSet(cvData[i].getStudNo(), cvData[i].getGrade(), cs.findCourseCredit(cvData[i].getCourseNo()));
			}
		}
		s.gradeCompute();
		s.gradeRankOut();
	}
	void gradeSort()
	{
		menu::menu12();
		int sel;
		cin >> sel;
		if (sel == 1)
		{
		}
		if (sel == 2)
		{
			for (int i=0; i<num; i++)
			{
				for (int j=i+1; j<num; j++)
				{
					if ((cvData[i].getGrade()) < cvData[j].getGrade())
					{
						Cv t;
						t=cvData[i];
						cvData[i] = cvData[j];
						cvData[j] = t;
					}
				}
			}
		}
		if (sel == 3)
		{
			for (int i=0; i<num; i++)
			{
				for (int j=i+1; j<num; j++)
				{
					if (cvData[i].getStudNo() > cvData[j].getStudNo())
					{
						Cv t;
						t = cvData[i];
						cvData[i] = cvData[j];
						cvData[j] = t;
					}
				}
			}
		}
	}
};
