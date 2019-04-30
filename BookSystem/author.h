#pragma once
#include "stdafx.h"

class author {
private:
	CString authorNo;
	CString authorName;
	CString authorSex;
	CString authorBirth;
	CString authorIntro;
	CString authorUnit;
public:
	void setAuthor(CString No, CString Name, CString Sex, CString Birth, CString intro, CString Unit)
	{
		authorNo = No;
		authorName = Name;
		authorSex = Sex;
		authorBirth = Birth;
		authorIntro = intro;
		authorUnit = Unit;
	}
	CString getAuthorNo()
	{
		return authorNo;
	}
	CString getAuthorName()
	{
		return authorName;
	}
	CString getAuthorSex()
	{
		return authorSex;
	}
	CString getAuthorBirth()
	{
		return authorBirth;
	}
	CString getAuthorIntro()
	{
		return authorIntro;
	}
	CString getAuthorUnit()
	{
		return authorUnit;
	}
};

class authorSet {
private:
	author auData[100];
	int Num;
	int Cursor;
public:
	authorSet()
	{
		Num = 0;
		Cursor = -1;
		ifstream f1;
		f1.open("AuthorData.dat");
		if(!f1)
		{
			MessageBox(NULL, "打开文件不成功", "警告 ", MB_OK);
			
			return;
		}
		while(f1)
		{
			CString authorNo;
			CString authorName;
			CString authorSex;
			CString authorBirth;
			CString authorIntro;
			CString authorUnit;
			char no[31];
			char name[31];
			char sex[31];
			char birth[31];
			char unit[31];
			char intro[100];
			f1>>no;
			if(!f1)
				break;
			f1>>name>>sex>>birth>>unit>>intro;
			authorNo.Format("%s",no);
			authorName.Format("%s",name);
			authorSex.Format("%s",sex);
			authorBirth.Format("%s",birth);
			authorUnit.Format("%s",unit);
			authorIntro.Format("%s",intro);
			author a;
			a.setAuthor(authorNo,authorName,authorSex,authorBirth,authorIntro,authorUnit);
			setAuthorSet(Num,a);
			Num++;
		}
	}
	~authorSet()
	{
		char no[31];
		char name[31];
		char sex[31];
		char birth[31];
		char unit[31];
		char intro[100];
		ofstream f1;
		f1.open("AuthorData.dat");
		for(int i=0;i<Num;i++)
		{
			transform(auData[i].getAuthorNo(),no);
			transform(auData[i].getAuthorName(),name);
			transform(auData[i].getAuthorSex(),sex);
			transform(auData[i].getAuthorBirth(),birth);
			transform(auData[i].getAuthorUnit(),unit);
			transform(auData[i].getAuthorIntro(),intro);
			f1<<no<<" "<<name<<" "<<sex<<" "<<birth<<" "<<unit<<" "<<intro<<endl;
		}
		f1.close();
		
	}
	void transform(CString s,char* str)
	{
		for(int i=0;i<s.GetLength();i++)
		{
			str[i]=s.GetAt(i);
		}
		str[i]=0;
	}
	void setNum(int n)
	{
		Num = n;
	}
	CString getCurrentAuthorNo()
	{
		return auData[Cursor].getAuthorNo();
	}
	CString getCurrentAuthorName()
	{
		return auData[Cursor].getAuthorName();
	}
	CString getCurrentAuthorSex()
	{
		return auData[Cursor].getAuthorSex();
	}
	CString getCurrentAuthorUnit()
	{
		return auData[Cursor].getAuthorUnit();
	}
	CString getCurrentAuthorBirth()
	{
		return auData[Cursor].getAuthorBirth();
	}
	CString getCurrentAuthorIntro()
	{
		return auData[Cursor].getAuthorIntro();
	}
	int getNum()
	{
		return Num;
	}
	void setAuthorSet(int i, author a)     //代替下面的函数
	{
		if (i >= 100 || i < 0)
		{
			MessageBox(NULL, "数据库中已无法存放数据或存放数据的下标有误", "警告", MB_OK);
		}
		else
		{
			auData[i] = a;
		}
		Cursor = i;
	}
	int  setAuthorSet(author a)
	{
		if (Cursor == -1)
			return 0;
		else
		{
			auData[Cursor] = a;
			return 1;
		}
	}
	void deleteAuthor(CString bh)
	{
		for (int i = 0; i < Num; i++)
		{
			if (auData[i].getAuthorName() == bh)
			{
				for (int j = i + 1; j < Num; j++)
				{
					auData[j - 1] = auData[j];
				}
				Num--;
				return;
			}
		}
	}
	int moveToFirst()
	{
		if (Cursor == -1)
			return 0;
		else
			Cursor = 0;
		return 1;
		
	}
	int  moveToEnd()
	{
		if (Cursor == -1)
			return 0;
		else
			Cursor = Num - 1;
		return 1;
	}
	int moveToNext()
	{
		if (Cursor == -1)
			return 0;
		else
		{
			if (Cursor != Num - 1)
				Cursor = Cursor + 1;
		}
		return 1;
	}
	int moveToBefore()
	{
		if (Cursor == -1)
			return 0;
		else
		{
			if (Cursor != 0)
				Cursor = Cursor - 1;
		}
		return 1;
	}
	int locationAuthorNo(CString No)
	{
		for (int i = 0; i < Num; i++)
		{
			if (auData[i].getAuthorNo() == No)
			{
				Cursor = i;
				return 1;
			}
		}
		return 0;
	}
	
	int ifAuthor(CString name)
	{
		for (int i = 0; i < Num; i++)
		{
			if (auData[i].getAuthorName()==name)
			{
				Cursor = i;
				return 1;
			}
		}
		return 0;
	}
};