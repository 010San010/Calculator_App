#include <string>
#include <vector>
#include "pch.h"
#include "../Project/Check_Fun.h"
#include "../Project/Calc_Fun.h"
#include "../Project/Math_Fun.h"
#include "../Project/Bin_Fun.h"

TEST(CheckFunTest, Test01) {
  std::string temp1 = "-12";
  std::string temp2;
  OneTokenExeption(temp1, temp2);

  EXPECT_EQ(stoi(temp2), -12);
}

TEST(CheckFunTest, Test02) {
  std::string temp = "\0";

  EXPECT_EQ(EmptyExpressionExeption(temp), true);
}

TEST(CheckFunTest, Test03) {
  char temp = '\0';

  EXPECT_EQ(SingleNumberExeption(temp), true);
}

TEST(CheckFunTest, Test04) {
  int temp1 = 3;
  int temp2 = 6;

  EXPECT_EQ(MoreOperationTokensExeption(temp1, temp2), true);
  EXPECT_EQ(MoreOperationTokensExeption(temp1, temp2), true);
}

TEST(CheckFunTest, Test05) {
  std::string temp = "abcdefghijklmnop";

  EXPECT_EQ(SizeCheckBin(temp), true);
}

TEST(CheckFunTest, Test06) {
  long temp = 23455;

  EXPECT_EQ(SizeCheckDec(temp), true);
}

TEST(CheckFunTest, Test07) {
  std::string temp = "+++";

  EXPECT_EQ(NotIntSymbolsExeption(temp), true);
}

TEST(CalcFunTest, Test01) {
  std::vector<int> tempV1 = {2, 3};
  std::vector<char> tempV2 = {'+', '-'};
  int temp = 0;

  EXPECT_EQ(EqualTokensCheck<int>(tempV1, tempV2, temp), true);
}

TEST(CalcFunTest, Test02) {
  std::string temp1 = "2+3";
  std::string temp2;
  int temp3 = 0;
  ReadNumber(temp1, temp2, temp3);

  EXPECT_EQ(temp2, 2);
  EXPECT_EQ(temp3, 1);
}

TEST(CutAndDoFunTest, Test01) {
  std::string temp = "2+3-6";

  EXPECT_EQ(CutAndDo(temp), -1);
}

TEST(CutAndDoFunTest, Test02) {
  std::string temp = "1001b+23";

  EXPECT_EQ(CutAndDoBin(temp), 32);
}

TEST(CutAndDoFunTest, Test03) {
  std::string temp = "12.12.2004/12.12.2022";

  EXPECT_EQ(CutAndDoBin(temp), 6573);
}