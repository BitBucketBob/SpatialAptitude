#include "StdAfx.h"
#include "UnfoldedCube.h"
#using <mscorlib.dll>

/*****************************************************************************
* SCubeRules - constructor
*
* This constructor initializes all of the rules that govern the assembly of
* each of the six faces of a cube into a flattened out unfolded construction.
*
* RETURNS: NA
*/
CJMCube::SCubeRules::SCubeRules()
	{
	// Allocate arrays

	mate     = new Int32[NUM_FACES, NUM_EDGES];
	mateEdge = new Int32[NUM_FACES, NUM_EDGES];
	rotation = new Int32[NUM_FACES, NUM_EDGES];
	faceBits = new Int32[NUM_FACES];
	edgeBits = new Int32[NUM_FACES];
	edgeBit  = new Int32[NUM_FACES, NUM_EDGES];

	// Mating face by bonded edge

	mate[0, TOP_EDGE   ] = 3;     // Top    edge matches face 3
	mate[0, RIGHT_EDGE ] = 2;     // Right  edge matches face 2
	mate[0, BOTTOM_EDGE] = 1;     // Bottom edge matches face 1
	mate[0, LEFT_EDGE  ] = 0;     // Left   edge matches face 4

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
	edgeBits[4] = 0x0A18;
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
	edgeBit[4, RIGHT_EDGE ]  = 0x0010;
	edgeBit[4, BOTTOM_EDGE]  = 0x0800;
	edgeBit[4, LEFT_EDGE  ]  = 0x0200;

	edgeBit[5, TOP_EDGE   ]  = 0x0800;
	edgeBit[5, RIGHT_EDGE ]  = 0x0020;
	edgeBit[5, BOTTOM_EDGE]  = 0x0100;
	edgeBit[5, LEFT_EDGE  ]  = 0x0400;
	}

CJMCube::CJMCube(String * dir, Graphics * gr) : m_dir(dir), m_gr(gr)
	{
	Random *	rnd      = new Random();     // Random number generator
	System::Text::StringBuilder * sb = new System::Text::StringBuilder(S"");
	m_seedList = new Bitmap *[NUM_FACES];

	sb->Append(m_dir);
	sb->Append("Face1.bmp");
	m_seedList[0] = new Bitmap(sb->ToString());

	sb->Length = 0;
	sb->Append(m_dir);
	sb->Append("Face2.bmp");
	m_seedList[1] = new Bitmap(sb->ToString());

	sb->Length = 0;
	sb->Append(m_dir);
	sb->Append("Face3.bmp");
	m_seedList[2] = new Bitmap(sb->ToString());

	sb->Length = 0;
	sb->Append(m_dir);
	sb->Append("Face4.bmp");
	m_seedList[3] = new Bitmap(sb->ToString());

	sb->Length = 0;
	sb->Append(m_dir);
	sb->Append("Face5.bmp");
	m_seedList[4] = new Bitmap(sb->ToString());

	sb->Length = 0;
	sb->Append(m_dir);
	sb->Append("Face6.bmp");
	m_seedList[5] = new Bitmap(sb->ToString());
			
	Int32	i;
	Int32	flawMode;
	Int32	rotation;

	// Randomly reorient the faces of the seed input faces

	for (i = 0; i < NUM_SEED; i++)
		{
		rotation = (static_cast<Int32> (96 * rnd->NextDouble())) % NUM_MODES;
		switch (rotation)
			{
			default:
				break;
			}
		}
	
	// Randomly insert different mismatch modes

	for (i = 0; i < NUM_CHOICES; i++)
		{
		flawMode = (static_cast<Int32> (96 * rnd->NextDouble())) % NUM_MODES;
		switch (flawMode)
			{
			default:
				break;
			}
		}

	ConstructUnfoldedView(800, 20);
	}

CJMCube::~CJMCube(void)
	{
	}

/*****************************************************************************
* UnfoldedView - displays the unfolded cube in random orientation and layout
*
* The input cube faces are randomized in terms of their orientation and layout
* but the correct edge to edge mapping of the cube faces remains correct.  The
* resulting image is then drawn centered relative to the input XY-coordinates.
*
* RETURNS: NA
*/
void CJMCube::ConstructUnfoldedView(int x, int y)
	{
	Random *	rnd      = new Random();     // Random number generator
	ArrayList * workList = new ArrayList();  // Working array
	ArrayList * faceList = new ArrayList();  // Status of picked faces
	ArrayList * showList = new ArrayList();
	Int32		edgeMap  = 0;
	Int32		faceMap  = 0;
	Int32		i;
	Int32		face;
	Int32		pick;

	Bitmap *	newList[] = new Bitmap *[NUM_FACES];

	// Copy the reference set of cube faces into a working set

	for (i = 0; i < NUM_FACES; i++)
		{
		workList->Add(m_seedList[i]->Clone
			(
			RectangleF
				(
				0, 0, 
				static_cast<float> (m_seedList[i]->Width), 
				static_cast<float> (m_seedList[i]->Height)
				),
			Imaging::PixelFormat::DontCare)
			);

		faceList->Add(__box(Int32(i)));
		}

	// Randomly select faces and edges to be appended to selection item

	for (i = NUM_FACES; i > 0; i--)
		{
		// If only one face has been selected, the there are constraints on the
		// one which of the remaining faces can be selected.  For all other cases
		// any remaining face is a valid selection.

		while (true)
			{
			pick = ((int) (96 * rnd->NextDouble())) % faceList->Count;
			face = *(__try_cast<Int32 *>(faceList->get_Item(pick)));
			if ((faceMap ^ m_cubeRules.faceBits[face]) != 0)
				{
				faceList->RemoveAt(pick);        // Remove selected face from list
				faceMap |= m_cubeRules.faceBits[face];  // Update included faces
				break;
				}
			}

		SAssembly * ta = new SAssembly;
		ta->face = face;

		// Randomly select a valid edge to mate to assembly

		do
			{
			ta->edge = ((int) (96 * rnd->NextDouble())) % NUM_EDGES;
			int chkBit = m_cubeRules.edgeBit[face, ta->edge];
			if ((chkBit & edgeMap) != 0)
				break;
			} while (showList->Count > 0);

		edgeMap |= m_cubeRules.edgeBits[face];  // Update included edges

		ta->x    = x;
		ta->y    = y;
		ta->bmp  = __try_cast<Bitmap *> (workList->get_Item(face));
		showList->Add(ta);
		}
		
	ShowUnfoldedView(showList);

	workList->Clear();
	faceList->Clear();
	}

void CJMCube::ConstructFoldedView(int x, int y)
	{
	}

void CJMCube::ShowUnfoldedView(ArrayList * ufCube)
	{
	SAssembly * ta = __try_cast<SAssembly *> (ufCube->get_Item(0));
	m_gr->DrawImage(ta->bmp, 800, 72);
	}

