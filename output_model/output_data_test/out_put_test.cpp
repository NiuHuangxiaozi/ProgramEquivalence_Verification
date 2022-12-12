
#include <gtest/gtest.h>
#include "FileTable.h"
#include <fstream>
using namespace std;


TEST(testCase0,out_put_result)
{
    //test data 1
   //save data
   StackFileTable table;
   std::string url1="./inputfile/50A/11111111.cpp";
   std::string url2="./inputfile/50A/22222222.cpp";
   std::string url3="./inputfile/50A/33333333.cpp";
   std::string url4="./inputfile/50A/44444444.cpp";
   table.Set_answer(url1,url2,true);
   table.Set_answer(url1,url3,false);
   table.Set_answer(url1,url4,false);
   table.Set_answer(url2,url3,false);
   table.Set_answer(url2,url4,false);
   table.Set_answer(url3,url4,false);
   table.Set_answerfile("./answer/50A");
   table.save_file_result();


   //test data 2
   //read and cover 
   std::string test_url1="inputfile/50A/11111111.cpp";
   std::string test_url2="inputfile/50A/22222222.cpp";
   std::string test_url3="inputfile/50A/33333333.cpp";
   std::string test_url4="inputfile/50A/44444444.cpp";
   string test_str;
   fstream file;
   file.open("./answer/50A/equal.csv");
   file>>test_str;   
   EXPECT_EQ(test_str,test_url1+","+test_url2);
   file.close();

   file.open("./answer/50A/inequal.csv");
   file>>test_str;   
   EXPECT_EQ(test_str,test_url3+","+test_url4);
   
   file>>test_str;   
   EXPECT_EQ(test_str,test_url2+","+test_url4);

   file>>test_str;   
   EXPECT_EQ(test_str,test_url2+","+test_url3);

   file>>test_str;   
   EXPECT_EQ(test_str,test_url1+","+test_url4);

   file>>test_str;   
   EXPECT_EQ(test_str,test_url1+","+test_url3);

   file.close();


}


int main(int argc,char **argv){

  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}