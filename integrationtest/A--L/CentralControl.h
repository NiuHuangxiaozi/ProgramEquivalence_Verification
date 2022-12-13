

#include <iostream>
#include <fstream>
#include <string>
#include "thread"
#include "IO_View.h"
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
	IO_View Io_control;

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



	//only for test 
	void DeviceDriver_Test(std::string command)
	{
		int flag=Command_March(command);
		Deal_With_Command(flag,command);
	}
	void DeviceDriver_Scene_Test()
	{
		Io_control.Show_Begin_Scene();
		Io_control.Show_Commend_Line_Scene();
		Io_control.Show_Unknown_Scene();
	}

};
