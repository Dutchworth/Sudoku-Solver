#include "BoardUtils.h"
#include <algorithm>
#include <set>
#include <stdexcept>
#include "Board.h"

bool BoardUtils::rowComplete(const int row, const Board& board) {
  // checks for legal row number
  if (row < 0) {
    throw std::invalid_argument("received negative row number");
  } else if (row >= 9) {
    throw std::invalid_argument("received invalid row number");
  }

  // will be set true if the row contains any zeroes (unset squares)
  bool containsZeroes = false;

  // will store only unique, used values
  std::set<int> usedValues;

  for (int column = 0; column < 9; column++) {
    int value = board.getAt(row, column);

    if (value == 0) {
      containsZeroes = true;
      break;
    }

    usedValues.insert(value);
  }

  // will be false if set does not contain numbers 0 - 9
  bool allValuesUsed = usedValues.size() == 9;

  return (not containsZeroes) && allValuesUsed;
}

bool BoardUtils::columnComplete(const int column, const Board& board) {
  // checks for legal column number
  if (column < 0) {
    throw std::invalid_argument("received negative column number");
  } else if (column >= 9) {
    throw std::invalid_argument("received invalid column number");
  }

  // will be set true if the row contains any zeroes (unset squares)
  bool containsZeroes = false;

  // will store only unique, used values
  std::set<int> usedValues;

  for (int row = 0; row < 9; row++) {
    int value = board.getAt(row, column);

    if (value == 0) {
      containsZeroes = true;
      break;
    }

    usedValues.insert(value);
  }

  // will be false if set does not contain numbers 0 - 9
  bool allValuesUsed = usedValues.size() == 9;

  return (not containsZeroes) && allValuesUsed;
}

bool BoardUtils::blockComplete(const int block, const Board& board) {
  // checks for legal block number
  if (block < 0) {
    throw std::invalid_argument("received negative block number");
  } else if (block >= 9) {
    std::invalid_argument("received invalid block number");
  }

  // will be set true if the row contains any zeroes (unset squares)
  bool containsZeroes = false;

  // will store only unique, used values
  std::set<int> usedValues;

  for (int i = 0; i < 9; i++) {
    int row;     // TODO convert block number and i to row number
    int column;  // TODO convert block number and i to column number

    int value = board.getAt(row, column);

    if (value == 0) {
      containsZeroes = true;
      break;
    }

    usedValues.insert(value);
  }

  // will be false if set does not contain numbers 0 - 9
  bool allValuesUsed = usedValues.size() == 9;

  return (not containsZeroes) && allValuesUsed;
}

bool BoardUtils::boardComplete(const Board& board) {
  bool allCorrect = true;

  for (int i = 0; i < 9; i++) {
    if (not BoardUtils::rowComplete(i, board)) {
      allCorrect = false;
      break;
    } else if (not BoardUtils::columnComplete(i, board)) {
      allCorrect = false;
      break;
    } else if (not BoardUtils::blockComplete(i, board)) {
      allCorrect = false;
      break;
    }
  }

  return allCorrect;
}