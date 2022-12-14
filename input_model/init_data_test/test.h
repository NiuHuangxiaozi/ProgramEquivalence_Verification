#include<iostream>
#include "file.h"
#include <vector>
#include<stack>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include <fstream>
class StackFileTable
{
	
public:
	std::stack<File> inputfile;
	std::stack<File> outputfile;
	std::string answerfile;
public:
	void Get_file_pairs(std::string &s1,std::string &s2);
	void Add_file_pairs(std::string& s1, std::string& s2);
	void init_data(std::string s,std::string answerfile);
};
