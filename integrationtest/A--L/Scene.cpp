

#include "Scene.h"

void Begin_Scene::show()
{
	std::cout << "            Welcome to my eqminer!" << std::endl;
	std::cout << "             Input your command!" << std::endl;
	std::cout << "              Commands follow:" << std::endl;
	std::cout << "===================================================" << std::endl;
	std::cout << "test :  Upload your files and test the equivalence." << std::endl;
	std::cout << "quit:   Close the program." << std::endl;
	std::cout << "===================================================" << std::endl;

}
void Begin_Scene::hide()
{
}

void Commend_Line_Scene::show()
{
	std::cout << "myequminer@>>";
}
void Commend_Line_Scene::hide()
{
}


void Unknowline_Scene::show()
{
	std::cout << "Unknow Commend!" << std::endl;
}
void Unknowline_Scene::hide()
{
}


void BusyScene::show()
{
	std::cout << "All factories are busy!" << std::endl;
}
void BusyScene::hide()
{

}


void WorkScene::show()
{

}
void WorkScene::hide()
{
}
void WorkScene::showstate(std::vector<bool> s)
{
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==true)
		{
			std::cout<<"Task"+std::to_string(i)+": "<<"busy"<<std::endl;
		}
		else
		{
			std::cout<<"Task"+std::to_string(i)+": "<<"free"<<std::endl;
		}
	}
}