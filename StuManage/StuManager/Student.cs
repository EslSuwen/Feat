using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace StuManager
{
    /// <summary>
    /// 性别枚举类型
    /// </summary>
    enum SexType
    {
        男,
        女,
        未知
    }
    
    /// <summary>
    /// 学生类
    /// </summary>
    class Student:Human
    {
        #region 字段
        /// <summary>
        /// 语文成绩
        /// </summary>
        internal double Chinese;
        /// <summary>
        /// 英语成绩
        /// </summary>
        internal double English;
        /// <summary>
        /// 数学成绩
        /// </summary>
        internal double Math;
        /// <summary>
        /// 计算机成绩
        /// </summary>
        internal double Computer;
        #endregion

        #region 属性
        /// <summary>
        /// 平均成绩，只读属性
        /// </summary>
        internal double AverageScore
        {
            get {
                return TotalScore/4.0;
            }
        }
        /// <summary>
        /// 总成绩
        /// </summary>
        internal double TotalScore
        {
            get {
                return this.Chinese + this.English + this.Math + this.Computer;
            }
        }
        #endregion

        #region 构造方法
        internal Student(string name,string id,int age,SexType sex,
            double chinese,double english,double math,double computer):base(name,id,age,sex)
        {
            this.Chinese=chinese;
            this.English = english;
            this.Computer = computer;
            this.Math = math;
        }
        internal Student()
        {
            this.Name = "";
            this.ID = "";
            this.Sex = SexType.未知;
            this.Age = 0;
            this.Chinese = 0.0;
            this.English = 0.0;
            this.Computer = 0.0;
            this.Math = 0.0;
        }
        #endregion

        #region 方法
        public override string ToString()
        {
            string str = string.Format("  语文：{0,:#.00} 数学：{1,:#.00} 英语：{2,:#.00} 计算机：{3,:#.00}",
                this.Chinese,this.Math,this.English,this.Computer);
            return base.ToString()+str+Environment.NewLine;
        }
        #endregion
    }
}
