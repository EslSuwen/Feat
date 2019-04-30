#pragma once
#include"stdafx.h"

class CourseSet {
private:
	Course csData[100];
	int num;
public:
	CourseSet()
	{
		num = 0;
		ifstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CourseData.dat", ios::binary);			//打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&csData[num], sizeof(Course));	// 将数组中的数据元素一个一个地写入文件
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//关闭文件，断开 f2与具体文件的关联
	}
	~CourseSet()
	{
		ofstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CourseData.dat", ios::binary);            //打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&csData[i], sizeof(Course));    // 将数组中的数据元素一个一个地写入文件
		}
		f2.close();                                         //关闭文件，断开 f2与具体文件的关联
	}
	void input()
	{
		int bh, s, tP, eP;
		char n[21], t[10], sel = 'y';
		float c;
		while (sel == 'y' || sel == 'Y')
		{
			/*cout << "课程编号:"; cin >> bh;
			if (findBH(bh))									//检查输入编号是否被占用
			{
				cout << " 该编号已被占用!" << endl;
				continue;									//编号被占用从新输入
			}
			cout << "课程名称:"; cin >> n;
			cout << "课程类型:"; cin >> t;
			cout << "课程学分:"; cin >> c;
			cout << "课程总学时:"; cin >> s;
			cout << "课程理论学时:"; cin >> tP;
			cout << "课程实验学时:"; cin >> eP;*/
			cin >> bh >> n >> t >> c >> s >> tP >> eP;
			csData[num].initCourse(bh, n, t, c, s, tP, eP);
			num++;
			cout << "是否继续输入（Y/N）：" << endl;
			cin >> sel;
		}
	}
	int findBH(int bh)
	{
		for (int i = 0; i < num; i++)
			if (bh == csData[i].getCourseNo())
				return 1;
		return 0;
	}
	void print()
	{
		cout << "\n\n\t\t                                课程列表" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		cout << "\t\t    编号        名称         性质      学分    总学时   理论学时   实验学时" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		for (int i = 0; i < num; i++)
		{
			csData[i].print();
		}
		cout << "\t\t   ------------------------------------------------------------------------\n\n" << endl;
	}
	void findCourse()
	{
		int sel;
		while (1)
		{
			menu::menu8();
			cout << "请输入你的选择：";
			cin >> sel;
			if (sel == 1)
			{
				int bh;
				int flag = 0;
				cout << "请输入课程编号：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == csData[i].getCourseNo())
					{
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						cout << "\t\t    编号        名称         性质      学分    总学时   理论学时   实验学时" << endl;
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						csData[i].print();
						cout << "\t\t    ------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该课程！" << endl;
			}
			if (sel == 2)
			{
				char bh[31];
				int flag = 0;
				cout << "请输入课程名称：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, csData[i].getCourseName()))
					{
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						cout << "\t\t    编号        名称         性质      学分    总学时   理论学时   实验学时" << endl;
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						csData[i].print();
						cout << "\t\t    ------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该课程！";
			}
			if (sel == 0)
				break;
		}
	}
	void modifyCourse()
	{
		int flag = 0, bh, s, tP, eP;
		char n[21], t[10];
		float c;
		cout << "请输入学院编号：";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
			{
				cout << "\t\t   ------------------------------------------------------------------------" << endl;
				cout << "\t\t    编号    名称         性质       学分     总学时    理论学时    实验学时" << endl;
				cout << "\t\t   ------------------------------------------------------------------------" << endl;
				csData[i].print();
				cout << "\t\t    ------------------------------------------------------------------------" << endl;
				cout << "请输入新的课程名称:"; cin >> n; csData[i].setName(n);
				cout << "请输入新的课程类型:"; cin >> t; csData[i].setType(t);
				cout << "请输入新的课程学分:"; cin >> c; csData[i].setCredit(c);
				cout << "请输入新的课程总学时:"; cin >> s; csData[i].setSumPeriod(s);
				cout << "请输入新的课程理论学时:"; cin >> tP; csData[i].setThPeiod(tP);
				cout << "请输入新的课程实验学时:"; cin >> eP; csData[i].setExpPeriod(eP);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "没找到该学院！" << endl;

	}
	void deleteCourse(int bh)
	{
		int flag = 0, i = 0;
		for (i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << csData[i].getCourseName() << " 已被删除！" << endl;
			for (; i < num; i++)
			{
				csData[i] = csData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "没找到该课程！";
	}
	char *findCourseName(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getCourseName();
		}
		return NULL;
	}
	char *findCourseType(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getCourseType();
		}
		return NULL;
	}
	float findCourseCredit(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getCourseCredit();
		}
		return NULL;
	}
	int findCourseSumPeriod(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getSumPeriod();
		}
		return NULL;
	}	
	int findCourseThPeriod(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getThPeriod();
		}
		return NULL;
	}
	int findCourseExpPeriod(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
				return csData[i].getExpPeriod();
		}
		return NULL;
	}

};
