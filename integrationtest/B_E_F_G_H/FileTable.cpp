
#include "FileTable.h"


void StackFileTable::Get_file_pairs(std::string& s1, std::string& s2)
{
	s1 = inputfile.top().Getpair()[0];
	s2 = inputfile.top().Getpair()[1];
	inputfile.pop();
}
void StackFileTable::Add_file_pairs(std::string& s1, std::string& s2)
{
	File* tempfile = new File(s1, s2);
	inputfile.push(*tempfile);

}
bool StackFileTable::is_empty()
{
	return inputfile.empty();
}
void StackFileTable::Set_answer(std::string& s1, std::string& s2,bool answer)
{
	File* tempfile = new File(s1, s2);
	tempfile->set_result(answer);
	outputfile.push(*tempfile);
}
void StackFileTable::init_data(std::string s,std::string answer)
{

	//1
	answerfile=answer;
	//2
	std::string path = s;
	DIR *pDir;   //  是头文件<dirent.h>的类型
    struct dirent *ptr;  // opendir、readdir这些都是头文件dirent.h
	std::vector<std::string>filesvec;
    if (!(pDir = opendir(path.c_str()))) return;
    while ((ptr = readdir(pDir)) != 0) {
        // strcmp是C语言里的，只导入string,然后std::strcmp都是没有的
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0) {
			std::string filename=ptr->d_name;
			if(filename.substr(filename.length()-4,4)!=".txt")
            	filesvec.push_back(path + "/" + ptr->d_name);  // 可以只保留名字
        }
    }
    closedir(pDir);
	for (int i = 0; i < filesvec.size(); i++)
	{
		for (int j = i + 1; j < filesvec.size(); j++)
		{
			Add_file_pairs(filesvec[i], filesvec[j]);
		}
	}
}

std::string turn_to_erlativepath(std::string s)
{
	int times=3;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='/'&& times==1)
		{
			return s.substr(i+1,s.size()-i);
		}
		else if(s[i]=='/')
		  times--;
	}
	return "";
}
void StackFileTable::save_file_result()
{

	// 向csv文档中写入数据
    std::ofstream dataFile_eq;
	dataFile_eq.open(answerfile+"/equal.csv", std::ios::out | std::ios::trunc);
	
	std::ofstream dataFile_uneq;
	dataFile_uneq.open(answerfile+"/inequal.csv", std::ios::out | std::ios::trunc);
	
	while (!outputfile.empty())
	{
		std::string url1=turn_to_erlativepath(outputfile.top().Getpair()[0]);
		std::string url2=turn_to_erlativepath(outputfile.top().Getpair()[1]);
		bool state=outputfile.top().Get_result();
		if(state)
			dataFile_eq <<url1<<","<<url2<<std::endl;
		else
			dataFile_uneq <<url1<<","<<url2<<std::endl;
		outputfile.pop();
	}	
	dataFile_eq.close(); 
	dataFile_uneq.close();
}