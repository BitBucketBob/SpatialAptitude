/* JMCube.cpp - implementation file for cube face manager */

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

#include "StdAfx.h"
#include "JMCube.h"

/*****************************************************************************
*
* SCubeRules::SCubeRules - constructor
*
* This constructor initializes all of the rules that govern the assembly of
* each of the six faces of a cube into a flattened out unfolded construction.
*
* RETURNS: NA
*/
CJMCube::SCubeRules::SCubeRules()
	{

	// Allocate arrays

	mate     = gcnew cli::array<System::Int32, 2>(NUM_FACES, NUM_EDGES); // Mating face
	mateEdge = gcnew cli::array<System::Int32, 2>(NUM_FACES, NUM_EDGES); // Face edge that will align with mate
	rotation = gcnew cli::array<System::Int32, 2>(NUM_FACES, NUM_EDGES); // Required rotation with mate at zero
	faceBits = gcnew cli::array<System::Int32>(NUM_FACES);
	edgeBits = gcnew cli::array<System::Int32>(NUM_FACES);
	edgeBit  = gcnew cli::array<System::Int32, 2>(NUM_FACES, NUM_EDGES);

	// Mating face by bonded edge

	mate[0, TOP_EDGE   ] = 3;     // Top    edge matches face 3
	mate[0, RIGHT_EDGE ] = 2;     // Right  edge matches face 2
	mate[0, BOTTOM_EDGE] = 1;     // Bottom edge matches face 1
	mate[0, LEFT_EDGE  ] = 4;     // Left   edge matches face 4

	mate[1, TOP_EDGE   ] = 0;     // Top    edge matches face 0
	mate[1, RIGHT_EDGE ] = 2;     // Right  edge matches face 2
	mate[1, BOTTOM_EDGE] = 5;     // Bottom edge matches face 5
	mate[1, LEFT_EDGE  ] = 4;     // Left   edge matches face 4

	mate[2, TOP_EDGE   ] = 0;     // Top    edge matches face 0
	mate[2, RIGHT_EDGE ] = 3;     // Right  edge matches face 3
	mate[2, BOTTOM_EDGE] = 5;     // Bottom edge matches face 5
	mate[2, LEFT_EDGE  ] = 1;     // Left   edge matches face 1

	mate[3, TOP_EDGE   ] = 0;     // Top    edge matches face 0
	mate[3, RIGHT_EDGE ] = 4;     // Right  edge matches face 4
	mate[3, BOTTOM_EDGE] = 5;     // Bottom edge matches face 5
	mate[3, LEFT_EDGE  ] = 2;     // Left   edge matches face 2

	mate[4, TOP_EDGE   ] = 0;     // Top    edge matches face 0
	mate[4, RIGHT_EDGE ] = 1;     // Right  edge matches face 1
	mate[4, BOTTOM_EDGE] = 5;     // Bottom edge matches face 5
	mate[4, LEFT_EDGE  ] = 3;     // Left   edge matches face 3

	mate[5, TOP_EDGE   ] = 4;     // Top    edge matches face 4
	mate[5, RIGHT_EDGE ] = 1;     // Right  edge matches face 1
	mate[5, BOTTOM_EDGE] = 2;     // Bottom edge matches face 2
	mate[5, LEFT_EDGE  ] = 3;     // Left   edge matches face 3

	// Mating edge of mating face by bonded edge

	mateEdge[0, TOP_EDGE   ] = TOP_EDGE;
	mateEdge[0, RIGHT_EDGE ] = TOP_EDGE;
	mateEdge[0, BOTTOM_EDGE] = TOP_EDGE;
	mateEdge[0, LEFT_EDGE  ] = TOP_EDGE;

	mateEdge[1, TOP_EDGE   ] = BOTTOM_EDGE;
	mateEdge[1, RIGHT_EDGE ] = LEFT_EDGE;
	mateEdge[1, BOTTOM_EDGE] = RIGHT_EDGE;
	mateEdge[1, LEFT_EDGE  ] = RIGHT_EDGE;

	mateEdge[2, TOP_EDGE   ] = RIGHT_EDGE;
	mateEdge[2, RIGHT_EDGE ] = LEFT_EDGE;
	mateEdge[2, BOTTOM_EDGE] = BOTTOM_EDGE;
	mateEdge[2, LEFT_EDGE  ] = RIGHT_EDGE;

	mateEdge[3, TOP_EDGE   ] = TOP_EDGE;
	mateEdge[3, RIGHT_EDGE ] = LEFT_EDGE;
	mateEdge[3, BOTTOM_EDGE] = LEFT_EDGE;
	mateEdge[3, LEFT_EDGE  ] = RIGHT_EDGE;

	mateEdge[4, TOP_EDGE   ] = LEFT_EDGE;
	mateEdge[4, RIGHT_EDGE ] = LEFT_EDGE;
	mateEdge[4, BOTTOM_EDGE] = TOP_EDGE;
	mateEdge[4, LEFT_EDGE  ] = RIGHT_EDGE;

	mateEdge[5, TOP_EDGE   ] = BOTTOM_EDGE;
	mateEdge[5, RIGHT_EDGE ] = BOTTOM_EDGE;
	mateEdge[5, BOTTOM_EDGE] = BOTTOM_EDGE;
	mateEdge[5, LEFT_EDGE  ] = BOTTOM_EDGE;

	// Rotation required by mated edge -- assume mate at zero rotation

	rotation[0, TOP_EDGE   ] = ROT_180;
	rotation[0, RIGHT_EDGE ] = ROT_90;
	rotation[0, BOTTOM_EDGE] = ROT_0;
	rotation[0, LEFT_EDGE  ] = ROT_270;

	rotation[1, TOP_EDGE   ] = ROT_0;
	rotation[1, RIGHT_EDGE ] = ROT_0;
	rotation[1, BOTTOM_EDGE] = ROT_90;
	rotation[1, LEFT_EDGE  ] = ROT_0;

	rotation[2, TOP_EDGE   ] = ROT_270;
	rotation[2, RIGHT_EDGE ] = ROT_0;
	rotation[2, BOTTOM_EDGE] = ROT_180;
	rotation[2, LEFT_EDGE  ] = ROT_0;

	rotation[3, TOP_EDGE   ] = ROT_180;
	rotation[3, RIGHT_EDGE ] = ROT_0;
	rotation[3, BOTTOM_EDGE] = ROT_270;
	rotation[3, LEFT_EDGE  ] = ROT_0;

	rotation[4, TOP_EDGE   ] = ROT_90;
	rotation[4, RIGHT_EDGE ] = ROT_0;
	rotation[4, BOTTOM_EDGE] = ROT_0;
	rotation[4, LEFT_EDGE  ] = ROT_0;

	rotation[5, TOP_EDGE   ] = ROT_0;
	rotation[5, RIGHT_EDGE ] = ROT_270;
	rotation[5, BOTTOM_EDGE] = ROT_180;
	rotation[5, LEFT_EDGE  ] = ROT_90;

	// Bit sets for adjacent faces

	faceBits[0] = 0x001E;
	faceBits[1] = 0x0035;
	faceBits[2] = 0x002B;
	faceBits[3] = 0x0035;
	faceBits[4] = 0x002B;
	faceBits[5] = 0x001E;

	// All bits for all edges of each face

	edgeBits[0] = 0x000F;
	edgeBits[1] = 0x0074;
	edgeBits[2] = 0x0192;
	edgeBits[3] = 0x0681;
	edgeBits[4] = 0x0A48;
	edgeBits[5] = 0x0D20;

	// Bit assignment to each edge of each face

	edgeBit[0, TOP_EDGE   ]  = 0x0001;
	edgeBit[0, RIGHT_EDGE ]  = 0x0002;
	edgeBit[0, BOTTOM_EDGE]  = 0x0004;
	edgeBit[0, LEFT_EDGE  ]  = 0x0008;

	edgeBit[1, TOP_EDGE   ]  = 0x0004;
	edgeBit[1, RIGHT_EDGE ]  = 0x0010;
	edgeBit[1, BOTTOM_EDGE]  = 0x0020;
	edgeBit[1, LEFT_EDGE  ]  = 0x0040;

	edgeBit[2, TOP_EDGE   ]  = 0x0002;
	edgeBit[2, RIGHT_EDGE ]  = 0x0080;
	edgeBit[2, BOTTOM_EDGE]  = 0x0100;
	edgeBit[2, LEFT_EDGE  ]  = 0x0010;

	edgeBit[3, TOP_EDGE   ]  = 0x0001;
	edgeBit[3, RIGHT_EDGE ]  = 0x0200;
	edgeBit[3, BOTTOM_EDGE]  = 0x0400;
	edgeBit[3, LEFT_EDGE  ]  = 0x0080;

	edgeBit[4, TOP_EDGE   ]  = 0x0008;
	edgeBit[4, RIGHT_EDGE ]  = 0x0040;
	edgeBit[4, BOTTOM_EDGE]  = 0x0800;
	edgeBit[4, LEFT_EDGE  ]  = 0x0200;

	edgeBit[5, TOP_EDGE   ]  = 0x0800;
	edgeBit[5, RIGHT_EDGE ]  = 0x0020;
	edgeBit[5, BOTTOM_EDGE]  = 0x0100;
	edgeBit[5, LEFT_EDGE  ]  = 0x0400;
	}

/*****************************************************************************
*
* CJMCube::CJMCube - constructs the views
*
* RETURNS: NA
*/
CJMCube::CJMCube
	(
	System::String ^ dir, 
	System::Drawing::Graphics ^ gr) : m_bitmapDir(dir), m_gr(gr)
	{
	rnd          = gcnew System::Random();     // Random number generator
	m_seedList   = gcnew cli::array<System::Drawing::Bitmap ^, 2>(NUM_CHOICES, NUM_FACES);
	m_ringerList = gcnew cli::array<System::Drawing::Bitmap ^>(2);
	m_cubeRules  = gcnew SCubeRules;

	if (!GetBmpFiles())
		return;

	System::Int32	i;
	System::Int32	j;
	System::Int32	flawMode;
	System::Int32	rotation;

	// Randomly reorient the faces of the seed input faces

	for (i = 0; i < NUM_SEED; i++)
		{
		rotation = (System::Int32(96 * rnd->NextDouble())) % NUM_EDGES;

		switch (rotation)
			{
			case ROT_90:
				m_seedList[0, i]->RotateFlip(RotateFlipType::Rotate90FlipNone);
				break;

			case ROT_180:
				m_seedList[0, i]->RotateFlip(RotateFlipType::Rotate180FlipNone);
				break;

			case ROT_270:
				m_seedList[0, i]->RotateFlip(RotateFlipType::Rotate270FlipNone);
				break;

			case ROT_0:
			default:
				break;
			}

		for (j = 1; j < NUM_CHOICES; j++)
			m_seedList[j, i] = m_seedList[0, i]->Clone
				(
				System::Drawing::RectangleF
					(
					0, 0, 
					System::Single(m_seedList[0, i]->Width), 
					System::Single(m_seedList[0, i]->Height)
					),

				System::Drawing::Imaging::PixelFormat::DontCare
				);
		}
	
	// Randomly select one of the set of cube faces to be the answer

	m_answer = (System::Int32(100 * rnd->NextDouble())) % NUM_CHOICES;

	// Scramble all of the cube face sets except for the one selected as
	// the answer

	for (i = 0; i < NUM_CHOICES; i++)
		{
		if (i == m_answer)
			continue;

		flawMode = (System::Int32(96 * rnd->NextDouble())) % NUM_MODES;
		ScrambleUnfoldedView(i, flawMode);
		}

	// Draw the reference view and the possible choices

	if (!m_foldedMode)
		{
		ConstructUnfoldedView(390, 130, 0);
		ConstructUnfoldedView(650, 130, 1);
		ConstructUnfoldedView(130, 390, 2);
		ConstructUnfoldedView(390, 390, 3);
		ConstructUnfoldedView(650, 390, 4);

		ConstructFoldedView(0, 0, m_answer);
		}
	else
		{
		ConstructUnfoldedView(130, 130, m_answer);

		ConstructFoldedView(260,   0, 0);
		ConstructFoldedView(520,   0, 1);
		ConstructFoldedView(  0, 260, 2);
		ConstructFoldedView(260, 260, 3);
		ConstructFoldedView(520, 260, 4);
		}
	}

/*****************************************************************************
*
* GetBmpFiles::GetBmpFiles - retrieve a set of bitmap cube faces
*
* RETURNS: TRUE if successful, otherwise FALSE
*/
System::Boolean CJMCube::GetBmpFiles()
	{
	System::Collections::ArrayList ^ fileList = gcnew System::Collections::ArrayList();
	System::Int32 i;
	System::Int32 pos;

	cli::array<System::String ^> ^ files = System::IO::Directory::GetFiles(m_bitmapDir);

	for (i = 0; i < files->Length; i++)
		{
		System::IO::FileInfo ^ fci = gcnew System::IO::FileInfo(files[i]->ToString());
		System::String ^ fileName = fci->Name->ToLower();
		pos = fileName->IndexOf(".bmp", 0, fileName->Length);

		if (pos >= 0)
			fileList->Add(fileName);
		}

	if (fileList->Count < (NUM_FACES + 2))
		{
		System::Windows::Forms::MessageBox::Show("Insufficient number of input files");
		return (false);
		}

	for (i = 0; i < NUM_FACES; i++)
		{
		System::Int32 pick = (System::Int32(10 * fileList->Count * rnd->NextDouble())) % fileList->Count;
		System::Text::StringBuilder ^ sb = gcnew System::Text::StringBuilder(m_bitmapDir);
		sb->Append(safe_cast<System::String ^>(fileList[pick]));
		m_seedList[0, i] = gcnew System::Drawing::Bitmap(sb->ToString());
		fileList->RemoveAt(pick);
		}

	for (i = 0; i < 2; i++)
		{
		System::Int32 pick = (System::Int32(10 * fileList->Count * rnd->NextDouble())) % fileList->Count;
		System::Text::StringBuilder ^ sb = gcnew System::Text::StringBuilder(m_bitmapDir);
		sb->Append(safe_cast<System::String ^> (fileList[pick]));
		m_ringerList[i] = gcnew System::Drawing::Bitmap(sb->ToString());
		fileList->RemoveAt(pick);
		}

	return (true);
	};

/*****************************************************************************
*
* UnfoldedView::ConstructUnfoldedView - displays randomized unfolded cube
*
* The input cube faces are randomized in terms of their orientation and layout
* but the correct edge to edge mapping of the cube faces remains correct.  The
* resulting image is then drawn centered relative to the input XY-coordinates.
*
* RETURNS: NA
*/
void CJMCube::ConstructUnfoldedView
	(
	System::Int32 x, 
	System::Int32 y, 
	System::Int32 choice
	)
	{
	System::Collections::ArrayList ^ workList = gcnew System::Collections::ArrayList();  // Working array
	System::Collections::ArrayList ^ faceList = gcnew System::Collections::ArrayList();  // Status of picked faces
	System::Collections::ArrayList ^ showList = gcnew System::Collections::ArrayList();
	System::Int32	edgeMap  = 0;
	System::Int32	faceMap  = 0;
	System::Int32	i;
	System::Int32	face;
	System::Int32	pick;

	cli::array<System::Drawing::Bitmap ^> ^ newList = gcnew cli::array<System::Drawing::Bitmap ^>(NUM_FACES);

	// Copy the reference set of cube faces into a working set

	for (i = 0; i < NUM_FACES; i++)
		{
		workList->Add(m_seedList[choice, i]->Clone
			(
			System::Drawing::RectangleF
				(
				0, 0, 
				System::Single(m_seedList[choice, i]->Width), 
				System::Single(m_seedList[choice, i]->Height)
				),

				System::Drawing::Imaging::PixelFormat::DontCare)
			);

		faceList->Add(System::Int32(i));
		}

	// Randomly select faces and edges to be appended to selection item

	for (i = NUM_FACES; i > 0; i--)
		{
		// If only one face has been selected, the there are constraints on the
		// one which of the remaining faces can be selected.  For all other cases
		// any remaining face is a valid selection.

		while (true)
			{
			pick = (System::Int32(96 * rnd->NextDouble())) % faceList->Count;
			face = safe_cast<System::Int32>(faceList[pick]);

			if ((faceMap ^ m_cubeRules->faceBits[face]) != 0)
				{
				faceList->RemoveAt(pick);        // Remove selected face from list
				faceMap |= m_cubeRules->faceBits[face];  // Update included faces
				break;
				}
			}

		SAssembly ^ ta = gcnew SAssembly;
		ta->face = face;

		// Randomly select a valid edge to mate to assembly

		do
			{
			ta->edge = ((int) (96 * rnd->NextDouble())) % NUM_EDGES;
			System::Int32 chkBit = m_cubeRules->edgeBit[face, ta->edge];

			if ((chkBit & edgeMap) != 0)
				break;

			} while (showList->Count > 0);

		edgeMap |= m_cubeRules->edgeBits[face];  // Update included edges

		ta->x    = x;
		ta->y    = y;
		ta->bmp  = safe_cast<System::Drawing::Bitmap ^>(workList[face]);
		showList->Add(ta);
		}
		
	ShowUnfoldedView(showList);

	workList->Clear();
	faceList->Clear();
	}

/*****************************************************************************
*
* UnfoldedView::ConstructFoldedView - displays randomized folded cube
*
* The input cube faces are randomized in terms of their orientation and layout
* but the correct edge to edge mapping of the cube faces remains correct.  The
* resulting image is then drawn centered relative to the input XY-coordinates.
*
* RETURNS: NA
*/
void CJMCube::ConstructFoldedView
	(
	System::Int32 xPos, 
	System::Int32 yPos, 
	System::Int32 choice
	)
	{
	System::Drawing::Bitmap ^ bmpA = m_seedList[choice, 0];
	System::Drawing::Bitmap ^ bmpB = m_seedList[choice, 1];
	System::Drawing::Bitmap ^ bmpC = m_seedList[choice, 2];
	System::Drawing::Bitmap ^ bmp  = gcnew System::Drawing::Bitmap(W_MAX, H_MAX);
	cli::array<System::Double, 2> ^ T = gcnew cli::array<System::Double, 2>(3,4);
	cli::array<System::Double, 2> ^ angles = gcnew cli::array<System::Double, 2>(10, 3);
	System::Double	u;
	System::Double	v;
	System::Double	scale;

	System::Int32 pick = ((System::Int32(100 * rnd->NextDouble())) % 10);

	angles[0,0] = 30;
	angles[0,1] = 30;
	angles[0,2] = 30;

	angles[1,0] = 60;
	angles[1,1] = 60;
	angles[1,2] = 60;

	angles[2,0] =  0;
	angles[2,1] = 30;
	angles[2,2] = 30;

	angles[3,0] =  0;
	angles[3,1] = 60;
	angles[3,2] = 30;

	angles[4,0] = 15;
	angles[4,1] = 60;
	angles[4,2] = 15;

	angles[5,0] = 30;
	angles[5,1] = 60;
	angles[5,2] = 30;

	angles[6,0] = 30;
	angles[6,1] = 30;
	angles[6,2] = 60;

	angles[7,0] = 45;
	angles[7,1] = 45;
	angles[7,2] = 45;

	angles[8,0] =  0;
	angles[8,1] = 45;
	angles[8,2] = 45;

	angles[9,0] = 45;
	angles[9,1] = 45;
	angles[9,2] = 60;

	System::Double	alpha = angles[pick, 0] * Math::PI / 180;
	System::Double	beta  = angles[pick, 1] * Math::PI / 180;
	System::Double	gamma = angles[pick, 2] * Math::PI / 180;

	T[0,0] = Math::Cos(alpha) * Math::Cos(beta);
	T[0,1] = Math::Cos(alpha) * Math::Sin(beta) * Math::Sin(gamma) - Math::Sin(alpha) * Math::Cos(gamma);
	T[0,2] = Math::Cos(alpha) * Math::Sin(beta) * Math::Cos(gamma) + Math::Sin(alpha) * Math::Sin(gamma);
	T[0,3] = 100;
	T[1,0] = Math::Sin(alpha) * Math::Cos(beta);
	T[1,1] = Math::Sin(alpha) * Math::Sin(beta) * Math::Sin(gamma) + Math::Cos(alpha) * Math::Cos(gamma);
	T[1,2] = Math::Sin(alpha) * Math::Sin(beta) * Math::Cos(gamma) - Math::Cos(alpha) * Math::Sin(gamma);
	T[1,3] = 125;
	T[2,0] = -Math::Sin(beta);
	T[2,1] = Math::Cos(beta) * Math::Sin(gamma);
	T[2,2] = Math::Cos(beta) * Math::Cos(gamma);
	T[2,3] = F_LENGTH;

	System::Int32 w;
	System::Int32 h;
	w = bmpA->Width;
	h = bmpA->Height;

	bmpA->RotateFlip(System::Drawing::RotateFlipType::Rotate270FlipNone);
	bmpB->RotateFlip(System::Drawing::RotateFlipType::Rotate270FlipNone);
	bmpC->RotateFlip(System::Drawing::RotateFlipType::Rotate180FlipNone);

	System::Int32 i;
	System::Int32 j;
	System::Int32 x;
	System::Int32 y;

	System::Drawing::Color	c;
	System::Drawing::Color	chk = bmpA->GetPixel(0, 0);

	for (i = 0; i < 260; i++)
		for (j = 0; j < 260; j++)
			bmp->SetPixel(i, j, System::Drawing::Color::Black);

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			u     = i * T[0,0] + j * T[0,1] + 0 * T[0,2] + T[0,3];
			v     = i * T[1,0] + j * T[1,1] + 0 * T[1,2] + T[1,3];
			scale = i * T[2,0] + j * T[2,1] + 0 * T[2,2] + T[2,3];
			u *= F_LENGTH;
			v *= F_LENGTH;
			x = System::Int32(u / scale);
			y = System::Int32(v / scale);

			if ((x < 1) || (x > (W_MAX - 2))) continue;
			if ((y < 1) || (y > (H_MAX - 2))) continue;

			bmp->SetPixel(x, y, System::Drawing::Color::White);
			bmp->SetPixel(x + 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x - 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x, y + 1, System::Drawing::Color::White);
			bmp->SetPixel(x, y - 1, System::Drawing::Color::White);
			}

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			c = bmpA->GetPixel(i, j);
			if (c == chk)
				{
				u     = i * T[0,0] + j * T[0,1] + 0 * T[0,2] + T[0,3];
				v     = i * T[1,0] + j * T[1,1] + 0 * T[1,2] + T[1,3];
				scale = i * T[2,0] + j * T[2,1] + 0 * T[2,2] + T[2,3];
				u *= F_LENGTH;
				v *= F_LENGTH;
				u /= scale;
				v /= scale;

				if ((u < 0) || (u > (W_MAX - 1))) continue;
				if ((v < 0) || (v > (H_MAX - 1))) continue;

				bmp->SetPixel(System::Int32(u), System::Int32(v), c);
				}
			}

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			u     = w * T[0,0] + j * T[0,1] + i * T[0,2] + T[0,3];
			v     = w * T[1,0] + j * T[1,1] + i * T[1,2] + T[1,3];
			scale = w * T[2,0] + j * T[2,1] + i * T[2,2] + T[2,3];
			u *= F_LENGTH;
			v *= F_LENGTH;
			x = static_cast<System::Int32> (u / scale);
			y = static_cast<System::Int32> (v / scale);

			if ((x < 1) || (x > (W_MAX - 2))) continue;
			if ((y < 1) || (y > (H_MAX - 2))) continue;

			bmp->SetPixel(x, y, System::Drawing::Color::White);
			bmp->SetPixel(x + 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x - 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x, y + 1, System::Drawing::Color::White);
			bmp->SetPixel(x, y - 1, System::Drawing::Color::White);
			}

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			c = bmpB->GetPixel(i, j);
			if (c == chk)
				{
				u     = w * T[0,0] + j * T[0,1] + i * T[0,2] + T[0,3];
				v     = w * T[1,0] + j * T[1,1] + i * T[1,2] + T[1,3];
				scale = w * T[2,0] + j * T[2,1] + i * T[2,2] + T[2,3];
				u *= F_LENGTH;
				v *= F_LENGTH;
				u /= scale;
				v /= scale;

				if ((u < 0) || (u > (W_MAX - 1))) continue;
				if ((v < 0) || (v > (H_MAX - 1))) continue;

				bmp->SetPixel(System::Int32(u), System::Int32(v), c);
				}
			}

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			u     = i * T[0,0] + 0 * T[0,1] + j * T[0,2] + T[0,3];
			v     = i * T[1,0] + 0 * T[1,1] + j * T[1,2] + T[1,3];
			scale = i * T[2,0] + 0 * T[2,1] + j * T[2,2] + T[2,3];
			u *= F_LENGTH;
			v *= F_LENGTH;
			x = static_cast<System::Int32> (u / scale);
			y = static_cast<System::Int32> (v / scale);

			if ((x < 1) || (x > (W_MAX - 2))) continue;
			if ((y < 1) || (y > (H_MAX - 2))) continue;

			bmp->SetPixel(x, y, System::Drawing::Color::White);
			bmp->SetPixel(x + 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x - 1, y, System::Drawing::Color::White);
			bmp->SetPixel(x, y + 1, System::Drawing::Color::White);
			bmp->SetPixel(x, y - 1, System::Drawing::Color::White);
			}

	for (i = 0; i < w; i++)
		for (j = 0; j < h; j++)
			{
			c = bmpC->GetPixel(i, j);
			if (c == chk)
				{
				u     = i * T[0,0] + 0 * T[0,1] + (h - j) * T[0,2] + T[0,3];
				v     = i * T[1,0] + 0 * T[1,1] + (h - j) * T[1,2] + T[1,3];
				scale = i * T[2,0] + 0 * T[2,1] + (h - j) * T[2,2] + T[2,3];
				u *= F_LENGTH;
				v *= F_LENGTH;
				u /= scale;
				v /= scale;
				if ((u < 0) || (u > (W_MAX - 1))) continue;
				if ((v < 0) || (v > (H_MAX - 1))) continue;
				bmp->SetPixel(System::Int32(u), System::Int32(v), c);
				}
			}

	m_gr->DrawImage(bmp, xPos, yPos);

	System::Drawing::Pen ^ p = gcnew System::Drawing::Pen(System::Drawing::Color::Red, 2);
	m_gr->DrawRectangle(p, xPos, yPos, 260, 260);
	}

/*****************************************************************************
*
* UnfoldedView::ShowUnfoldedView - displays instance of unfolded cube
*
* RETURNS: NA
*/
void CJMCube::ShowUnfoldedView
	(
	ArrayList ^ ufCube
	)
	{
	System::Int32	i;
	System::Int32	j;
	System::Int32	xCenter;
	System::Int32	yCenter;
	System::Int32	xAdjust;
	System::Int32	yAdjust;
	System::Int32	xMin;
	System::Int32	xMax;
	System::Int32	yMin;
	System::Int32	yMax;

	cli::array<System::Int32> ^ rotation = gcnew cli::array<System::Int32>(NUM_FACES);
	cli::array<RotateFlipType> ^ rotFlip = gcnew cli::array<RotateFlipType>(NUM_EDGES);

	SAssembly ^	face;
	SAssembly ^	mate;

	face = safe_cast<SAssembly ^> (ufCube[0]);
	xCenter = face->x;
	yCenter = face->y;

	rotFlip[TOP_EDGE]    = RotateFlipType::RotateNoneFlipNone;
	rotFlip[RIGHT_EDGE]  = RotateFlipType::Rotate90FlipNone;
	rotFlip[BOTTOM_EDGE] = RotateFlipType::Rotate180FlipNone;
	rotFlip[LEFT_EDGE]   = RotateFlipType::Rotate270FlipNone;

	switch (face->edge)
		{
		case LEFT_EDGE:
			rotation[face->face] = ROT_90;
			face->bmp->RotateFlip(RotateFlipType::Rotate90FlipNone);
			break;

		case BOTTOM_EDGE:
			rotation[face->face] = ROT_180;
			face->bmp->RotateFlip(RotateFlipType::Rotate180FlipNone);
			break;

		case RIGHT_EDGE:
			rotation[face->face] = ROT_270;
			face->bmp->RotateFlip(RotateFlipType::Rotate270FlipNone);
			break;

		case TOP_EDGE:
		default:
			rotation[face->face] = ROT_0;
			break;
		}

	xMin = xCenter;
	xMax = xCenter;
	yMin = yCenter;
	yMax = yCenter;

	face->x = xMin;
	face->y = yMin;

	for (i = 1; i < NUM_FACES; i++)
		{
		face = safe_cast<SAssembly ^> (ufCube[i]);

		for (j = 0; j < i; j++)
			{
			mate = safe_cast<SAssembly ^> (ufCube[j]);
			if (mate->face == m_cubeRules->mate[face->face, face->edge])
				break;
			}
				
		rotation[face->face] = rotation[mate->face] + m_cubeRules->rotation[face->face, face->edge];
		rotation[face->face] %= NUM_EDGES;
		face->bmp->RotateFlip(rotFlip[rotation[face->face]]);
		
		switch ((rotation[mate->face] + m_cubeRules->mateEdge[face->face, face->edge]) % NUM_EDGES)
			{
			case TOP_EDGE:
				face->x = mate->x;
				face->y = mate->y - face->bmp->Height;
				break;

			case RIGHT_EDGE:
				face->x = mate->x + face->bmp->Width;
				face->y = mate->y ;
				break;

			case BOTTOM_EDGE:
				face->x = mate->x;
				face->y = mate->y + face->bmp->Height;
				break;

			case LEFT_EDGE:
				face->x = mate->x - face->bmp->Width;
				face->y = mate->y;
				break;

			default:
				break;
			}

		if (face->x > xMax) xMax = face->x;
		if (face->x < xMin) xMin = face->x;
		if (face->y > yMax) yMax = face->y;
		if (face->y < yMin) yMin = face->y;
		}

	System::Drawing::SolidBrush ^ b = gcnew System::Drawing::SolidBrush(Color::Black);

	m_gr->FillRectangle(b, 
		xCenter - (5 * face->bmp->Width) /2 , 
		yCenter - (5 * face->bmp->Height) / 2,
		5 * face->bmp->Width,
		5 * face->bmp->Height);

	System::Drawing::Pen ^ p = gcnew System::Drawing::Pen(Color::Red, 2);

	m_gr->DrawRectangle(p, 
		xCenter - (5 * face->bmp->Width) /2 , 
		yCenter - (5 * face->bmp->Height) / 2,
		5 * face->bmp->Width,
		5 * face->bmp->Height);

	xAdjust = xCenter - ((xMax + xMin + face->bmp->Width) / 2);
	yAdjust = yCenter - ((yMax + yMin + face->bmp->Height) / 2);

	for (i = 0; i < NUM_FACES; i++)
		{
		face = safe_cast<SAssembly ^> (ufCube[i]);
		face->x += xAdjust;
		face->y += yAdjust;
		m_gr->DrawImage(face->bmp, face->x, face->y);
		}
	}

/*****************************************************************************
*
* CJMCube::ScrambleUnfoldedView - generates invalid combination of faces
*
* This function corrupts the selected set of cube faces passed in as "choice"
* in accordance with the rule associated with "mode".
*
* RETURNS: NA
*/
void CJMCube::ScrambleUnfoldedView
	(
	System::Int32 choice, 
	System::Int32 mode
	)
	{
	System::Drawing::Bitmap ^ bmp;

	switch(mode)
		{
		case 0:
			m_seedList[choice, 0]->RotateFlip(RotateFlipType::Rotate90FlipNone);
			break;

		case 1:
			m_seedList[choice, 0]->RotateFlip(RotateFlipType::Rotate270FlipNone);
			break;

		case 2:
			m_seedList[choice, 1]->RotateFlip(RotateFlipType::Rotate90FlipNone);
			break;

		case 3:
			m_seedList[choice, 1]->RotateFlip(RotateFlipType::Rotate270FlipNone);
			break;

		case 4:
			m_seedList[choice, 2]->RotateFlip(RotateFlipType::Rotate90FlipNone);
			break;

		case 5:
			m_seedList[choice, 2]->RotateFlip(RotateFlipType::Rotate270FlipNone);
			break;

		case 6:
			bmp = m_seedList[choice, 0];
			m_seedList[choice, 0] = m_seedList[choice, 1];
			m_seedList[choice, 1] = bmp;
			break;

		case 7:
			bmp = m_seedList[choice, 0];
			m_seedList[choice, 0] = m_seedList[choice, 2];
			m_seedList[choice, 2] = bmp;
			break;

		case 8:
			bmp = m_seedList[choice, 1];
			m_seedList[choice, 1] = m_seedList[choice, 2];
			m_seedList[choice, 2] = bmp;
			break;

		case 9:
			bmp = m_seedList[choice, 0];
			m_seedList[choice, 0] = m_seedList[choice, 3];
			m_seedList[choice, 3] = bmp;
			break;

		case 10:
			bmp = m_seedList[choice, 0];
			m_seedList[choice, 0] = m_seedList[choice, 4];
			m_seedList[choice, 4] = bmp;
			break;

		case 11:
			bmp = m_seedList[choice, 0];
			m_seedList[choice, 0] = m_seedList[choice, 5];
			m_seedList[choice, 5] = bmp;
			break;

		case 12:
			bmp = m_seedList[choice, 1];
			m_seedList[choice, 1] = m_seedList[choice, 3];
			m_seedList[choice, 3] = bmp;
			break;

		case 13:
			bmp = m_seedList[choice, 1];
			m_seedList[choice, 1] = m_seedList[choice, 4];
			m_seedList[choice, 4] = bmp;
			break;

		case 14:
			bmp = m_seedList[choice, 1];
			m_seedList[choice, 1] = m_seedList[choice, 5];
			m_seedList[choice, 5] = bmp;
			break;

		case 15:
			bmp = m_seedList[choice, 2];
			m_seedList[choice, 2] = m_seedList[choice, 3];
			m_seedList[choice, 3] = bmp;
			break;

		case 16:
			bmp = m_seedList[choice, 2];
			m_seedList[choice, 2] = m_seedList[choice, 4];
			m_seedList[choice, 4] = bmp;
			break;

		case 17:
			bmp = m_seedList[choice, 2];
			m_seedList[choice, 2] = m_seedList[choice, 5];
			m_seedList[choice, 5] = bmp;
			break;

		case 18:
			m_seedList[choice, 0] = m_ringerList[0];
			break;

		case 19:
			m_seedList[choice, 0] = m_ringerList[1];
			break;

		case 20:
			m_seedList[choice, 1] = m_ringerList[0];
			break;

		case 21:
			m_seedList[choice, 1] = m_ringerList[1];
			break;

		case 22:
			m_seedList[choice, 2] = m_ringerList[0];
			break;

		case 23:
			m_seedList[choice, 2] = m_ringerList[1];
			break;

		default:
			break;
		}
	}

/*****************************************************************************
                                 END OF MODULE
*****************************************************************************/

