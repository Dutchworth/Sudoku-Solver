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

  return !containsZeroes && allValuesUsed;
}

bool BoardUtils::columnComplete(const int column, const Board& board) {
  // checks for legal column number
  if (column < 0) {
    throw std::invalid_argument("received negative column number");
  } else if (column >= 9) {
    throw std::invalid_argument("receivec invalid column number");
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

  return !containsZeroes && allValuesUsed;
}

bool BoardUtils::blockComplete(const int block, const Board& board) {
  return false;
}