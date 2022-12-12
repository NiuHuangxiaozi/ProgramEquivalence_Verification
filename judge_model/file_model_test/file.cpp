
#include "file.h"
void File::set_result(bool flag)
{
	is_equal = flag;
}

std::vector<std::string> File::Getpair()
{
	return { url1, url2 };
}