#include "gtest/gtest.h"

#include <iostream>
#include <math.h>
#include <ctime>

#include "date.h"


class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  current_day = Date();
  epoch = Date(2);
  //setup string for current date (global format)
  t = std::time(0);
  now = std::localtime(&t);
  yr = now->tm_year + 1900;
  m = now->tm_mon + 1;
  d = now->tm_mday;
  current_date_string = "";
  sprintf(numstr, "%d", yr);
  current_date_string = current_date_string + numstr + "-";
  if (m < 10)
    current_date_string = current_date_string + "0";
  sprintf(numstr, "%d", m);
  current_date_string = current_date_string + numstr + "-";
  if (d < 10)
    current_date_string = current_date_string + "0";
  sprintf(numstr, "%d", d);
  current_date_string = current_date_string + numstr;
  //setup string for current date (US format)
  if (m < 10)
    current_date_string_US = current_date_string_US + "0";
  sprintf(numstr2, "%d", m);
  current_date_string_US = current_date_string_US + numstr2 + "-";
  if (d < 10)
    current_date_string_US = current_date_string_US + "0";
  sprintf(numstr2, "%d", d);
  current_date_string_US = current_date_string_US + numstr2;
  sprintf(numstr2, "%d", yr);
  current_date_string_US = current_date_string_US + "-" + numstr2;
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date current_day;
  std::time_t t;
  std::tm* now;
  int yr, m, d;
  char numstr[5];
  char numstr2[5];
  std::string current_date_string;
  std::string current_date_string_US;
  Date epoch;
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}


TEST_F(DateTest, DefaultDateTests) {
  EXPECT_EQ(current_day.GetDate(), current_date_string) << "Date default constructor not setup properly";
  EXPECT_EQ(current_day.GetUsDate(), current_date_string_US) << "Date default constructor not setup properly";
}

TEST_F(DateTest, ParameterizedDateTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "Parameterized Date constructor not setup properly";
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "Parameterized Date constructor not setup properly";
}

TEST_F(DateTest, EpochTests) {
  EXPECT_EQ(epoch.GetDate(), "1970-01-01") << "Epoch Date constructor not setup properly";
  EXPECT_EQ(epoch.GetUsDate(), "01-01-1970") << "Epoch Date constructor not setup properly";
}

TEST_F(DateTest, AddDaysTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ( (first_day + 1).GetDate(), "2018-09-05") << "Overloaded plus operator not setup properly";
  EXPECT_EQ( (first_day + 30).GetDate(), "2018-10-04") << "Overloaded plus operator not setup properly";
  EXPECT_EQ( (first_day + 365).GetDate(), "2019-09-04") << "Overloaded plus operator not setup properly";
  EXPECT_EQ( (first_day + 1).GetUsDate(), "09-05-2018") << "Overloaded plus operator not setup properly";
  EXPECT_EQ( (first_day + 30).GetUsDate(), "10-04-2018") << "Overloaded plus operator not setup properly";
  EXPECT_EQ( (first_day + 365).GetUsDate(), "09-04-2019") << "Overloaded plus operator not setup properly";

}

TEST_F(DateTest, SubtractDaysTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ( (first_day - 1).GetDate(), "2018-09-03") << "Overloaded minus operator not setup properly";
  EXPECT_EQ( (first_day - 4).GetDate(), "2018-08-31") << "Overloaded minus operator not setup properly";
  EXPECT_EQ( (first_day - 365).GetDate(), "2017-09-04") << "Overloaded minus operator not setup properly";
  EXPECT_EQ( (first_day - 1).GetUsDate(), "09-03-2018") << "Overloaded minus operator not setup properly";
  EXPECT_EQ( (first_day - 4).GetUsDate(), "08-31-2018") << "Overloaded minus operator not setup properly";
  EXPECT_EQ( (first_day - 365).GetUsDate(), "09-04-2017") << "Overloaded minus operator not setup properly";
}

TEST_F(DateTest, GetDateTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Last day of class not setup properly";
  EXPECT_EQ(epoch.GetDate(), "1970-01-01") << "Epoch Date constructor not setup properly";
  EXPECT_EQ(current_day.GetDate(), current_date_string) << "Date default constructor not setup properly";
}

TEST_F(DateTest, GetUsDateTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(epoch.GetUsDate(), "01-01-1970") << "Epoch Date constructor not setup properly";
  EXPECT_EQ(current_day.GetUsDate(), current_date_string_US) << "Date default constructor not setup properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
