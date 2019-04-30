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
		ifstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CvData.dat", ios::binary);			//��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			return;

		}
		while (1)
		{
			f2.read((char*)&cvData[num], sizeof(Cv));	// �������е�����Ԫ��һ��һ����д���ļ�
			if (f2.eof())
				break;
			num++;
		}
		f2.close();											//�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	~CvSet()
	{
		ofstream f2;										//����һ��������ļ����󣬼��ļ�������
		f2.open("CvData.dat", ios::binary);            //��һ���ļ�������ļ������ڣ����г�����Ϣ
		if (!f2)
		{
			cout << "Save Data Error!" << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			f2.write((char*)&cvData[i], sizeof(Cv));    // �������е�����Ԫ��һ��һ����д���ļ�
		}
		f2.close();                                         //�ر��ļ����Ͽ� f2������ļ��Ĺ���
	}
	void input()
	{
		char sel = 'y';
		int sNo, cNo;
		while (sel == 'y' || sel == 'Y')
		{
			cout << "ѧ��ѧ�ţ�"; cin >> sNo;
			cout << "�γ̱�ţ�"; cin >> cNo;
			cvData[num].initCv(sNo, cNo);
			num++;
			cout << "�Ƿ�������루Y/N����" << endl;
			cin >> sel;
		}

	}
	void print(StudentSet s, CourseSet cs)
	{
		cout << "\n\n\t\t                                ѡ���б�" << endl;
		cout << "\t\t    ---------------------------------------------------------------------------" << endl;
		cout << "\t\t      ѧ������   ѧ��ѧ��   �γ̱��   �γ�����  �γ̳ɼ�   ����  ѧ��   ��ѧʱ" << endl;
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
				cout << "������γ̱�ţ�";
				cin >> bh;
				if (cs.findBH(bh))
				{
					cout << "\t\t    ---------------------------------------------------------------------------" << endl;
					cout << "\t\t      ѧ������   ѧ��ѧ��   �γ̱��   �γ�����  �γ̳ɼ�   ����  ѧ��   ��ѧʱ" << endl;
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
					cout << "\t\t                                ѧ���б�" << endl;
					cout << "\t\t  ------------------------------------------------------------------------" << endl;
					cout << "\t\t   ѧ��    ����   �Ա�        רҵ                ѧԺ          ��ϵ��ʽ" << endl;
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
					cout << "û�ҵ��ÿγ̣�";
			}
			if (sel == 2)
			{
				int bh;
				int flag = 0;
				cout << "������ѧ��ѧ�ţ�";
				cin >> bh;
				cout << "\t\t    ---------------------------------------------------------------------------" << endl;
				cout << "\t\t      ѧ������   ѧ��ѧ��   �γ̱��   �γ�����  �γ̳ɼ�   ����  ѧ��   ��ѧʱ" << endl;
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
					cout << "û�ҵ���ѧ����";
			}
			if (sel == 0)
				break;
		}
	}
	void deleteCv()
	{
		int bh, zh;
		cout << "������ѧ�ţ�"; cin >> bh;
		cout << "������γ̱�ţ�"; cin >> zh;
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
			cout << "δ�ҵ���ѡ����Ϣ��";
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
		cout << "������γ̱�ţ�";
		cin >> bh;
		if (cs.findBH(bh))
		{
			cout << "\n\n\t\t                                �γ���Ϣ" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
			cout << "\t\t                                ѧ���б�" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t ѧ��       ����     �Ա�           רҵ            ѧԺ        ��ϵ��ʽ" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			for (int i = 0; i < num; i++)
			{
				float grade;
				if (bh == cvData[i].getCourseNo())
				{
					s.studentFind(c, m, cvData[i].getStudNo());
					cout << "����������ÿγ̳ɼ���" << endl; cin >> grade;
					cvData[i].setGrade(grade);
				}
			}
			cout << "\t\t------------------------------------------------------------------------\n\n" << endl;
			flag = 1;
		}
		if (flag == 0)
			cout << "û�ҵ��ÿγ̣�";
	}
	void courseGradeOut(StudentSet s,CourseSet cs)
	{
		int bh;
		cout << "������γ̱�ţ�";
		cin >> bh;
		if (cs.findBH(bh))
		{
			cout << "\n\n\t\t                                �γ���Ϣ" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\t ���    ����         ����    ѧ��        ��ѧʱ    ����ѧʱ    ʵ��ѧʱ" << endl;
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
			cout << "\n\t\t                              ѧ���ɼ��б�" << endl;
			cout << "\t\t------------------------------------------------------------------------" << endl;
			cout << "\t\tѧ������   ѧ��ѧ��        �γ̱��   �γ�����  �γ̳ɼ�    ����  ѧ�� " << endl;
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
			cout << "δ�ҵ��ÿγ̣�" << endl;
	}
	void studGradeOut(StudentSet s,CourseSet cs)
	{
		int bh,flag = 0;
		cout << "������ѧ��ѧ�ţ�";
		cin >> bh;
		cout << "\n\t\t                              ѧ���ɼ��б�" << endl;
		cout << "\t\t------------------------------------------------------------------------" << endl;
		cout << "\t\tѧ������   ѧ��ѧ��        �γ̱��   �γ�����  �γ̳ɼ�    ����  ѧ�� " << endl;
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
			cout << "û�ҵ���ѧ����";
	}
	void rankGradeOut(StudentSet s,CourseSet cs)
	{
		char str1[10] = { "����" };
		char str2[10] = { "��ѡ" };
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
