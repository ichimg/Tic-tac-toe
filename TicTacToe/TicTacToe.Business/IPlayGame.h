#pragma once
#include "IPlayer.h"
#include "IGameListener.h"
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
	static IPlayGamePtr Produce(EGameType type, SymbolType symbol);

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
	///		Places symbol on board at position(x, y).
	/// </summary>
	/// <param name="board">Board Class that stores current board.</param>
	/// <param name="position">Position of where you want to put symbol.</param>
	virtual void PutSymbol(SymbolType symbol) = 0;


	virtual IPlayer* GetPlayer() = 0;

	/// <summary>
	///		Add a listener.
	/// </summary>
	/// <param name="listener">IGameListener* that represents a listener. </param>
	virtual void AddListener(IGameListener* listener) = 0;

	/// <summary>
	///		Remove a listener.
	/// </summary>
	/// <param name="listener">IGameListener* that represents a listener. </param>
	virtual void RemoveListener(IGameListener* listener) = 0;

	virtual ~IPlayGame() = default;
};

