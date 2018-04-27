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
		ifstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CollegeData.dat", ios::binary);			//��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&cData[num], sizeof(College));	// �������е�����Ԫ��һ��һ����д���ļ�
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	~CollegeSet()
	{
		ofstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CollegeData.dat", ios::binary);            //��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&cData[i], sizeof(College));    // �������е�����Ԫ��һ��һ����д���ļ�
		}
		f2.close();                                         //�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	void input()
	{
		int bh;
		char sel = 'y';
		char mc[31], yz[31];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "ѧԺ���:"; cin >> bh;
			if (findBH(bh))									//����������Ƿ�ռ��
			{
				cout << " �ñ���ѱ�ռ��!" << endl;
				continue;									//��ű�ռ�ô�������
			}
			cout << "ѧԺ����:"; cin >> mc;
			cout << "ѧԺԺ��:"; cin >> yz;
			cData[num].initCollege(bh, mc, yz);
			num++;
			cout << "�Ƿ�������루Y/N����" << endl;
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
		cout << "\n\n\t\t                  ѧԺ��Ϣ�б�" << endl;
		cout << "\t\t   ----------------------------------------------" << endl;
		cout << "\t\t   ѧԺ���                 ѧԺ����        Ժ��" << endl;
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
			cout << "���������ѡ��";
			cin >> sel;
			if (sel == 1)
			{
				char bh[31];
				int flag = 0;
				cout << "������ѧԺ���ƣ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, cData[i].getCollegeName()))
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t   ѧԺ���                   ѧԺ����      Ժ��" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���ѧԺ��" << endl;
			}
			if (sel == 2)
			{
				char bh[31];
				int flag = 0;
				cout << "������Ժ��������";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, cData[i].getDeanName()))
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t   ѧԺ���                   ѧԺ����      Ժ��" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���ѧԺ��";
			}
			if (sel == 3)
			{
				int bh, flag = 0;
				cout << "������ѧԺ��ţ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == cData[i].getCollegeNo())
					{
						cout << "\t\t   ----------------------------------------------" << endl;
						cout << "\t\t    ѧԺ���                   ѧԺ����      Ժ��" << endl;
						cData[i].print();
						cout << "\t\t   ----------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���ѧԺ��" << endl;
			}
			if (sel == 0)
				break;
		}
	}
	void modifyCollege()
	{
		int flag = 0, bh;
		char collegeName[31], deanName[31];
		cout << "������ѧԺ��ţ�";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == cData[i].getCollegeNo())
			{
				cout << "\t\t   ----------------------------------------------" << endl;
				cout << "\t\t   ѧԺ���      ѧԺ����                 Ժ��" << endl;
				cData[i].print();
				cout << "\t\t   ----------------------------------------------" << endl;
				cout << "�������µ�ѧԺ���ƣ� "; cin >> collegeName; cData[i].setCollegeName(collegeName);
				cout << "�������µ�Ժ�������� "; cin >> deanName; cData[i].setDeanName(deanName);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "û�ҵ���ѧԺ��" << endl;

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
				cout << cData[i].getCollegeName() << " �ѱ�ɾ����" << endl;
				for (; i < num; i++)
				{
					cData[i] = cData[i + 1];
				}
				num--;
			}
			if (flag == 0)
				cout << "û�ҵ���ѧԺ��";
	}
};

