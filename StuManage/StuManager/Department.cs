using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StuManager
{
    class Department
    {
        #region 字段
        /// <summary>
        /// 存储班级数据的结合
        /// </summary>
        private List<clsClass> ClassList = new List<clsClass>();
        internal string Name = "";
        #endregion

        #region 属性
        /// <summary>
        /// 获取所属系的班级数量
        /// </summary>
        internal int ClassNumber
        {
            get
            {
                return ClassList.Count;
            }
        }
        /// <summary>
        /// 获取所属系的学生数量
        /// </summary>
        internal int StudentNumber
        {
            get
            {
                int sum = 0;
                foreach (clsClass p in ClassList)
                {
                    sum += p.StudentNumber;
                }
                return sum;
            }
        }
        /// <summary>
        /// 获取所属系的班级集合
        /// </summary>
        internal List<clsClass> Classes
        {
            get
            {
                return ClassList;
            }
        }
        #endregion

        #region 构造方法
        /// <summary>
        /// 构造函数
        /// </summary>
        internal Department()
        {
            this.Name = "";
        }
        internal Department(string name)
        {
            this.Name = name;
        }
        #endregion

        #region 查找方法
        /// <summary>
        /// 根据班级的名称查找班级对象
        /// </summary>
        /// <param name="name">班级的名称</param>
        /// <returns>找到的班级对象，若没有找到则为null</returns>
        internal clsClass FindClassByName(string name)
        {
            clsClass pobj = null;
            foreach (clsClass p in Classes)
            {
                if (p.Name == name)
                {
                    pobj = p;
                    break;
                }
            }
            return pobj;
        }
        #endregion

        #region 增加班级方法
        /// <summary>
        /// 在系中增加一个班级对象
        /// </summary>
        /// <param name="p">班级对象</param>
        /// <return>成功：true；失败：false</return>
        internal bool AddClass(clsClass p)
        {
            if (FindClassByName(p.Name) == null)
            {
                Classes.Add(p);
                return true;
            }
            else
            {
                return false;
            }
        }
        /// <summary>
        /// 增加一个班级
        /// </summary>
        /// <param name="name">班级的名称</param>
        /// <return>成功：true；失败：false</return>
        internal bool AddClass(string name)
        {
            clsClass p = new clsClass(name);
            return AddClass(p);
        }
        #endregion

        #region 删除班级方法
        /// <summary>
        /// 删除一个班级对象
        /// </summary>
        /// <param name="pClass">班级对象</param>
        /// <returns>成功:true；失败:false</returns>
        internal bool DelCalss(clsClass pClass)
        {
            return Classes.Remove(pClass);
        }
        /// <summary>
        /// 删除一个班级对象
        /// </summary>
        /// <param name="name">班级名称</param>
        /// <returns>成功:true；失败:false</returns>
        internal bool DelCalss(string name)
        {
            clsClass pobj = FindClassByName(name);
            if (pobj != null)
                return DelCalss(pobj);
            return false;
        }
        #endregion
    }
}
