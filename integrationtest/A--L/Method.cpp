
#include "Method.h"

void Sample_Test::init(std::string s,std::vector<std::string>&files,\
					std::string tempfile)
{

	


	//0
	judge_epoch = 25;
	time_adjust=0;
	inputfile = tempfile+"/input.txt";
	outputfile_1 = tempfile+"/output1.txt";
	outputfile_2 = tempfile+"/output2.txt";
	exe_files=tempfile+"/program";

	//1
	init_exe_file(files);

	//2、
	std::fstream myfile(s);
	std::string inputtype;
	while (myfile.peek() != EOF) {
		myfile>> inputtype;
		add_vals(inputtype);
		std::cout << inputtype << "\n";

	}


	//3、
	std::fstream File;
	File.open(inputfile, std::ios::out | std::ios::trunc);
	File.close();
	File.open(outputfile_1, std::ios::out | std::ios::trunc);
	File.close();
	File.open(outputfile_2, std::ios::out | std::ios::trunc);
	File.close();
}
void Sample_Test::init_exe_file(std::vector<std::string>& files)
{
	//1、
	tempfiles.resize(files.size(),"");
	compile_error.resize(files.size(),0);

	for(int i=0;i<files.size();i++)
	{
		std::string exe_label=exe_files+std::to_string(i);
		std::string command1 = "g++ -w "+ files[i]+ " -o " + exe_label;
		compile_error[i]=system(command1.c_str());
		tempfiles[i]=exe_label;
		filename_to_index[files[i]]=i;
	}
	
}
void Sample_Test::add_vals(std::string s)
{
	if (s.substr(0, 3) == "int")
	{
		std::string int_pair = s.substr(4, s.length() - 4);
		int loc = 0;
		while (int_pair[loc] != ',')
			loc++;
		int num1 = std::atoi(int_pair.substr(0, loc).c_str());
		int num2=  std::atoi(int_pair.substr(loc+1, int_pair.length()-loc-1).c_str());
		Val temp(s.substr(0, 3), num1, num2);
		vals.push_back(temp);
	}
	else if (s.substr(0, 4) == "char")
	{
		Val temp(s.substr(0, 4), 0, 0);
		vals.push_back(temp);
	}
	else if (s.substr(0, 6) == "string")
	{
		Val temp(s.substr(0, 6), 0, 0);
		vals.push_back(temp);
	}
}
bool Sample_Test::judge(std::string s1, std::string s2)
{
	int label1=filename_to_index[s1];
	int label2=filename_to_index[s2];
	if(compile_error[label1]|compile_error[label2])
		return false;	

	std::string redirect1 = tempfiles[label1] + "  <" + inputfile + "   >" + outputfile_1+" 2>&1";
	std::string redirect2 = tempfiles[label2] + "  <" + inputfile + "   >" + outputfile_2+" 2>&1";
	
	
	
	for (int i = 0; i < judge_epoch; i++)
	{
		create_test_data();
		int code_one_error2=system(redirect1.c_str());
		int code_two_error2=system(redirect2.c_str());
		bool is_equal=compare_test_result(code_one_error2,code_two_error2);
		if (!is_equal)
			return false;
	}


	return true;
}

void Sample_Test::create_test_data()
{

	std::fstream File;
	File.open(inputfile, std::ios::out | std::ios::trunc);
	for (int i = 0; i < vals.size(); i++)
	{
		std::string type = vals[i].Get_type();
		if (type == "int")
		{
		 int m = random_int(vals[i].Get_lowint(),vals[i].Get_highint());
		 File << m<<" ";

		}
		else if (type == "char")
		{
			char c= random_char();
			File<<c<<" ";
		}
		else if (type == "string")
		{
			std::string s= random_string(vals[i].Get_lowint(), vals[i].Get_highint());
			File << s << " ";
		}
	}
	File.close();
}

bool Sample_Test::compare_test_result(int one_err_2,int two_err_2)
{
	if(one_err_2!=0)
		return false;
	else if(two_err_2!=0)
		return false;
	else
	{
		std::fstream  File1;
		std::fstream  File2;
		File1.open(outputfile_1,std::ios::in);
		File2.open(outputfile_2,std::ios::in);
		std::string ans1;
		std::string ans2;

		while (File1.peek() != EOF)
			File1>> ans1;
		while (File2.peek() != EOF)
			File2>> ans2;

		if(ans1.size()!=ans2.size())
		{
			File1.close();
			File2.close();
			return false;
		}
			
		for(int i=0;i<ans1.size();i++)
		{
			if(ans1[i]!=ans2[i])
			{
				File1.close();
				File2.close();
				return false;
			}
		}
		File1.close();
		File2.close();
		return true;
	}
}






char Sample_Test::random_char()
{
	//1、
	srand((int)time(0)+time_adjust);
	int lowcharacter = rand() % 26 + 97;
	int highcharacter = (rand()+7) % 26 + 65;
	//2、
	srand((int)time(0)+time_adjust);
	int choice = rand() % 2;

	//3、
	time_adjust=rand() % 10000;

	if (choice == 0)
		return lowcharacter;
	else
		return highcharacter;

}
int Sample_Test::random_int(int lownum,int highnum)
{
	srand((int)time(0)*5+time_adjust);
	int high2 = highnum + 1;


	time_adjust=rand() % 10000+2;

	return rand() % (high2 -lownum)+lownum;

}
std::string Sample_Test::random_string(int lowlength,int highlength)
{
	srand((int)time(0)+time_adjust);
	int length= rand() % (highlength +1- lowlength) + lowlength;
	std::string answer = "";
	for (int i = 0; i < length; i++)
	{
		answer += random_char();
	}

	time_adjust=rand() % 10000/3;

	return  answer;
}