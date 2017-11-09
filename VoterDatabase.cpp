#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "VoterDatabase.h"
#include "Voter.h"

using namespace std;




	
	VoterDatabase::VoterDatabase(int s) {
		maxSize = s;
		v = new Voter[s];
		currentSize = 0;
	}


	void VoterDatabase::login() {
		string id, password;
		cout << "User ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;
		for(int i=0; i<currentSize; i++) {
			if(v[i].getUserId() == id) {
				if(v[i].getPassword() == password) {
					v[i].secondMenu();
					return;
				}
			}
		}
		cout << "User Id or password could not be matched. Back to menu.\n";
		return;
	}

	void VoterDatabase::newFunction() {
		if(currentSize >= maxSize)
			cout << "Cannot add new voter; max voters achieved.\n";
		else {
			v[currentSize].init();
			currentSize++;
		}
	}

	
	void VoterDatabase::save() {
		int y = 0;
		string saveYesOrNo;
		while(y == 0) {
			string fileName;
			cout << "Name of file: ";
			cin >> fileName;
			
			if(fileAlready(fileName)) {
				cout << "File already exists. Overwrite? Y for yes: ";
				cin >> saveYesOrNo;
				if(saveYesOrNo == "Y") {
					//write in to file
					ofstream files;
					files.open(fileName.c_str());
					files << currentSize << '\n';
					for(int i=0; i<currentSize; i++) {
						
						files << v[i].getLastName() << '\n';
						files << v[i].getFirstName() << '\n';
						files << v[i].getUserId() << '\n';
						files << v[i].getPassword() << '\n';
						files << v[i].getAge() << '\n';
						files << v[i].getStreetNumber() << '\n';
						files << v[i].getStreetName() << '\n';
						files << v[i].getTown() << '\n';
						files << v[i].getState() << '\n';
						files << v[i].getZipCode() << '\n';
						files << v[i].getAmountDonated() << '\n';
					}
					files.close();
					y = 1;
					continue;
				}
				else if(saveYesOrNo == "N") {
					cout << "Select different file name? Y for yes: ";
					cin >> saveYesOrNo;
					if(saveYesOrNo == "Y")
						continue;
					else {
						y = 1;
						continue;
					}
				}
			}
			else { //file does not exist, must create it
				ofstream files;
				files.open(fileName.c_str());
				for(int i=0; i<currentSize; i++) {
					files << currentSize << '\n';
					files << v[i].getLastName() << '\n';
					files << v[i].getFirstName() << '\n';
					files << v[i].getUserId() << '\n';
					files << v[i].getPassword() << '\n';
					files << v[i].getAge() << '\n';
					files << v[i].getStreetNumber() << '\n';
					files << v[i].getStreetName() << '\n';
					files << v[i].getTown() << '\n';
					files << v[i].getState() << '\n'; // enum??
					files << v[i].getZipCode() << '\n';
					files << v[i].getAmountDonated() << '\n';
				}
				files.close();
				y = 1;		
			}
		}
	}

	void VoterDatabase::load() {
		int numVoters;
		string fileName;
		string nextLine;
		cout << "File name to load: ";
		cin >> fileName;
		readFile(fileName);
		
		
		return;
	}

	void VoterDatabase::readFile(string s) {
		string nextLine;
		int numVoters;
		ifstream files(s.c_str());
		if(files.is_open()) {
			int sum = 0;
			getline(files, nextLine);
			numVoters = atoi(nextLine.c_str());
			currentSize = numVoters;
			for(int i=0; i<numVoters; i++) {
				getline(files, nextLine);
				v[i].setLastName(nextLine);
				getline(files, nextLine);
				v[i].setFirstName(nextLine);
				getline(files, nextLine);
				v[i].setUserId(nextLine);
				getline(files, nextLine);
				v[i].setPassword(nextLine);
				getline(files, nextLine);
				v[i].setAge(atoi(nextLine.c_str()));
				getline(files, nextLine);
				v[i].setStreetNumber(atoi(nextLine.c_str()));
				getline(files, nextLine);
				v[i].setStreetName(nextLine);
				getline(files, nextLine);
				v[i].setTown(nextLine);
				getline(files, nextLine);
				v[i].setState(nextLine); // enum???
				getline(files, nextLine);
				v[i].setZipCode(nextLine);
				getline(files, nextLine);
				v[i].setAmountDonated(atoi(nextLine.c_str()));
			}
			files.close();
		}
		else {
			cout << "File does not exist. Back to menu.\n";
			return;
		}
	}

	void VoterDatabase::report() {
		cout << "Total voters in database: " << currentSize << "\n";
		int sum = 0;
		for(int i=0; i<currentSize; i++) {
			sum += v[i].getAmountDonated();
		}
		cout << "Campaign donations: $" << fixed << setprecision(2) << sum << "\n";
		return;
	}

	int VoterDatabase::getCurrentSize() {
		return currentSize;
	}

	void VoterDatabase::setCurrentSize(int s) {
		currentSize = s;
	}

	bool VoterDatabase::fileAlready(string s) {
		ifstream temp(s.c_str());
		if(temp.is_open())
			return true;
		else
			return false;
	}

	

