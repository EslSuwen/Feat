#pragma once

#include "stdafx.h"

class StudentSet;

class MajorSet {
private:
	Major mData[100];
	int num;
public:
	MajorSet()
	{
		num = 0;
		ifstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("MajorData.dat", ios::binary);			//打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			return;
		}
		while (1)
		{
			f2.read((char*)&mData[num], sizeof(Major));	// 将数组中的数据元素一个一个地写入文件
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//关闭文件，断开 f2与具体文件的关联
	}
	~MajorSet()
	{
		ofstream f2;										//定义一个输出流文件对象，即文件流变量
		f2.open("MajorData.dat", ios::binary);            //打开一个文件，如果文件不存在，则有出错信息
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&mData[i], sizeof(Major));    // 将数组中的数据元素一个一个地写入文件
		}
		f2.close();                                         //关闭文件，断开 f2与具体文件的关联
	}
	void input()
	{
		int bh, y, n;
		char sel = 'y';
		char mc[31];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "专业编号:"; cin >> bh;
			if (findMajorBH(bh))									//检查输入编号是否被占用
			{
				cout << " 该编号已被占用!" << endl;
				continue;									//编号被占用从新输入
			}
			cout << "专业名称:"; cin >> mc;
			cout << "所属学院:"; cin >> n;
			cout << "专业学制:"; cin >> y;
			mData[num].initMajor(bh, n, mc, y);
			num++;
			cout << "是否继续输入（Y/N）：" << endl;
			cin >> sel;
		}
	}
	void print(CollegeSet c)
	{
		cout << "\t\t                             专业列表" << endl;
		cout << "\t\t---------------------------------------------------------------------" << endl;
		cout << "\t\t专业编号              专业名称           学制                所属学院" << endl;
		cout << "\t\t---------------------------------------------------------------------" << endl;
		for (int i = 0; i < num; i++)
		{
			mData[i].print(c, mData[i].getCollegeNo());
		}
	}
	void findMajor(CollegeSet c)
	{
		int sel;
		while (1)
		{
			menu::menu5();
			cout << "请输入你的选择：";
			cin >> sel;
			if (sel == 1)
			{
				char bh[31];
				int flag = 0;
				cout << "请输入专业名称：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, mData[i].getMajorName()))
					{
						cout << "\t\t                             专业列表" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << "\t\t专业编号              专业名称           学制                所属学院" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						mData[i].print(c, mData[i].getCollegeNo());
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该专业！";
			}
			if (sel == 2)
			{
				int bh;
				int i = 0, flag = 0;
				cout << "请输入所属学院编号：";
				cin >> bh;
				cout << "\t\t                             专业列表" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << "\t\t专业编号              专业名称           学制                所属学院" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				for (int i = 0; i < num; i++)
				{
					if (bh == mData[i].getCollegeNo())
					{
						mData[i].print(c, mData[i].getCollegeNo());
						flag = 1;
					}
				}
				cout << "\t\t\t---------------------------------------------------------------------" << endl;
				cout << endl;
				if (flag == 0)
					cout << "没找到该专业！";
			}
			if (sel == 3)
			{
				int flag = 0, bh;
				cout << "请输入专业编号：";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == mData[i].getMajorNo())
					{
						cout << "\t\t                             专业列表" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << "\t\t专业编号              专业名称           学制                所属学院" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						mData[i].print(c, mData[i].getCollegeNo());
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "没找到该专业！";
			}
			if (sel == 0)
				break;
		}
	}
	int findMajorBH(int bh)
	{
		for (int i = 0; i < num; i++)
			if (bh == mData[i].getMajorNo())
				return 1;
		return 0;
	}
	int findBH(int bh)
	{
		for (int i = 0; i < num; i++)
			if (bh == mData[i].getCollegeNo())
				return 1;
		return 0;
	}
	void modifyMajor(CollegeSet c)
	{
		int flag = 0, bh, my, cn;
		char majorName[31];
		cout << "请输入专业编号：";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == mData[i].getMajorNo())
			{
				cout << "\t\t                             专业列表" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << "\t\t专业编号          专业名称                       学制        所属学院" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				mData[i].print(c, mData[i].getCollegeNo());
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << endl;
				cout << "请输入新的专业名称："; cin >> majorName; mData[i].setMajorName(majorName);
				cout << "请输入新的专业学制："; cin >> my; mData[i].setMajorYear(my);
				cout << "请输入新的专业所属学院编号："; cin >> cn; mData[i].setCollegeNo(cn);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "没找到该学院！" << endl;

	}
	char *findMajorName(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (mData[i].getMajorNo() == bh)
				return mData[i].getMajorName();
		}
		return NULL;
	}
	int findCollegeNo(int bh)
	{
		for (int i = 0; i < num; i++)
		{
			if (mData[i].getMajorNo() == bh)
				return mData[i].getCollegeNo();
		}
		return NULL;
	}
	void deleteMajor(int bh)
	{
		int flag = 0, i = 0;
		for (i = 0; i < num; i++)
		{
			if (bh == mData[i].getMajorNo())
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << mData[i].getMajorName() << " 已被删除！" << endl;
			for (; i < num; i++)
			{
				mData[i] = mData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "没找到该专业！";
	}
};

