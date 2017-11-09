#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Voter.h"

using namespace std;


class VoterDatabase {
	
	private:
	
	int currentSize;
	Voter* v;
	int maxSize;
	
	public:
	
	VoterDatabase(int s);


	void login();

	void newFunction();

	void save();

	void load();

	void report();

	int getArraySize();

	int getCurrentSize();

	void setCurrentSize(int s);
	
	
	void readFile(string s);

	bool fileAlready(string s);

};
