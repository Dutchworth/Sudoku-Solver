#include "Board.h"
#include <array>
#include <stdexcept>

Board::Board() {
  // do nothing, m_board will be automatically initialied
}

Board::Board(const Board& other) : m_board(other.m_board) {
  // do nothing, m_board set from member initialisation list
}

Board& Board::operator=(const Board& other) {
  m_board = other.m_board;

  return *this;
}

Board::~Board() {
  // do nothing, resources will destruct themselves
}

int Board::getAt(const int row, const int column) const {
  return m_board.at(row).at(column);
}

void Board::setAt(const int row, const int column, const int value) {
  if (value < 0) {
    throw std::invalid_argument("received negative value");
  } else if (value > 9) {
    throw std::invalid_argument("received invalid value");
  } else {
    m_board.at(row).at(column) = value;
  }
}