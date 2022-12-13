#include"IO_View.h"

IO_View::IO_View()
{
	begin_scene = new Begin_Scene;
	commandline_scene = new Commend_Line_Scene;
	unknowline_scene = new Unknowline_Scene;
}
IO_View::~IO_View()
{
	delete begin_scene;
	delete commandline_scene;
	delete unknowline_scene;

	begin_scene=nullptr;
	commandline_scene=nullptr;
	unknowline_scene=nullptr;
}
void IO_View::Show_Begin_Scene()
{
	begin_scene->show();
}
void IO_View::Show_Commend_Line_Scene()
{
	commandline_scene->show();
}
void IO_View::Show_Unknown_Scene()
{
	unknowline_scene->show();
}