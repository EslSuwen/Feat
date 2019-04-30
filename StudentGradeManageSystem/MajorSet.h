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
		ifstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("MajorData.dat", ios::binary);			//��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			return;
		}
		while (1)
		{
			f2.read((char*)&mData[num], sizeof(Major));	// �������е�����Ԫ��һ��һ����д���ļ�
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	~MajorSet()
	{
		ofstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("MajorData.dat", ios::binary);            //��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&mData[i], sizeof(Major));    // �������е�����Ԫ��һ��һ����д���ļ�
		}
		f2.close();                                         //�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	void input()
	{
		int bh, y, n;
		char sel = 'y';
		char mc[31];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "רҵ���:"; cin >> bh;
			if (findMajorBH(bh))									//����������Ƿ�ռ��
			{
				cout << " �ñ���ѱ�ռ��!" << endl;
				continue;									//��ű�ռ�ô�������
			}
			cout << "רҵ����:"; cin >> mc;
			cout << "����ѧԺ:"; cin >> n;
			cout << "רҵѧ��:"; cin >> y;
			mData[num].initMajor(bh, n, mc, y);
			num++;
			cout << "�Ƿ�������루Y/N����" << endl;
			cin >> sel;
		}
	}
	void print(CollegeSet c)
	{
		cout << "\t\t                             רҵ�б�" << endl;
		cout << "\t\t---------------------------------------------------------------------" << endl;
		cout << "\t\tרҵ���              רҵ����           ѧ��                ����ѧԺ" << endl;
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
			cout << "���������ѡ��";
			cin >> sel;
			if (sel == 1)
			{
				char bh[31];
				int flag = 0;
				cout << "������רҵ���ƣ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, mData[i].getMajorName()))
					{
						cout << "\t\t                             רҵ�б�" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << "\t\tרҵ���              רҵ����           ѧ��                ����ѧԺ" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						mData[i].print(c, mData[i].getCollegeNo());
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���רҵ��";
			}
			if (sel == 2)
			{
				int bh;
				int i = 0, flag = 0;
				cout << "����������ѧԺ��ţ�";
				cin >> bh;
				cout << "\t\t                             רҵ�б�" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << "\t\tרҵ���              רҵ����           ѧ��                ����ѧԺ" << endl;
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
					cout << "û�ҵ���רҵ��";
			}
			if (sel == 3)
			{
				int flag = 0, bh;
				cout << "������רҵ��ţ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == mData[i].getMajorNo())
					{
						cout << "\t\t                             רҵ�б�" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << "\t\tרҵ���              רҵ����           ѧ��                ����ѧԺ" << endl;
						cout << "\t\t---------------------------------------------------------------------" << endl;
						mData[i].print(c, mData[i].getCollegeNo());
						cout << "\t\t---------------------------------------------------------------------" << endl;
						cout << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���רҵ��";
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
		cout << "������רҵ��ţ�";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == mData[i].getMajorNo())
			{
				cout << "\t\t                             רҵ�б�" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << "\t\tרҵ���          רҵ����                       ѧ��        ����ѧԺ" << endl;
				cout << "\t\t---------------------------------------------------------------------" << endl;
				mData[i].print(c, mData[i].getCollegeNo());
				cout << "\t\t---------------------------------------------------------------------" << endl;
				cout << endl;
				cout << "�������µ�רҵ���ƣ�"; cin >> majorName; mData[i].setMajorName(majorName);
				cout << "�������µ�רҵѧ�ƣ�"; cin >> my; mData[i].setMajorYear(my);
				cout << "�������µ�רҵ����ѧԺ��ţ�"; cin >> cn; mData[i].setCollegeNo(cn);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "û�ҵ���ѧԺ��" << endl;

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
			cout << mData[i].getMajorName() << " �ѱ�ɾ����" << endl;
			for (; i < num; i++)
			{
				mData[i] = mData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "û�ҵ���רҵ��";
	}
};

