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
    public partial class FrmAdd : Form
    {
        #region 字段
        /// <summary>
        /// 数据类
        /// </summary>
        private DataClass pdata = null;
        /// <summary>
        /// 用户激活的页
        /// 0：系
        /// 1：班级
        /// 2：学生
        /// </summary>
        private int Index = 0;
        /// <summary>
        /// 用户输入的性别
        /// </summary>
        private SexType sex = SexType.未知;
        #endregion

        #region 构造函数
        internal FrmAdd(int index,DataClass p)
        {
            InitializeComponent();
            Index = index;
            pdata = p;
        }
        #endregion

        #region 初始化方法
        /// <summary>
        /// 初始化窗体布局
        /// </summary>
        private void InitForm()
        {
            panel1.Height = (int)(this.Height * 0.8);
            panel2.Height = this.Height - panel1.Height;
        }
        #endregion

        #region 窗体事件

        private void FrmAdd_Load(object sender, EventArgs e)
        {
            InitForm();
            this.tabControl1.SelectedIndex=Index;
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

        #region tabControl控件事件

        /// <summary>
        /// 初始化班级页的内容
        /// </summary>
        private void InitClassPage()
        {
            //清除原先的内容
            this.combSelDepClass.Items.Clear();
            foreach (Department p in pdata.DepList)
                combSelDepClass.Items.Add(p.Name);
            if (combSelDepClass.Items.Count != 0)
                combSelDepClass.SelectedIndex = 0;
        }

        /// <summary>
        /// 初始化学生页的内容
        /// </summary>
        private void InitStudentPage()
        {
            this.combSelDepStudent.Items.Clear();
            this.combSelClassStudent.Items.Clear();
            foreach (Department p in pdata.DepList)
                combSelDepStudent.Items.Add(p.Name);
            if(combSelDepStudent.Items.Count!=0)
                combSelDepStudent.SelectedIndex = 0;
            radioBtnUnkown.Checked = true;
        }

        /// <summary>
        /// 当用户选择页时发生
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (tabControl1.SelectedIndex)
            {
                case 0:
                    txtDepName.Text = "";
                    txtDepName.Focus();
                    break;
                case 1:
                    InitClassPage();
                    break;
                case 2:
                    InitStudentPage();
                    break;
            }
        }
        #endregion

        #region 按钮事件
        /// <summary>
        /// 保存系
        /// </summary>
        private void SaveDepartment()
        {
            string str = txtDepName.Text.Trim();
            if (str == "")
            {
                MessageBox.Show("系名为空，请重新输入！", "提示", MessageBoxButtons.OK,MessageBoxIcon.Information);
                txtDepName.Focus();
            }
            else
            {
                if (!pdata.AddDepartment(str))
                    MessageBox.Show(str+"已存在，请重新输入！","警告",MessageBoxButtons.OK,MessageBoxIcon.Error);
                txtDepName.SelectAll();
                txtDepName.Focus();
            }
        }
        /// <summary>
        /// 保存班级
        /// </summary>
        private void SaveClass()
        {
            if (combSelDepClass.SelectedIndex == -1)
            {
                MessageBox.Show("没有选择班级所在的系，请选择系！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            else
            {
                if (!pdata.AddClass(combSelDepClass.Text, txtClassName.Text))
                {
                    MessageBox.Show(txtClassName.Text+"已经存在，请重新输入","提示",MessageBoxButtons.OK,MessageBoxIcon.Error);
                }
                txtClassName.SelectAll();
                txtClassName.Focus();
            }
        }
        /// <summary>
        /// 保存学生
        /// </summary>
        private void SaveStudent()
        {
            if (combSelDepStudent.SelectedIndex == -1)
            {
                MessageBox.Show("没有选择系，请选择！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                combSelDepStudent.Focus();
                return;
            }
            if (combSelClassStudent.SelectedIndex == -1)
            {
                MessageBox.Show("没有选择班级，请选择！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                combSelClassStudent.Focus();
                return;
            }
            if (txtStudentName.Text == "" || txtStudentID.Text == "")
            {
                MessageBox.Show("姓名和ID不能为空，请输入！", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            Student stu = new Student();
            stu.Name = txtStudentName.Text.Trim();
            stu.ID = txtStudentID.Text.Trim();
            stu.Age = (int)numericStudentAge.Value;
            stu.Sex = this.sex;
            stu.Chinese = double.Parse(txtChinese.Text);
            stu.Math = double.Parse(txtMath.Text);
            stu.English = double.Parse(txtEnglish.Text);
            stu.Computer = double.Parse(txtComputer.Text);
            bool result = pdata.AddStudent(this.combSelDepStudent.Text.Trim(), 
                                           this.combSelClassStudent.Text.Trim(), stu);
            if(!result)
            {
                MessageBox.Show("该学生的ID号已经存在，请重新输入！","提示",MessageBoxButtons.OK,MessageBoxIcon.Error);
                txtStudentID.SelectAll();
                txtStudentID.Focus();
            }
        }
        /// <summary>
        /// 保存按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOK_Click(object sender, EventArgs e)
        {
            switch (tabControl1.SelectedIndex)
            {
                case 1: //保存班级
                    SaveClass();
                    break;
                case 2: //保存学生
                    this.SaveStudent();
                    break;
                case 0: //保存系
                    this.SaveDepartment();
                    break;
            }
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

        #region combBox控件事件

        private void combSelDepStudent_SelectedIndexChanged(object sender, EventArgs e)
        {
            combSelClassStudent.Items.Clear();
            Department dep = pdata.FindDepartmentByName(combSelDepStudent.Text);
            if (dep == null)
                return;
            foreach (clsClass p in dep.Classes)
                combSelClassStudent.Items.Add(p.Name);
            if (combSelClassStudent.Items.Count != 0)
                combSelClassStudent.SelectedIndex = 0;
        }

        #endregion
    }
}
