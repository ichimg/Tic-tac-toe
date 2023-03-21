#pragma once
#include <utility>
#include <string>
#include "Board.h"
#include "SymbolType.h"
class IPlayer
{
public:
	/// <summary>
	///		Stores Position off current symbol of player.
	/// </summary>
	using Position = std::pair<int, int>;

	/// <summary>
	///		Returns position of current symbol.
	/// </summary>
	/// <returns>Position of current symbol.</returns>
	virtual Position RequestPutSymbol() = 0;

	/// <summary>
	///		Places symbol on board at position(x, y).
	/// </summary>
	/// <param name="board">Board Class that stores current board.</param>
	/// <param name="position">Position of where you want to put symbol.</param>
	virtual void PutSymbol(Board& board, const Position& position) = 0;

	/// <summary>
	///		Returns name of current player.
	/// </summary>
	/// <returns>Name of current player.</returns>
	virtual std::string GetName() const = 0;

	/// <summary>
	///		Returns current symbol of player.
	/// </summary>
	/// <returns>Current symbol of player.</returns>
	virtual SymbolType GetSymbol() const = 0;

	/// <summary>
	///		Changes symbol from X to 0 or from O to X.
	/// </summary>
	virtual void ChangeSymbol() = 0;

	/// <summary>
	///		Setter for SymbolType.
	/// </summary>
	/// <param name="symbol">SymbolType that stores X or O.</param>
	virtual void SetSymbol(const SymbolType& symbol) = 0;

	/// <summary>
	///		Setter for Position.
	/// </summary>
	/// <param name="position"></param>
	virtual void SetPosition(const Position& position) = 0;

	/// <summary>
	///		Virtual destructor for Player Class.
	/// </summary>
	virtual ~IPlayer() = default;

private:
	SymbolType symbol;
	std::string m_name;
};

