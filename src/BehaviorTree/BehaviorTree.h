#pragma once

class CBehaviorTree
{
public:
	CBehaviorTree();
	~CBehaviorTree();

	inline int GetTreeId() const { return TreeId; }

private:
	int TreeId;
};
