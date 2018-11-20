#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void usage(char * arg0){
	cout << arg0 << " <max> <num> <output file> (<multiple>)" << endl;
}

int main(int argc, char ** argv){
	if(argc<4){
		usage(argv[0]);
		return 0;
	}
	unsigned int max = stoi(argv[1], NULL, 10);
	unsigned int num = stoi(argv[2], NULL, 10);
	unsigned int multiple = 1;
	if(argc>4)
		multiple = stoi(argv[4], NULL, 10);
	ofstream ofp;
	ofp.open(argv[3]);
	if(!ofp.is_open() || !ofp.good()){
		cout << "Bad Output File Name: \"" << argv[2] << "\"; printing to STDOUT instead" << endl;
		return 1;
	}
	
	srand(time(NULL));
	for(unsigned int i=0; i<num; i++){
		unsigned int n = (unsigned int)(rand()%((unsigned int) max/multiple))*multiple;
		ofp << n << endl;
	}
	ofp.close()
	return 0;
}