#include"JudgeControl.h"





void JudgeControl::start_judge()
{
	Init_data();
	//fliter();
	judge();
	save_results();
}







void JudgeControl::Init_data()
{
	table = new StackFileTable;
	table->init_data(filepath,answerfilepath);
}

void JudgeControl::Extract_data()
{
	DIR *pDir;   //  是头文件<dirent.h>的类型
    struct dirent *ptr;  // opendir、readdir这些都是头文件dirent.h
    if (!(pDir = opendir(filepath.c_str()))) return;

    while ((ptr = readdir(pDir)) != 0)
	 {
        // strcmp是C语言里的，只导入string,然后std::strcmp都是没有的
        if (strcmp(ptr->d_name, ".") != 0 && strcmp(ptr->d_name, "..") != 0)
		 {
			std::string filename=ptr->d_name;
			std::string p;
			p.assign(filepath).append("/").append(filename);
			if (p.substr(p.length() - 4, 4) == ".cpp")
				files.push_back(p);
			else if (p.substr(p.length() - 4, 4) == ".txt")
				standardfile = p;
         }
    }
    closedir(pDir);
}

void JudgeControl::judge()
{
	while (!table->is_empty())
	{
		std::string url1;
		std::string url2;
		table->Get_file_pairs(url1,url2);
		std::cout<<url1<< " "<<url2<<std::endl;
		bool answer;
		if(dsu->isConnected(url1, url2))
		{
			std::cout<<"ss"<<url1<< " "<<url2<<std::endl;
			answer=true;
		}
		else
		{
			answer=method->judge(url1,url2);
			if(answer)
				dsu->unionElements(url1,url2);
		}
		table->Set_answer(url1,url2,answer);

	}
}

void JudgeControl::save_results()
{
	table->save_file_result();
}
