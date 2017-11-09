#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "VoterDatabase.h"

using namespace std;


int main(int argc, char **argv) {
	
	int s, c;
	istringstream buf(argv[1]);
	buf >> s;
	VoterDatabase* vd = new VoterDatabase(s);

	if(argc > 2) { // if there is an input fil
		vd -> readFile(argv[2]);
	}

	int x = 0;
	while(x == 0) {
		string selection;
		cout << "Make a selection (Login, New, Save, Load, Report, or Quit): ";
		cin >> selection;
		if(selection.compare("Login") == 0)
			vd -> login();
		else if(selection.compare("New") == 0)
			vd -> newFunction();
		else if(selection.compare("Save") == 0)
			vd -> save();
		else if(selection.compare("Load") == 0)
			vd -> load();
		else if(selection.compare("Report") == 0)
			vd -> report();
		else if(selection.compare("Quit") == 0) {
			string saveYesOrNo;
			cout << "Save current voter information in to a file? Y for yes: ";
			cin >> saveYesOrNo;
			if(saveYesOrNo == "Y"){
				vd -> save();
				return 1;
			}
			else
				return 1;	
		}
		else
			cout << "Command not recognized. Make a valid selection.\n";
	}
	return 1;
}
