using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StuManager
{
    #region 事件参数类

    class EventArgsDep : EventArgs
    {
        /// <summary>
        /// 更改的系对象
        /// </summary>
        internal Department pobj;
        /// <summary>
        /// 更改以后的数量
        /// </summary>
        internal int number;
        /// <summary>
        /// 更改前的名字
        /// </summary>
        internal string OldDepName;
        /// <summary>
        /// 更改后的名字
        /// </summary>
        internal string NewDepName;
    }

    class EventArgsClass : EventArgs
    {
        /// <summary>
        /// 班级所在的系
        /// </summary>
        internal Department depobj;
        /// <summary>
        /// 更改的班级对象
        /// </summary>
        internal clsClass clsobj;
        /// <summary>
        /// 更改后的班级数量
        /// </summary>
        internal int number;
        /// <summary>
        /// 班级更改前的名字
        /// </summary>
        internal string OldClassName;
        /// <summary>
        /// 班级更改以后的名字
        /// </summary>
        internal string NewClassName;
    }

    class EventArgsStudent : EventArgs
    {
        /// <summary>
        /// 学生所在的系
        /// </summary>
        internal Department depobj;
        /// <summary>
        /// 学生所在的班级
        /// </summary>
        internal clsClass clsobj;
        /// <summary>
        /// 学生对象
        /// </summary>
        internal Student stuobj;
        /// <summary>
        /// 更改后的学生对象
        /// </summary>
        internal Student NewStuobj;
        /// <summary>
        /// 更改以后的学生数量
        /// </summary>
        internal int number;
        /// <summary>
        /// 学生更改前所在的系
        /// </summary>
        internal string OldDepName;
        /// <summary>
        /// 更改后学生所在的系
        /// </summary>
        internal string NewDepName;
        /// <summary>
        /// 更改以前所在的班级
        /// </summary>
        internal string OldClassName;
        /// <summary>
        /// 更改以后所在的班级
        /// </summary>
        internal string NewClassName;
    }

    #endregion

    #region 委托
    internal delegate void EventHandlerDepartment(object sender,EventArgsDep e);//关于系的委托
    internal delegate void EventHandlerClass(object sender, EventArgsClass e);//关于班级的委托
    internal delegate void EventHandlerStudent(object sender, EventArgsStudent e);//关于学生的委托
    #endregion

    /// <summary>
    /// 数据类
    /// </summary>
    class DataClass
    {
        #region 字段
        /// <summary>
        /// 存储系的集合
        /// </summary>
        internal List<Department> DepList = new List<Department>();
        #endregion

        #region 属性
        /// <summary>
        /// 系的数量
        /// </summary>
        internal int DepartmentNumber
        {
            get
            {
                return DepList.Count;
            }
        }
        /// <summary>
        /// 所有系的班级数量
        /// </summary>
        internal int ClassNumber
        {
            get {
                int sum = 0;
                foreach (Department p in DepList)
                    sum += p.ClassNumber;
                return sum;
            }
        }
        /// <summary>
        /// 所有系的学生数量
        /// </summary>
        internal int StudentNumber
        {
            get
            {
                int sum = 0;
                foreach (Department p in DepList)
                    sum += p.StudentNumber;
                return sum;
            }
        }
        #endregion

        #region 事件
        internal event EventHandlerDepartment OnDepartmentAdd;
        internal event EventHandlerDepartment OnDepartmentDel;
        internal event EventHandlerClass OnClassAdd;
        internal event EventHandlerClass OnClassDel;
        internal event EventHandlerStudent OnStudentAdd;
        internal event EventHandlerStudent OnStudentDel;
        internal event EventHandlerDepartment OnDepartmentModify;
        internal event EventHandlerClass OnClassModify;
        internal event EventHandlerStudent OnStudentModify;
        #endregion

        #region 激活事件的方法

        private void ActOnDepartmentAdd(object sender,EventArgsDep e)
        {
            if (OnDepartmentAdd != null)
                OnDepartmentAdd(this, e);
        }
        private void ActOnDepartmentDel(object sender,EventArgsDep e)
        {
            if (OnDepartmentDel != null)
                OnDepartmentDel(this, e);
        }
        private void ActOnClassAdd(object sender, EventArgsClass e)
        {
            if (OnClassAdd != null)
                OnClassAdd(this, e);
        }
        private void ActOnClassDel(object sender, EventArgsClass e)
        {
            if (OnClassDel != null)
                OnClassDel(this, e);
        }
        private void ActOnStudentAdd(object sender, EventArgsStudent e)
        {
            if (OnStudentAdd != null)
                OnStudentAdd(this, e);
        }
        private void ActOnStudentDel(object sender, EventArgsStudent e)
        {
            if (OnStudentDel != null)
                OnStudentDel(this, e);
        }
        private void ActOnDepartmentModify(object sender,EventArgsDep e)
        {
            if (this.OnDepartmentModify != null)
                OnDepartmentModify(this, e);
        }
        private void ActOnClassModify(object sender, EventArgsClass e)
        {
            if (this.OnClassModify != null)
                OnClassModify(this, e);
        }
        private void ActOnStudentModify(object sender, EventArgsStudent e)
        {
            if (this.OnStudentModify != null)
                OnStudentModify(this, e);
        }
        #endregion

        #region 关于对系进行操作的方法

        /// <summary>
        /// 根据系的名称找到对象
        /// </summary>
        /// <param name="name">系的名称</param>
        /// <returns>成功：返回系的对象；不成功：null</returns>
        internal Department FindDepartmentByName(string name)
        {
            Department dep=null;
            foreach (Department p in DepList)
            {
                if (p.Name == name)
                {
                    dep = p;
                    break;
                }
            }
            return dep;
        }

        /// <summary>
        /// 增加系
        /// </summary>
        /// <param name="obj">对象</param>
        /// <returns>成功：true；不成功：false</returns>
        internal bool AddDepartment(Department obj)
        {
            if (FindDepartmentByName(obj.Name) == null)
            {
                DepList.Add(obj);
                EventArgsDep e = new EventArgsDep();
                e.number = DepartmentNumber;
                e.pobj = obj;
                ActOnDepartmentAdd(this, e);
                return true;
            }
            return false;
        }

        /// <summary>
        /// 增加系
        /// </summary>
        /// <param name="obj">系的名称</param>
        /// <returns>成功：true；不成功：false</returns>
        internal bool AddDepartment(string name)
        {
            Department obj = new Department(name);
            return AddDepartment(obj);
        }

        /// <summary>
        /// 删除一个系
        /// </summary>
        /// <param name="obj">系对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelDepartment(Department obj)
        {
            if (DepList.Remove(obj))//删除成功
            {
                EventArgsDep e = new EventArgsDep();
                e.pobj = obj;
                e.number = DepartmentNumber;
                ActOnDepartmentDel(this,e);
                return true;
            }
            return false;
        }

        /// <summary>
        /// 根据系的名称删除一个系的对象
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        internal bool DelDepartment(string name)
        {
            Department obj = FindDepartmentByName(name);
            if (obj == null)
                return false;
            else
            {
                return DelDepartment(obj);
            }
        }

        /// <summary>
        /// 修改系的名称
        /// </summary>
        /// <param name="oldName">旧名字</param>
        /// <param name="NewName">新名字</param>
        internal void ModifyDepartment(string oldName,string NewName)
        {
            Department dep = FindDepartmentByName(oldName);
            dep.Name = NewName;
            EventArgsDep e=new EventArgsDep();
            e.pobj=dep;
            e.OldDepName=oldName;
            e.NewDepName=NewName;
            e.number=DepartmentNumber;
            ActOnDepartmentModify(this,e);
        }

        #endregion

        #region 对班级进行操作的方法
        
        /// <summary>
        /// 在系dep中查找一个班级对象
        /// </summary>
        /// <param name="dep">系的名称</param>
        /// <param name="name">班级名称</param>
        /// <returns>成功：返回班级对象；失败：返回null</returns>
        internal clsClass FindClassByName(Department dep,string name)
        {
            clsClass cls = null;
            cls=dep.FindClassByName(name);
            return cls;
        }
        
        /// <summary>
        /// 在所有的系中查找班级
        /// </summary>
        /// <param name="name">班级名称</param>
        /// <param name="dep">班级所在的系对象，输出参数</param>
        /// <returns>成功：班级对象；不成功：false</returns>        
        internal clsClass FindClassByName(string name,out Department dep)
        {
            clsClass cls = null;
            foreach (Department p in DepList)
            {
                cls = FindClassByName(p, name);
                if (cls != null)//找到
                {
                    dep = p;
                    return cls;
                }
            }
            dep = null;
            return cls;
        }
       
        /// <summary>
        /// 在系中增加一个班级
        /// </summary>
        /// <param name="dep">系的对象</param>
        /// <param name="cls">班级对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool AddClass(Department dep, clsClass cls)
        {
            if (dep.AddClass(cls))//成功
            {
                EventArgsClass e = new EventArgsClass();
                e.depobj = dep;
                e.clsobj= cls;
                e.number = this.ClassNumber;
                ActOnClassAdd(this, e);
                return true;
            }
            return false;
        }
        
        /// <summary>
        /// 在某个系中增加一个班级
        /// </summary>
        /// <param name="depname">系的名称</param>
        /// <param name="classname">班级名称</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool AddClass(string depname, string classname)
        {
            Department depobj = FindDepartmentByName(depname);
            if (depobj != null)//找到系对象
            {
                clsClass cls = new clsClass(classname);
                return AddClass(depobj,cls);
            }
            return false;
        }
        
        /// <summary>
        /// 在某个系中删除一个班级
        /// </summary>
        /// <param name="depobj">系对象</param>
        /// <param name="clsobj">班级对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelClass(Department depobj, clsClass clsobj)
        {
            if (depobj.DelCalss(clsobj))//删除成功
            {
                EventArgsClass e = new EventArgsClass();
                e.depobj = depobj; e.number = ClassNumber;
                e.clsobj = clsobj;
                ActOnClassDel(this,e);
                return true;
            }
            return false;
        }
        
        /// <summary>
        /// 删除一个班级
        /// </summary>
        /// <param name="classname">班级名称</param>
        /// <param name="dep">输出参数，班级所在的系</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelClass(string classname, out Department dep)
        {
            dep=null;
            clsClass cls=FindClassByName(classname,out dep);
            if (cls != null)//找到班级
                return DelClass(dep, cls);
            return false;
        }
        
        /// <summary>
        /// 修改系中某个班级的名称
        /// </summary>
        /// <param name="dep">班级所在的系</param>
        /// <param name="OldName">班级的旧名</param>
        /// <param name="NewName">班级的新名</param>
        /// <returns>成功：Ture；失败：false</returns>
        internal bool ModifyClass(Department dep,string OldName,string NewName)
        {
            clsClass clsobj=FindClassByName(dep,OldName);
            if(clsobj==null) //如果没有找到班级
                return false;
            clsobj.Name=NewName;
            EventArgsClass e=new EventArgsClass();
            e.depobj=dep;
            e.clsobj=clsobj;
            e.OldClassName=OldName;
            e.NewClassName=NewName;
            e.number=ClassNumber;
            ActOnClassModify(this,e);
            return true;
        }

        /// <summary>
        /// 修改某个班级的名称
        /// </summary>
        /// <param name="OldName">班级旧名</param>
        /// <param name="NewName">班级新名</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool ModifyClass(string OldName,string NewName)
        {
            Department dep=null;
            clsClass clsobj=FindClassByName(OldName,out dep);
            if(clsobj==null)
                return false;
            return ModifyClass(dep,OldName,NewName);
        }

        #endregion

        #region 关于学生的方法

        /// <summary>
        /// 根据学生的ID查找学生对象
        /// </summary>
        /// <param name="cls">学生所在的班级</param>
        /// <param name="ID">学生的ID</param>
        /// <returns>成功：学生对象；失败：null</returns>
        internal Student FindStudentByID(clsClass cls, string ID)
        {
            return cls.FindStudentByID(ID);
        }

        /// <summary>
        /// 根据学生的ID查找学生对象
        /// </summary>
        /// <param name="ID">学生的ID</param>
        /// <param name="depobj">学生所在的系，输出参数</param>
        /// <param name="clsobj">学生所在的班级，输出参数</param>
        /// <returns>成功：true；失败：false</returns>
        internal Student FindStudentByID(string ID, out Department depobj, out clsClass clsobj)
        {
            depobj = null; clsobj = null;
            Student pstu = null;
            foreach(Department pdep in DepList)
                foreach (clsClass pcls in pdep.Classes)
                {
                    if ((pstu=pcls.FindStudentByID(ID))!=null)//找到
                    {
                        depobj = pdep; clsobj = pcls;
                        return pstu;
                    }
                }
            return pstu;
        }

        /// <summary>
        /// 增加一个学生
        /// </summary>
        /// <param name="depname">学生所在系的名称</param>
        /// <param name="classname">学生所在班级的名称</param>
        /// <param name="stu">学生对象</param>
        /// <returns></returns>
        internal bool AddStudent(string depname, string classname, Student stu)
        {
            Department depobj = FindDepartmentByName(depname);
            if (depobj == null) return false;
            clsClass clsobj = FindClassByName(depobj, classname);
            if (clsobj == null) return false;
            if (clsobj.AddStudent(stu)) //学生增加成功
            {
                EventArgsStudent e = new EventArgsStudent();
                e.clsobj = clsobj; e.depobj = depobj;
                e.stuobj = stu;
                e.number = StudentNumber;
                ActOnStudentAdd(this, e);
                return true;
            }
            return false;
        }

        /// <summary>
        /// 删除一个学生
        /// </summary>
        /// <param name="depname">学生所在系的名称</param>
        /// <param name="classname">学生所在班级的名称</param>
        /// <param name="stu">学生对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelStudent(string depname, string classname, Student stu)
        {
            Department depobj = FindDepartmentByName(depname);
            if (depobj == null) return false; //没有找到系对象，返回
            clsClass clsobj = depobj.FindClassByName(classname);
            if (clsobj == null) return false; //没有找到班对象，返回
            if (clsobj.DelStudent(stu)) //删除成功
            {
                EventArgsStudent e = new EventArgsStudent();
                e.depobj = depobj;
                e.clsobj = clsobj;
                e.stuobj = stu;
                e.number = StudentNumber;
                ActOnStudentDel(this, e);
                return true;
            }
            return false;
        }

        /// <summary>
        /// 删除一个学生
        /// </summary>
        /// <param name="depname">学生所在系的名称</param>
        /// <param name="classname">学生所在班级的名称</param>
        /// <param name="studentname">学生的姓名</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelStudent(string depname, string classname, string studentID)
        {
            Department depobj = FindDepartmentByName(depname);
            if (depobj == null) return false; //没有找到系对象，返回
            clsClass clsobj = depobj.FindClassByName(classname);
            if (clsobj == null) return false; //没有找到班对象，返回
            Student stuobj = clsobj.FindStudentByID(studentID);
            if (stuobj == null) return false;
            return DelStudent(depname, classname, stuobj);
        }

        /// <summary>
        /// 删除一个学生
        /// </summary>
        /// <param name="studentname">学生ID</param>
        /// <param name="depobj">学生所在系，输出参数</param>
        /// <param name="clsobj">学生所在的班级，输出参数</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelStudent(string studentID, out Department depobj, out clsClass clsobj)
        {
            depobj = null; clsobj = null;
            Student stu = null;
            foreach(Department pdep in DepList)
                foreach (clsClass pcls in pdep.Classes)
                {
                    stu=pcls.FindStudentByID(studentID);
                    if(stu!=null) //找到学生对象 
                    {
                        depobj=pdep; clsobj=pcls;
                        return DelStudent(depobj.Name,clsobj.Name,stu);
                    }
                }
            return false;
        }

        /// <summary>
        /// 将第2个学生的信息给予第一个学生
        /// </summary>
        /// <param name="FirstStudent">第一个学生</param>
        /// <param name="SecondStudent">第二个学生</param>
        private void ChangeStudentInfo(Student FirstStudent, Student SecondStudent)
        {
            FirstStudent.Name = SecondStudent.Name;
            FirstStudent.Sex = SecondStudent.Sex;
            FirstStudent.Age = SecondStudent.Age;
            FirstStudent.ID = SecondStudent.ID;
            FirstStudent.Chinese = SecondStudent.Chinese;
            FirstStudent.Computer = SecondStudent.Computer;
            FirstStudent.Math = SecondStudent.Math;
            FirstStudent.English = SecondStudent.English;
        }

        /// <summary>
        /// 修改学生信息
        /// </summary>
        /// <param name="OldDepName">修改前所在的系名称</param>
        /// <param name="NewDepName">修改后所在的系名称</param>
        /// <param name="OldClassName">修改前所在的班级名称</param>
        /// <param name="NewClassName">修改后所在的班级名称</param>
        /// <param name="StudentID">学生的ID</param>
        /// <param name="NewStudent">新的学生对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool ModifyStudent(string OldDepName,string NewDepName,
                                    string OldClassName,string NewClassName,
                                    string StudentID,Student NewStudent)
        {
            Department olddep;
            clsClass oldclass;
            Student OldStudent=FindStudentByID(StudentID,out olddep,out oldclass);
            Department newdep=FindDepartmentByName(NewDepName);
            clsClass newclass=FindClassByName(newdep,NewClassName);//原来的学生对象
            //找不到相应的对象，则返回ture;
            if(olddep==null||newdep==null||oldclass==null||newclass==null||OldStudent==null)
                return false;
            if(olddep==newdep)
            {
                if(oldclass==newclass) //学生所在的系和班级没有改动
                {
                    ChangeStudentInfo(OldStudent,NewStudent);
                    EventArgsStudent e=new EventArgsStudent();
                    e.OldDepName=OldDepName; e.OldClassName=OldClassName;
                    e.NewDepName=NewDepName; e.NewClassName=NewClassName;
                    e.stuobj = OldStudent; e.NewStuobj = NewStudent;
                    e.number=StudentNumber;
                    ActOnStudentModify(this,e);
                }
                else //系没有改动，班级发生改动
                {
                    oldclass.DelStudent(StudentID); //在原来班级中删除学生对象
                    newclass.AddStudent(NewStudent); //在新班级中添加学生
                    EventArgsStudent e=new EventArgsStudent();
                    e.OldDepName=OldDepName; e.OldClassName=OldClassName;
                    e.NewDepName=NewDepName; e.NewClassName=NewClassName;
                    e.stuobj = OldStudent; e.NewStuobj = NewStudent;
                    e.number = StudentNumber;
                    ActOnStudentModify(this,e);
                }
            }
            else//系发生改变
            {
                DelStudent(OldDepName,OldClassName,StudentID);//在原来的系原来的班级中删除学生对象
                AddStudent(NewDepName,NewClassName,NewStudent);//在新的系新的班级中增加学生
                EventArgsStudent e=new EventArgsStudent();
                e.OldDepName=OldDepName; e.OldClassName=OldClassName;
                e.NewDepName=NewDepName; e.NewClassName=NewClassName;
                e.stuobj = OldStudent; e.NewStuobj = NewStudent;
                e.number = StudentNumber;
                ActOnStudentModify(this,e);
            }
            return true;
        }
        #endregion
    }
}
