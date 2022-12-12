#include <gtest/gtest.h>
#include "./test.h"
using namespace std;
#include <string>

//whether is a right character
bool is_character(char s)
{
  return (s>='a'&&s<='z')||(s>='A'&&s<='Z');
}
//whether is a right int
bool is_right_int(int val,int low,int high)
{
  return val<=high && val>=low;
}
//whether is a right str
bool is_right_str(std::string val,int low,int high)
{
    for(int i=0;i<val.size();i++)
    {
        if(!is_character(val[i]))
              return false;
    }
    return val.size()<=high &&val.size()>=low;
}

//test 0
//test for parameter input 
TEST(testCase0,parameter_test)
{
    std::string  s ="./inputfile/4A/stdin_format.txt";
    vector<std::string> files{
      "./inputfile/4A/48762087.cpp",
      "./inputfile/4A/127473352.cpp",
      "./inputfile/4A/134841308.cpp",
      "./inputfile/4A/173077807.cpp"
    };

    Sample_Test * pt=new Sample_Test();
    pt->init(s,files,"./mytemp/4A");

    for(int i=0;i<pt->vals.size();i++)
    {
      if(i==0)
      {
        EXPECT_EQ(pt->vals[i].Get_type(),"int");
        EXPECT_EQ(pt->vals[i].Get_lowint(),1);
        EXPECT_EQ(pt->vals[i].Get_highint(),100);
      }
      

      else if(i==1)
      {
        EXPECT_EQ(pt->vals[i].Get_type(),"char");
        char s=pt->vals[i].inputtype[0];
        EXPECT_PRED1(is_character,s);
      }
      else if(i==2)
      {
        EXPECT_EQ(pt->vals[i].Get_type(),"int");
        EXPECT_EQ(pt->vals[i].Get_lowint(),1);
        EXPECT_EQ(pt->vals[i].Get_highint(),2);
      }
      else if(i==3)
      {
        EXPECT_EQ(pt->vals[i].Get_type(),"string");
        EXPECT_EQ(pt->vals[i].Get_lowint(),2);
        EXPECT_EQ(pt->vals[i].Get_highint(),3);
        for(int j=0;j<pt->vals[i].inputtype.size();j++)
        {
          char s=pt->vals[i].inputtype.c_str()[j];
          EXPECT_PRED1(is_character,s);
        }
      }
    }


    //test 2 
    //create the parameter
    //output the parameter
  
	};


TEST(testCase1,random_values_test)
{
    //init class
    std::string  s ="./inputfile/4A/stdin_format.txt";
    vector<std::string> files{
      "./inputfile/4A/48762087.cpp",
      "./inputfile/4A/127473352.cpp",
      "./inputfile/4A/134841308.cpp",
      "./inputfile/4A/173077807.cpp"
    };

    Sample_Test * pt=new Sample_Test();
    pt->init(s,files,"./mytemp");
   
    char s1=pt->random_char();
    int low1=3;int high1=7;
    int number1=pt->random_int(low1,high1);
    string str1=pt->random_string(low1,high1);

    char s2=pt->random_char();
    int low2=1;int high2=9;
    int number2=pt->random_int(low2,high2);
    string str2=pt->random_string(low2,high2);



    //test assertion
    EXPECT_PRED1(is_character,s1);
    EXPECT_PRED1(is_character,s2);

    EXPECT_PRED3(is_right_int,number1,low1,high1);
    EXPECT_PRED3(is_right_int,number2,low2,high2);

    EXPECT_PRED3(is_right_str,str1,low1,high1);
    EXPECT_PRED3(is_right_str,str2,low2,high2);
};




TEST(testCase2,Compare_result_test)
{
    std::string  s3 ="./inputfile/4A/stdin_format.txt";
    vector<std::string> files3{
      "./inputfile/4A/48762087.cpp",
      "./inputfile/4A/127473352.cpp",
      "./inputfile/4A/134841308.cpp",
      "./inputfile/4A/173077807.cpp"
    };

    Sample_Test * pt3=new Sample_Test();
    pt3->init(s3,files3,"./mytemp/4A");

    //either one or the other  code is wrong
    EXPECT_EQ(pt3->compare_test_result(0,1),false);
    EXPECT_EQ(pt3->compare_test_result(1,0),false);

    //normal comapre compare two file output1.txt and output2.txt
    //test one
    //check if(ans1.size()!=ans2.size())
    std::fstream File;
	  File.open("./mytemp/4A/output1.txt", std::ios::out|std::ios::trunc);
    File<<23;
    File<<" ";
    File<<"name";
    File.close();

	  File.open("./mytemp/4A/output2.txt", std::ios::out|std::ios::trunc);
    File<<23;
    File<<" ";
    File<<"names";
    File.close();

    EXPECT_EQ(pt3->compare_test_result(0,0),false);

    //test two
    //check main branch
	  File.open("./mytemp/4A/output1.txt", std::ios::out|std::ios::trunc);
    File<<2334;
    File<<"&&";
    File<<"beijing";
    File.close();

	  File.open("./mytemp/4A/output2.txt", std::ios::out|std::ios::trunc);
    File<<2334;
    File<<"&&";
    File<<"beijing";
    File.close();
    EXPECT_EQ(pt3->compare_test_result(0,0),true);

    //test three
    //check if(ans1[i]!=ans2[i])
	  File.open("./mytemp/4A/output1.txt", std::ios::out|std::ios::trunc);
    File<<2334;
    File<<"&*";
    File<<"beijing";
    File.close();

	  File.open("./mytemp/4A/output2.txt", std::ios::out|std::ios::trunc);
    File<<2334;
    File<<"&&";
    File<<"nanjing";
    File.close();
    EXPECT_EQ(pt3->compare_test_result(0,0),false);

}

TEST(testCase3,load_Executablefile_test)
{
    std::string  s4 ="./inputfile/50A/stdin_format.txt";
    vector<std::string> files4{
      "./inputfile/50A/138805414.cpp",
      "./inputfile/50A/142890373.cpp",
      "./inputfile/50A/164831265.cpp",
    };
    Sample_Test * pt4=new Sample_Test();
    pt4->init(s4,files4,"./mytemp/50A");
    pt4->init_exe_file(files4);

    bool test1=pt4->judge("./inputfile/50A/138805414.cpp","./inputfile/50A/142890373.cpp");
    EXPECT_EQ(test1,false);

    bool test2=pt4->judge("./inputfile/50A/138805414.cpp","./inputfile/50A/164831265.cpp");
    EXPECT_EQ(test2,true);

    bool test3=pt4->judge("./inputfile/50A/142890373.cpp", "./inputfile/50A/164831265.cpp");
    EXPECT_EQ(test3,false);

};





int main(int argc,char **argv){

  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}