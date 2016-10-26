#include "Viterbi.h"

Viterbi::Viterbi(string perm)
{
	generateTrellace(perm);
	state = "000";
}

void Viterbi::generateTrellace(string perm) {
	int count = 0;
	for each (string i in ids) {
		stateChanges[count].id = i;
		stateChanges[count].sto[0] = sto[count][0];
		stateChanges[count].sto[1] = sto[count][1];
		string temp0 = "0" + i;
		string temp1 = "1" + i;
		stateChanges[count].bit[0] = xorgate(temp0[perm[3] - 48], temp0[perm[2] - 48]) + xorgate(temp0[perm[1] - 48], temp0[perm[0] - 48]);
		stateChanges[count].bit[1] = xorgate(temp1[perm[3] - 48], temp1[perm[2] - 48]) + xorgate(temp1[perm[1] - 48], temp1[perm[0] - 48]);

		cout << "For ID; " << i << " Input 0 = " << stateChanges[count].bit[0] << " And Input 1 = " << stateChanges[count].bit[1] << endl;
		count++;
	}
}

string Viterbi::xorgate(char a, char b) {
	return to_string(((int)a + (int)b) % 2);
}

string Viterbi::xorgate(char a, char b, char c) {
	int ta = ((int)a + (int)b) % 2;
	int tb = (ta + (int)c) % 2;
	return to_string(tb);
}

string Viterbi::decode(string file) {
	string decoded;
	string cState = state;
	for (int i = 0; i < file.length(); i+=2) {
		string temp = file.substr(i,2);
		int count = 0;
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
		}
		//next bit must be 1
		else if (stateChanges[count].bit[1] == temp) {
			decoded += "1";
			cState = ids[stateChanges[count].sto[1]];
		}
		else {
			//error
			cout << "Error";
			break;
		}
	}
	return decoded;
}

//string Viterbi::runviterbi() {
//	for each() {
//
//	}
//	for (int i = 0; i < T; i++) {
//		for each(state) {
//
//		}
//	}
//	for (int i = 0; i < T; i++) {
//
//	}
//	return x;
//}

Viterbi::~Viterbi()
{
}
