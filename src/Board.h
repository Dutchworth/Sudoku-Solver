/****************************************************************************
 * Copyright (C) 2018, <Copyright Holder>                                   *
 * All rights reserved                                                      *
 *                                                                          *
 * For the licensing terms see LICENSE file inside the root directory.      *
 * For the list of contributors see AUTHORS file inside the root directory. *
 ***************************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include <array>

/** @brief Class for holding sudoku board details
 *
 * This class will hold the internals of the sudoku board itself during the
 * program's runtime.
 * Exposes methods for manipulating the board.
 */
class Board {
 private:
  /** @brief internal 2D array of ints for the board
   *
   */
  std::array<std::array<int, 9>, 9> m_board;

 public:
  /** @brief Constructor with no set variable
   *
   */
  Board();

  /** @brief Copy Constructor
   *
   */
  Board(const Board& other);

  /** @brief Assignment operator
   *
   */
  Board& operator=(const Board& other);

  /** @brief Destructor
   *
   */
  ~Board();

  /** @brief Gets the value at the given square
   * @param row Row number of square to retreive
   * @param column Column number of square to retrieve
   * @return The value of the given square
   */
  int getAt(const int row, const int column) const;

  /** @brief Sets the value of the given square
   * @param row Row number of square to set
   * @param column Column number of square to set
   * @param value Value to set the square to
   */
  void setAt(const int row, const int column, const int value);
};

#endif  // BOARD_H