/****************************************************************************
 * Copyright (C) 2018, <Copyright Holder>                                   *
 * All rights reserved                                                      *
 *                                                                          *
 * For the licensing terms see LICENSE file inside the root directory.      *
 * For the list of contributors see AUTHORS file inside the root directory. *
 ***************************************************************************/
#ifndef BOARDUTILS_H
#define BOARDUTILS_H

#include "Board.h"

/** @brief Namespace for holding sudoku board utility functions
 *
 * this namespace contains useful, utility functions that are performed on
 * the sudoku board.
 */
namespace BoardUtils {
/** @brief Determines whether the given board is complete
 * Iterates through all possible rows, columns, and blocks to determine if
 * every square has been assigned and there are no contradictions.
 * @param board The board object to be tested
 * @return Boolean of whether the board is complete
 */
bool isComplete(const Board& board);

/** @brief Determines whether the given row is complete
 * Iterates through the given row number (0 - 9) and determines if every
 * square has been assigned and there are no contradictions.
 * @param row The number of the row to be tested (0 - 9)
 * @param board The board to be tested
 * @return Boolean of whether the row is complete
 */
bool rowComplete(const int row, const Board& board);

/** @brief Determines whether the given column is complete
 * Iterates through the given column number (0 - 9) and determines if every
 * square has been assigned and there are no contradictions.
 * @param column The number of the row to be tested (0 - 9)
 * @param board The board to be tested
 * @return Boolean of whether the column is complete
 */
bool columnComplete(const int column, const Board& board);

/** @brief Determines whether the given row is complete
 * Iterates through the given block number (0 - 9) and determines if every
 * square has been assigned and there are no contradictions.
 * Block numbering scheme:
 * - 0 = Top left
 * - 1 = Top Centre
 * - 2 = Top Right
 * - 3 = Middle Left
 * - 4 = Middle Centre
 * - 5 = Middle Right
 * - 6 = Bottom left
 * - 7 = Bottom Centre
 * - 8 = Bottom Right
 * @param row The number of the row to be tested (0 - 9)
 * @param board The board to be tested
 * @return Boolean of whether the row is complete
 */
bool blockComplete(const int block, const Board& board);
}  // namespace BoardUtils

#endif  // BOARDUTILS_H