#include <dirent.h>
using namespace std;
#include<string>
#include<vector>
#include<string.h>
class Judge {
private:
	std::vector<std::string> fordernames;
	std::string tempprefix;
	std::string answerfix;
  	std::string sourcefix;
	bool finished;
public:

	Judge(std::string sourcepath);

	bool is_finished() {
		return finished == true;
	}
	std::string get_tempprefix(){return tempprefix;}

	std::string get_answerfix(){return answerfix;}

	std::string get_sourcefix(){return sourcefix;}

	std::vector<std::string> get_filenames(){return fordernames;}
	
	bool get_finished(){return finished;}



};

//judge
Judge::Judge(std::string sourcepath)
{
    //0
    sourcefix=sourcepath+"/";

    //1
	std::string task = "task/";
	tempprefix = "./temp/" + task;
	answerfix = "./answer/" + task;
	finished = false;

    //2
	DIR* pDir;   //  是头文件<dirent.h>的类型
	struct dirent* ptr;  // opendir、readdir这些都是头文件dirent.h
	if (!(pDir = opendir(sourcepath.c_str()))) return;

	while ((ptr = readdir(pDir)) != 0)
	{
		if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
		{
			std::string filename = ptr->d_name;
            fordernames.push_back(filename);
		}
	}
	closedir(pDir);

}