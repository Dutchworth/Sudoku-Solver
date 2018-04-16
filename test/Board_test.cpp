#include <stdexcept>
#include "Board.h"
#include "gtest/gtest.h"

class BoardTest : public ::testing::Test {
 protected:
  Board testBoard;

  virtual void SetUp() { testBoard = Board(); }

  virtual void TearDown() {}
};

TEST_F(BoardTest, testSetAndGetAtTakesCorrectValueRange) {
  for (int each = 0; each < 10; each++) {
    EXPECT_NO_THROW(testBoard.setAt(0, 0, each));
    EXPECT_EQ(each, testBoard.getAt(0, 0));
  }
}

TEST_F(BoardTest, testSetAndGetAtTakesCorrectRowRange) {
  for (int row = 0; row < 9; row++) {
    EXPECT_NO_THROW(testBoard.setAt(row, 0, 4));
    EXPECT_EQ(4, testBoard.getAt(row, 0));
  }
}

TEST_F(BoardTest, testSetAndGetAtTakesCorrectColumnRange) {
  for (int column = 0; column < 9; column++) {
    EXPECT_NO_THROW(testBoard.setAt(0, column, 4));
    EXPECT_EQ(4, testBoard.getAt(0, column));
  }
}

TEST_F(BoardTest, testSetAtThrowsExceptionForNegativeValue) {
  EXPECT_THROW(testBoard.setAt(0, 0, -1), std::invalid_argument);
}

TEST_F(BoardTest, testSetAtThrowsExceptionForvalueTooHigh) {
  EXPECT_THROW(testBoard.setAt(0, 0, 12), std::invalid_argument);
}

TEST_F(BoardTest, testSetAtThrowsExceptionForBadRowNumbers) {
  EXPECT_THROW(testBoard.setAt(-1, 0, 4), std::out_of_range);
  EXPECT_THROW(testBoard.setAt(9, 0, 4), std::out_of_range);
}

TEST_F(BoardTest, testSetAtThrowsExceptionForBadRColumnNumbers) {
  EXPECT_THROW(testBoard.setAt(0, -1, 4), std::out_of_range);
  EXPECT_THROW(testBoard.setAt(0, 9, 4), std::out_of_range);
}

TEST_F(BoardTest, testGetAtThrowsExceptionForBadRowNumbers) {
  EXPECT_THROW(testBoard.getAt(-1, 0), std::out_of_range);
  EXPECT_THROW(testBoard.getAt(9, 0), std::out_of_range);
}

TEST_F(BoardTest, testGetAtThrowsExceptionForBadColumnNumbers) {
  EXPECT_THROW(testBoard.getAt(0, -1), std::out_of_range);
  EXPECT_THROW(testBoard.getAt(0, 9), std::out_of_range);
}