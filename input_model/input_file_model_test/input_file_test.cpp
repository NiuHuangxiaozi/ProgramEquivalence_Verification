#include<gtest/gtest.h>
#include <vector>
#include "test.h"
using namespace std;




/*
 ========readme==========
(1) very easy so use StatementCoverage.
(2) test judge class, test Judge::Judge().
(3) see whether subdir can be read into vector
*/


Judge judge("./inputfile");

TEST(testCase0,filenames_test){
    //1
    std::vector<std::string> filesname=judge.get_filenames();
    std::vector<std::string> filesnamestandard={"50A","4A"};
    ASSERT_EQ(filesname.size(),filesnamestandard.size());
    for(int i=0;i<filesnamestandard.size();i++)
        EXPECT_EQ(filesname[i],filesnamestandard[i]);
}

TEST(testCase1,status_test){
 	//2
    EXPECT_EQ(judge.is_finished(),false); 
}

TEST(testCase1,filepath_test){
    //3
    EXPECT_EQ(judge.get_sourcefix(),"./inputfile/"); 
	EXPECT_EQ(judge.get_tempprefix(),"./temp/task/"); 
	EXPECT_EQ(judge.get_answerfix(),"./answer/task/"); 
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}