#pragma once
#include <memory>
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
};


