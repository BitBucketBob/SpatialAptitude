#pragma once

#include "JMCube.h"
#include "HelpForm.h"

using namespace System::Text;

namespace JaynesCubes
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Summary for MainForm
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{	
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
  
	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button ^  Draw;
	private: System::Windows::Forms::Button ^  SelectA;
	private: System::Windows::Forms::Button ^  SelectB;
	private: System::Windows::Forms::Button ^  SelectC;
	private: System::Windows::Forms::Button ^  SelectD;
	private: System::Windows::Forms::Button ^  SelectE;
	private: System::Windows::Forms::MainMenu^  msMain;
	private: System::Windows::Forms::MenuItem^  msMainFile;
	private: System::Windows::Forms::MenuItem^  msMainFileExit;






	private: System::Windows::Forms::TextBox ^  TotalCount;
	private: System::Windows::Forms::TextBox ^  CorrectCount;
	private: System::Windows::Forms::TextBox ^  ErrorCount;
	private: System::Windows::Forms::Label ^  label2;
	private: System::Windows::Forms::Label ^  label3;
	private: System::Windows::Forms::Label ^  label4;
	private: System::Windows::Forms::Label ^  label5;
	private: System::Windows::Forms::Label ^  label6;
	private: System::Windows::Forms::Label ^  label7;
	private: System::Windows::Forms::Label ^  label8;
	private: System::Windows::Forms::TextBox ^  ElapsedTime;
	private: System::Windows::Forms::TextBox ^  AverageTime;
	private: System::Windows::Forms::MenuItem^  msMainActions;
	private: System::Windows::Forms::MenuItem^  msMainActionsReset;


	private: System::Windows::Forms::TextBox ^  Percent;
	private: System::Windows::Forms::Label ^  label9;
	private: System::Windows::Forms::MenuItem^  msMainActionsSetMode;
	private: System::Windows::Forms::MenuItem^  msMainActionsSetModeFolded;



	private: System::Windows::Forms::MenuItem^  msMainActionsSetModeUnfolded;

	private: System::Windows::Forms::MenuItem^  msMainHelp;
	private: System::Windows::Forms::MenuItem^  msMainHelpHelp;
	private: System::Windows::Forms::MenuItem^  msMainHelpAbout;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Draw = (gcnew System::Windows::Forms::Button());
			this->SelectA = (gcnew System::Windows::Forms::Button());
			this->SelectB = (gcnew System::Windows::Forms::Button());
			this->SelectC = (gcnew System::Windows::Forms::Button());
			this->SelectD = (gcnew System::Windows::Forms::Button());
			this->SelectE = (gcnew System::Windows::Forms::Button());
			this->msMain = (gcnew System::Windows::Forms::MainMenu(this->components));
			this->msMainFile = (gcnew System::Windows::Forms::MenuItem());
			this->msMainFileExit = (gcnew System::Windows::Forms::MenuItem());
			this->msMainActions = (gcnew System::Windows::Forms::MenuItem());
			this->msMainActionsReset = (gcnew System::Windows::Forms::MenuItem());
			this->msMainActionsSetMode = (gcnew System::Windows::Forms::MenuItem());
			this->msMainActionsSetModeFolded = (gcnew System::Windows::Forms::MenuItem());
			this->msMainActionsSetModeUnfolded = (gcnew System::Windows::Forms::MenuItem());
			this->msMainHelp = (gcnew System::Windows::Forms::MenuItem());
			this->msMainHelpHelp = (gcnew System::Windows::Forms::MenuItem());
			this->msMainHelpAbout = (gcnew System::Windows::Forms::MenuItem());
			this->TotalCount = (gcnew System::Windows::Forms::TextBox());
			this->CorrectCount = (gcnew System::Windows::Forms::TextBox());
			this->ErrorCount = (gcnew System::Windows::Forms::TextBox());
			this->ElapsedTime = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->AverageTime = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Percent = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Draw
			// 
			this->Draw->Location = System::Drawing::Point(736, 525);
			this->Draw->Name = L"Draw";
			this->Draw->Size = System::Drawing::Size(40, 23);
			this->Draw->TabIndex = 0;
			this->Draw->Text = L"Start";
			this->Draw->Click += gcnew System::EventHandler(this, &MainForm::Draw_Click);
			// 
			// SelectA
			// 
			this->SelectA->Location = System::Drawing::Point(265, 235);
			this->SelectA->Name = L"SelectA";
			this->SelectA->Size = System::Drawing::Size(24, 23);
			this->SelectA->TabIndex = 1;
			this->SelectA->Text = L"A";
			this->SelectA->Visible = false;
			this->SelectA->Click += gcnew System::EventHandler(this, &MainForm::SelectA_Click);
			// 
			// SelectB
			// 
			this->SelectB->Location = System::Drawing::Point(525, 235);
			this->SelectB->Name = L"SelectB";
			this->SelectB->Size = System::Drawing::Size(24, 23);
			this->SelectB->TabIndex = 1;
			this->SelectB->Text = L"B";
			this->SelectB->Visible = false;
			this->SelectB->Click += gcnew System::EventHandler(this, &MainForm::SelectB_Click);
			// 
			// SelectC
			// 
			this->SelectC->Location = System::Drawing::Point(5, 495);
			this->SelectC->Name = L"SelectC";
			this->SelectC->Size = System::Drawing::Size(24, 23);
			this->SelectC->TabIndex = 1;
			this->SelectC->Text = L"C";
			this->SelectC->Visible = false;
			this->SelectC->Click += gcnew System::EventHandler(this, &MainForm::SelectC_Click);
			// 
			// SelectD
			// 
			this->SelectD->Location = System::Drawing::Point(265, 495);
			this->SelectD->Name = L"SelectD";
			this->SelectD->Size = System::Drawing::Size(24, 23);
			this->SelectD->TabIndex = 1;
			this->SelectD->Text = L"D";
			this->SelectD->Visible = false;
			this->SelectD->Click += gcnew System::EventHandler(this, &MainForm::SelectD_Click);
			// 
			// SelectE
			// 
			this->SelectE->Location = System::Drawing::Point(525, 495);
			this->SelectE->Name = L"SelectE";
			this->SelectE->Size = System::Drawing::Size(24, 23);
			this->SelectE->TabIndex = 1;
			this->SelectE->Text = L"E";
			this->SelectE->Visible = false;
			this->SelectE->Click += gcnew System::EventHandler(this, &MainForm::SelectE_Click);
			// 
			// msMain
			// 
			this->msMain->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(3) {this->msMainFile, this->msMainActions, 
				this->msMainHelp});
			// 
			// msMainFile
			// 
			this->msMainFile->Index = 0;
			this->msMainFile->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(1) {this->msMainFileExit});
			this->msMainFile->Text = L"File";
			// 
			// msMainFileExit
			// 
			this->msMainFileExit->Index = 0;
			this->msMainFileExit->Text = L"Exit";
			this->msMainFileExit->Click += gcnew System::EventHandler(this, &MainForm::FileMenuExit_Click);
			// 
			// msMainActions
			// 
			this->msMainActions->Index = 1;
			this->msMainActions->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(2) {this->msMainActionsReset, 
				this->msMainActionsSetMode});
			this->msMainActions->Text = L"Actions";
			// 
			// msMainActionsReset
			// 
			this->msMainActionsReset->Index = 0;
			this->msMainActionsReset->Text = L"Reset";
			this->msMainActionsReset->Click += gcnew System::EventHandler(this, &MainForm::msMainActionsMenuReset_Click);
			// 
			// msMainActionsSetMode
			// 
			this->msMainActionsSetMode->Index = 1;
			this->msMainActionsSetMode->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(2) {this->msMainActionsSetModeFolded, 
				this->msMainActionsSetModeUnfolded});
			this->msMainActionsSetMode->Text = L"Set Mode";
			// 
			// msMainActionsSetModeFolded
			// 
			this->msMainActionsSetModeFolded->Index = 0;
			this->msMainActionsSetModeFolded->Text = L"Folded";
			this->msMainActionsSetModeFolded->Click += gcnew System::EventHandler(this, &MainForm::msMainActionsSetModeFolded_Click);
			// 
			// msMainActionsSetModeUnfolded
			// 
			this->msMainActionsSetModeUnfolded->Index = 1;
			this->msMainActionsSetModeUnfolded->Text = L"Unfolded";
			this->msMainActionsSetModeUnfolded->Click += gcnew System::EventHandler(this, &MainForm::msMainActionsSetModeUnfolded_Click);
			// 
			// msMainHelp
			// 
			this->msMainHelp->Index = 2;
			this->msMainHelp->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(2) {this->msMainHelpHelp, this->msMainHelpAbout});
			this->msMainHelp->Text = L"Help";
			// 
			// msMainHelpHelp
			// 
			this->msMainHelpHelp->Index = 0;
			this->msMainHelpHelp->Text = L"Help";
			this->msMainHelpHelp->Click += gcnew System::EventHandler(this, &MainForm::msMainHelpHelp_Click);
			// 
			// msMainHelpAbout
			// 
			this->msMainHelpAbout->Index = 1;
			this->msMainHelpAbout->Text = L"About";
			this->msMainHelpAbout->Click += gcnew System::EventHandler(this, &MainForm::msMainHelpAbout_Click);
			// 
			// TotalCount
			// 
			this->TotalCount->Location = System::Drawing::Point(32, 525);
			this->TotalCount->Name = L"TotalCount";
			this->TotalCount->Size = System::Drawing::Size(48, 20);
			this->TotalCount->TabIndex = 2;
			// 
			// CorrectCount
			// 
			this->CorrectCount->Location = System::Drawing::Point(128, 525);
			this->CorrectCount->Name = L"CorrectCount";
			this->CorrectCount->Size = System::Drawing::Size(48, 20);
			this->CorrectCount->TabIndex = 2;
			// 
			// ErrorCount
			// 
			this->ErrorCount->Location = System::Drawing::Point(232, 525);
			this->ErrorCount->Name = L"ErrorCount";
			this->ErrorCount->Size = System::Drawing::Size(48, 20);
			this->ErrorCount->TabIndex = 2;
			// 
			// ElapsedTime
			// 
			this->ElapsedTime->Location = System::Drawing::Point(496, 525);
			this->ElapsedTime->Name = L"ElapsedTime";
			this->ElapsedTime->Size = System::Drawing::Size(72, 20);
			this->ElapsedTime->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(96, 527);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Right";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(192, 527);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Wrong";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(416, 527);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Elapsed Time";
			// 
			// AverageTime
			// 
			this->AverageTime->Location = System::Drawing::Point(656, 525);
			this->AverageTime->Name = L"AverageTime";
			this->AverageTime->Size = System::Drawing::Size(72, 20);
			this->AverageTime->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(576, 527);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(80, 16);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Average Time";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(128, 527);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 16);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Right";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(0, 527);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 16);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Total";
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(240, 527);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(40, 16);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Wrong";
			// 
			// Percent
			// 
			this->Percent->Location = System::Drawing::Point(344, 525);
			this->Percent->Name = L"Percent";
			this->Percent->Size = System::Drawing::Size(48, 20);
			this->Percent->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(296, 528);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 16);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Percent";
			// 
			// MainForm
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(780, 550);
			this->ControlBox = false;
			this->Controls->Add(this->TotalCount);
			this->Controls->Add(this->SelectA);
			this->Controls->Add(this->Draw);
			this->Controls->Add(this->SelectB);
			this->Controls->Add(this->SelectC);
			this->Controls->Add(this->SelectD);
			this->Controls->Add(this->SelectE);
			this->Controls->Add(this->CorrectCount);
			this->Controls->Add(this->ErrorCount);
			this->Controls->Add(this->ElapsedTime);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->AverageTime);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->Percent);
			this->Controls->Add(this->label9);
			this->Menu = this->msMain;
			this->Name = L"MainForm";
			this->Text = L"Jayne\'s Cubes";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private:
		Int32		correctChoice;
		bool		choiceMade;
		bool		clockRunning;
		Int32		totalCount;
		Int32		correctCount;
		Int32		errorCount;
		DateTime	start;

	private:
		System::Drawing::Color SetSelectionColor(Int32 choice)
			{
			Drawing::Color	retColor;

			// If the clock is not running, then no use keeping score

			if (!clockRunning)
				return (System::Drawing::SystemColors::Control);

			// Determing whether or not correct choice was made
			// Update appropriate score (only one increment per display)

			if (choice == correctChoice)
				{
				if (!choiceMade)
					correctCount++;

				retColor = Color::Green;
				}
			else
				{
				if (!choiceMade)
					errorCount++;

				retColor = Color::Red;
				}

			// If first choice for display, increment total count

			if (!choiceMade)
				{
				totalCount++;
				choiceMade = true;
				}

			// Update statistics

			System::DateTime stop = DateTime::Now;
			System::TimeSpan span = stop - start;
			
			System::Text::StringBuilder ^ sb = gcnew System::Text::StringBuilder("");
			sb->AppendFormat("{0}:{1}:{2}", 
				span.Hours, 
				span.Minutes, 
				span.Seconds);

			ElapsedTime->Text  = sb->ToString();
			AverageTime->Text  = (span.TotalSeconds / totalCount).ToString("00.00");
			TotalCount->Text   = totalCount.ToString();
			CorrectCount->Text = correctCount.ToString();
			ErrorCount->Text   = errorCount.ToString();

			Double percent = 100 * correctCount;
			percent /= totalCount;
			Percent->Text      = static_cast<Int32>(percent).ToString();
		
			return (retColor);
			}

	private: System::Void DrawCubes()
		{
		SelectA->BackColor = System::Drawing::SystemColors::Control;
		SelectB->BackColor = System::Drawing::SystemColors::Control;
		SelectC->BackColor = System::Drawing::SystemColors::Control;
		SelectD->BackColor = System::Drawing::SystemColors::Control;
		SelectE->BackColor = System::Drawing::SystemColors::Control;

		Drawing::Graphics ^ gr = CreateGraphics();
		CJMCube ^ cube = gcnew CJMCube(BITMAP_DIR, gr);
		correctChoice = cube->GetAnswer();
		}

	private: System::Void Draw_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		// Reset button labels and colors

		Draw->Text = "Next";
		SelectA->Visible = true;
		SelectB->Visible = true;
		SelectC->Visible = true;
		SelectD->Visible = true;
		SelectE->Visible = true;

		choiceMade = false;
		
		if (!clockRunning)
			{
			start = DateTime::Now;
			clockRunning = true;
			}

		DrawCubes();
		}

	private: System::Void SelectA_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		SelectA->BackColor = SetSelectionColor(0);
		}

	private: System::Void SelectB_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		SelectB->BackColor = SetSelectionColor(1);
		}

	private: System::Void SelectC_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		SelectC->BackColor = SetSelectionColor(2);
		}

	private: System::Void SelectD_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		SelectD->BackColor = SetSelectionColor(3);
		}

	private: System::Void SelectE_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		SelectE->BackColor = SetSelectionColor(4);
		}

	private: System::Void FileMenuExit_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		Close();
		}

	/*************************************************************************
	* ResetDisplay - helper function to reset display to startup condition
	*/
	private: System::Void ResetDisplay()
		{
		totalCount = 0;
		errorCount = 0;
		correctCount = 0;

		TotalCount->Text   = totalCount.ToString();
		CorrectCount->Text = correctCount.ToString();
		ErrorCount->Text   = errorCount.ToString();
		ElapsedTime->Text  = "";
		AverageTime->Text  = "";
		Percent->Text      = "";

		Draw->Text = "Start";
		SelectA->BackColor = System::Drawing::SystemColors::Control;
		SelectB->BackColor = System::Drawing::SystemColors::Control;
		SelectC->BackColor = System::Drawing::SystemColors::Control;
		SelectD->BackColor = System::Drawing::SystemColors::Control;
		SelectE->BackColor = System::Drawing::SystemColors::Control;

		SelectA->Visible = false;
		SelectB->Visible = false;
		SelectC->Visible = false;
		SelectD->Visible = false;
		SelectE->Visible = false;

		choiceMade = false;
		clockRunning = false;
		this->Invalidate();
		}

	private: System::Void MainForm_Load(System::Object ^  sender, System::EventArgs ^  e)
		{
		this->Text = "Jayne's Cubes - Unfolded";
		CJMCube::set_foldedMode(false);
		ResetDisplay();
		}

	private: System::Void msMainActionsMenuReset_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		ResetDisplay();
		}

	private: System::Void msMainActionsSetModeFolded_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		this->Text = "Jayne's Cubes - Folded";
		CJMCube::set_foldedMode(true);
		ResetDisplay();
		}

	private: System::Void msMainActionsSetModeUnfolded_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		this->Text = "Jayne's Cubes - Unfolded";
		CJMCube::set_foldedMode(false);
		ResetDisplay();
		}

	private: System::Void msMainHelpHelp_Click(System::Object ^  sender, System::EventArgs ^  e)
		{
		HelpForm ^ helpForm = gcnew HelpForm;
		helpForm->ShowDialog();
		}

	private: System::Void msMainHelpAbout_Click(System::Object^  sender, System::EventArgs^  e)
		{
		System::Windows::Forms::MessageBox::Show("Jayne's Cubes 2011-05-22");
		}

	private: System::Void MainForm_Paint(System::Object ^  sender, System::Windows::Forms::PaintEventArgs ^  e)
		{
		DrawCubes();
		}
};
}


