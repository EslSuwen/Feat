using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StuManager
{
    class Human
    {
        #region 字段
        /// <summary>
        ///姓名
        /// </summary>
        internal string Name;
        /// <summary>
        /// 身份识别号
        /// </summary>
        internal string ID;
        /// <summary>
        /// 年龄
        /// </summary>
        private int age;
        internal SexType Sex = SexType.未知;
        #endregion

        #region 属性
        /// <summary>
        /// 获取或设置年龄
        /// </summary>
        internal int Age
        {
            get {
                return age;
            }
            set
            {
                if (value < 0)
                    age = 0;
                else if (value > 100)
                    age = 100;
                else
                    age = value;
            }
        }
        #endregion

        #region 构造方法
        internal Human()
        {
            this.Name = "";
            this.ID = "";
            this.age = 20;
            this.Sex = SexType.未知;
        }
        internal Human(string name, string id, int age,SexType sex)
        {
            this.Name = name;
            this.ID = id;
            this.Age = age;
            this.Sex = sex;
        }
        #endregion

        #region 常规方法
        public override string ToString()
        {
            return string.Format("姓名：{0}  ID：{1}  年龄：{2}  性别：[3] ",this.Name,this.ID,this.Age,this.Sex);
        }
        #endregion
    }
}
