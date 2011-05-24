#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace JaynesCubes
{
	/// <summary> 
	/// Summary for HelpForm
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public: 
		HelpForm(void)
		{
			InitializeComponent();
			tbHelp->Select(0, 0);
		}
        
	protected: 
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox ^  tbHelp;
	private: System::Windows::Forms::Button ^  pbOK;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^ components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbHelp = gcnew System::Windows::Forms::TextBox();
			this->pbOK = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// tbHelp
			// 
			this->tbHelp->Location = System::Drawing::Point(16, 16);
			this->tbHelp->Multiline = true;
			this->tbHelp->ReadOnly  = true;
			this->tbHelp->Name = "tbHelp";
			this->tbHelp->Size = System::Drawing::Size(384, 40);
			this->tbHelp->TabIndex = 0;
			this->tbHelp->Text = "The goal is to get 100% of the challenges correct with an average time of less th" 
				"an 30 seconds.  Obviously better times with 100% accuracy are even better.";
			// 
			// pbOK
			// 
			this->pbOK->Location = System::Drawing::Point(320, 72);
			this->pbOK->Name = "pbOK";
			this->pbOK->TabIndex = 1;
			this->pbOK->Text = "OK";
			this->pbOK->Click += gcnew System::EventHandler(this, &HelpForm::pbOK_Click);
			// 
			// HelpForm
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(416, 106);
			this->ControlBox = false;
			this->Controls->Add(this->pbOK);
			this->Controls->Add(this->tbHelp);
			this->Name = "HelpForm";
			this->Text = "HelpForm";
			this->ResumeLayout(false);

		}		
	private: System::Void pbOK_Click(System::Object ^sender, System::EventArgs ^ e)
			 {
			 Close();
			 }

	};
}