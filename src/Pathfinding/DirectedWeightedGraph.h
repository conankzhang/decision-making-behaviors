#pragma once

#include <vector>

class CObstacle;

//=======================================================================================================================
class CDirectedWeightedEdge
{
public:
	CDirectedWeightedEdge();
	CDirectedWeightedEdge(float InCost, int InSource, int InSink);
	~CDirectedWeightedEdge();

	inline float GetCost() const { return Cost; }

	inline int GetSource() const { return Source; }
	inline int GetSink() const { return Sink; }

private:
	float Cost;

	int Source;
	int Sink;
};

//=======================================================================================================================
enum class EGraph
{
	NONE,
	PALLET,
	TILED
};

//=======================================================================================================================
class CDirectedWeightedGraph
{
public:
	CDirectedWeightedGraph();
	CDirectedWeightedGraph(EGraph GraphType, int InScreenWidth, int InScreenHeight, int InTileWidth, int InTileHeight, const std::vector<CObstacle*>& InObstacles);
	~CDirectedWeightedGraph();

	void GetOutgoingEdges(int InNode, std::vector<const CDirectedWeightedEdge*>& OutOutgoingEdges) const;

private:
	void CreatePalletGraph();
	void GenerateTiledGraph();

	float CalculateCost(int Row, int Column);

private:
	std::vector<CDirectedWeightedEdge> Edges;
	const std::vector<CObstacle*>& Obstacles = std::vector<CObstacle *>();

	int ScreenWidth;
	int ScreenHeight;

	int TileWidth;
	int TileHeight;
};
