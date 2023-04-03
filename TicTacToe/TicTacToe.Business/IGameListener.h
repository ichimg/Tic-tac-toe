#pragma once
#include <memory>
class IGameListener
{

public:

	virtual void OnWin() = 0;

	virtual void OnDraw() = 0;
};


