#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;

public __gc class CJMCube
{
private:
	__value enum EConstants   // Constants used to map cube faces
			{
			NO_EDGE     = -1,
			TOP_EDGE    =  0,
			RIGHT_EDGE  =  1,
			BOTTOM_EDGE =  2,
			LEFT_EDGE   =  3,
			ROT_0       =  0,
			ROT_90      =  1,
			ROT_180     =  2,
			ROT_270     =  3,
			NUM_EDGES   =  4,
			NUM_FACES   =  6,
			NUM_SEED    =  6,
			NUM_CHOICES =  5,
			NUM_MODES   =  6
			};

	__value struct SCubeRules // Structure used to describe cube construction
		{
		Int32	mate[,];
		Int32	mateEdge[,];
		Int32	rotation[,];
		Int32	faceBits[];
		Int32	edgeBits[];
		Int32	edgeBit[,];

		SCubeRules();
		};

	__gc class SAssembly      // Structure for ordered list of cube faces
		{
		public:
			int			face;
			int			edge;
			int			x;
			int			y;
			Bitmap *	bmp;
		};

public:
	CJMCube(String * dir, Graphics * gr);
	~CJMCube(void);
	void ConstructUnfoldedView(int x, int y);
	void ConstructFoldedView(int x, int y);
	void ShowUnfoldedView(ArrayList * ufCube);
	Int32 GetAnswer() { return (m_answer); }

private:
	String *	m_dir;
	Graphics *	m_gr;
	Bitmap *	m_seedList[];
	Bitmap *	m_cubeBmp;
	SCubeRules	m_cubeRules;
	Int32		m_answer;
};
