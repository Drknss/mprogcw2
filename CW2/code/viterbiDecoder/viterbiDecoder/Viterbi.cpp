#include "Viterbi.h"

Viterbi::Viterbi(int r3, int r2, int r1, int i1, int xorc1, int xorc2)
{
	state = "000";
	generateTrellace(r3,r2,r1,i1,xorc1,xorc2);
	
}

string Viterbi::xorgate(char a, char b) {
	return to_string(((int)a + (int)b) % 2);
}

string Viterbi::xorgate(char a, char b, char c) {
	int ta = (((int)a + (int)b) % 2);
	int tb = (ta + (int)c) % 2;
	return to_string(tb);
}

void Viterbi::generateTrellace(int r3, int r2, int r1, int i1, int xorc1, int xorc2) {
	int count = 0;
	for each (string i in ids) {
		stateChanges[count].id = i;		
		for (int s = 0; s < 2; s++) {
			stateChanges[count].sto[s] = sto[count][s];
			string temp = to_string(s) + i;
			if (xorc1 == 2 && xorc2 == 2) {
				stateChanges[count].bit[s] += xorgate((char)temp[i1], (char)temp[r1]) + xorgate((char)temp[r2], (char)temp[r3]);
				}
			if (xorc1 == 3 && xorc2 == 2) {
				stateChanges[count].bit[s] += xorgate((char)temp[i1], (char)temp[r1], (char)temp[r2]) + xorgate((char)temp[r2], (char)temp[r3]);
			}
			if (xorc1 == 2 && xorc2 == 3) {
				stateChanges[count].bit[s] += xorgate((char)temp[i1], (char)temp[r1]) + xorgate((char)temp[r1], (char)temp[r2], (char)temp[r3]);
			}
			if (xorc1 == 3 && xorc2 == 3) {
				stateChanges[count].bit[s] += xorgate((char)temp[i1], (char)temp[r1], (char)temp[r2]) + xorgate((char)temp[r1], (char)temp[r2], (char)temp[r3]);
			}
		}
		cout << "For ID; " << i << " Input 0 = " << stateChanges[count].bit[0] << " And Input 1 = " << stateChanges[count].bit[1] << endl;
		count++;
	}
	cout << endl;
}

string Viterbi::decode(string file) {
	string decoded;
	string cState = state;
	int count = 0;
	for (int i = 0; i < file.length(); i+=2) {
		string temp = file.substr(i,2);
		
		for each(schange s in stateChanges) {
			if (s.id == cState) {
				break;
			}
			count++;
		}
		//next bit must be 0
		if (stateChanges[count].bit[0] == temp) {
			decoded += "0";
			cState = ids[stateChanges[count].sto[0]];
			count = 0;
		}
		//next bit must be 1
		else if (stateChanges[count].bit[1] == temp) {
			decoded += "1";
			cState = ids[stateChanges[count].sto[1]];
			count = 0;
		}
		else {
			//error
			string error = (" Decode Ran into an Error!! Current state is = " + cState + " Possible Outputs were = " + ids[stateChanges[count].sto[0]] + " For " + stateChanges[count].bit[0] + " and " + ids[stateChanges[count].sto[1]] + " for " + stateChanges[count].bit[1] + " Actual output was " + temp);
			decoded += error;
			break;
		}
	}
	return decoded;
}

Viterbi::~Viterbi()
{
}
