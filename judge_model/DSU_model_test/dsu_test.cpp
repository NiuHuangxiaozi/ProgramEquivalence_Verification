#include<gtest/gtest.h>
#include "test.h"

std::vector<string> files;

TEST(testCase0,init_test){
    files.push_back("inputfile/50A/142890373.cpp");
    files.push_back("inputfile/50A/45851050.cpp");
    files.push_back("inputfile/50A/138805414.cpp");
    files.push_back("inputfile/50A/30534178.cpp");

    DSU dsu(files);

    //look whether filename map to index is right
    EXPECT_EQ(dsu.path_to_index["inputfile/50A/142890373.cpp"],0);
    EXPECT_EQ(dsu.path_to_index["inputfile/50A/138805414.cpp"],2);

    //check file numbers
    EXPECT_EQ(dsu.path_to_index.size(),4);
};

TEST(testCase1,connected_test)
{
    //1
    //add four 
    files.push_back("inputfile/50A/142890373.cpp");
    files.push_back("inputfile/50A/45851050.cpp");
    files.push_back("inputfile/50A/138805414.cpp");
    files.push_back("inputfile/50A/30534178.cpp");
    DSU dsu2(files);
    bool flag1=dsu2.isConnected("inputfile/50A/142890373.cpp","inputfile/50A/45851050.cpp");
    bool flag2=dsu2.isConnected("inputfile/50A/142890373.cpp","inputfile/50A/30534178.cpp");
  
    EXPECT_EQ(flag1,false);
    EXPECT_EQ(flag2,false);
    dsu2.unionElements("inputfile/50A/142890373.cpp","inputfile/50A/30534178.cpp");
    bool flag3=dsu2.isConnected("inputfile/50A/142890373.cpp","inputfile/50A/30534178.cpp");
    EXPECT_EQ(flag3,true);
};

//flowing test use branchcoverage

/*
we should assign samples to cover any Determine statements.
*/

/*
 test function void unionElements(std::string s1, std::string s2) in DSU
*/

TEST(testCase2,rank_test_one)
{
    //add 5 files
    files.push_back("inputfile/50A/142890373.cpp");//zero
    files.push_back("inputfile/50A/45851050.cpp");//one
    files.push_back("inputfile/50A/138805414.cpp");//two
    files.push_back("inputfile/50A/30534178.cpp");//three
    files.push_back("inputfile/50A/1111111111.cpp");//four
    files.push_back("inputfile/50A/2222222222.cpp");//five
    DSU dsu3(files);

    // zero connect one
    // cover else { // rank[pRoot] == rank[qRoot]
    dsu3.unionElements("inputfile/50A/142890373.cpp","inputfile/50A/45851050.cpp");
    
    // two connect three
    // cover else { // rank[pRoot] == rank[qRoot]
    dsu3.unionElements("inputfile/50A/138805414.cpp","inputfile/50A/30534178.cpp");

   // four connect three
   //cover if (rank[pRoot] < rank[qRoot])
    dsu3.unionElements("inputfile/50A/1111111111.cpp","inputfile/50A/30534178.cpp");

   // three connect five
   //cover  else if (rank[qRoot] < rank[pRoot])
    dsu3.unionElements("inputfile/50A/30534178.cpp","inputfile/50A/2222222222.cpp");
   

    // 1 and 3 not connected
    EXPECT_EQ(dsu3.isConnected("inputfile/50A/45851050.cpp","inputfile/50A/30534178.cpp"),false);

    //3 and 4 connected
    EXPECT_EQ(dsu3.isConnected("inputfile/50A/30534178.cpp","inputfile/50A/1111111111.cpp"),true);

    //2 and 5 connected
    EXPECT_EQ(dsu3.isConnected("inputfile/50A/138805414.cpp","inputfile/50A/2222222222.cpp"),true);

}
int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}