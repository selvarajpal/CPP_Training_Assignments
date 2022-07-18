//
//  Singleton.hpp
//  gtest
//
//  Created by Selvaraj Palaniyappan on 17/07/22.
//

#ifndef Singleton_h
#define Singleton_h
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>
using boost::lexical_cast;
class Database
{
public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
  SingletonDatabase()
  {
    std::cout << "Initializing database" << std::endl;
    std::ifstream ifs;
    ifs.open("/Users/spalaniyappa/Documents/TechnicalDoc/JuniperDoc/C++Trainingg/juniper-traineee/gtest/capitals.txt");
    std::string s, s2;
    while (getline(ifs, s))
    {
      getline(ifs, s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
    instance_count++;
  }
  std::map<std::string, int> capitals;
public:
  static int instance_count;
  //static SingletonDatabase *instance;
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;
   size_t getRecordCount() {
        return capitals.size();
   }
 
  int get_population(const std::string& name) override
  {
    return capitals[name];
  }
  
  static SingletonDatabase& get_instance()
  {
    static SingletonDatabase   instance;
    return instance; // atexit
  }
  
};

int SingletonDatabase::instance_count = 0;

class DummyDatabase : public Database
{
  std::map<std::string, int> capitals;
public:
  DummyDatabase()
  {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }
  int get_population(const std::string& name) override {
    return capitals[name];
  }
};

struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names)
      result += SingletonDatabase::get_instance().get_population(name);
       std::cout <<" TOTAL_POLULATION NAME val = " << result<<std::endl;
    return result;
  }
};
struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFinder(Database& db)
    : db{db}
  {
  }
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names)
      result += db.get_population(name);
      std::cout <<" TOTAL_POLULATION NAME val = " << result<<std::endl;
    return result;
  }
  Database& db;
};

#endif /* Singleton_h */
