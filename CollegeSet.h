#pragma once
#include "stdafx.h"

//class MajorSet;

class CollegeSet {
private:
	College cData[100];
	int num;
public:
	CollegeSet()
	{
		num = 0;
		ifstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CollegeData.dat", ios::binary);			//打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&cData[num], sizeof(College));	// 将数组中的数据元素一个一个地写入文件
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//关闭文件，断开 f2与具体文件的关联
	}
	~CollegeSet()
	{
		ofstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("CollegeData.dat", ios::binary);            //打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&cData[i], sizeof(College));    // 将数组中的数据元素一个一个地写入文件
		}
		f2.close();                                         //关闭文件，断开 f2与具体文件的关联
	}
	void input()
	{
		int bh;
		char sel = 'y';
		char mc[31], yz[31];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "学院编号:"; cin >> bh;
			if (findBH(bh))									//检查输入编号是否被占用
			{
				cout << " 该编号已被占用!" << endl;
				continue;									//编号被占用从新输入
			}
			cout << "学院名称:"; cin >> mc;
			cout << "学院院长:"; cin >> yz;
			cData[num].initCollege(bh, mc, yz);
			num++;
			cout << "是否继续输入（Y/N）：" << endl;
			cin >> sel;
		}

	}
	int findBH(int bh)
	{
		for (int i = 0; i < num; i++)
			if (bh == cData[i].getCollegeNo())
				return 1;
		return 0;
	}
	void print()
	{
		cout << "\n\n\t\t                  学院信息列表" << endl;
		cout << "\t\t   ----------------------------------------------" << endl;
		cout << "\t\t   学院编号                 学院名称        院长" << endl;
		cout << "\t\t   ----------------------------------------------" << endl;
		for (int i = 0; i < num; i++)
		{
			cData[i].print();
		}
		cout << "\t\t   ----------------------------------------------\n\n" << endl;
	}
	void findCollege()
	{
		int sel;
		while (1)
		{
			menu::menu4();
			cout << "请输入你的选择：";
			cin >> sel;
			if (sel == 1)
			{
				char bh[31];
				int flag = 0;
				cout << "请输入学院名称：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, cData[i].getCollegeName()))
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t   学院编号                   学院名称      院长" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该学院！" << endl;
			}
			if (sel == 2)
			{
				char bh[31];
				int flag = 0;
				cout << "请输入院长姓名：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, cData[i].getDeanName()))
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t   学院编号                   学院名称      院长" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该学院！";
			}
			if (sel == 3)
			{
				int bh, flag = 0;
				cout << "请输入学院编号：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == cData[i].getCollegeNo())
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t    学院编号                   学院名称      院长" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该学院！" << endl;
			}
			if (sel == 0)
				break;
		}
	}
	void modifyCollege()
	{
		int flag = 0, bh;
		char collegeName[31], deanName[31];
		cout << "请输入学院编号：";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == cData[i].getCollegeNo())
			{
				cout << "\t\t   ----------------------------------------------" << endl;
				cout << "\t\t   学院编号      学院名称                 院长" << endl;
				cData[i].print();
				cout << "\t\t   ----------------------------------------------" << endl;
				cout << "请输入新的学院名称： "; cin >> collegeName; cData[i].setCollegeName(collegeName);
				cout << "请输入新的院长姓名： "; cin >> deanName; cData[i].setDeanName(deanName);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "没找到该学院！" << endl;

	}
	char *findCollegeName(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (cData[i].getCollegeNo() == bh)
				return cData[i].getCollegeName();
		}
		return NULL;
	}
	void deleteCollege(int bh)
	{
		int flag = 0;
			int i = 0;
			for (i = 0; i < num; i++)
			{
				if (bh == cData[i].getCollegeNo())
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				cout << cData[i].getCollegeName() << " 已被删除！" << endl;
				for (; i < num; i++)
				{
					cData[i] = cData[i + 1];
				}
				num--;
			}
			if (flag == 0)
				cout << "没找到该学院！";
	}
};

