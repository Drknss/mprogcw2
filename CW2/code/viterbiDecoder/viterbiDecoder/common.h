#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class common
{
public:
	common();
	~common();
	string readin(string file_location);
	void readinlbl(string filename, vector<string> *filenames);
	void printtofile(string file, string content);
	void printtofilelbl(string file, vector<string> content);
};