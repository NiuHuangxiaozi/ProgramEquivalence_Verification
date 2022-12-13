

#include <iostream>
#include <fstream>
#include <string>
#include "thread"
#include "Task.h"

class CentralControl
{
	enum command_error
	{
		empty=1,
		unknown=2,
		test=3,
		quit=4
	};
private:
	std::string command;

	Judge *task;


	void delete_task();
	void Add_task(std::string command);
	bool Test_file(std::string command);
	bool Test_dir(std::string command);
public:
	CentralControl();
	void start();
	int Command_March(std::string &command);
	void Deal_With_Command(int flag,std::string command);



	//outer move program
	void test_start(std::string s){
		int flag=Command_March(s);
		if (flag == quit)
			return;
		Deal_With_Command(flag,s);
	}
    std::vector<JudgeControl*> get_task_files()
	{
		std::cout<<"7"<<std::endl;
        return task->get_factories();
	}

};
