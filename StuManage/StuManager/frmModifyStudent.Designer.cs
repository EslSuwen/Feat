namespace StuManager
{
    partial class frmModifyStudent
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
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtStudentName = new System.Windows.Forms.TextBox();
            this.txtStudentID = new System.Windows.Forms.TextBox();
            this.numericStudentAge = new System.Windows.Forms.NumericUpDown();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioBtnUnkown = new System.Windows.Forms.RadioButton();
            this.radioBtnFemale = new System.Windows.Forms.RadioButton();
            this.radioBtnMale = new System.Windows.Forms.RadioButton();
            this.combClass = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.combDepartment = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.splitter1 = new System.Windows.Forms.Splitter();
            this.splitter2 = new System.Windows.Forms.Splitter();
            this.splitter3 = new System.Windows.Forms.Splitter();
            this.txtStudentChinese = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.txtStudentMath = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.txtStudentEnglish = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txtStudentComputer = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(21, 108);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 14);
            this.label3.TabIndex = 4;
            this.label3.Text = "姓名：";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(171, 51);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 14);
            this.label4.TabIndex = 5;
            this.label4.Text = "ID：";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(21, 137);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(49, 14);
            this.label5.TabIndex = 6;
            this.label5.Text = "年龄：";
            // 
            // txtStudentName
            // 
            this.txtStudentName.Location = new System.Drawing.Point(65, 104);
            this.txtStudentName.Name = "txtStudentName";
            this.txtStudentName.Size = new System.Drawing.Size(83, 23);
            this.txtStudentName.TabIndex = 2;
            // 
            // txtStudentID
            // 
            this.txtStudentID.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.txtStudentID.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtStudentID.Location = new System.Drawing.Point(212, 47);
            this.txtStudentID.Name = "txtStudentID";
            this.txtStudentID.ReadOnly = true;
            this.txtStudentID.Size = new System.Drawing.Size(83, 16);
            this.txtStudentID.TabIndex = 8;
            this.txtStudentID.TabStop = false;
            // 
            // numericStudentAge
            // 
            this.numericStudentAge.Location = new System.Drawing.Point(64, 133);
            this.numericStudentAge.Name = "numericStudentAge";
            this.numericStudentAge.Size = new System.Drawing.Size(84, 23);
            this.numericStudentAge.TabIndex = 3;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioBtnUnkown);
            this.groupBox1.Controls.Add(this.radioBtnFemale);
            this.groupBox1.Controls.Add(this.radioBtnMale);
            this.groupBox1.Location = new System.Drawing.Point(174, 76);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(121, 80);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "性别";
            // 
            // radioBtnUnkown
            // 
            this.radioBtnUnkown.AutoSize = true;
            this.radioBtnUnkown.Location = new System.Drawing.Point(13, 62);
            this.radioBtnUnkown.Name = "radioBtnUnkown";
            this.radioBtnUnkown.Size = new System.Drawing.Size(53, 18);
            this.radioBtnUnkown.TabIndex = 6;
            this.radioBtnUnkown.TabStop = true;
            this.radioBtnUnkown.Text = "未知";
            this.radioBtnUnkown.UseVisualStyleBackColor = true;
            this.radioBtnUnkown.CheckedChanged += new System.EventHandler(this.radioBtnUnkown_CheckedChanged);
            // 
            // radioBtnFemale
            // 
            this.radioBtnFemale.AutoSize = true;
            this.radioBtnFemale.Location = new System.Drawing.Point(13, 42);
            this.radioBtnFemale.Name = "radioBtnFemale";
            this.radioBtnFemale.Size = new System.Drawing.Size(39, 18);
            this.radioBtnFemale.TabIndex = 5;
            this.radioBtnFemale.TabStop = true;
            this.radioBtnFemale.Text = "女";
            this.radioBtnFemale.UseVisualStyleBackColor = true;
            this.radioBtnFemale.CheckedChanged += new System.EventHandler(this.radioBtnFemale_CheckedChanged);
            // 
            // radioBtnMale
            // 
            this.radioBtnMale.AutoSize = true;
            this.radioBtnMale.Location = new System.Drawing.Point(13, 22);
            this.radioBtnMale.Name = "radioBtnMale";
            this.radioBtnMale.Size = new System.Drawing.Size(39, 18);
            this.radioBtnMale.TabIndex = 4;
            this.radioBtnMale.TabStop = true;
            this.radioBtnMale.Text = "男";
            this.radioBtnMale.UseVisualStyleBackColor = true;
            this.radioBtnMale.CheckedChanged += new System.EventHandler(this.radioBtnMale_CheckedChanged);
            // 
            // combClass
            // 
            this.combClass.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combClass.FormattingEnabled = true;
            this.combClass.Location = new System.Drawing.Point(65, 72);
            this.combClass.Name = "combClass";
            this.combClass.Size = new System.Drawing.Size(83, 22);
            this.combClass.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(21, 76);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 14);
            this.label2.TabIndex = 14;
            this.label2.Text = "班级：";
            // 
            // combDepartment
            // 
            this.combDepartment.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.combDepartment.FormattingEnabled = true;
            this.combDepartment.Location = new System.Drawing.Point(65, 43);
            this.combDepartment.Name = "combDepartment";
            this.combDepartment.Size = new System.Drawing.Size(83, 22);
            this.combDepartment.TabIndex = 0;
            this.combDepartment.SelectedIndexChanged += new System.EventHandler(this.combDepartment_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(35, 47);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 14);
            this.label1.TabIndex = 12;
            this.label1.Text = "系：";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.label6.Font = new System.Drawing.Font("楷体_GB2312", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label6.Location = new System.Drawing.Point(107, 9);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(93, 19);
            this.label6.TabIndex = 16;
            this.label6.Text = "学生信息";
            // 
            // splitter1
            // 
            this.splitter1.Dock = System.Windows.Forms.DockStyle.Top;
            this.splitter1.Location = new System.Drawing.Point(0, 37);
            this.splitter1.Name = "splitter1";
            this.splitter1.Size = new System.Drawing.Size(307, 132);
            this.splitter1.TabIndex = 17;
            this.splitter1.TabStop = false;
            // 
            // splitter2
            // 
            this.splitter2.Dock = System.Windows.Forms.DockStyle.Top;
            this.splitter2.Location = new System.Drawing.Point(0, 0);
            this.splitter2.Name = "splitter2";
            this.splitter2.Size = new System.Drawing.Size(307, 37);
            this.splitter2.TabIndex = 18;
            this.splitter2.TabStop = false;
            // 
            // splitter3
            // 
            this.splitter3.Dock = System.Windows.Forms.DockStyle.Top;
            this.splitter3.Location = new System.Drawing.Point(0, 169);
            this.splitter3.Name = "splitter3";
            this.splitter3.Size = new System.Drawing.Size(307, 73);
            this.splitter3.TabIndex = 19;
            this.splitter3.TabStop = false;
            // 
            // txtStudentChinese
            // 
            this.txtStudentChinese.Location = new System.Drawing.Point(65, 175);
            this.txtStudentChinese.Name = "txtStudentChinese";
            this.txtStudentChinese.Size = new System.Drawing.Size(83, 23);
            this.txtStudentChinese.TabIndex = 7;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(21, 179);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(49, 14);
            this.label7.TabIndex = 20;
            this.label7.Text = "语文：";
            // 
            // txtStudentMath
            // 
            this.txtStudentMath.Location = new System.Drawing.Point(212, 179);
            this.txtStudentMath.Name = "txtStudentMath";
            this.txtStudentMath.Size = new System.Drawing.Size(83, 23);
            this.txtStudentMath.TabIndex = 9;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(168, 183);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(49, 14);
            this.label8.TabIndex = 22;
            this.label8.Text = "数学：";
            // 
            // txtStudentEnglish
            // 
            this.txtStudentEnglish.Location = new System.Drawing.Point(65, 204);
            this.txtStudentEnglish.Name = "txtStudentEnglish";
            this.txtStudentEnglish.Size = new System.Drawing.Size(83, 23);
            this.txtStudentEnglish.TabIndex = 8;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(21, 208);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(49, 14);
            this.label9.TabIndex = 24;
            this.label9.Text = "英语：";
            // 
            // txtStudentComputer
            // 
            this.txtStudentComputer.Location = new System.Drawing.Point(212, 208);
            this.txtStudentComputer.Name = "txtStudentComputer";
            this.txtStudentComputer.Size = new System.Drawing.Size(83, 23);
            this.txtStudentComputer.TabIndex = 10;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(154, 212);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(63, 14);
            this.label10.TabIndex = 26;
            this.label10.Text = "计算机：";
            // 
            // btnOK
            // 
            this.btnOK.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnOK.Location = new System.Drawing.Point(64, 248);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(54, 23);
            this.btnOK.TabIndex = 11;
            this.btnOK.Text = "确定";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnCancel.Location = new System.Drawing.Point(165, 248);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(54, 23);
            this.btnCancel.TabIndex = 12;
            this.btnCancel.Text = "取消";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // frmModifyStudent
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(307, 281);
            this.ControlBox = false;
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.txtStudentComputer);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.txtStudentEnglish);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.txtStudentMath);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.txtStudentChinese);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.splitter3);
            this.Controls.Add(this.combDepartment);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.combClass);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.numericStudentAge);
            this.Controls.Add(this.txtStudentID);
            this.Controls.Add(this.txtStudentName);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.splitter1);
            this.Controls.Add(this.splitter2);
            this.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "frmModifyStudent";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "修改学生信息";
            this.Load += new System.EventHandler(this.frmModifyStudent_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtStudentName;
        private System.Windows.Forms.TextBox txtStudentID;
        private System.Windows.Forms.NumericUpDown numericStudentAge;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox combClass;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox combDepartment;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Splitter splitter1;
        private System.Windows.Forms.Splitter splitter2;
        private System.Windows.Forms.RadioButton radioBtnMale;
        private System.Windows.Forms.RadioButton radioBtnUnkown;
        private System.Windows.Forms.RadioButton radioBtnFemale;
        private System.Windows.Forms.Splitter splitter3;
        private System.Windows.Forms.TextBox txtStudentChinese;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtStudentMath;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox txtStudentEnglish;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txtStudentComputer;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
    }
}