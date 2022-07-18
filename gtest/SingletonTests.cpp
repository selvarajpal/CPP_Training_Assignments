//
//  SingletonTests.cpp
//  gtest
//
//  Created by Selvaraj Palaniyappan on 17/07/22.
//

#include "Singleton.hpp"
#include <gtest/gtest.h>

TEST(DatabaseTests, IsSingletonTest)
{
  auto& db = SingletonDatabase::get_instance();
  auto& db2 = SingletonDatabase::get_instance();
  ASSERT_EQ(1, db.instance_count);
  ASSERT_EQ(1, db2.instance_count);
}
TEST(DatabaseTests, DatabaseRecordTest)
{
  auto& db = SingletonDatabase::get_instance();
  ASSERT_EQ(10, db.getRecordCount());
}
TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Seoul", "Mexico City" };
  int tp = rf.total_population(names);
  EXPECT_EQ(17500000 + 17400000, tp);
}

TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{ db };
  EXPECT_EQ(4, rf.total_population(
  std::vector<std::string>{"alpha", "gamma"}));
}

