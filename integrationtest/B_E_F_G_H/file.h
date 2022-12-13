#include<string>
#include<vector>


class File
{
private:
	bool is_equal;
	std::string url1;
	std::string url2;
public:
	File(std::string new_url1, std::string new_url2)
	{
		url1 = new_url1;
		url2 = new_url2;
	}
	void set_result(bool flag);
	bool Get_result(){return is_equal;}
	std::vector<std::string> Getpair();
};
