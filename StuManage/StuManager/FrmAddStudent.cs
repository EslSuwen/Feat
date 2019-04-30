using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StuManager
{
    public partial class FrmAddStudent : Form
    {
        #region 字段
        
        /// <summary>
        /// 数据类
        /// </summary>
        private DataClass pdata = null;
        
        /// <summary>
        /// 用户输入的性别
        /// </summary>
        private SexType sex = SexType.未知;
        
        /// <summary>
        /// 系名
        /// </summary>
        private string DepName="";
        
        /// <summary>
        /// 班级名
        /// </summary>
        private string ClassName="";

        #endregion

        #region 构造函数
        internal FrmAddStudent(int index, DataClass p,string depname,string classname)
        {
            InitializeComponent();
            pdata = p;
            this.DepName=depname;
            this.ClassName=classname;
        }
        #endregion

        #region 窗体事件

        private void FrmAdd_Load(object sender, EventArgs e)
        {
            labelDepName.Text = DepName;
            labelClassName.Text = ClassName;
        }

        #endregion

        #region 文本框事件
        /// <summary>
        /// 输入成绩时，用户只能输入数字和小数点
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void textBoxInput_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar=='.'))
            {
                e.KeyChar='\0';
                return;
            }
        }
        #endregion


        #region 按钮事件
        /// <summary>
        /// 保存按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOK_Click(object sender, EventArgs e)
        {
            Student stuobj = new Student(txtStudentName.Text.Trim(),txtStudentID.Text.Trim(),
                                       (int)numericStudentAge.Value, sex,
                                       double.Parse(txtChinese.Text), double.Parse(txtEnglish.Text),
                                       double.Parse(txtMath.Text), double.Parse(txtComputer.Text));
            pdata.AddStudent(DepName, ClassName, stuobj);
        }
        /// <summary>
        /// 取消按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        #endregion

        #region radioButton事件
        private void radioBtnMale_Click(object sender, EventArgs e)
        {
            sex = SexType.男;
        }

        private void radioBtnFemal_Click(object sender, EventArgs e)
        {
            sex = SexType.女;
        }

        private void radioBtnUnkown_Click(object sender, EventArgs e)
        {
            sex = SexType.未知;
        }
        #endregion
    }
}
