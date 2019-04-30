#pragma once
#include "stdafx.h"
#include "fstream.h"

class press{
private:
	CString pressNo;
	CString pressName;
	CString pressLeader;
	CString pressDivision;
	CString pressIntro;
public:
	void setPress(CString No,CString Name,CString Leader,CString Division,CString Intro)
	{
		pressNo=No;
		pressName=Name;
		pressLeader=Leader;
		pressDivision=Division;
		pressIntro=Intro;
	}
	CString getPressNo()
	{
		return pressNo;
	}
	CString getPressName()
	{
		return pressName;
	}
	CString getPressLeader()
	{
		return pressLeader;
	}
	CString getPressDivision()
	{
		return pressDivision;
	}
	CString getPressIntro()
	{
		return pressIntro;
	}
};



class pressSet{
private:
	press phData[100];
	int Num;
	int Cursor;
public:
	pressSet()
	{
		Num=0;
		Cursor=-1;
		ifstream f1;
		f1.open("PressData.dat");
		if(!f1)
		{
			MessageBox(NULL, "打开文件不成功", "警告 ", MB_OK);
			
			return;
		}
		while(f1)
		{
			CString No;
			CString Name;
			CString Leader;
			CString Division;
			CString Intro;
			char no[31];
			char name[31];
			char leader[31];
			char division[31];
			char intro[100];
			f1>>no;
			if(!f1)
				break;
			f1>>name>>leader>>division>>intro;
			No.Format("%s",no);
			Name.Format("%s",name);
			Leader.Format("%s",leader);
			Division.Format("%s",division);
			Intro.Format("%s",intro);
			press a;
			a.setPress(No,Name,Leader,Division,Intro);
			setPressSet(Num,a);
			Num++;
		}
	}
	~pressSet()
	{
		char no[31];
		char name[31];
		char leader[31];
		char division[31];
		char intro[100];
		ofstream f1;
		f1.open("PressData.dat");
		for(int i=0;i<Num;i++)
		{
			transform(phData[i].getPressNo(),no);
			transform(phData[i].getPressName(),name);
			transform(phData[i].getPressLeader(),leader);
			transform(phData[i].getPressDivision(),division);
			transform(phData[i].getPressIntro(),intro);
			f1<<no<<" "<<name<<" "<<leader<<" "<<division<<" "<<intro<<endl;
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
	int getCursor()
	{
		return Cursor;
	}
	void setNum(int n)
	{
		Num=n;
	}
	CString getCurrentPressNo()
	{
		return phData[Cursor].getPressNo();
	}
	CString getCurrentPressName()
	{
		return phData[Cursor].getPressName();
	}
	CString getCurrentPressLeader()
	{
		return phData[Cursor].getPressLeader();
	}
	CString getCurrentPressDivision()
	{
		return phData[Cursor].getPressDivision();
	}
	CString getCurrentPressIntro()
	{
		return phData[Cursor].getPressIntro();
	}
	int getNum()
	{
		return Num;
	}
    void setPressSet(int i,press a)     //代替下面的函数
	{
		if (i>=100 || i<0)
		{
			MessageBox(NULL,"数据库中已无法存放数据或存放数据的下标有误","警告",MB_OK);
		}
		else
		{
			phData[i]=a;
		}
		Cursor=i;
	}
	int  setPressSet(press a)
	{
		if (Cursor==-1)
			return 0;
		else
		{
			phData[Cursor]=a;
			return 1;
		}
	}
	void deletePress(CString bh)
	{
		for (int i=0;i<Num;i++)
		{
			if (phData[i].getPressName()==bh)
			{
				for (int j=i+1;j<Num;j++)
				{
					phData[j-1]=phData[j];
				}
				Num--;
				return;
			}
		}
	}
	int moveToFirst()
	{
		if (Cursor==-1)
			return 0;
		else
			Cursor=0;
		return 1;
		
	}
	int  moveToEnd()
	{
		if (Cursor==-1)
			return 0;
		else
			Cursor=Num-1;
		return 1;
	}
	int moveToNext()
	{
		if (Cursor==-1)
			return 0;
		else
		{
			if (Cursor!=Num-1)
				Cursor=Cursor+1;
		}
		return 1;
	}
	int moveToBefore()
	{
		if (Cursor==-1)
			return 0;
		else
		{
			if (Cursor!=0)
				Cursor=Cursor-1;
		}
		return 1;
	}
	int locationPressNo(CString No)
	{
		for (int i=0;i<Num;i++)
		{
			if (phData[i].getPressNo()==No)
			{
				Cursor=i;
				return 1;
			}
		}
		return 0;
	}

	int ifPress(CString name)
	{
		for (int i=0;i<Num;i++)
		{
			if (phData[i].getPressName()==name)
			{
				Cursor=i;
				return 1;
			} 
		}
		return 0;
	}
};