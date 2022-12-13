#include<gtest/gtest.h>
#include "Task.h"
#include<string>
using namespace std;
#include <set>


void test_for_4A()
{
//create input 
  string sourcefile1="./inputfile/4A";
  string answerfile1="./answer/task/4A";
  string tempfile1="./temp/task/4A";
  JudgeControl * c=new JudgeControl(sourcefile1,answerfile1,tempfile1);
  c->start_judge();


  std::set<std::string> inequal_test={
      "inputfile/4A/84822639.cpp,inputfile/4A/48762087.cpp",
      "inputfile/4A/84822639.cpp,inputfile/4A/101036360.cpp",
      "inputfile/4A/84822639.cpp,inputfile/4A/117364748.cpp",
      "inputfile/4A/84822638.cpp,inputfile/4A/48762087.cpp",
      "inputfile/4A/84822638.cpp,inputfile/4A/101036360.cpp",
      "inputfile/4A/84822638.cpp,inputfile/4A/117364748.cpp",
      "inputfile/4A/48762087.cpp,inputfile/4A/101036360.cpp",
      "inputfile/4A/48762087.cpp,inputfile/4A/117364748.cpp",
      "inputfile/4A/101036360.cpp,inputfile/4A/117364748.cpp"

  };
  //read csv to test whether judge is right
  fstream file;
  file.open("./answer/task/4A/inequal.csv");
  string answer_str;
  for(int i=0;i<9;i++)
  {
     file>>answer_str;
     bool flag=inequal_test.find(answer_str)!=inequal_test.end();
     EXPECT_EQ(flag,true);
     inequal_test.erase(answer_str);
  }
  EXPECT_EQ(inequal_test.size(),0);
  file.close();


std::set<std::string> equal_test={
     "inputfile/4A/84822639.cpp,inputfile/4A/84822638.cpp"
                                   };

  file.open("./answer/task/4A/equal.csv");
  for(int i=0;i<1;i++)
  {
     file>>answer_str;
     bool flag=equal_test.find(answer_str)!=equal_test.end();
     EXPECT_EQ(flag,true);
     equal_test.erase(answer_str);
  }
  EXPECT_EQ(equal_test.size(),0);
  file.close();


};

void test_for_50A()
{
//create input 
  string sourcefile1="./inputfile/50A";
  string answerfile1="./answer/task/50A";
  string tempfile1="./temp/task/50A";
  JudgeControl * c=new JudgeControl(sourcefile1,answerfile1,tempfile1);
  c->start_judge();


  std::set<std::string> equal_test={
      "inputfile/50A/21508887.cpp,inputfile/50A/21715601.cpp",
      "inputfile/50A/21508887.cpp,inputfile/50A/29019948.cpp",
      "inputfile/50A/21508887.cpp,inputfile/50A/21508898.cpp",
      "inputfile/50A/21715601.cpp,inputfile/50A/29019948.cpp",
      "inputfile/50A/21715601.cpp,inputfile/50A/21508898.cpp",
      "inputfile/50A/29019948.cpp,inputfile/50A/21508898.cpp"
  };
  
  //read csv to test whether judge is right
  fstream file;
  file.open("./answer/task/50A/equal.csv");
  string answer_str;
  for(int i=0;i<6;i++)
  {
     file>>answer_str;
     bool flag=equal_test.find(answer_str)!=equal_test.end();
     EXPECT_EQ(flag,true);
     equal_test.erase(answer_str);
  }
  EXPECT_EQ(equal_test.size(),0);
  file.close();
};


TEST(testCase0,one_test)
{

   //run
    Judge judge("./inputfile");
    judge.start_factories();
    judge.save_results();


    
    //test one 
    test_for_4A();

     //test for two
    test_for_50A();
}



int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}






