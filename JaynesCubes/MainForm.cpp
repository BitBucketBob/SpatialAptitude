/* MainForm.cpp - implementation file for main display */

/* Copyright (C) 2011 SW Shackelford *

/*
modification history
--------------------
01jun05,sws	Original hack.
27may11,sws	Converted from VCPP .NET 2003 to 2008
*/

/*
DESCRIPTION:

This application challenges the user to correctly identify the correct unfolded
box from a perspective view of a folded box and vice versa.  This type of
challenge is common to spatial aptitude tests.
*/

#include "stdafx.h"
#include "MainForm.h"
#include <windows.h>

using namespace JaynesCubes;

/******************************************************************************
*
* _tWinMain - main entry for application
*
* RETURNS: Zero
*/
int APIENTRY _tWinMain
	(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow
	)
	{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
	Application::Run(gcnew MainForm());
	return 0;
	}

/******************************************************************************
*
* MainForm::SetSelectionColor -
*
* RETURNS: Selected color
*/
System::Drawing::Color MainForm::SetSelectionColor
	(
	System::Int32 choice
	)
	{
	System::Drawing::Color	retColor;

	// If the clock is not running, then no use keeping score

	if (!clockRunning)
		return (System::Drawing::SystemColors::Control);

	// Determing whether or not correct choice was made
	// Update appropriate score (only one increment per display)

	if (choice == correctChoice)
		{
		if (!choiceMade)
			correctCount++;

		retColor = System::Drawing::Color::Green;
		}
	else
		{
		if (!choiceMade)
			errorCount++;

		retColor = System::Drawing::Color::Red;
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
	Percent->Text      = System::Int32(percent).ToString();

	return (retColor);
	}

/******************************************************************************
*
* MainForm::DrawCubes -
*
* RETURNS: NA
*/
System::Void MainForm::DrawCubes()
	{
	SelectA->BackColor = System::Drawing::SystemColors::Control;
	SelectB->BackColor = System::Drawing::SystemColors::Control;
	SelectC->BackColor = System::Drawing::SystemColors::Control;
	SelectD->BackColor = System::Drawing::SystemColors::Control;
	SelectE->BackColor = System::Drawing::SystemColors::Control;

	System::Drawing::Graphics ^ gr = CreateGraphics();
	CJMCube ^ cube = gcnew CJMCube("..\\Bitmaps\\", gr);
	correctChoice = cube->GetAnswer();
	}

/******************************************************************************
*
* MainForm::Draw_Click -
*
* RETURNS: NA
*/
System::Void MainForm::Draw_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
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


/******************************************************************************
*
* MainForm::SelectA_Click -
*
* RETURNS: NA
*/
System::Void MainForm::SelectA_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	SelectA->BackColor = SetSelectionColor(0);
	}

/******************************************************************************
*
* MainForm::SelectB_Click -
*
* RETURNS: NA
*/
System::Void MainForm::SelectB_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	SelectB->BackColor = SetSelectionColor(1);
	}

/******************************************************************************
*
* MainForm::SelectC_Click -
*
* RETURNS: NA
*/
System::Void MainForm::SelectC_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	SelectC->BackColor = SetSelectionColor(2);
	}

/******************************************************************************
*
* MainForm::SelectD_Click -
*
* RETURNS: NA
*/
System::Void MainForm::SelectD_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	SelectD->BackColor = SetSelectionColor(3);
	}

/******************************************************************************
*
* MainForm::SelectE_Click -
*
* RETURNS: NA
*/
System::Void MainForm::SelectE_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	SelectE->BackColor = SetSelectionColor(4);
	}

/******************************************************************************
*
* MainForm::FileMenuExit_Click -
*
* RETURNS: NA
*/
System::Void MainForm::FileMenuExit_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	Close();
	}

/*************************************************************************
* ResetDisplay - helper function to reset display to startup condition
*
* RETURNS: NA
*/
System::Void MainForm::ResetDisplay()
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
	Invalidate();
	}

/******************************************************************************
*
* MainForm::MainForm_Load -
*
* RETURNS: NA
*/
System::Void MainForm::MainForm_Load
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	Text = "Jayne's Cubes - Unfolded";
	CJMCube::set_foldedMode(false);
	ResetDisplay();
	}

/******************************************************************************
*
* MainForm::msMainActionsMenuReset_Click -
*
* RETURNS: NA
*/
System::Void MainForm::msMainActionsMenuReset_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	ResetDisplay();
	}

/******************************************************************************
*
* MainForm::msMainActionsSetModeFolded_Click -
*
* RETURNS: NA
*/
System::Void MainForm::msMainActionsSetModeFolded_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	Text = "Jayne's Cubes - Folded";
	CJMCube::set_foldedMode(true);
	ResetDisplay();
	}

/******************************************************************************
*
* MainForm::msMainActionsSetModeUnfolded_Click -
*
* RETURNS: NA
*/
System::Void MainForm::msMainActionsSetModeUnfolded_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	Text = "Jayne's Cubes - Unfolded";
	CJMCube::set_foldedMode(false);
	ResetDisplay();
	}

/******************************************************************************
*
* MainForm::msMainHelpHelp_Click -
*
* RETURNS: NA
*/
System::Void MainForm::msMainHelpHelp_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	HelpForm ^ helpForm = gcnew HelpForm;
	helpForm->ShowDialog();
	}

/******************************************************************************
*
* MainForm::msMainHelpAbout_Click -
*
* RETURNS: NA
*/
System::Void MainForm::msMainHelpAbout_Click
	(
	System::Object ^  sender, 
	System::EventArgs ^  e
	)
	{
	System::Windows::Forms::MessageBox::Show("Jayne's Cubes 2011-05-27");
	}

/******************************************************************************
*
* MainForm::MainForm_Paint -
*
* RETURNS: NA
*/
System::Void MainForm::MainForm_Paint
	(
	System::Object ^  sender, 
	System::Windows::Forms::PaintEventArgs ^  e
	)
	{

	// The "firstPass" flag eliminates display bounce on start

	static System::Boolean firstPass(true);

	if (firstPass)
		{
		firstPass = false;
		return;
		}

	DrawCubes();
	}

/******************************************************************************
                               END OF MODULE
******************************************************************************/


