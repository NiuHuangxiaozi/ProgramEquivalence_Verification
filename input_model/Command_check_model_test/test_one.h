/*
=======readme======
//test 1 
	recognize command
*/
#include <string>
#include <iostream>
#include <cstring>
using namespace std;


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
	if (command.substr(0, 5) == "test ")
	{
		int loc=5;
		while(command[loc]==' ')
			loc++;
		command = command.substr(loc, command.length() - loc);
		return test;
	}
	else if (command.substr(0, 4) == "quit")
	{
		return quit;
	}
	else
		return unknown;
}

