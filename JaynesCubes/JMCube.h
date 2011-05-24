#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace	System::IO;

#define BITMAP_DIR (System::IO::Directory::GetCurrentDirectory() + "\\..\\Bitmaps\\")


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
			Int32						face;
			Int32						edge;
			Int32						x;
			Int32						y;
			System::Drawing::Bitmap ^	bmp;
		};

public:
	CJMCube(System::String ^ dir, System::Drawing::Graphics ^ gr);
	Int32 GetAnswer() { return (m_answer); }
	static void set_foldedMode(Boolean mode) { m_foldedMode = mode; }

private:
	System::Random ^			rnd; 	
	System::String ^			m_dir;
	System::Drawing::Graphics ^	m_gr;
	cli::array<System::Drawing::Bitmap ^, 2> ^	m_seedList;
	cli::array<System::Drawing::Bitmap ^> ^		m_ringerList;
	System::Drawing::Bitmap ^	m_cubeBmp;
	SCubeRules ^				m_cubeRules;
	System::Int32				m_answer;
	static System::Boolean		m_foldedMode;

	void ConstructUnfoldedView(Int32 x, Int32 y, Int32 choice);
	void ConstructFoldedView(Int32 xPos, Int32 yPos, Int32 choice);
	void ShowUnfoldedView(System::Collections::ArrayList ^ ufCube);
	void ScrambleUnfoldedView(Int32 choice, Int32 mode);
	Boolean GetBmpFiles();
};
