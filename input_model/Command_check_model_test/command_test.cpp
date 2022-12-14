#include <gtest/gtest.h>
using namespace std;
#include "test_one.h"
#include "test_two.h"








TEST(testCase0,init_test){

    //empty input
    string s1="";
    EXPECT_EQ(Command_March(s1),1);

    //test command
    string s2="test ./inputfile/50A/123.cpp";
    EXPECT_EQ(Command_March(s2),test);

    string s3="test   ./inputfile/50A/23123.cpp";
    EXPECT_EQ(Command_March(s3),test);

    //quit command
    string s4="quit";
    EXPECT_EQ(Command_March(s4),quit);

    //unknowncommand
    string s5="assadsadsadsa";
    EXPECT_EQ(Command_March(s5),unknown);

    string s6=" quit";
    EXPECT_EQ(Command_March(s6),unknown);
}




TEST(testCase1,true_wrong_test)
{	
	//right
	EXPECT_EQ(Test_file("./inputfile/50A"),true);

	//other file 
	EXPECT_EQ(Test_file("./inputfile/4A"),false);

	//double or more txt 
	EXPECT_EQ(Test_file("./inputfile/51A"),false);
}



int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
