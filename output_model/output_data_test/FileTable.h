#include<iostream>
#include "file.h"
#include <vector>
#include<stack>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
class FileTable
{
public:
	virtual void Get_file_pairs(std::string& s1, std::string& s2) {};
	virtual void Add_file_pairs(std::string& s1, std::string& s2) {};
	virtual bool is_empty() {return true;};
	virtual void save_file_result() {};
	virtual void init_data(std::string s,std::string answerfile) {};
	virtual void Set_answer(std::string& s1, std::string& s2,bool answer){};

};
class StackFileTable:public FileTable
{
	
private:
	std::stack<File> inputfile;
	std::stack<File> outputfile;
	std::string answerfile;
public:
	//void Get_file_pairs(std::string &s1,std::string &s2);
	//void Add_file_pairs(std::string& s1, std::string& s2);
	//bool is_empty();
	void save_file_result();
	//void init_data(std::string s,std::string answerfile);
	void Set_answer(std::string& s1, std::string& s2,bool answer);

	void Set_answerfile(std::string s){answerfile=s;}

};