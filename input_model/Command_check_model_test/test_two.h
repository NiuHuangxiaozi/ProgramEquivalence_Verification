
/*

====raedme=====
//test whether input file is right

*/
#include <dirent.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;



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
