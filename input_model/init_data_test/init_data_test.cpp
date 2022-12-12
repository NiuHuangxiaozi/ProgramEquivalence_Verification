#include<gtest/gtest.h>
#include "test.h"
#include <string>
using namespace std;



//test whether data put into the stack 
TEST(testCase0,init_test)
{
   //init data 
   string answerpath="./answer/task/50A";
   StackFileTable pt;
   pt.init_data("inputfile/50A",answerpath);

   //
   std::vector<string> files={
    "inputfile/50A/138805414.cpp",
    "inputfile/50A/142890373.cpp",
    "inputfile/50A/164831265.cpp",
   };

   ASSERT_EQ((files.size()*(files.size()-1))/2,pt.inputfile.size());

   std::string s1;std::string s2;
   std::string url1="inputfile/50A/164831265.cpp";
   std::string url2="inputfile/50A/138805414.cpp";
   std::string url3="inputfile/50A/142890373.cpp";
   std::string url4="inputfile/50A/138805414.cpp";
   std::string url5="inputfile/50A/142890373.cpp";
   std::string url6="inputfile/50A/164831265.cpp";
    pt.Get_file_pairs(s1,s2);
    EXPECT_EQ(s1,url1);
    EXPECT_EQ(s2,url2);

    pt.Get_file_pairs(s1,s2);
    EXPECT_EQ(s1,url3);
    EXPECT_EQ(s2,url4);

    pt.Get_file_pairs(s1,s2);
    EXPECT_EQ(s1,url5);
    EXPECT_EQ(s2,url6);

}

int main(int argc,char **argv){

  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}