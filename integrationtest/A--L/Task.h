
#include<vector>
#include<string>
#include<iostream>
#include<dirent.h>
#include<cstring>
#include <sys/stat.h>
#include <sys/types.h>
#include "JudgeControl.h"
#include <thread>

class Judge {


private:
	std::vector<JudgeControl*> factories;
	std::vector<std::string> fordernames;
    	std::vector<std::thread*> thds;
	std::string tempprefix;
	std::string answerfix;
    	std::string sourcefix;
	bool finished;

	void create_environment();//make dir
	void clear_temp_file();

public:
	Judge(std::string sourcepath);
    ~Judge();

	bool is_finished() {
		return finished == true;
	}
	void start_factories();

	void save_results();
};
