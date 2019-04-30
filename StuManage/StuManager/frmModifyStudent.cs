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
    public partial class frmModifyStudent : Form
    {
        #region 字段
        /// <summary>
        /// 数据对象
        /// </summary>
        private DataClass pData = null;
        /// <summary>
        /// 修改学生所在的系的名称
        /// </summary>
        private string OldDepName = "";
        /// <summary>
        /// 修改学生所在的班级的名称
        /// </summary>
        private string OldClassName ="";
        /// <summary>
        /// 即将修改的学生对象
        /// </summary>
        private Student  StuObj=null;
        /// <summary>
        /// 存储用户选择性别
        /// </summary>
        private SexType sex = SexType.未知;

        #endregion

        #region 构造函数
        /// <summary>
        /// 构造函数，传递原来的学生信息，所在的系和班级
        /// </summary>
        /// <param name="pdata">数据对象</param>
        /// <param name="dep">原来所在的系</param>
        /// <param name="cls">原来所在的班级</param>
        /// <param name="stu">原来的学生对象</param>
        internal frmModifyStudent(DataClass pdata,string depname,string clsname,Student stuObj)
        {
            InitializeComponent();
            this.pData=pdata;
            this.OldDepName = depname;
            this.OldClassName = clsname;
            this.StuObj = stuObj;
        }
        #endregion

        #region 窗体事件

        /// <summary>
        /// 初始化窗体控件里的值
        /// </summary>
        private void InitForm()
        {
            foreach (Department p in pData.DepList)
                combDepartment.Items.Add(p.Name);
            combDepartment.Text = OldDepName;
            combClass.Text = this.OldClassName;
            txtStudentName.Text = this.StuObj.Name;
            this.txtStudentID.Text = StuObj.ID;
            this.numericStudentAge.Value = StuObj.Age;
            switch (StuObj.Sex)
            {
                case SexType.男:
                    this.radioBtnMale.Checked = true;
                    this.sex = SexType.男;
                    break;
                case SexType.女:
                    this.radioBtnFemale.Checked = true;
                    this.sex = SexType.女;
                    break;
                case SexType.未知:
                    this.radioBtnUnkown.Checked = true;
                    this.sex = SexType.未知;
                    break;
            }
            this.txtStudentChinese.Text = StuObj.Chinese.ToString();
            this.txtStudentEnglish.Text = StuObj.English.ToString();
            this.txtStudentComputer.Text = StuObj.Computer.ToString();
            this.txtStudentMath.Text = StuObj.Math.ToString();
        }

        private void frmModifyStudent_Load(object sender, EventArgs e)
        {
            InitForm();
            combDepartment.Focus();
        }

        #endregion

        #region combBox控件事件
        /// <summary>
        /// 更改系时发生
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void combDepartment_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.combClass.Items.Clear();
            Department dep = pData.FindDepartmentByName(this.combDepartment.Text);
            if (dep == null)
                return;
            foreach (clsClass p in dep.Classes)
                combClass.Items.Add(p.Name);
        }
        #endregion

        #region 按钮事件
        /// <summary>
        /// 保存
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnOK_Click(object sender, EventArgs e)
        {
            //形成新的学生对象
            Student stuobj = new Student(txtStudentName.Text.Trim(),txtStudentID.Text.Trim(),
                                         (int)numericStudentAge.Value,sex,
                                         double.Parse(txtStudentChinese.Text.Trim()),double.Parse(txtStudentEnglish.Text.Trim()),
                                         double.Parse(txtStudentMath.Text.Trim()),double.Parse(txtStudentComputer.Text.Trim()));
            if (pData.ModifyStudent(OldDepName, combDepartment.Text,
                                OldClassName, combClass.Text,
                                StuObj.ID, stuobj) == true)
            {
                this.DialogResult = DialogResult.OK;
            }
        }
        /// <summary>
        /// 取消按钮
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确认取消？", "询问", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                this.DialogResult = DialogResult.OK;
                Close();
            }
            else
                return;
        }
        #endregion

        #region radioButton事件

        private void radioBtnMale_CheckedChanged(object sender, EventArgs e)
        {
            this.sex = SexType.男;
        }
       

        private void radioBtnFemale_CheckedChanged(object sender, EventArgs e)
        {
            this.sex = SexType.女;
        }

        private void radioBtnUnkown_CheckedChanged(object sender, EventArgs e)
        {
            this.sex = SexType.未知;
        }

        #endregion
    }
}
