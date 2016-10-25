#include "burst.h"

mt19937 rng(time(NULL));
uniform_int_distribution<int> gen(0, 20);

burst::burst()
{	
}

string burst::addErrors(string file) {
	bool burst_mode = false;
	int burst_mode_counter = 0;
	for (int i = 0; i < file.size(); i++){
		if (burst_mode) {
			burst_mode_counter++;
			int r = gen(rng);
			if (r > 10) {
				file[i] = '0';
			}
			else {
				file[i] = '1';
			}			
			if (burst_mode_counter > 4) {
				burst_mode = false;
				burst_mode_counter = 0;
			}
		}
		else {			
			int r = gen(rng);
			if (r > 18) {
				burst_mode = true;
			}
		}
	}

	return file;
}


burst::~burst()
{
}
