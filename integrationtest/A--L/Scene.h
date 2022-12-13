
#include <iostream>
#include <vector>
class Scene {

public:
	virtual void show()=0;
	virtual void hide()=0;
	virtual void showstate(std::vector<bool>){};
	virtual ~Scene(){};
};

class Begin_Scene:public Scene
{
public:
	void show();
	void hide();

};

class Commend_Line_Scene :public Scene
{
public:
	void show();
	void hide();

};
class Unknowline_Scene :public Scene
{
public:
	void show();
	void hide();

};

class BusyScene :public Scene
{
public:
	void show();
	void hide();

};
class WorkScene:public Scene
{
	public:
		void show();
		void hide();
		void showstate(std::vector<bool>);

};
