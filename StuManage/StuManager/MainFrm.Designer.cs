namespace StuManager
{
    partial class MainFrm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.MenuFile = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuFileExit = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEdit = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditAddDepartment = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditAddClass = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditAddStudent = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditDel = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditDelDepartment = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditDelClass = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuEditDelStudent = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.labelCompany = new System.Windows.Forms.ToolStripStatusLabel();
            this.labelDateTime = new System.Windows.Forms.ToolStripStatusLabel();
            this.labelDepNumber = new System.Windows.Forms.ToolStripStatusLabel();
            this.labelClassNumber = new System.Windows.Forms.ToolStripStatusLabel();
            this.labelStudentNumber = new System.Windows.Forms.ToolStripStatusLabel();
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.TreeViewMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.TreeViewMenuEdit = new System.Windows.Forms.ToolStripMenuItem();
            this.TreeViewMenuDel = new System.Windows.Forms.ToolStripMenuItem();
            this.TreeViewMenuAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.DataGridViewMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.DataGridViewMenuModify = new System.Windows.Forms.ToolStripMenuItem();
            this.DataGridViewMenuDel = new System.Windows.Forms.ToolStripMenuItem();
            this.DataGridViewMenuAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.TreeViewMenu.SuspendLayout();
            this.DataGridViewMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuFile,
            this.MenuEdit});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1470, 25);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // MenuFile
            // 
            this.MenuFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuFileExit});
            this.MenuFile.Name = "MenuFile";
            this.MenuFile.Size = new System.Drawing.Size(58, 21);
            this.MenuFile.Text = "文件(&F)";
            // 
            // MenuFileExit
            // 
            this.MenuFileExit.Name = "MenuFileExit";
            this.MenuFileExit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.X)));
            this.MenuFileExit.Size = new System.Drawing.Size(140, 22);
            this.MenuFileExit.Text = "退出";
            this.MenuFileExit.Click += new System.EventHandler(this.MenuFileExit_Click);
            // 
            // MenuEdit
            // 
            this.MenuEdit.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuEditAdd,
            this.MenuEditDel});
            this.MenuEdit.Name = "MenuEdit";
            this.MenuEdit.Size = new System.Drawing.Size(59, 21);
            this.MenuEdit.Text = "编辑(&E)";
            // 
            // MenuEditAdd
            // 
            this.MenuEditAdd.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuEditAddDepartment,
            this.MenuEditAddClass,
            this.MenuEditAddStudent});
            this.MenuEditAdd.Name = "MenuEditAdd";
            this.MenuEditAdd.Size = new System.Drawing.Size(180, 22);
            this.MenuEditAdd.Text = "增加";
            // 
            // MenuEditAddDepartment
            // 
            this.MenuEditAddDepartment.Name = "MenuEditAddDepartment";
            this.MenuEditAddDepartment.Size = new System.Drawing.Size(180, 22);
            this.MenuEditAddDepartment.Text = "系";
            this.MenuEditAddDepartment.Click += new System.EventHandler(this.MenuEditAddDepartment_Click);
            // 
            // MenuEditAddClass
            // 
            this.MenuEditAddClass.Name = "MenuEditAddClass";
            this.MenuEditAddClass.Size = new System.Drawing.Size(180, 22);
            this.MenuEditAddClass.Text = "班级";
            this.MenuEditAddClass.Click += new System.EventHandler(this.MenuEditAddDepartment_Click);
            // 
            // MenuEditAddStudent
            // 
            this.MenuEditAddStudent.Name = "MenuEditAddStudent";
            this.MenuEditAddStudent.Size = new System.Drawing.Size(180, 22);
            this.MenuEditAddStudent.Text = "学生";
            this.MenuEditAddStudent.Click += new System.EventHandler(this.MenuEditAddDepartment_Click);
            // 
            // MenuEditDel
            // 
            this.MenuEditDel.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuEditDelDepartment,
            this.MenuEditDelClass,
            this.MenuEditDelStudent});
            this.MenuEditDel.Name = "MenuEditDel";
            this.MenuEditDel.Size = new System.Drawing.Size(180, 22);
            this.MenuEditDel.Text = "删除";
            // 
            // MenuEditDelDepartment
            // 
            this.MenuEditDelDepartment.Name = "MenuEditDelDepartment";
            this.MenuEditDelDepartment.Size = new System.Drawing.Size(100, 22);
            this.MenuEditDelDepartment.Text = "系";
            // 
            // MenuEditDelClass
            // 
            this.MenuEditDelClass.Name = "MenuEditDelClass";
            this.MenuEditDelClass.Size = new System.Drawing.Size(100, 22);
            this.MenuEditDelClass.Text = "班级";
            // 
            // MenuEditDelStudent
            // 
            this.MenuEditDelStudent.AccessibleRole = System.Windows.Forms.AccessibleRole.None;
            this.MenuEditDelStudent.Name = "MenuEditDelStudent";
            this.MenuEditDelStudent.Size = new System.Drawing.Size(100, 22);
            this.MenuEditDelStudent.Text = "学生";
            // 
            // toolStrip1
            // 
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.toolStrip1.Location = new System.Drawing.Point(0, 25);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1470, 25);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // statusStrip1
            // 
            this.statusStrip1.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.labelCompany,
            this.labelDateTime,
            this.labelDepNumber,
            this.labelClassNumber,
            this.labelStudentNumber});
            this.statusStrip1.Location = new System.Drawing.Point(0, 1038);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1470, 23);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // labelCompany
            // 
            this.labelCompany.Name = "labelCompany";
            this.labelCompany.Size = new System.Drawing.Size(245, 18);
            this.labelCompany.Text = "  重庆交通大学信息科学与工程学院  ";
            // 
            // labelDateTime
            // 
            this.labelDateTime.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.labelDateTime.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.labelDateTime.BorderStyle = System.Windows.Forms.Border3DStyle.Sunken;
            this.labelDateTime.Name = "labelDateTime";
            this.labelDateTime.Size = new System.Drawing.Size(200, 18);
            this.labelDateTime.Text = "yyyy-mm-dd HH:mm:ss  星期一";
            // 
            // labelDepNumber
            // 
            this.labelDepNumber.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelDepNumber.Name = "labelDepNumber";
            this.labelDepNumber.Size = new System.Drawing.Size(83, 18);
            this.labelDepNumber.Text = "系数量：  ";
            // 
            // labelClassNumber
            // 
            this.labelClassNumber.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.labelClassNumber.BorderSides = ((System.Windows.Forms.ToolStripStatusLabelBorderSides)((((System.Windows.Forms.ToolStripStatusLabelBorderSides.Left | System.Windows.Forms.ToolStripStatusLabelBorderSides.Top) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Right) 
            | System.Windows.Forms.ToolStripStatusLabelBorderSides.Bottom)));
            this.labelClassNumber.BorderStyle = System.Windows.Forms.Border3DStyle.Sunken;
            this.labelClassNumber.Name = "labelClassNumber";
            this.labelClassNumber.Size = new System.Drawing.Size(102, 18);
            this.labelClassNumber.Text = "班级数量：   ";
            // 
            // labelStudentNumber
            // 
            this.labelStudentNumber.Name = "labelStudentNumber";
            this.labelStudentNumber.Size = new System.Drawing.Size(91, 18);
            this.labelStudentNumber.Text = "学生数量:   ";
            // 
            // splitContainer1
            // 
            this.splitContainer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.IsSplitterFixed = true;
            this.splitContainer1.Location = new System.Drawing.Point(0, 50);
            this.splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.treeView1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.dataGridView1);
            this.splitContainer1.Size = new System.Drawing.Size(1470, 988);
            this.splitContainer1.SplitterDistance = 486;
            this.splitContainer1.SplitterWidth = 2;
            this.splitContainer1.TabIndex = 3;
            // 
            // treeView1
            // 
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.Location = new System.Drawing.Point(0, 0);
            this.treeView1.Name = "treeView1";
            this.treeView1.Size = new System.Drawing.Size(484, 986);
            this.treeView1.TabIndex = 0;
            this.treeView1.AfterLabelEdit += new System.Windows.Forms.NodeLabelEditEventHandler(this.treeView1_AfterLabelEdit);
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            this.treeView1.NodeMouseClick += new System.Windows.Forms.TreeNodeMouseClickEventHandler(this.treeView1_NodeMouseClick);
            // 
            // dataGridView1
            // 
            dataGridViewCellStyle1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.dataGridView1.AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridView1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(980, 986);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.RowHeaderMouseClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dataGridView1_RowHeaderMouseClick);
            this.dataGridView1.RowHeaderMouseDoubleClick += new System.Windows.Forms.DataGridViewCellMouseEventHandler(this.dataGridView1_RowHeaderMouseDoubleClick);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 800;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // TreeViewMenu
            // 
            this.TreeViewMenu.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.TreeViewMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.TreeViewMenuEdit,
            this.TreeViewMenuDel,
            this.TreeViewMenuAdd});
            this.TreeViewMenu.Name = "TreeViewMenu";
            this.TreeViewMenu.Size = new System.Drawing.Size(101, 70);
            // 
            // TreeViewMenuEdit
            // 
            this.TreeViewMenuEdit.Name = "TreeViewMenuEdit";
            this.TreeViewMenuEdit.Size = new System.Drawing.Size(100, 22);
            this.TreeViewMenuEdit.Text = "修改";
            this.TreeViewMenuEdit.Click += new System.EventHandler(this.TreeViewMenuEdit_Click);
            // 
            // TreeViewMenuDel
            // 
            this.TreeViewMenuDel.Name = "TreeViewMenuDel";
            this.TreeViewMenuDel.Size = new System.Drawing.Size(100, 22);
            this.TreeViewMenuDel.Text = "删除";
            this.TreeViewMenuDel.Click += new System.EventHandler(this.TreeViewMenuDel_Click);
            // 
            // TreeViewMenuAdd
            // 
            this.TreeViewMenuAdd.Name = "TreeViewMenuAdd";
            this.TreeViewMenuAdd.Size = new System.Drawing.Size(100, 22);
            this.TreeViewMenuAdd.Text = "增加";
            this.TreeViewMenuAdd.Click += new System.EventHandler(this.TreeViewMenuAdd_Click);
            // 
            // DataGridViewMenu
            // 
            this.DataGridViewMenu.AccessibleRole = System.Windows.Forms.AccessibleRole.None;
            this.DataGridViewMenu.ImageScalingSize = new System.Drawing.Size(32, 32);
            this.DataGridViewMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.DataGridViewMenuModify,
            this.DataGridViewMenuDel,
            this.DataGridViewMenuAdd});
            this.DataGridViewMenu.Name = "DataGridViewMenu";
            this.DataGridViewMenu.Size = new System.Drawing.Size(101, 70);
            // 
            // DataGridViewMenuModify
            // 
            this.DataGridViewMenuModify.Name = "DataGridViewMenuModify";
            this.DataGridViewMenuModify.Size = new System.Drawing.Size(100, 22);
            this.DataGridViewMenuModify.Text = "修改";
            this.DataGridViewMenuModify.Click += new System.EventHandler(this.DataGridViewMenuModify_Click);
            // 
            // DataGridViewMenuDel
            // 
            this.DataGridViewMenuDel.Name = "DataGridViewMenuDel";
            this.DataGridViewMenuDel.Size = new System.Drawing.Size(100, 22);
            this.DataGridViewMenuDel.Text = "删除";
            this.DataGridViewMenuDel.Click += new System.EventHandler(this.DataGridViewMenuDel_Click);
            // 
            // DataGridViewMenuAdd
            // 
            this.DataGridViewMenuAdd.Name = "DataGridViewMenuAdd";
            this.DataGridViewMenuAdd.Size = new System.Drawing.Size(100, 22);
            this.DataGridViewMenuAdd.Text = "增加";
            this.DataGridViewMenuAdd.Click += new System.EventHandler(this.DataGridViewMenuAdd_Click);
            // 
            // MainFrm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1470, 1061);
            this.Controls.Add(this.splitContainer1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainFrm";
            this.Text = "学生信息管理系统";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.MainFrm_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.TreeViewMenu.ResumeLayout(false);
            this.DataGridViewMenu.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.ToolStripMenuItem MenuFile;
        private System.Windows.Forms.ToolStripMenuItem MenuFileExit;
        private System.Windows.Forms.ToolStripMenuItem MenuEdit;
        private System.Windows.Forms.ToolStripMenuItem MenuEditAdd;
        private System.Windows.Forms.ToolStripMenuItem MenuEditDel;
        private System.Windows.Forms.ToolStripStatusLabel labelCompany;
        private System.Windows.Forms.ToolStripStatusLabel labelDateTime;
        private System.Windows.Forms.ToolStripStatusLabel labelDepNumber;
        private System.Windows.Forms.ToolStripStatusLabel labelClassNumber;
        private System.Windows.Forms.ToolStripStatusLabel labelStudentNumber;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.ToolStripMenuItem MenuEditAddDepartment;
        private System.Windows.Forms.ToolStripMenuItem MenuEditAddClass;
        private System.Windows.Forms.ToolStripMenuItem MenuEditAddStudent;
        private System.Windows.Forms.ToolStripMenuItem MenuEditDelDepartment;
        private System.Windows.Forms.ToolStripMenuItem MenuEditDelClass;
        private System.Windows.Forms.ToolStripMenuItem MenuEditDelStudent;
        private System.Windows.Forms.ContextMenuStrip TreeViewMenu;
        private System.Windows.Forms.ToolStripMenuItem TreeViewMenuEdit;
        private System.Windows.Forms.ToolStripMenuItem TreeViewMenuDel;
        private System.Windows.Forms.ToolStripMenuItem TreeViewMenuAdd;
        private System.Windows.Forms.ContextMenuStrip DataGridViewMenu;
        private System.Windows.Forms.ToolStripMenuItem DataGridViewMenuModify;
        private System.Windows.Forms.ToolStripMenuItem DataGridViewMenuDel;
        private System.Windows.Forms.ToolStripMenuItem DataGridViewMenuAdd;
    }
}

