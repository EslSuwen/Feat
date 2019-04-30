#pragma once
#include "stdafx.h"

class book {
private:
	CString bookNo;
	CString bookName;
	CString bookPNo;
	CString bookANo;
	CString bookBirth;
	CString bookIntro;
	CString bookPrice;
public:
	void setBook(CString No, CString Name, CString PNo,CString ANo,CString Birth, CString intro, CString price)
	{
		bookNo = No;
		bookName = Name;
		bookPNo = PNo;
		bookANo = ANo;
		bookBirth = Birth;
		bookIntro = intro;
		bookPrice = price;
	}
	CString getBookNo()
	{
		return bookNo;
	}
	CString getBookName()
	{
		return bookName;
	}
	CString getBookPNo()
	{
		return bookPNo;
	}
	CString getBookANo()
	{
		return bookANo;
	}
	CString getBookBirth()
	{
		return bookBirth;
	}
	CString getBookIntro()
	{
		return bookIntro;
	}
	CString getBookPrice()
	{
		return bookPrice;
	}
};

class bookSet {
private:
	book bkData[100];
	int Num;
	int Cursor;
public:
	bookSet()
	{
		Num = 0;
		Cursor = -1;
		ifstream f1;
		f1.open("BookData.dat");
		if(!f1)
		{
			MessageBox(NULL, "打开文件不成功", "警告 ", MB_OK);
			
			return;
		}
		while(f1)
		{
			CString No;
			CString Name;
			CString PNo;
			CString ANo;
			CString Birth;
			CString Intro;
			CString Price;
			char no[31];
			char name[31];
			char pNo[31];
			char aNo[31];
			char birth[31];
			char price[31];
			char intro[100];
			f1>>no;
			if(!f1)
				break;
			f1>>name>>pNo>>aNo>>birth>>price>>intro;
			No.Format("%s",no);
			Name.Format("%s",name);
			PNo.Format("%s",pNo);
			ANo.Format("%s",aNo);
			Birth.Format("%s",birth);
			Price.Format("%s",price);
			Intro.Format("%s",intro);
			book a;
			a.setBook(No,Name,PNo,ANo,Birth,Intro,Price);
			setBookSet(Num,a);
			Num++;
		}
	}
	~bookSet()
	{
		char no[31];
		char name[31];
		char pNo[31];
		char aNo[31];
		char birth[31];
		char price[31];
		char intro[100];
		ofstream f1;
		f1.open("BookData.dat");
		for(int i=0;i<Num;i++)
		{
			transform(bkData[i].getBookNo(),no);
			transform(bkData[i].getBookName(),name);
			transform(bkData[i].getBookPNo(),pNo);
			transform(bkData[i].getBookANo(),aNo);
			transform(bkData[i].getBookBirth(),birth);
			transform(bkData[i].getBookPrice(),price);
			transform(bkData[i].getBookIntro(),intro);
			
			f1<<no<<" "<<name<<" "<<pNo<<" "<<aNo<<" "<<birth<<" "<<price<<" "<<intro<<endl;
		}
		f1.close();
		
	}
	void setNum(int n)
	{
		Num = n;
	}
	void transform(CString s,char* str)
	{
		for(int i=0;i<s.GetLength();i++)
		{
			str[i]=s.GetAt(i);
		}
		str[i]=0;
	}
	CString getCurrentBookNo()
	{
		return bkData[Cursor].getBookNo();
	}
	CString getCurrentBookName()
	{
		return bkData[Cursor].getBookName();
	}
	CString getCurrentBookPNo()
	{
		return bkData[Cursor].getBookPNo();
	}
	CString getCurrentBookANo()
	{
		return bkData[Cursor].getBookANo();
	}
	CString getCurrentBookPrice()
	{
		return bkData[Cursor].getBookPrice();
	}
	CString getCurrentBookBirth()
	{
		return bkData[Cursor].getBookBirth();
	}
	CString getCurrentBookIntro()
	{
		return bkData[Cursor].getBookIntro();
	}
	int getNum()
	{
		return Num;
	}
	void setBookSet(int i, book a)     //代替下面的函数
	{
		if (i >= 100 || i < 0)
		{
			MessageBox(NULL, "数据库中已无法存放数据或存放数据的下标有误", "警告", MB_OK);
		}
		else
		{
			bkData[i] = a;
		}
		Cursor = i;
	}
	int  setBookSet(book a)
	{
		if (Cursor == -1)
			return 0;
		else
		{
			bkData[Cursor] = a;
			return 1;
		}
	}
	void deleteBook(CString bh)
	{
		for (int i = 0; i < Num; i++)
		{
			if (bkData[i].getBookNo() == bh)
			{
				for (int j = i + 1; j < Num; j++)
				{
					bkData[j - 1] = bkData[j];
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
	int locationBookNo(CString No)
	{
		for (int i = 0; i < Num; i++)
		{
			if (bkData[i].getBookNo() == No)
			{
				Cursor = i;
				return 1;
			}
		}
		return 0;
	}
	
	int ifBook(CString name)
	{
		for (int i = 0; i < Num; i++)
		{
			if (bkData[i].getBookName() == name)
			{
				Cursor = i;
				return 1;
			}
		}
		return 0;
	}
	int ifDeletePress(CString Name)
	{
		for (int i = 0; i < Num; i++)
		{
			if (bkData[i].getBookPNo() == Name)
			{
				return 1;
			}
		}
		return 0;
	}
	int ifDeleteAuthor(CString Name)
	{
		for (int i = 0; i < Num; i++)
		{
			if (bkData[i].getBookANo() == Name)
			{
				return 1;
			}
		}
		return 0;
	}
};