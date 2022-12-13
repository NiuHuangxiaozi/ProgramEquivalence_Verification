#include <gtest/gtest.h>
#include "CentralControl.h"
#include<set>
using namespace std;



void test_for_4A(CentralControl *my_equminer)
{
//test for 4A
    set<vector<string>> test_file_group;
    test_file_group.insert({"./inputfile/4A/48762087.cpp","./inputfile/4A/84822638.cpp"});
    test_file_group.insert({"./inputfile/4A/48762087.cpp","./inputfile/4A/84822639.cpp"});
    test_file_group.insert({"./inputfile/4A/48762087.cpp","./inputfile/4A/101036360.cpp"});
    test_file_group.insert({"./inputfile/4A/48762087.cpp","./inputfile/4A/117364748.cpp"});
    test_file_group.insert({"./inputfile/4A/84822638.cpp","./inputfile/4A/84822639.cpp"});
    test_file_group.insert({"./inputfile/4A/84822638.cpp","./inputfile/4A/101036360.cpp"});
    test_file_group.insert({"./inputfile/4A/84822638.cpp","./inputfile/4A/117364748.cpp"});
    test_file_group.insert({"./inputfile/4A/84822639.cpp","./inputfile/4A/101036360.cpp"});
    test_file_group.insert({"./inputfile/4A/84822639.cpp","./inputfile/4A/117364748.cpp"});
    test_file_group.insert({"./inputfile/4A/101036360.cpp","./inputfile/4A/117364748.cpp"});
    
    test_file_group.insert({"./inputfile/4A/84822638.cpp","./inputfile/4A/48762087.cpp"});
    test_file_group.insert({"./inputfile/4A/84822639.cpp","./inputfile/4A/48762087.cpp"});
    test_file_group.insert({"./inputfile/4A/101036360.cpp","./inputfile/4A/48762087.cpp"});
    test_file_group.insert({"./inputfile/4A/117364748.cpp","./inputfile/4A/48762087.cpp"});
    test_file_group.insert({"./inputfile/4A/84822639.cpp","./inputfile/4A/84822638.cpp"});
    test_file_group.insert({"./inputfile/4A/101036360.cpp","./inputfile/4A/84822638.cpp"});
    test_file_group.insert({"./inputfile/4A/117364748.cpp","./inputfile/4A/84822638.cpp"});
    test_file_group.insert({"./inputfile/4A/101036360.cpp","./inputfile/4A/84822639.cpp"});
    test_file_group.insert({"./inputfile/4A/117364748.cpp","./inputfile/4A/84822639.cpp"});
    test_file_group.insert({"./inputfile/4A/117364748.cpp","./inputfile/4A/101036360.cpp"});
    std::vector<JudgeControl*> test_judge_model=my_equminer->get_task_files();
    FileTable * pt1=test_judge_model[1]->Get_file_table();
    string url1; string url2;
    while (!pt1->is_empty())
    
    {
        pt1->Get_file_pairs(url1,url2);
        bool flag=(test_file_group.find({url1,url2})!=test_file_group.end())||
                  (test_file_group.find({url2,url1})!=test_file_group.end());
        EXPECT_EQ(flag,true);
        test_file_group.erase({url1,url2});
        test_file_group.erase({url2,url1});
    }
    EXPECT_EQ(test_file_group.size(),0);

}
void test_for_50A(CentralControl *my_equminer)
{
    //test for 50A
    set<vector<string>> test_file_group1;
    test_file_group1.insert({"./inputfile/50A/21508887.cpp","./inputfile/50A/21508898.cpp"});
    test_file_group1.insert({"./inputfile/50A/21508887.cpp","./inputfile/50A/21715601.cpp"});
    test_file_group1.insert({"./inputfile/50A/21508887.cpp","./inputfile/50A/29019948.cpp"});
    test_file_group1.insert({"./inputfile/50A/21508898.cpp","./inputfile/50A/21715601.cpp"});
    test_file_group1.insert({"./inputfile/50A/21508898.cpp","./inputfile/50A/29019948.cpp"});
    test_file_group1.insert({"./inputfile/50A/21715601.cpp","./inputfile/50A/29019948.cpp"});

    
    test_file_group1.insert({"./inputfile/50A/21508898.cpp","./inputfile/50A/21508887.cpp"});
    test_file_group1.insert({"./inputfile/50A/21715601.cpp","./inputfile/50A/21508887.cpp"});
    test_file_group1.insert({"./inputfile/50A/29019948.cpp","./inputfile/50A/21508887.cpp"});
    test_file_group1.insert({"./inputfile/50A/21715601.cpp","./inputfile/50A/21508898.cpp"});
    test_file_group1.insert({"./inputfile/50A/29019948.cpp","./inputfile/50A/21508898.cpp"});
    test_file_group1.insert({"./inputfile/50A/29019948.cpp","./inputfile/50A/21715601.cpp"});
    
    std::vector<JudgeControl*> test_judge_model1=my_equminer->get_task_files();
    FileTable * pt2=test_judge_model1[0]->Get_file_table();
    string url1; string url2;
    while (!pt2->is_empty())
    {
        pt2->Get_file_pairs(url1,url2);
        bool flag=(test_file_group1.find({url1,url2})!=test_file_group1.end())||
                  (test_file_group1.find({url2,url1})!=test_file_group1.end());
        EXPECT_EQ(flag,true);
        test_file_group1.erase({url1,url2});
        test_file_group1.erase({url2,url1});
    }
    EXPECT_EQ(test_file_group1.size(),0);

}

//test  
TEST(testCase0,one_test)
{
    //run 
    CentralControl * my_equminer=new CentralControl();
	my_equminer->test_start("test ./inputfile");

    //one test
    test_for_4A(my_equminer);

    //two test
    test_for_50A(my_equminer);
}




int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
