
#include <iostream>
#include "FileTable.h"


class JudgeControl
{
private:
	std::string filepath;
	std::string answerfilepath;
	std::string tempfilepath;
	std::vector<std::string> files;
	std::string standardfile;
	FileTable* table;
	//DSU* dsu;
	//Method* method;

	void Init_data();
	void Extract_data();
	//void judge();
	//void save_results();


public:


	JudgeControl(std::string newfilepath,std::string answerpath,std::string temppath)
	{
		filepath = newfilepath;
		answerfilepath=answerpath;
		tempfilepath=temppath;

		Extract_data();
		//dsu = new DSU(files);
		//method = new Sample_Test;
		//method->init(standardfile,files,tempfilepath);
	}


	~JudgeControl()
	{
		//delete dsu;
		delete table;
	}


	void start_judge();
	std::string Get(){return filepath;}


	//only for integrate test 
	FileTable * Get_file_table(){return table;}
};