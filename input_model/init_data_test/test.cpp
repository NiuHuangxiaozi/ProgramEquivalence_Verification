
#include "test.h"


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
