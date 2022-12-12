#include <gtest/gtest.h>
using namespace std;





/*
=======readme======
//test 1 
	recognize command
*/
enum command_error
	{
		myempty=1,
		unknown=2,
		test=3,
		quit=4
	};

int Command_March(std::string &command)
{
	if (command == "")
	{
		return myempty;
	}
	std::string test_order = command.substr(0, 5);
	std::string quit_order= command.substr(0, 4);
	if (test_order == "test ")
	{
		int loc=5;
		while(command[loc]==' ')
			loc++;
		command = command.substr(loc, command.length() - loc);
		return test;
	}
	else if (quit_order == "quit")
	{
		return quit;
	}
	else
		return unknown;
}


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


/*

====raedme=====
//test whether input file is right

*/
#include <dirent.h>

bool Test_file(std::string command)
{

	DIR* pDir;   //  是头文件<dirent.h>的类型
	struct dirent* ptr;  // opendir、readdir这些都是头文件dirent.h
	if (!(pDir = opendir(command.c_str())))
	{
		std::cout<<command+" Error:Dir not exist!"<<std::endl;
		return false;
	}
	int time=0;
	bool answer=true;
	while ((ptr = readdir(pDir)) != 0)
	{
		if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
		{
			std::string filename = ptr->d_name;
			if(filename.size()<5)
			{
				std::cout<<"unexpected file."+command+"/"+filename<<std::endl;
			}
			else if(filename.substr(filename.size()-4,4)==".cpp")
				continue;
			else if (filename.substr(filename.size()-4,4)==".txt")
			{
				time++;
				if(time==2)
				{
					std::cout<<"two or more txt file."<<std::endl;
					answer=false;
					break;
				}
			}
			else
			{
					std::cout<<"Erroe: unexpected file."+command+"/"+filename<<std::endl;
					answer=false;
					break;
			}
            
		}
	}
	closedir(pDir);
	return answer;
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