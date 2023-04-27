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
	///		Virtual destructor for Player Class.
	/// </summary>
	virtual ~IPlayer() = default;

private:
	SymbolType symbol;
	std::string m_name;
};

