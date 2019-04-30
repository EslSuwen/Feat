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
		ifstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("StudentData.dat", ios::binary);			//��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&sData[num], sizeof(Student));	// �������е�����Ԫ��һ��һ����д���ļ�
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	~StudentSet()
	{
		ofstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("StudentData.dat", ios::binary);            //��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&sData[i], sizeof(Student));    // �������е�����Ԫ��һ��һ����д���ļ�
		}
		f2.close();                                         //�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	void input()
	{
		int bh, cbh;
		char sel = 'y';
		char mz[31], ph[31], sex[8];
		while (sel == 'y' || sel == 'Y')
		{
			cout << "ѧ��ѧ��:"; cin >> bh;
			if (findBH(bh))									//����������Ƿ�ռ��
			{
				cout << " ��ѧ���ѱ�ռ��!" << endl;
				continue;									//��ű�ռ�ô�������
			}
			cout << "ѧ������:"; cin >> mz;
			cout << "רҵ���:"; cin >> cbh;
			cout << "�Ա�:"; cin >> sex;
			cout << "��ϵ�绰:"; cin >> ph;
			//cin >> mz >> sex >> cbh >> bh >> ph;
			sData[num].initStudent(bh, cbh, mz, sex, ph);
			num++;
			cout << "�Ƿ�������루Y/N����" << endl;
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
		cout << "\t\t                                   ѧ���б�" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		cout << "\t\t    ѧ��    ����   �Ա�                רҵ           ѧԺ        ��ϵ��ʽ" << endl;
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
			cout << "���������ѡ��";
			cin >> sel;
			if (sel == 1)
			{
				char name[31];
				int flag = 0;
				cout << "������ѧ��������";
				cin >> name;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(name, sData[i].getStudName()))
					{
						cout << "\t\t                                ѧ���б�" << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						cout << "\t\t  ѧ��    ����   �Ա�                רҵ           ѧԺ        ��ϵ��ʽ" << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						sData[i].print(c, m);
						cout << endl;
						cout << "\t\t------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ���ѧ����";
			}
			if (sel == 2)
			{
				int flag = 0, bh;
				cout << "������ѧ��ѧ�ţ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == sData[i].getStudNo())
					{
						{
							cout << "\t\t                                ѧ���б�" << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							cout << "\t\t  ѧ��    ����   �Ա�                רҵ           ѧԺ        ��ϵ��ʽ" << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							sData[i].print(c, m);
							cout << endl;
							cout << "\t\t------------------------------------------------------------------------" << endl;
							flag = 1;
						}
					}
				}
				if (flag == 0)
					cout << "û�ҵ���ѧ����";
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
		cout << "������ѧ��ѧ�ţ�";
		cin >> bh;
		for (; i < num; i++)
		{
			if (bh == sData[i].getStudNo())
			{
				cout << "\t\t                                ѧ���б�" << endl;
				cout << "\t\t------------------------------------------------------------------------" << endl;
				cout << "\t\t ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
			cout << "������"; cin >> name; sData[i].setName(name);
			cout << "�Ա�"; cin >> sex; sData[i].setSex(sex);
			cout << "����רҵ��ţ�"; cin >> mn; sData[i].setMajorNo(mn);
			cout << "��ϵ�绰��"; cin >> ph; sData[i].setPhnoeNumber(ph);
		}
		else
			cout << "û�ҵ���ѧ����";

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
			cout << sData[i].getStudName() << " �ѱ�ɾ����" << endl;
			for (; i < num; i++)
			{
				sData[i] = sData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "û�ҵ���ѧ����";
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
		cout << "\n\n\t\t        ѧ���ɼ��б�" << endl;
		cout << "\t\t  ---------------------------------------" << endl;
		cout << "\t\t  ѧ������               ƽ���ɼ�" << endl;
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

