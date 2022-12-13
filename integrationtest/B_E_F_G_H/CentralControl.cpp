#include"CentralControl.h"

#define MAX_TASK_NUM 10

CentralControl::CentralControl()
{

	command = "";
	task=nullptr;

	
}

void CentralControl::delete_task()
{
	delete task;
	task=nullptr;
}
void CentralControl::start()
{
	//Io_control.Show_Begin_Scene();

	while (true)
	{
		//Io_control.Show_Commend_Line_Scene();
		getline(std::cin,command);
		int flag=Command_March(command);
		if (flag == quit)
			break;
		Deal_With_Command(flag,command);

		break;
	}
}
int CentralControl::Command_March(std::string &command)
{
	if (command == "")
	{
		return empty;
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

void CentralControl::Deal_With_Command(int flag, std::string command)
{

	switch (flag)
	{
		case test:
			if(Test_dir(command))
				Add_task(command);
			break;
		case unknown:
			//Io_control.Show_Unknown_Scene();
			break;
		case empty:
		default:break;
	}
}



void  CentralControl::Add_task(std::string command)
{

	task=new Judge(command);
	std::cout<<"start factory"<<std::endl;
	task->start_factories();
	//task->save_results();
	//delete_task();
}

bool CentralControl::Test_dir(std::string command)
{
	DIR* pDir;   //  是头文件<dirent.h>的类型
	struct dirent* ptr;  // opendir、readdir这些都是头文件dirent.h
	if (!(pDir = opendir(command.c_str())))
	{
		std::cout<<command+" Error:Dir not exist!"<<std::endl;
		return false;
	}
	bool answer=true;
	while ((ptr = readdir(pDir)) != 0)
	{
		if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
		{
			std::string filename=ptr->d_name;
			bool flag=Test_file(command+"/"+filename);
			if(!flag)
				return false;
		}
	}
	closedir(pDir);
	return true;
}
bool CentralControl::Test_file(std::string command)
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