
#include<iostream>
#include"Scene.h"
class IO_View
{
	
private:
	Scene *begin_scene;
	Scene* commandline_scene;
	Scene* unknowline_scene;
public:
	IO_View();
        ~IO_View();
	void Show_Begin_Scene();
	void Show_Commend_Line_Scene();
	void Show_Unknown_Scene();

};
