#pragma once
#include <string>
#include <iostream>

using namespace std;

struct schange {
	string id;
	string bit[2];
	int sto[2];
};

class Viterbi
{
public:
	Viterbi(int r3, int r2, int r1, int i1, int xorc1, int xorc2);
	//string runviterbi();
	void generateTrellace(int r3, int r2, int r1, int i1, int xorc1, int xorc2);
	string decode(string file);
	string xorgate(char a, char b);
	string xorgate(char a, char b, char c);
	~Viterbi();

	string ids[8] = { "000","001","010","011","100","101","110","111" };
	schange stateChanges[8];
	int sto[8][2] = { {0,4},{0 ,4 },{ 1, 5},{1 ,5 },{2 ,6 },{2 ,6 },{3 ,7 },{3 ,7 } };
private:	
	string state;
};

