namespace StuManager
{
    partial class FrmAddStudent
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
            this.radioBtnMale = new System.Windows.Forms.RadioButton();
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
            this.label5 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.btnOK = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtStudentID = new System.Windows.Forms.TextBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.txtStudentName = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.labelDepName = new System.Windows.Forms.Label();
            this.labelClassName = new System.Windows.Forms.Label();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
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
            this.groupBox3.Location = new System.Drawing.Point(12, 171);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(387, 97);
            this.groupBox3.TabIndex = 31;
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
            this.numericStudentAge.Location = new System.Drawing.Point(86, 92);
            this.numericStudentAge.Name = "numericStudentAge";
            this.numericStudentAge.Size = new System.Drawing.Size(100, 23);
            this.numericStudentAge.TabIndex = 30;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioBtnUnkown);
            this.groupBox2.Controls.Add(this.radioBtnFemal);
            this.groupBox2.Controls.Add(this.radioBtnMale);
            this.groupBox2.Location = new System.Drawing.Point(86, 119);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(220, 34);
            this.groupBox2.TabIndex = 29;
            this.groupBox2.TabStop = false;
            // 
            // radioBtnUnkown
            // 
            this.radioBtnUnkown.AutoSize = true;
            this.radioBtnUnkown.ForeColor = System.Drawing.Color.Black;
            this.radioBtnUnkown.Location = new System.Drawing.Point(141, 11);
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
            this.radioBtnFemal.Location = new System.Drawing.Point(73, 11);
            this.radioBtnFemal.Name = "radioBtnFemal";
            this.radioBtnFemal.Size = new System.Drawing.Size(39, 18);
            this.radioBtnFemal.TabIndex = 1;
            this.radioBtnFemal.TabStop = true;
            this.radioBtnFemal.Text = "女";
            this.radioBtnFemal.UseVisualStyleBackColor = true;
            this.radioBtnFemal.Click += new System.EventHandler(this.radioBtnFemal_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label5.Location = new System.Drawing.Point(48, 28);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(35, 14);
            this.label5.TabIndex = 20;
            this.label5.Text = "系：";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.ForeColor = System.Drawing.Color.Black;
            this.label8.Location = new System.Drawing.Point(36, 132);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(49, 14);
            this.label8.TabIndex = 28;
            this.label8.Text = "性别：";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.ForeColor = System.Drawing.Color.Black;
            this.label9.Location = new System.Drawing.Point(34, 94);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(49, 14);
            this.label9.TabIndex = 27;
            this.label9.Text = "年龄：";
            // 
            // btnOK
            // 
            this.btnOK.Location = new System.Drawing.Point(79, 302);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(75, 23);
            this.btnOK.TabIndex = 17;
            this.btnOK.Text = "保存";
            this.btnOK.UseVisualStyleBackColor = true;
            this.btnOK.Click += new System.EventHandler(this.btnOK_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.SystemColors.Desktop;
            this.label4.Location = new System.Drawing.Point(214, 28);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 14);
            this.label4.TabIndex = 21;
            this.label4.Text = "班级：";
            // 
            // txtStudentID
            // 
            this.txtStudentID.Location = new System.Drawing.Point(261, 61);
            this.txtStudentID.Name = "txtStudentID";
            this.txtStudentID.Size = new System.Drawing.Size(100, 23);
            this.txtStudentID.TabIndex = 26;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(203, 303);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 19;
            this.btnCancel.Text = "取消";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ForeColor = System.Drawing.Color.Black;
            this.label7.Location = new System.Drawing.Point(225, 65);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(35, 14);
            this.label7.TabIndex = 25;
            this.label7.Text = "ID：";
            // 
            // txtStudentName
            // 
            this.txtStudentName.Location = new System.Drawing.Point(86, 61);
            this.txtStudentName.Name = "txtStudentName";
            this.txtStudentName.Size = new System.Drawing.Size(100, 23);
            this.txtStudentName.TabIndex = 24;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.Color.Black;
            this.label6.Location = new System.Drawing.Point(34, 65);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(49, 14);
            this.label6.TabIndex = 18;
            this.label6.Text = "姓名：";
            // 
            // labelDepName
            // 
            this.labelDepName.AutoSize = true;
            this.labelDepName.ForeColor = System.Drawing.SystemColors.ControlText;
            this.labelDepName.Location = new System.Drawing.Point(89, 28);
            this.labelDepName.Name = "labelDepName";
            this.labelDepName.Size = new System.Drawing.Size(35, 14);
            this.labelDepName.TabIndex = 32;
            this.labelDepName.Text = "系：";
            // 
            // labelClassName
            // 
            this.labelClassName.AutoSize = true;
            this.labelClassName.ForeColor = System.Drawing.SystemColors.ControlText;
            this.labelClassName.Location = new System.Drawing.Point(258, 28);
            this.labelClassName.Name = "labelClassName";
            this.labelClassName.Size = new System.Drawing.Size(35, 14);
            this.labelClassName.TabIndex = 33;
            this.labelClassName.Text = "系：";
            // 
            // FrmAddStudent
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 14F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(393, 337);
            this.Controls.Add(this.labelClassName);
            this.Controls.Add(this.labelDepName);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.numericStudentAge);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtStudentID);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.txtStudentName);
            this.Controls.Add(this.label6);
            this.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Name = "FrmAddStudent";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "增加（系、班级、学生）";
            this.Load += new System.EventHandler(this.FrmAdd_Load);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericStudentAge)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RadioButton radioBtnMale;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox txtComputer;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.TextBox txtMath;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox txtEnglish;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox txtChinese;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.NumericUpDown numericStudentAge;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton radioBtnUnkown;
        private System.Windows.Forms.RadioButton radioBtnFemal;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtStudentID;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox txtStudentName;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label labelDepName;
        private System.Windows.Forms.Label labelClassName;


    }
}