#pragma once
#include <memory>
using Position = std::pair<int, int>;
class IGameListener
{

public:

	/// <summary>
	///		Display win message.
	/// </summary>
	virtual void OnWin() = 0;

	/// <summary>
	///		Display draw message.
	/// </summary>
	virtual void OnDraw() = 0;

	/// <summary>
	///		Take action on making a move.
	/// </summary>
	virtual void OnMove() = 0;
};


