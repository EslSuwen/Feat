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
		ifstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CourseData.dat", ios::binary);			//��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&csData[num], sizeof(Course));	// �������е�����Ԫ��һ��һ����д���ļ�
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	~CourseSet()
	{
		ofstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CourseData.dat", ios::binary);            //��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&csData[i], sizeof(Course));    // �������е�����Ԫ��һ��һ����д���ļ�
		}
		f2.close();                                         //�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	void input()
	{
		int bh, s, tP, eP;
		char n[21], t[10], sel = 'y';
		float c;
		while (sel == 'y' || sel == 'Y')
		{
			/*cout << "�γ̱��:"; cin >> bh;
			if (findBH(bh))									//����������Ƿ�ռ��
			{
				cout << " �ñ���ѱ�ռ��!" << endl;
				continue;									//��ű�ռ�ô�������
			}
			cout << "�γ�����:"; cin >> n;
			cout << "�γ�����:"; cin >> t;
			cout << "�γ�ѧ��:"; cin >> c;
			cout << "�γ���ѧʱ:"; cin >> s;
			cout << "�γ�����ѧʱ:"; cin >> tP;
			cout << "�γ�ʵ��ѧʱ:"; cin >> eP;*/
			cin >> bh >> n >> t >> c >> s >> tP >> eP;
			csData[num].initCourse(bh, n, t, c, s, tP, eP);
			num++;
			cout << "�Ƿ�������루Y/N����" << endl;
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
		cout << "\n\n\t\t                                �γ��б�" << endl;
		cout << "\t\t   ------------------------------------------------------------------------" << endl;
		cout << "\t\t    ���        ����         ����      ѧ��    ��ѧʱ   ����ѧʱ   ʵ��ѧʱ" << endl;
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
			cout << "���������ѡ��";
			cin >> sel;
			if (sel == 1)
			{
				int bh;
				int flag = 0;
				cout << "������γ̱�ţ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (bh == csData[i].getCourseNo())
					{
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						cout << "\t\t    ���        ����         ����      ѧ��    ��ѧʱ   ����ѧʱ   ʵ��ѧʱ" << endl;
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						csData[i].print();
						cout << "\t\t    ------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ��ÿγ̣�" << endl;
			}
			if (sel == 2)
			{
				char bh[31];
				int flag = 0;
				cout << "������γ����ƣ�";
				cin >> bh;
				for (int i = 0; i < num; i++)
				{
					if (!strcmp(bh, csData[i].getCourseName()))
					{
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						cout << "\t\t    ���        ����         ����      ѧ��    ��ѧʱ   ����ѧʱ   ʵ��ѧʱ" << endl;
						cout << "\t\t   ------------------------------------------------------------------------" << endl;
						csData[i].print();
						cout << "\t\t    ------------------------------------------------------------------------" << endl;
						flag = 1;
					}
				}
				if (flag == 0)
					cout << "û�ҵ��ÿγ̣�";
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
		cout << "������ѧԺ��ţ�";
		cin >> bh;
		for (int i = 0; i < num; i++)
		{
			if (bh == csData[i].getCourseNo())
			{
				cout << "\t\t   ------------------------------------------------------------------------" << endl;
				cout << "\t\t    ���    ����         ����       ѧ��     ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
				cout << "\t\t   ------------------------------------------------------------------------" << endl;
				csData[i].print();
				cout << "\t\t    ------------------------------------------------------------------------" << endl;
				cout << "�������µĿγ�����:"; cin >> n; csData[i].setName(n);
				cout << "�������µĿγ�����:"; cin >> t; csData[i].setType(t);
				cout << "�������µĿγ�ѧ��:"; cin >> c; csData[i].setCredit(c);
				cout << "�������µĿγ���ѧʱ:"; cin >> s; csData[i].setSumPeriod(s);
				cout << "�������µĿγ�����ѧʱ:"; cin >> tP; csData[i].setThPeiod(tP);
				cout << "�������µĿγ�ʵ��ѧʱ:"; cin >> eP; csData[i].setExpPeriod(eP);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "û�ҵ���ѧԺ��" << endl;

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
			cout << csData[i].getCourseName() << " �ѱ�ɾ����" << endl;
			for (; i < num; i++)
			{
				csData[i] = csData[i + 1];
			}
			num--;
		}
		if (flag == 0)
			cout << "û�ҵ��ÿγ̣�";
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
