using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StuManager
{
    public partial class MainFrm : Form
    {
        #region 字段
        /// <summary>
        /// 数据
        /// </summary>
        private DataClass pData = new DataClass();
        /// <summary>
        /// 单位名称
        /// </summary>
        private string strCompany = "   重庆交通大学信息科学与工程学院   ";
        /// <summary>
        /// 操作过程中用户选择的节点
        /// </summary>
        private TreeNode TN = null;
        /// <summary>
        /// 用户所选择行
        /// </summary>
        private int rowindex=-1;
        #endregion

        #region 构造函数
        public MainFrm()
        {
            InitializeComponent();
        }
        #endregion

        #region 方法

        /// <summary>
        /// 根据文本找在treeView中找到对应的节点对象
        /// </summary>
        /// <param name="strText">节点文本</param>
        /// <returns>成功：节点对象；失败：null</returns>
        private TreeNode FindNodeInTree(string strText)
        {
            TreeNode tn = null;
            foreach (TreeNode p in treeView1.Nodes)
            {
                tn = FindTreeNodeInNodes(p, strText);
                if (tn != null)
                    return tn;
            }
            return tn;
        }

        /// <summary>
        /// 根据文本，在以p为根的树种查找节点对象
        /// </summary>
        /// <param name="p">树的根节点</param>
        /// <param name="strText">节点对应的文本内容</param>
        /// <returns></returns>
        private TreeNode FindTreeNodeInNodes(TreeNode p, string strText)
        {
            if (p.Text == strText) //如果是根节点，则返回
                return p;
            foreach (TreeNode pnode in p.Nodes)
            {
                TreeNode tn = FindTreeNodeInNodes(pnode, strText);
                if (tn != null)
                    return tn;
            }
            return null;
        }

        /// <summary>
        /// 找节点对象
        /// </summary>
        /// <param name="strText"></param>
        /// <returns></returns>
        private TreeNode FindNodeInTreeUsingQueue(string strText)
        {
            TreeNode tn=null;
            Queue<TreeNode> tnqueue = new Queue<TreeNode>();
            foreach (TreeNode p in treeView1.Nodes) 
                tnqueue.Enqueue(p);
            TreeNode head=tnqueue.Dequeue(); //取队列的头
            while(head!=null)
            {
                if (head.Text == strText)
                {
                    tn = head;
                    break;
                }
                else
                {
                    foreach (TreeNode p in head.Nodes)
                        tnqueue.Enqueue(p);
                    head = tnqueue.Dequeue();
                }
            }
            return tn;
        }

        /// <summary>
        /// 在dataGridView控件中增加一行学生信息
        /// </summary>
        /// <param name="stu"></param>
        private void AddStudentInDataGridView(Student stu)
        {
            dataGridView1.Rows.Add(new DataGridViewRow());
            DataGridViewRow row = dataGridView1.Rows[dataGridView1.RowCount - 2];
            row.Cells["stuName"].Value = stu.Name;
            row.Cells["stuID"].Value = stu.ID;
            row.Cells["stuAge"].Value = stu.Age;
            row.Cells["stuSex"].Value = stu.Sex;
            row.Cells["stuChinese"].Value = stu.Chinese;
            row.Cells["stuEnglish"].Value = stu.English;
            row.Cells["stuMath"].Value = stu.Math;
            row.Cells["stuComputer"].Value = stu.Computer;
            dataGridView1.CurrentCell = row.Cells["stuName"];
        }
        
        /// <summary>
        /// 显示所有学生的信息
        /// </summary>
        private void DisplayAllStudent()
        {
            dataGridView1.Rows.Clear();
            foreach (Department pdep in pData.DepList)
                foreach (clsClass pcls in pdep.Classes)
                    foreach (Student pstu in pcls.Students)
                        this.AddStudentInDataGridView(pstu);
        }

        /// <summary>
        /// 显示一个系的学生信息
        /// </summary>
        /// <param name="depobj">系对象</param>
        private void DisplayDepartmentStudent(Department depobj)
        {
            dataGridView1.Rows.Clear();
            foreach (clsClass pcls in depobj.Classes)
                foreach (Student pstu in pcls.Students)
                    AddStudentInDataGridView(pstu);
        }

        /// <summary>
        /// 显示一个班级的所有学生的信息
        /// </summary>
        /// <param name="clsobj">班级对象</param>
        private void DisplayClassStudent(clsClass clsobj)
        {
            dataGridView1.Rows.Clear();
            foreach (Student pstu in clsobj.Students)
                this.AddStudentInDataGridView(pstu);
        }

        /// <summary>
        /// 根据学生的ID查找所在的行的索引
        /// </summary>
        /// <param name="ID"></param>
        /// <returns></returns>
        private int FindStudentInDataGridView(string ID)
        {
            int Index = -1;
            foreach (DataGridViewRow prow in dataGridView1.Rows)
            {
                if (Convert.ToString(prow.Cells["stuID"].Value) == ID)//找到
                {
                    Index = dataGridView1.Rows.IndexOf(prow);
                    break;
                }
            }
            return Index;
        }

        /// <summary>
        /// 返回学生所在的行索引
        /// </summary>
        /// <param name="ID"></param>
        /// <returns></returns>
        private int IndexOfStudentInDataGridView(string ID)
        {
            int index = -1;
            for (int i = 0; i < dataGridView1.Rows.Count-1; i++)
            {
                if (dataGridView1.Rows[i].Cells["StuID"].Value.ToString() == ID)
                {
                    index = i;
                    break;
                }
            }
            return index;
        }

        #endregion

        #region 窗体事件

        /// <summary>
        /// 初始化两个区域的大小
        /// </summary>
        private void InitFormLayout()
        {
            this.splitContainer1.SplitterDistance=(int)(this.Width*0.2);
        }

        /// <summary>
        /// 初始化TreeView
        /// </summary>
        private void InitTreeView()
        {
            TreeNode tn = new TreeNode("全部");
            treeView1.Nodes.Add(tn);
            treeView1.SelectedNode = tn;
        }

        /// <summary>
        /// 初始化DataGridView控件
        /// </summary>
        private void InitDataGridView()
        {
            int width = 121;
            dataGridView1.ColumnHeadersDefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;//表头单元格中的文字居中
            dataGridView1.DefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;//单元格中的文字居中
            DataGridViewTextBoxColumn col = new DataGridViewTextBoxColumn();
            col.HeaderText = "姓名"; col.Name = "StuName"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "ID"; col.Name = "StuID"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "年龄"; col.Name = "StuAge"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "性别"; col.Name = "StuSex"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "语文"; col.Name = "StuChinese"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "数学"; col.Name = "StuMath"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "英语"; col.Name = "StuEnglish"; col.Width = width;
            dataGridView1.Columns.Add(col);
            col = new DataGridViewTextBoxColumn();
            col.HeaderText = "计算机"; col.Name = "StuComputer"; col.Width = width;
            dataGridView1.Columns.Add(col);
        }

        /// <summary>
        /// 窗体Load事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MainFrm_Load(object sender, EventArgs e)
        {
            InitFormLayout();
            InitTreeView();
            InitDataGridView();
            pData.OnClassAdd += new EventHandlerClass(pData_OnClassAdd);
            pData.OnDepartmentAdd += new EventHandlerDepartment(pData_OnDepartmentAdd);
            pData.OnStudentAdd += new EventHandlerStudent(pData_OnStudentAdd);
            pData.OnClassDel += new EventHandlerClass(pData_OnClassDel);
            pData.OnDepartmentDel += new EventHandlerDepartment(pData_OnDepartmentDel);
            pData.OnStudentDel += new EventHandlerStudent(pData_OnStudentDel);
            pData.OnDepartmentModify += new EventHandlerDepartment(pData_OnDepartmentModify);
            pData.OnClassModify += new EventHandlerClass(pData_OnClassModify);
            pData.OnStudentModify += new EventHandlerStudent(pData_OnStudentModify);
        }

        #endregion

        #region 增加、删除、修改事件
        /// <summary>
        /// 处理增加学生事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnStudentAdd(object sender, EventArgsStudent e)
        {
            TreeNode depNode = FindNodeInTree(e.depobj.Name); //学生对应的系节点
            TreeNode clsNode = FindNodeInTree(e.clsobj.Name);//学生对应的班级节点
            //如果treeView当前节点是“全部”或是学生所在的系或者是学生所在的班级节点，则显示学生信息
            if(treeView1.SelectedNode!=null)
                if (treeView1.SelectedNode.Text == "全部" || treeView1.SelectedNode == depNode 
                    || treeView1.SelectedNode == clsNode)
                    this.AddStudentInDataGridView(e.stuobj);
            this.labelStudentNumber.Text = "学生数量：" + e.number.ToString("00");
        }

        /// <summary>
        /// 处理增加系事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        
        private void pData_OnDepartmentAdd(object sender, EventArgsDep e)
        {
            treeView1.Nodes.Add(e.pobj.Name);
            this.labelDepNumber.Text = "系数量："+e.number.ToString("##");
        }
        
        /// <summary>
        /// 处理增加班级事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnClassAdd(object sender, EventArgsClass e)
        {
            TreeNode node = this.FindNodeInTreeUsingQueue(e.depobj.Name);
            node.Nodes.Add(e.clsobj.Name);
            treeView1.CollapseAll();
            node.Expand();
            this.labelClassNumber.Text = "班级数量：" + e.number.ToString("##"); ;
        }

        /// <summary>
        /// 处理删除学生事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnStudentDel(object sender, EventArgsStudent e)
        {
            TreeNode tndep = FindNodeInTree(e.depobj.Name);
            TreeNode tncls = FindNodeInTree(e.clsobj.Name);
            if (treeView1.SelectedNode == tndep || treeView1.SelectedNode == tncls 
                || treeView1.SelectedNode.Text == "全部")
            {
                int index = FindStudentInDataGridView(e.stuobj.ID);
                if (index != -1)
                    dataGridView1.Rows.RemoveAt(index);
                this.labelStudentNumber.Text = "学生数量：" + e.number.ToString("00");
            }
        }

        /// <summary>
        /// 处理删除系事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnDepartmentDel(object sender, EventArgsDep e)
        {
            TreeNode tn = FindNodeInTree(e.pobj.Name);
            treeView1.Nodes.Remove(tn);
            labelDepNumber.Text = "系数量："+e.number.ToString();
            labelClassNumber.Text = "班级数量：" + pData.ClassNumber.ToString();
            labelStudentNumber.Text = "学生数量：" + pData.StudentNumber.ToString();
        }

        /// <summary>
        /// 处理删除班级事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnClassDel(object sender, EventArgsClass e)
        {
            TreeNode tndep = FindNodeInTree(e.depobj.Name); //班级所在系对应的树节点
            TreeNode tncls = FindNodeInTree(e.clsobj.Name);
            if (tncls == null)
                return;
            tndep.Nodes.Remove(tncls);
            labelClassNumber.Text = "班级数量：" + e.number.ToString("00");
            labelStudentNumber.Text = "学生数量：" + pData.StudentNumber.ToString("00");
        }

        /// <summary>
        /// 修改学生信息事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void pData_OnStudentModify(object sender, EventArgsStudent e)
        {
            TreeNode tn = treeView1.SelectedNode;
            if (tn == null) return;
            //学生的系和班级没有更改,修改表格中的内容
            if (tn.Text == e.NewClassName || tn.Text == e.NewDepName || tn.Text == "全部")
            {
                DataGridViewRow row = dataGridView1.Rows[this.rowindex];
                row.Cells["StuName"].Value = e.NewStuobj.Name;
                row.Cells["StuAge"].Value = e.NewStuobj.Age;
                row.Cells["StuSex"].Value = e.NewStuobj.Sex.ToString();
                row.Cells["StuChinese"].Value = e.NewStuobj.Chinese;
                row.Cells["StuEnglish"].Value = e.NewStuobj.English;
                row.Cells["StuMath"].Value = e.NewStuobj.Math;
                row.Cells["StuComputer"].Value = e.NewStuobj.Computer;
            }
            else 
            {
                dataGridView1.Rows.RemoveAt(rowindex);
            }
        }

        /// <summary>
        /// 修改班级事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void pData_OnClassModify(object sender, EventArgsClass e)
        {
            TreeNode tn = FindNodeInTreeUsingQueue(e.OldClassName);
            if (tn != null)
                tn.Text = e.NewClassName;
        }

        /// <summary>
        /// 修改系事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void pData_OnDepartmentModify(object sender, EventArgsDep e)
        {
            TreeNode tn = FindNodeInTree(e.OldDepName);
            if (tn != null)
                tn.Text = e.NewDepName;
        }
        #endregion

        #region 菜单事件

        /// <summary>
        ///“增加--系”事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MenuEditAddDepartment_Click(object sender, EventArgs e)
        {
            string strText = ((ToolStripMenuItem)sender).Text;
            int i=0;
            switch (strText)
            {
                case "系":
                    i = 0;
                    break;
                case "班级":
                    i = 1;
                    break;
                case "学生":
                    i = 2;
                    break;
            }
            FrmAdd frmadd = new FrmAdd(i, pData);
            frmadd.ShowDialog();
        }
       
        /// <summary>
        /// “退出”事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void MenuFileExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        #endregion

        #region Timer事件
        /// <summary>
        /// 形成日期时间字符串,并在状态条上显示
        /// </summary>
        /// <returns></returns>
        private void GetCurrientDateTime()
        {
            DateTime dt = DateTime.Now;
            string str = dt.ToString(" yyyy-MM-dd HH:mm:ss ");
            switch (dt.DayOfWeek)
            {
                case DayOfWeek.Sunday:
                    str += "星期日";
                    break;
                case DayOfWeek.Monday:
                    str+="星期一";
                    break;
                case DayOfWeek.Tuesday:
                    str += "星期二";
                    break;
                case DayOfWeek.Wednesday:
                    str += "星期三";
                    break;
                case DayOfWeek.Thursday:
                    str += "星期四";
                    break;
                case DayOfWeek.Friday:
                    str += "星期五";
                    break;
                case DayOfWeek.Saturday:
                    str += "星期六";
                    break;
            }
            this.labelDateTime.Text = str+" ";
        }
        /// <summary>
        /// 在状态条上显示单位名称
        /// </summary>
        private void DisplayCompany()
        {
            string strLeft = strCompany.Substring(0, 1);
            string strRight = strCompany.Substring(1, strCompany.Length - 1);
            strCompany = strRight + strLeft;
            this.labelCompany.Text = strCompany;
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            DisplayCompany();
            GetCurrientDateTime();
        }
        #endregion

        #region treeView事件
        
        /// <summary>
        /// 用户更改节点
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            string strNodeText = e.Node.Text;
            if (strNodeText == "全部")
            {
                this.DisplayAllStudent();
            }
            else
            {
                Department depobj = pData.FindDepartmentByName(strNodeText);
                if (depobj != null)
                {
                    this.DisplayDepartmentStudent(depobj);
                    return;
                }
                else
                {
                    clsClass clsobj = pData.FindClassByName(strNodeText,out depobj);
                    this.DisplayClassStudent(clsobj);
                }
            }
        }

        /// <summary>
        /// 鼠标单击节点时发生
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            //用户鼠标右键单击节点
            if (e.Button == MouseButtons.Right)
            {
                this.TreeViewMenu.Show(e.X, e.Y);
                TN = e.Node;
            }
        }
        
        /// <summary>
        /// 修改完毕
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void treeView1_AfterLabelEdit(object sender, NodeLabelEditEventArgs e)
        {
            if (e.Node.Text == "全部")
            {
                MessageBox.Show("该节点不能修改");
                return;
            }
            Department depobj = pData.FindDepartmentByName(e.Node.Text);
            if (depobj != null) //修改系的名字
            {
                if (MessageBox.Show("确认修改？", "确认", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                {
                    pData.ModifyDepartment(e.Node.Text, e.Label);
                    e.CancelEdit = false;
                }
            }
            else //修改班级的名字
            {
                clsClass clsobj = pData.FindClassByName(e.Node.Text, out depobj);
                if (MessageBox.Show("确认修改？", "确认", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                    clsobj.Name = e.Label;
                else
                    e.CancelEdit = true;
            }
            //treeView1.LabelEdit = false;
        }
        #endregion

        #region TreeView上下文菜单事件
        
        /// <summary>
        /// 修改菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewMenuEdit_Click(object sender, EventArgs e)
        {
            if (TN != null)
            {
                treeView1.LabelEdit = true;
                TN.BeginEdit();
            }
        }

        /// <summary>
        /// 增加一个节点
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewMenuAdd_Click(object sender, EventArgs e)
        {
            if (TN != null)
            {
                string strInput="";
                if (TN.Parent == null)
                {
                    if (TN.Text == "全部")//增加系节点
                    {
                        frmAddMenu frm = new frmAddMenu();
                        DialogResult result = frm.ShowDialog();
                        if (result == DialogResult.OK)
                            strInput = frm.strName;
                        else
                            return;
                        treeView1.Nodes.Add(strInput);
                        pData.DepList.Add(new Department(strInput));
                    }
                    else//增加班级节点
                    {
                        frmAddMenu frm = new frmAddMenu();
                        DialogResult result = frm.ShowDialog();
                        if (result == DialogResult.OK)
                            strInput = frm.strName;
                        else
                            return;
                        TN.Nodes.Add(strInput);
                        Department dep = pData.FindDepartmentByName(TN.Text);
                        dep.Classes.Add(new clsClass(strInput));
                    }
                }
            }
        }
        
        /// <summary>
        /// 删除菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void TreeViewMenuDel_Click(object sender, EventArgs e)
        {
            if (TN == null)
                return;
            if (TN.Text == "全部")
            {
                MessageBox.Show("该节点不可删除");
                return;
            }
            if (TN.Parent == null)//删除系节点
            {
                DialogResult result = MessageBox.Show("确认删除" + TN.Text + "?\n\r删除后该系所属的班级和学生会丢失！！",
                    "警告", MessageBoxButtons.YesNo, MessageBoxIcon.Asterisk);
                if (result == DialogResult.Yes)//确认删除
                {
                    treeView1.Nodes.Remove(TN);
                    Department dep = pData.FindDepartmentByName(TN.Text);
                    pData.DepList.Remove(dep);
                }
            }
            else//删除班级节点
            {
                DialogResult result = MessageBox.Show("确认删除？" + TN.Text + "\n\r删除后该班级的学生信息会丢失！！",
                                   "警告", MessageBoxButtons.YesNo, MessageBoxIcon.Asterisk);
                if (result == DialogResult.Yes)//确认删除
                {
                    Department dep = pData.FindDepartmentByName(TN.Parent.Text);
                    clsClass cls = pData.FindClassByName(dep, TN.Text);
                    treeView1.Nodes.Remove(TN);
                    pData.DelClass(dep, cls);
                }
            }
        }
        #endregion

        #region DataGridView事件
        /// <summary>
        /// 双击时显示学生信息
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dataGridView1_RowHeaderMouseDoubleClick(object sender, DataGridViewCellMouseEventArgs e)
        {
        }
        /// <summary>
        /// 右键弹出上下文菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dataGridView1_RowHeaderMouseClick(object sender, DataGridViewCellMouseEventArgs e)
        {
            if (e.Button == MouseButtons.Right) //用户单击鼠标右键
            {
                this.rowindex = e.RowIndex; //记录用户所选择的行
                DataGridViewMenu.Show(dataGridView1,e.X, e.Y);
            }
        }
        #endregion

        #region DataGridView上下文菜单
        /// <summary>
        /// 修改学生信息，ID不能修改
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void DataGridViewMenuModify_Click(object sender, EventArgs e)
        {
            DataGridViewRow row = dataGridView1.Rows[rowindex];
            string ID = row.Cells["stuID"].Value.ToString();
            Department depobj=null;
            clsClass clsobj=null;
            Student stuobj = pData.FindStudentByID(ID, out depobj, out clsobj);
            if (stuobj != null)
            {
                frmModifyStudent frm = new frmModifyStudent(pData, depobj.Name, clsobj.Name,stuobj);
                frm.ShowDialog();
            }
        }
        
        /// <summary>
        /// 删除一个学生
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void DataGridViewMenuDel_Click(object sender, EventArgs e)
        {
            DataGridViewRow row = dataGridView1.Rows[rowindex];
            string ID = row.Cells["stuID"].Value.ToString();
            Department depobj;
            clsClass clsobj;
            MessageBox.Show(pData.DelStudent(ID, out depobj, out clsobj) ? "删除成功" : "删除失败");
        }

        /// <summary>
        /// 增加一个学生
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void DataGridViewMenuAdd_Click(object sender, EventArgs e)
        {

        }
        #endregion


    }
}
