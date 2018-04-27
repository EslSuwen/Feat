#pragma once
#include <iostream>
using namespace std;
class menu {
public:
	static void menu0()
	{
		cout << "\n\t\t\t学生基本信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学院信息管理" << endl;
		cout << "\t\t\t2. 专业信息管理" << endl;
		cout << "\t\t\t3. 学生信息管理" << endl;
		cout << "\t\t\t4. 课程信息管理" << endl;
		cout << "\t\t\t5. 选课信息管理" << endl;
		cout << "\t\t\t6. 学生成绩管理" << endl;
		cout << "\t\t\t0. 退出系统" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu1()
	{
		cout << "\n\t\t\t  学院信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学院信息输入" << endl;
		cout << "\t\t\t2. 学院信息显示" << endl;
		cout << "\t\t\t3. 学院信息查询" << endl;
		cout << "\t\t\t4. 学院信息修改" << endl;
		cout << "\t\t\t5. 学院信息删除" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu2()
	{
		cout << "\n\t\t\t  专业信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 专业信息输入" << endl;
		cout << "\t\t\t2. 专业信息显示" << endl;
		cout << "\t\t\t3. 专业信息查询" << endl;
		cout << "\t\t\t4. 专业信息修改" << endl;
		cout << "\t\t\t5. 专业信息删除" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu3()
	{
		cout << "\n\t\t\t  学生信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学生信息输入" << endl;
		cout << "\t\t\t2. 学生信息显示" << endl;
		cout << "\t\t\t3. 学生信息查询" << endl;
		cout << "\t\t\t4. 学生信息修改" << endl;
		cout << "\t\t\t5. 学生信息删除" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu4()
	{
		cout << "\n\t\t\t请选择查询学院的方式：\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学院名称查找" << endl;
		cout << "\t\t\t2. 学院院长查找" << endl;
		cout << "\t\t\t3. 学院编号查找" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu5()
	{
		cout << "\n\t\t\t请选择查询专业的方式：\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 专业名称查找" << endl;
		cout << "\t\t\t2. 所属学院查找" << endl;
		cout << "\t\t\t3. 专业编号查找" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu6()
	{
		cout << "\n\t\t\t请选择查询学生的方式：\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学生姓名查找" << endl;
		cout << "\t\t\t2. 学生学号查找" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu7()
	{
		cout << "\n\t\t\t  课程信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 课程信息输入" << endl;
		cout << "\t\t\t2. 课程信息显示" << endl;
		cout << "\t\t\t3. 课程信息查询" << endl;
		cout << "\t\t\t4. 课程信息修改" << endl;
		cout << "\t\t\t5. 课程信息删除" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu8()
	{
		cout << "\n\t\t\t请选择查询课程的方式：\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 课程名称查找" << endl;
		cout << "\t\t\t2. 课程编号查找" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu9()
	{
		cout << "\n\t\t\t  选课信息管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 选课信息输入" << endl;
		cout << "\t\t\t2. 选课信息显示" << endl;
		cout << "\t\t\t3. 选课信息查询" << endl;
		cout << "\t\t\t4. 选课信息删除" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu10()
	{
		cout << "\n\t\t\t  选课信息查询\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 课程选课查询" << endl;
		cout << "\t\t\t2. 学生选课查询" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu11()
	{
		cout << "\n\t\t\t  学生成绩管理\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1. 学生成绩输入" << endl;
		cout << "\t\t\t2. 课程成绩输出" << endl;
		cout << "\t\t\t3. 学生成绩输出" << endl;
		cout << "\t\t\t4. 成绩排名输出" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
	static void menu12()
	{
		cout << "\n\t\t\t  成绩排序方式\n" << endl;
		cout << "\t\t\t----------------" << endl;
		cout << "\t\t\t1.   默认排序" << endl;
		cout << "\t\t\t2. 成绩由高到低" << endl;
		cout << "\t\t\t3. 学号由低到高" << endl;
		cout << "\t\t\t0. 退出" << endl;
		cout << "\t\t\t----------------" << endl;
	}
};

