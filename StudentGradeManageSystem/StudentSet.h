#pragma once
#include "stdafx.h"
class StudentSet {
private:
	Student sData[100];
	int num;
public:
	StudentSet()
	{
		num = 0;
		ifstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("StudentData.dat", ios::binary);			//打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&sData[num], sizeof(Student));	// 将数组中的数据元素一个一个地写入文件
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//关闭文件，断开 f2与具体文件的关联
	}
	~StudentSet()
	{
		ofstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("StudentData.dat", ios::binary);            //打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&sData[i], sizeof(Student));    // 将数组中的数据元素一个一个地写入文件
		}
		f2.close();                                         //关闭文件，断开 f2与具体文件的关联
	}
	void input()
	{
		int bh, cbh;
		char sel = 'y';
		char mz[31], ph[31], sex[8];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "学生学号:"; cin >> bh;
			if (findBH(bh))									//检查输入编号是否被占用
			{
				cout << " 该学号已被占用!" << endl;
				continue;									//编号被占用从新输入
			}
			cout << "学生姓名:"; cin >> mz;
			cout << "专业编号:"; cin >> cbh;
			cout << "性别:"; cin >> sex;
			cout << "联系电话:"; cin >> ph;
			//cin >> mz >> sex >> cbh >> bh >> ph;
			sData[num].initStudent(bh, cbh, mz, sex, ph);
			num++;
			cout << "是否继续输入（Y/N）：" << endl;
			cin >> sel;
		}

	}
	int findBH(int bh)
	{
		for (int i = 0; i < num; i++)
			if (bh == sData[i].getStudNo())
				return 1;
		return 0;
	}
	void print(CollegeSet c, MajorSet m)
	{
		cout << "\t\t                                   学生列表" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		cout << "\t\t    学号    姓名   性别                专业           学院        联系方式" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		for (int i = 0; i < num; i++)
		{
			sData[i].print(c, m);
		}
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
	}
	void findStudent(CollegeSet c, MajorSet m)
	{
		int sel;
		while (1)
		{
			menu::menu6();
			cout << "请输入你的选择：";
			cin >> sel;
			if (sel == 1)
			{
				char name[31];
				int flag = 0;
				cout << "请输入学生姓名：";
				cin >> name;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(name, sData[i].getStudName()))
					{
						cout << "\t\t                                学生列表" << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						cout << "\t\t  学号    姓名   性别                专业           学院        联系方式" << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						sData[i].print(c, m);
						cout << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该学生！";
			}
			if (sel == 2)
			{
				int flag = 0, bh;
				cout << "请输入学生学号：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == sData[i].getStudNo())
					{
						{
							cout << "\t\t                                学生列表" << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							cout << "\t\t  学号    姓名   性别                专业           学院        联系方式" << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							sData[i].print(c, m);
							cout << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							flag = 1;
						}
					}
				}
				if (flag == 0)
					cout << "没找到该学生！";
			}
			if (sel == 0)
				break;
		}
	}
	void modifyStudent(CollegeSet c, MajorSet m)
	{
		int i = 0, flag = 0, bh;
		char name[31], ph[31], sex[8];
		int mn;
		cout << "请输入学生学号：";
		cin >> bh;
		for (; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
			{
				cout << "\t\t                                学生列表" << endl;
				cout << "\t\t------------------------------------------------------------------------" << endl;
				cout << "\t\t 学号    姓名   性别        专业                学院          联系方式" << endl;
				cout << "\t\t------------------------------------------------------------------------" << endl;
				sData[i].print(c, m);
				cout << endl;
				cout << "\t\t------------------------------------------------------------------------" << endl;
				flag = 1;
				break;
			}

		}
		if (flag)
		{
			cout << "姓名："; cin >> name; sData[i].setName(name);
			cout << "性别："; cin >> sex; sData[i].setSex(sex);
			cout << "所属专业编号："; cin >> mn; sData[i].setMajorNo(mn);
			cout << "联系电话："; cin >> ph; sData[i].setPhnoeNumber(ph);
		}
		else
			cout << "没找到该学生！";

	}
	void deleteStudent(int bh)
	{
		int flag = 0, i = 0;
		for (i = 0; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << sData[i].getStudName() << " 已被删除！" << endl;
			for (; i < num; i++)
			{
				sData[i] = sData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "没找到该学生！";
	}
	char *findStudName(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
				return sData[i].getStudName();
		}
		return NULL;
	}
	void studentFind(CollegeSet c, MajorSet m, int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
			{
				cout << "\t\t" << setw(8) << sData[i].getStudNo() << setw(8) << sData[i].getStudName() << setw(8) << sData[i].getSex();
				cout << setw(18) << m.findMajorName(sData[i].getMajorNo()) << setw(18) << c.findCollegeName(m.findCollegeNo(sData[i].getMajorNo()));
				cout << setw(12) << sData[i].getPhoneNumber() << endl;
			}
		}
	}
	void gradeSet(int bh, float grade, float credit)
	{
		for (int i = 0; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
			{
				sData[i].setAvgGrade(grade, credit);
			}
		}
	}
	void gradeCompute()
	{
		for (int i = 0; i < num; i++)
		{
			sData[i].computeGrade();
		}
	}
	void gradeRankOut()
	{
		cout << "\n\n\t\t        学生成绩列表" << endl;
		cout << "\t\t  ---------------------------------------" << endl;
		cout << "\t\t  学生姓名               平均成绩" << endl;
		Student t;
		for (int i = 0; i < num; i++)
			for (int j = i + 1; j < num; j++)
				if (sData[i].getAvgGrade() < sData[j].getAvgGrade())
				{
					t = sData[i];
					sData[i] = sData[j];
					sData[j] = t;
				}
		for (int i = 0; i < num; i++)
			cout << "\t\t   " << setw(6) << sData[i].getStudName() << setw(24) << sData[i].getAvgGrade() << endl;
		cout << "\t\t  -----------------------------------------\n\n" << endl;
	}
};

