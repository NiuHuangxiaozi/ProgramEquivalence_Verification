#include<gtest/gtest.h>
#include "CentralControl.h"
#include <string>
using namespace std;



void test()
{

 std::set<std::string> equal_test={
      "inputfile/50A/21508887.cpp,inputfile/50A/21715601.cpp",
      "inputfile/50A/21508887.cpp,inputfile/50A/29019948.cpp",
      "inputfile/50A/21508887.cpp,inputfile/50A/21508898.cpp",
      "inputfile/50A/21715601.cpp,inputfile/50A/29019948.cpp",
      "inputfile/50A/21715601.cpp,inputfile/50A/21508898.cpp",
      "inputfile/50A/29019948.cpp,inputfile/50A/21508898.cpp",
      "inputfile/4A/84822639.cpp,inputfile/4A/84822638.cpp"
  };

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

  //equal
  fstream file;
  file.open("./inputfile/equal.csv");
  string answer_str;
  file>>answer_str;
  for(int i=0;i<7;i++)
  {
     file>>answer_str;
     bool flag=equal_test.find(answer_str)!=equal_test.end();
     ASSERT_EQ(flag,true);
     equal_test.erase(answer_str);
  }
  file.close();
  ASSERT_EQ(equal_test.size(),0);


  //inequal
  file.open("./inputfile/inequal.csv");
  file>>answer_str;
  for(int i=0;i<9;i++)
  {
     file>>answer_str;
     bool flag=inequal_test.find(answer_str)!=inequal_test.end();
     ASSERT_EQ(flag,true);
     inequal_test.erase(answer_str);
  }
  file.close();
  ASSERT_EQ(inequal_test.size(),0);
};




TEST(testCase0,one_test)
{

   //run
    CentralControl my_equminer;
	  my_equminer.DeviceDriver_Test("test ./inputfile");

    //merge two test into
    test();

}

//SCENE SHOW IS EASY just command output 
//so test here not unit test
//just print out and see

TEST(testCase1,one_test)
{
    CentralControl my_equminer;
    my_equminer.DeviceDriver_Scene_Test();
}


int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
