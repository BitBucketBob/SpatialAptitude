/* JMCube.h - header file for cube face manager */

/* Copyright (C) 2011 SW Shackelford */

/*
modification history
--------------------
01jun05,sws	Original hack.
27may11,sws	Converted from VCPP .NET 2003 to 2008
*/

/*
DESCRIPTION:

This module manages the display and construction of cube faces used to
challenge the user.
*/

#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace	System::IO;

public ref class CJMCube
{
private:
	
	static const System::Int32 NO_EDGE     =  -1;
	static const System::Int32 TOP_EDGE    =   0;
	static const System::Int32 RIGHT_EDGE  =   1;
	static const System::Int32 BOTTOM_EDGE =   2;
	static const System::Int32 LEFT_EDGE   =   3;
	static const System::Int32 ROT_0       =   0;
	static const System::Int32 ROT_90      =   1;
	static const System::Int32 ROT_180     =   2;
	static const System::Int32 ROT_270     =   3;
	static const System::Int32 NUM_EDGES   =   4;
	static const System::Int32 NUM_FACES   =   6;
	static const System::Int32 NUM_SEED    =   6;
	static const System::Int32 NUM_CHOICES =   5;
	static const System::Int32 NUM_MODES   =  24;
	static const System::Int32 W_MAX       = 260;
	static const System::Int32 H_MAX       = 260;
	static const System::Int32 F_LENGTH    = 1000;

	ref struct SCubeRules // Structure used to describe cube construction
		{
		cli::array<System::Int32, 2> ^	mate;
		cli::array<System::Int32, 2> ^	mateEdge;
		cli::array<System::Int32, 2> ^	rotation;
		cli::array<System::Int32> ^		faceBits;
		cli::array<System::Int32> ^		edgeBits;
		cli::array<System::Int32, 2> ^	edgeBit;

		SCubeRules();
		};

	ref class SAssembly      // Structure for ordered list of cube faces
		{
		public:
			System::Int32				face;
			System::Int32				edge;
			System::Int32				x;
			System::Int32				y;
			System::Drawing::Bitmap ^	bmp;
		};

public:
	CJMCube(System::String ^ dir, System::Drawing::Graphics ^ gr);
	Int32 GetAnswer() { return (m_answer); }
	static void set_foldedMode(System::Boolean mode) { m_foldedMode = mode; }

private:
	System::Random ^			rnd; 	
	System::String ^			m_bitmapDir;
	System::Drawing::Graphics ^	m_gr;
	cli::array<System::Drawing::Bitmap ^, 2> ^	m_seedList;
	cli::array<System::Drawing::Bitmap ^> ^		m_ringerList;
	System::Drawing::Bitmap ^	m_cubeBmp;
	SCubeRules ^				m_cubeRules;
	System::Int32				m_answer;
	static System::Boolean		m_foldedMode;

	void ConstructUnfoldedView(System::Int32 x, System::Int32 y, System::Int32 choice);
	void ConstructFoldedView(System::Int32 xPos, System::Int32 yPos, System::Int32 choice);
	void ShowUnfoldedView(System::Collections::ArrayList ^ ufCube);
	void ScrambleUnfoldedView(System::Int32 choice, System::Int32 mode);
	System::Boolean GetBmpFiles();
};

/******************************************************************************
                               END OF MODULE
******************************************************************************/