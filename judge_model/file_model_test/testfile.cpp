#include "file.h"
#include<gtest/gtest.h>
#include <vector>
using namespace std;

File f1("inputfile/50A/123.cpp","inputfile/50A/234.cpp");
vector<std::string>answer=f1.Getpair();

TEST(testCase,set_is_right){
    f1.set_result(true);
    EXPECT_EQ(f1.Get_result(),true);
}

TEST(testCase,init){
    EXPECT_EQ(answer[1],"inputfile/50A/234.cpp");
    EXPECT_EQ(answer[0],"inputfile/50A/234.cpp");
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
