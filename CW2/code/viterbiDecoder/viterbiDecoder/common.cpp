#include "common.h"

common::common()
{
}

common::~common()
{
}

string common::readin(string file_location) {
	string fname = file_location + ".txt";
	try {
		ifstream file(fname);
		if (file.is_open()) {
			string file_contents{ istreambuf_iterator<char>(file), istreambuf_iterator<char>() };
			file.close();
			return file_contents;
		}
	}
	catch (std::exception &ex) {
		throw std::runtime_error("Could not open file");
	}
}

void common::readinlbl(string filename, vector<string> *filenames) {
	string line;
	try {
		ifstream file(filename);
		if (file.is_open()) {
			while (getline(file, line)) {
				filenames->push_back(line);
			}
			file.close();
		}
	}
	catch (std::exception &ex) {
		throw std::runtime_error("Could not open file");
	}
}

void common::printtofile(string file, string content) {
	string fname = file + ".txt";
	ofstream out(fname);
	out << content;
	out.close();
}

void common::printtofilelbl(string file, vector<string> content) {
	string fname = file + ".txt";
	ofstream out(fname);
	if (out.is_open()) {
		for each (string s in content) {
			out << s << endl;
		}
	}
}