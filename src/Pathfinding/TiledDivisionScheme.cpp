#include "TiledDivisionScheme.h"

#include "DirectedWeightedGraph.h"

//=======================================================================================================================
CTiledDivisionScheme::CTiledDivisionScheme(int InScreenWidth, int InScreenHeight, int InTileWidth, int InTileHeight, CDirectedWeightedGraph* InGraph) :
	ScreenWidth(InScreenWidth),
	ScreenHeight(InScreenHeight),
	TileWidth(InTileWidth),
	TileHeight(InTileHeight),
	Graph(InGraph)
{
	GraphWidth = ScreenWidth / TileWidth;
	GraphHeight = ScreenHeight / TileHeight;
}

//=======================================================================================================================
CTiledDivisionScheme::~CTiledDivisionScheme()
{
}

//=======================================================================================================================
int CTiledDivisionScheme::Quantize(const ofVec2f& InPosition) const
{
	int Column = floor(InPosition.x / TileWidth);
	int Row = floor(InPosition.y / TileHeight);

	int CurrentNode = (Row * GraphHeight) + Column;

	return CurrentNode;
}

//=======================================================================================================================
ofVec2f CTiledDivisionScheme::Localize(int InNode) const
{
	int Row = InNode / GraphHeight;
	int Column = InNode % GraphWidth;

	ofVec2f Position;

	Position.x = Column * TileWidth + (TileWidth / 2);
	Position.y = Row * TileHeight + (TileWidth / 2);

	return Position;
}
