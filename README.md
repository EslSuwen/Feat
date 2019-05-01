﻿<!--
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @LastEditors: Suwen SP\n
 * @Date: 2019-04-30 23:16:53
 * @LastEditTime: 2019-05-01 08:37:36
 -->
# Feat
**学习中的一些实验程序，包括各种语言。**

---
## [BookSystem](https://github.com/EslSuwen/Feat/tree/master/BookSystem) :图书管理系统
VC6.0 MFC 调试编写\
**需求** :
1. 能实现书籍信息的录入，包括出版社书籍数据的录入、图书数据的录入、作者数据的录入。基本数据包括：出版社：出版社编号、出版社名称、出版社负责人、出版社简介、出版社下设出版分社（出版分社专注于某一个技术领域出版图书）。书籍的书号、书名、作者编号、出版日期、出版社编号、图书内容简介、图书价格；作者：作者编号、作者姓名、出生日期、性别、作者单位、作者简介；
2. 能实现数据的修改，包括所有基本信息的修改；
3. 能按编号或名称实现数据的查询，包括书籍信息的查询，作者的查询、按书名进行模糊查询；
4. 能实现数据的浏览，包括基本信息的浏览，统计数据的输出；
5. 能够删除基本数据，（注：出版社有出版图书信息，不能删除，作者有出版图书，不能删除）；

---
## [StudentGradeManageSystem](https://github.com/EslSuwen/Feat/tree/master/StudentGradeManageSystem) : 学生成绩管理系统
VS2017 C++控制台调试编写\
**简介** :
1. 创建学院类，专业类，课程类，选课类，学生类。
2. 实现各种类的创建，修改和删除。
3. 采用文件读取和保存。
---
## [StuManage](https://github.com/EslSuwen/Feat/tree/master/StuManage) : 学生信息管理系统
VS2017 C#调试编写\
**简介**
学生信息管理系统的设计
1. 工具栏要有经常使用的快捷方式；
2. 状态栏上显示日期和时间、系的数量、班级的数量和学生的数量；
3. 具有输入系、班级和学生信息的人机接口；
4. 能够根据所选择的系和班级，显示班级的学生信息；
---
## [StuManage-Master](https://github.com/EslSuwen/Feat/tree/master/StuManage-Master) : 学生选课及成绩查询管理系统
VS2017 C#调试编写
1. **项目背景**
学生选课及成绩查询系统是一个学校不可缺少的部分，传统的人工管理档案的方式存在着很 多的缺点，如：效率低、保密性差等，所以开发一套综合教务系统管理软件很有必要，它应 该具有传统的手工管理所无法比拟的优点，如：检索迅速、查找方便、可靠性高、存储量大、 保密性好、寿命长、成本低等。这些优点能够极大的提高学校的管理效率，有助于推进学校 的信息化建设。
2. **技术选型**
_c#的窗体程序开发_ _Sql server数据库_\
本系统未采用C#实现MDI——多文档窗口，因为考虑到C#的该技术与java类似，而暑 期java实训时，曾用过类似的方法做过停车场管理系统，所以想为这次的系统注入一 点新鲜的血液，所以本系统设计的主题采用了了 C#的C#TreeView实现。
3. **需求分析**
本系统包括两类用户：学生、管理员。管理员可以通过系统来添加管理员信息、修改管理员 信息、添加学生信息、修改学生信息；开设课程、查询课程、录入成绩、统计成绩、修改成 绩、修改个人密码等，而学生则可以通过系统来选择课程、查询课程、显示自己的课表、查 询自己的成绩单、修改个人密码等等。




