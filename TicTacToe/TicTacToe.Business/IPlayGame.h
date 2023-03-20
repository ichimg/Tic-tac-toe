#pragma once
#include "IPlayer.h"
#include <memory>

enum class EGameType
{
	type1
};

using IPlayGamePtr = std::shared_ptr<class IPlayGame>;
using Position = std::pair<int, int>;
class IPlayGame
{
public:
	/// <summary>
	///		Starts Game with specified type.
	/// </summary>
	/// <param name="type">Type of game.</param>
	/// <param name="player"></param>
	/// <returns></returns>
	static IPlayGamePtr Produce(EGameType type, IPlayer* player);

	/// <summary>
	///		Checks if position is empty.
	/// </summary>
	/// <param name="position">Position class as parameter.</param>
	/// <returns>Returns True or False.</returns>
	bool virtual IsEmptyPosition(const Position& position) const = 0;

	/// <summary>
	///		Checks if game is won.
	/// </summary>
	/// <returns>Returns True or False.</returns>
	bool virtual IsWin() const = 0;

	/// <summary>
	///		Checks if game is over.
	/// </summary>
	/// <returns>Returns True or False.</returns>
	bool virtual IsGameOver() const = 0;

	/// <summary>
	///		Returns Current State of Board.
	/// </summary>
	/// <returns></returns>
	virtual Board GetBoard() const = 0;

	/// <summary>
	///		Puts symbol on board.
	/// </summary>
	/// <param name="symbol">SymbolType value that stores X or O.</param>
	virtual void PutSymbol(SymbolType symbol) = 0;
	virtual ~IPlayGame() = default;
};

