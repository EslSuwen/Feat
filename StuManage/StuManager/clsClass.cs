using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StuManager
{
    class clsClass
    {
        #region 字段
        /// <summary>
        /// 班级的名称
        /// </summary>
        internal string Name="";
        /// <summary>
        /// 学生集合
        /// </summary>
        private List<Student> stuList = new List<Student>();
        #endregion

        #region 属性
        /// <summary>
        /// 获取学生集合对象
        /// </summary>
        internal List<Student> Students
        {
            get {
                return stuList;
            }
        }
        /// <summary>
        /// 获取班级学生的数量
        /// </summary>
        internal int StudentNumber
        {
            get {
                return Students.Count;
            }
        }
        /// <summary>
        /// Item属性的定义，即索引定义
        /// </summary>
        /// <param name="insex">下标索引</param>
        /// <returns>学生对象</returns>
        internal Student this[int index]
        {
            get {
                if (index >= 0 && index < Students.Count)
                    return Students[index];
                else
                    throw new IndexOutOfRangeException("索引下标超出范围！");
            }
            set {
                if (index >= 0 && index < Students.Count)
                    Students[index] = value;
                else
                    throw new IndexOutOfRangeException("索引下标超出范围");
            }
        }
        #endregion

        #region 构造方法
        internal clsClass()
        {
            this.Name = "";
        }
        internal clsClass(string name)
        {
            this.Name = name;
        }
        #endregion

        #region 增加学生方法
        /// <summary>
        /// 增加学生
        /// </summary>
        /// <param name="name">姓名</param>
        /// <param name="id">ID</param>
        /// <param name="age">年龄</param>
        /// <param name="sex">性别</param>
        /// <param name="chinese">语文成绩</param>
        /// <param name="math">数学成绩</param>
        /// <param name="english">英语成绩</param>
        /// <param name="computer">计算机成绩</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool AddStudent(string name, string id, int age, SexType sex,
            double chinese,double math,double english,double computer)
        {
            Student pobj = new Student(name, id, age, sex,chinese,english,math,computer);
            return AddStudent(pobj);
        }
        /// <summary>
        /// 在班级中增加学生
        /// </summary>
        /// <param name="pobj">学生对象</param>
        /// <return>增加成功，则返回ture；不成功，返回false，说明此ID已存在</return>
        internal bool AddStudent(Student pobj)
        {
            if (FindStudentByID(pobj.ID) == null)//此ID号不存在
            {
                Students.Add(pobj);
                return true;
            }
            return false;
        }
        #endregion

        #region 删除学生方法
        /// <summary>
        /// 在班级中删除学生
        /// </summary>
        /// <param name="pobj">学生对象</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelStudent(Student pobj)
        {
            if (pobj != null)
                return Students.Remove(pobj);
            return false;
        }
        /// <summary>
        /// 在班级中删除学生
        /// </summary>
        /// <param name="id">学生的id</param>
        /// <returns>成功：true；失败：false</returns>
        internal bool DelStudent(string id)
        {
            Student pobj = FindStudentByID(id);
            return DelStudent(pobj);
        }
        #endregion

        #region 查找方法
        /// <summary>
        /// 根据学生的ID查找学生对象,ID号唯一
        /// </summary>
        /// <param name="id">ID</param>
        /// <returns>找到则返回学生对象，否则返回null</returns>
        internal Student FindStudentByID(string id)
        {
            Student pstu = null;
            foreach (Student p in Students)
            {
                if (p.ID == id)
                {
                    pstu = p;
                    break;
                }
            }
            return pstu;
        }
        /// <summary>
        /// 根据学生的名字查找学生对象
        /// </summary>
        /// <param name="name">学生的姓名</param>
        /// <returns>返回包含符合条件的学生集合</returns>
        internal List<Student> FindStudentByName(string name)
        {
            List<Student> plist = new List<Student>();
            foreach(Student p in Students)
            {
                if (p.Name == name)
                    plist.Add(p);
            }
            return plist;
        }
        #endregion
    }
}
