#include"Utils.h"

std::string intToString(const int& i)
{
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

int stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int i;
	iss >> i;
	return i;
}