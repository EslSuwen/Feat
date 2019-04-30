namespace StuManager
{
    partial class FrmAdd
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPageDep = new System.Windows.Forms.TabPage();
            this.label1 = new System.Windows.Forms.Label();
            this.txtDepName = new System.Windows.Forms.TextBox();
            this.tabPageClass = new System.Windows.Forms.TabPage();
            this.txtClassName = new System.Windows.Forms.TextBox();
            this.combSelDepClass = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.tabPageStudent = new System.Windows.Forms.TabPage();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txtComputer = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.txtMath = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.txtEnglish = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.txtChinese = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.numericStudentAge = new System.Windows.Forms.NumericUpDown();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.radioBtnUnkown = new System.Windows.Forms.RadioButton();
            this.radioBtnFemal = new System.Windows.Forms.RadioButton();
            this.radioBtnMale = new System.Windows.Forms.RadioButton();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.txtStudentID = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.txtStudentName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.combSelClassStudent = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.combSelDepStudent = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnOK = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.tabPageDep.SuspendLayout();
            this.tabPageClass.SuspendLayout();
            this.tabPageStudent.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.tabControl1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(393, 296);
            this.panel1.TabIndex = 0;
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPageDep);
            this.tabControl1.Controls.Add(this.tabPageClass);
            this.tabControl1.Controls.Add(this.tabPageStudent);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(393, 296);
            this.tabControl1.TabIndex = 1;
            this.tabControl1.SelectedIndexChanged += new System.EventHandler(this.tabControl1_SelectedIndexChanged);
            // 
            // tabPageDep
            // 
            this.tabPageDep.Controls.Add(this.label1);
            this.tabPageDep.Controls.Add(this.txtDepName);
            this.tabPageDep.Location = new System.Drawing.Point(4, 23);
            this.tabPageDep.Name = "tabPageDep";
            this.tabPageDep.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageDep.Size = new System.Drawing.Size(385, 269);
            this.tabPageDep.TabIndex = 0;
            this.tabPageDep.Text = "系";
            this.tabPageDep.UseVisualStyleBackColor = true;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(66, 88);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(91, 14);
            this.label1.TabIndex = 2;
            this.label1.Text = "请输入系名：";
            // 
            // txtDepName
            // 
            this.txtDepName.Location = new System.Drawing.Point(163, 84);
            this.txtDepName.Name = "txtDepName";
            this.txtDepName.Size = new System.Drawing.Size(114, 23);
            this.txtDepName.TabIndex = 1;
            // 
            // tabPageClass
            // 
            this.tabPageClass.Controls.Add(this.txtClassName);
            this.tabPageClass.Controls.Add(this.combSelDepClass);
            this.tabPageClass.Controls.Add(this.label3);
            this.tabPageClass.Controls.Add(this.label2);
            this.tabPageClass.Location = new System.Drawing.Point(4, 23);
            this.tabPageClass.Name = "tabPageClass";
            this.tabPageClass.Padding = new System.Windows.Forms.Padding(3);
            this.tabPageClass.Size = new System.Drawing.Size(385, 269);
            this.tabPageClass.TabIndex = 1;
            this.tabPageClass.Text = "班级";
            this.tabPageClass.UseVisualStyleBackColor = true;
            // 
            // txtClassName
            // 
            this.txtClassName.Location = new System.Drawing.Point(177, 117);
            this.txtClassName.Name = "txtClassName";
            this.txtClassName.Size = new System.Drawing.Size(100, 23);
            this.txtClassName.TabIndex = 3;
            // 
            // combSelDepClass
            // 
            this.combSelDepClass.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combSelDepClass.FormattingEnabled = true;
            this.combSelDepClass.Location = new System.Drawing.Point(177, 68);
            this.combSelDepClass.Name = "combSelDepClass";
            this.combSelDepClass.Size = new System.Drawing.Size(100, 22);
            this.combSelDepClass.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(83, 121);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 14);
            this.label3.TabIndex = 1;
            this.label3.Text = "班级名称：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(83, 72);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 14);
            this.label2.TabIndex = 0;
            this.label2.Text = "请选择系：";
            // 
            // tabPageStudent
            // 
            this.tabPageStudent.Controls.Add(this.groupBox3);
            this.tabPageStudent.Controls.Add(this.numericStudentAge);
            this.tabPageStudent.Controls.Add(this.groupBox2);
            this.tabPageStudent.Controls.Add(this.label8);
            this.tabPageStudent.Controls.Add(this.label9);
            this.tabPageStudent.Controls.Add(this.txtStudentID);
            this.tabPageStudent.Controls.Add(this.label7);
            this.tabPageStudent.Controls.Add(this.txtStudentName);
            this.tabPageStudent.Controls.Add(this.label6);
            this.tabPageStudent.Controls.Add(this.groupBox1);
            this.tabPageStudent.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            this.tabPageStudent.Location = new System.Drawing.Point(4, 23);
            this.tabPageStudent.Name = "tabPageStudent";
            this.tabPageStudent.Size = new System.Drawing.Size(385, 269);
            this.tabPageStudent.TabIndex = 2;
            this.tabPageStudent.Text = "学生";
            this.tabPageStudent.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtComputer);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.txtMath);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.txtEnglish);
            this.groupBox3.Controls.Add(this.label11);
            this.groupBox3.Controls.Add(this.txtChinese);
            this.groupBox3.Controls.Add(this.label10);
            this.groupBox3.Location = new System.Drawing.Point(2, 164);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(387, 97);
            this.groupBox3.TabIndex = 16;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "课程成绩";
            // 
            // txtComputer
            // 
            this.txtComputer.Location = new System.Drawing.Point(249, 59);
            this.txtComputer.Name = "txtComputer";
            this.txtComputer.Size = new System.Drawing.Size(100, 23);
            this.txtComputer.TabIndex = 16;
            this.txtComputer.Text = "0";
            this.txtComputer.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxInput_KeyPress);
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.ForeColor = System.Drawing.Color.Black;
            this.label13.Location = new System.Drawing.Point(183, 63);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(63, 14);
            this.label13.TabIndex = 15;
            this.label13.Text = "计算机：";
            // 
            // txtMath
            // 
            this.txtMath.Location = new System.Drawing.Point(76, 59);
            this.txtMath.Name = "txtMath";
            this.txtMath.Size = new System.Drawing.Size(100, 23);
            this.txtMath.TabIndex = 14;
            this.txtMath.Text = "0";
            this.txtMath.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxInput_KeyPress);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.ForeColor = System.Drawing.Color.Black;
            this.label12.Location = new System.Drawing.Point(24, 63);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(49, 14);
            this.label12.TabIndex = 13;
            this.label12.Text = "数学：";
            // 
            // txtEnglish
            // 
            this.txtEnglish.Location = new System.Drawing.Point(249, 21);
            this.txtEnglish.Name = "txtEnglish";
            this.txtEnglish.Size = new System.Drawing.Size(100, 23);
            this.txtEnglish.TabIndex = 12;
            this.txtEnglish.Text = "0";
            this.txtEnglish.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxInput_KeyPress);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.ForeColor = System.Drawing.Color.Black;
            this.label11.Location = new System.Drawing.Point(197, 25);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(49, 14);
            this.label11.TabIndex = 11;
            this.label11.Text = "英语：";
            // 
            // txtChinese
            // 
            this.txtChinese.Location = new System.Drawing.Point(76, 21);
            this.txtChinese.Name = "txtChinese";
            this.txtChinese.Size = new System.Drawing.Size(100, 23);
            this.txtChinese.TabIndex = 10;
            this.txtChinese.Text = "0";
            this.txtChinese.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBoxInput_KeyPress);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.ForeColor = System.Drawing.Color.Black;
            this.label10.Location = new System.Drawing.Point(24, 25);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(49, 14);
            this.label10.TabIndex = 9;
            this.label10.Text = "语文：";
            // 
            // numericStudentAge
            // 
            this.numericStudentAge.Location = new System.Drawing.Point(60, 119);
            this.numericStudentAge.Name = "numericStudentAge";
            this.numericStudentAge.Size = new System.Drawing.Size(100, 23);
            this.numericStudentAge.TabIndex = 15;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioBtnUnkown);
            this.groupBox2.Controls.Add(this.radioBtnFemal);
            this.groupBox2.Controls.Add(this.radioBtnMale);
            this.groupBox2.Location = new System.Drawing.Point(229, 110);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(146, 34);
            this.groupBox2.TabIndex = 14;
            this.groupBox2.TabStop = false;
            // 
            // radioBtnUnkown
            // 
            this.radioBtnUnkown.AutoSize = true;
            this.radioBtnUnkown.ForeColor = System.Drawing.Color.Black;
            this.radioBtnUnkown.Location = new System.Drawing.Point(95, 11);
            this.radioBtnUnkown.Name = "radioBtnUnkown";
            this.radioBtnUnkown.Size = new System.Drawing.Size(53, 18);
            this.radioBtnUnkown.TabIndex = 2;
            this.radioBtnUnkown.TabStop = true;
            this.radioBtnUnkown.Text = "未知";
            this.radioBtnUnkown.UseVisualStyleBackColor = true;
            this.radioBtnUnkown.Click += new System.EventHandler(this.radioBtnUnkown_Click);
            // 
            // radioBtnFemal
            // 
            this.radioBtnFemal.AutoSize = true;
            this.radioBtnFemal.ForeColor = System.Drawing.Color.Black;
            this.radioBtnFemal.Location = new System.Drawing.Point(50, 11);
            this.radioBtnFemal.Name = "radioBtnFemal";
            this.radioBtnFemal.Size = new System.Drawing.Size(39, 18);
            this.radioBtnFemal.TabIndex = 1;
            this.radioBtnFemal.TabStop = true;
            this.radioBtnFemal.Text = "女";
            this.radioBtnFemal.UseVisualStyleBackColor = true;
            this.radioBtnFemal.Click += new System.EventHandler(this.radioBtnFemal_Click);
            // 
            // radioBtnMale
            // 
            this.radioBtnMale.AutoSize = true;
            this.radioBtnMale.ForeColor = System.Drawing.Color.Black;
            this.radioBtnMale.Location = new System.Drawing.Point(5, 11);
            this.radioBtnMale.Name = "radioBtnMale";
            this.radioBtnMale.Size = new System.Drawing.Size(39, 18);
            this.radioBtnMale.TabIndex = 0;
            this.radioBtnMale.TabStop = true;
            this.radioBtnMale.Text = "男";
            this.radioBtnMale.UseVisualStyleBackColor = true;
            this.radioBtnMale.Click += new System.EventHandler(this.radioBtnMale_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.ForeColor = System.Drawing.Color.Black;
            this.label8.Location = new System.Drawing.Point(179, 123);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(49, 14);
            this.label8.TabIndex = 13;
            this.label8.Text = "性别：";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.ForeColor = System.Drawing.Color.Black;
            this.label9.Location = new System.Drawing.Point(8, 123);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(49, 14);
            this.label9.TabIndex = 11;
            this.label9.Text = "年龄：";
            // 
            // txtStudentID
            // 
            this.txtStudentID.Location = new System.Drawing.Point(229, 81);
            this.txtStudentID.Name = "txtStudentID";
            this.txtStudentID.Size = new System.Drawing.Size(100, 23);
            this.txtStudentID.TabIndex = 10;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(193, 85);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 14);
            this.label7.TabIndex = 9;
            this.label7.Text = "ID：";
            // 
            // txtStudentName
            // 
            this.txtStudentName.Location = new System.Drawing.Point(60, 81);
            this.txtStudentName.Name = "txtStudentName";
            this.txtStudentName.Size = new System.Drawing.Size(100, 23);
            this.txtStudentName.TabIndex = 8;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(8, 85);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 14);
            this.label6.TabIndex = 1;
            this.label6.Text = "姓名：";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.combSelClassStudent);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.combSelDepStudent);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Location = new System.Drawing.Point(3, 13);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(374, 56);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "请选择";
            // 
            // combSelClassStudent
            // 
            this.combSelClassStudent.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combSelClassStudent.FormattingEnabled = true;
            this.combSelClassStudent.Location = new System.Drawing.Point(242, 22);
            this.combSelClassStudent.Name = "combSelClassStudent";
            this.combSelClassStudent.Size = new System.Drawing.Size(101, 22);
            this.combSelClassStudent.TabIndex = 7;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label5.Location = new System.Drawing.Point(19, 26);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(35, 14);
            this.label5.TabIndex = 4;
            this.label5.Text = "系：";
            // 
            // combSelDepStudent
            // 
            this.combSelDepStudent.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combSelDepStudent.FormattingEnabled = true;
            this.combSelDepStudent.Location = new System.Drawing.Point(60, 22);
            this.combSelDepStudent.Name = "combSelDepStudent";
            this.combSelDepStudent.Size = new System.Drawing.Size(109, 22);
            this.combSelDepStudent.TabIndex = 6;
            this.combSelDepStudent.SelectedIndexChanged += new System.EventHandler(this.combSelDepStudent_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.SystemColors.Desktop;
            this.label4.Location = new System.Drawing.Point(191, 26);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 14);
            this.label4.TabIndex = 5;
            this.label4.Text = "班级：";
            // 
            // panel2
            // 
            this.panel2.AutoSize = true;
            this.panel2.Controls.Add(this.btnCancel);
            this.panel2.Controls.Add(this.btnOK);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel2.Location = new System.Drawing.Point(0, 308);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(393, 29);
            this.panel2.TabIndex = 1;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(206, 3);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 1;
            this.btnCancel.Text = "取消";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(82, 3);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 0;
            this.btnOK.Text = "保存";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // FrmAdd
            // 
            this.AcceptButton = this.btnOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnCancel;
            this.ClientSize = new System.Drawing.Size(393, 337);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "FrmAdd";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "增加（系、班级、学生）";
            this.Load += new System.EventHandler(this.FrmAdd_Load);
            this.panel1.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.tabPageDep.ResumeLayout(false);
            this.tabPageDep.PerformLayout();
            this.tabPageClass.ResumeLayout(false);
            this.tabPageClass.PerformLayout();
            this.tabPageStudent.ResumeLayout(false);
            this.tabPageStudent.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPageDep;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtDepName;
        private System.Windows.Forms.TabPage tabPageClass;
        private System.Windows.Forms.TabPage tabPageStudent;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.TextBox txtClassName;
        private System.Windows.Forms.ComboBox combSelDepClass;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox combSelDepStudent;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtStudentID;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtStudentName;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton radioBtnMale;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.NumericUpDown numericStudentAge;
        private System.Windows.Forms.RadioButton radioBtnUnkown;
        private System.Windows.Forms.RadioButton radioBtnFemal;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txtComputer;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox txtMath;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox txtEnglish;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox txtChinese;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox combSelClassStudent;

    }
}