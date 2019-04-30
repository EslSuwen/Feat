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
    public partial class frmAddMenu : Form
    {
        public string strName = "";

        public frmAddMenu()
        {
            InitializeComponent();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            string str=txtInput.Text.Trim();
            if (str == "")
            {
                MessageBox.Show("输入为空，请输入", "错误");
                return;
            }
            else
            {
                strName = str;
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }
    }
}
