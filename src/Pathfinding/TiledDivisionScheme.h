#pragma once

#include "DivisionScheme.h"

class CDirectedWeightedGraph;

//=======================================================================================================================
class CTiledDivisionScheme : public CDivisionScheme
{
public:
	CTiledDivisionScheme(int InScreenWidth, int InScreenHeight, int InTileWidth, int InTileHeight, CDirectedWeightedGraph* InGraph);
	~CTiledDivisionScheme();

	virtual int Quantize(const ofVec2f& InPosition) const override;
	virtual ofVec2f Localize(int InNode) const override;

private:
	int ScreenWidth;
	int ScreenHeight;

	int TileWidth;
	int TileHeight;

	int GraphWidth;
	int GraphHeight;

	CDirectedWeightedGraph* Graph;
};

