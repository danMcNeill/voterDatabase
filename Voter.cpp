#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Voter.h"


using namespace std;



	

	Voter::Voter() {
		
	}

	void Voter::init() {
		int x;
		string temp;
		string intTemp;
		char c;	
		amountDonated = 0;
		bool valid = true;
		bool digit = false;
		bool specialChar = false;
		bool isInt = true;
		
		for(;;) { // new last name
			cout << "Last Name: ";
			cin >> temp;
			for(int i=0; i<temp.length(); i++) {
				c = temp.at(i);
				if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
					cout << "Name must contain only letters. Try again.\n";
					valid = false;
					break;
				}
			}
			if(valid == true) {
				lastName = temp;
				break;
			}
		}

		for(;;) { // new first name
			cout << "First Name: ";
			cin >> temp;
			for(int i=0; i<temp.length(); i++) {
				c = temp.at(i);
				if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
					cout << "\nName must contain only letters. Try again.";
					valid = false;
					break;
				}
			}
			if(valid == true) {
				firstName = temp;
				break;
			}
		}

		for(;;) { // new user Id
			cout << "User ID: ";
			cin >> temp;
			if(temp.length() < 5) {
				cout << "User Id must contain at least five characters.\n";
				continue;
			}
			for(int i=0; i<temp.length(); i++) {
				c = temp.at(i);
				if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
					cout << "Name must contain only letters and digits. Try again.\n";
					valid = false;
					break;
				}
			}
			if(valid == true) {
				userId = temp;
				break;
			}
		}

		for(;;) { // new password
			cout << "New password: ";
			cin >> temp;
			if(temp.length() < 6) {
				cout << "Password not long enough.\n";
				continue;
			}
			for(int i=0; i<temp.length(); i++) {
				c = temp.at(i);
				if(c >= '0' && c <= '9') {
					digit = true;
				}
				if((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~')) {
					specialChar = true;
				}
			}
			if(digit == true && specialChar == true) {
				password = temp;
				break;
			}
			else {
				cout << "Password must contain at least one digit and character that is not a letter or digit.\n";
				continue;
			}
		}

		for(;;) { // new age
			cout << "Age: ";
			cin >> intTemp;
			for(x=0; x<intTemp.length(); x++) { //check if this string is an integer
				if(!(intTemp.at(x) >= '0' && intTemp.at(x) <= '9')) {
					cout << "Please enter an integer.\n";
					continue;
				}
			}
			if(atoi(intTemp.c_str()) < 18) {
				cout << "Must be at least 18 years old.\n";
				continue;
			}
			age = atoi(intTemp.c_str());
			break;
		}

		// new street name    ???????????????
		cout << "Street name: ";
		cin.ignore(256, '\n');
		getline(cin, streetName);

		valid = true;		
		int streetNum;

		for(;;) { // new street number
			cout << "Street number: ";
			cin >> streetNum;
			if(cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Street number must be positive. Try again.\n";
				continue;
			}
			if(streetNum < 1) {
				cout << "Street number must be positive. Try again.\n";
				continue;
			}
			streetNumber = streetNum;
			break;
		}

		cout << "Town: ";	   // new town name ?????
		cin.ignore(256, '\n');
		getline(cin, town);

		for(;;) {
			cout << "State (NY, PA, or New England states only): ";
			cin >> temp;
			if(temp.compare("NY") == 0) {
				state = NY;
				break;
			}
			else if(temp.compare("PA") == 0) {
				state = PA;
				break;
			}
			else if(temp.compare("VT") == 0) {
				state = VT;
				break;
			}
			else if(temp.compare("NH") == 0) {
				state = NH;
				break;
			}
			else if(temp.compare("MA") == 0) {
				state = MA;
				break;
			}
			else if(temp.compare("CT") == 0) {
				state = CT;
				break;
			}
			else if(temp.compare("ME") == 0) {
				state = ME;
				break;
			}
			else if(temp.compare("RI") == 0) {
				state = RI;
				break;
			}
			else
				cout << "Not recognized as state.\n";
		}

		valid = true;
		for(;;) {
			cout << "Zip code: ";
			cin >> temp;
			if(temp.size() != 5) {
				cout << "Must be five digits.\n";
				continue;
			}
			for(int i=0; i<5; i++) {
				c = temp.at(i);
				if(!(c >= '0' && c <= '9')) {
					cout << "Must be five digits.\n";
					valid = false;
					break;
				}
			}
			if(valid) {
				zipCode = temp;
				break;
			}
		}

		cout << "\n";
		return;
	}

	void Voter::update() {
		bool valid = true;
		char checker;
		string choice;
		string intTemp;
		string temp;
		char c;
		cout << "Update Last Name? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			for(;;) {
				cout << "Last Name: ";
				cin >> temp;
				for(int i=0; i<temp.length(); i++) {
					if(!((temp.at(i) >= 'a' && temp.at(i) <= 'z') || (temp.at(i) >= 'A' && temp.at(i) <= 'Z'))) {
						cout << "Name must contain only letters. Try again.\n";
						valid = false;
						break;
					}
				}
				if(valid == true) {
					lastName = temp;
					break;
				}
			}
		}
		cout << "Update First Name? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			for(;;) {
				cout << "First Name: ";
				cin >> temp;
				for(int i=0; i<temp.length(); i++) {
					if(!((temp.at(i) >= 'a' && temp.at(i) <= 'z') || (temp.at(i) >= 'A' && temp.at(i) <= 'Z'))) {
						cout << "Name must contain only letters. Try again.\n";
						valid = false;
						break;
					}
				}
				if(valid == true) {
					firstName = temp;
					break;
				}
			}
		}

		cout << "Update Age? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			for(;;) { // new age
				cout << "Age: ";
				cin >> intTemp;
				for(int x=0; x<intTemp.length(); x++) { //check if this string is an integer
					if(!(intTemp.at(x) >= '0' && intTemp.at(x) <= '9')) {
						cout << "Please enter an integer.\n";
						continue;
					}
				}
				if(atoi(intTemp.c_str()) < 18) {
					cout << "Must be at least 18 years old.\n";
					continue;
				}
				age = atoi(intTemp.c_str());
				break;
			}
		}

		cout << "Update Street Name? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			cout << "Street name: ";
			cin.ignore(256, '\n');
			getline(cin, temp);
		}

		int streetNum;

		cout << "Update Street Number? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			valid = true;
			for(;;) { // new street number
				cout << "Street number: ";
				cin >> streetNum;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Street number must be positive. Try again.\n";
					continue;
				}
				if(streetNum < 1) {
					cout << "Street number must be positive. Try again.\n";
					continue;
				}
				streetNumber = streetNum;
				break;
			}
		}

		cout << "Update Town? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			cout << "\nTown: ";	   // new town name ?????
			cin.ignore(256, '\n');
			getline(cin, town);
		}

		cout << "Update State? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			for(;;) {
				cout << "\nState (NY, PA, or New England states only): ";
				cin >> temp;
				if(temp.compare("NY") == 0) {
					state = NY;
					break;
				}
				else if(temp.compare("PA") == 0) {
					state = PA;
					break;
				}
				else if(temp.compare("VT") == 0) {
					state = VT;
					break;
				}
				else if(temp.compare("NH") == 0) {
					state = NH;
					break;
				}
				else if(temp.compare("MA") == 0) {
					state = MA;
					break;
				}
				else if(temp.compare("CT") == 0) {
					state = CT;
					break;
				}
				else if(temp.compare("ME") == 0) {
					state = ME;
					break;
				}
				else if(temp.compare("RI") == 0) {
					state = RI;
					break;
				}
				else
					cout << "Not recognized as state.";
			}
		}

		cout << "Update Zip Code? Y for yes: ";
		cin >> choice;
		if(choice == "Y") {
			valid = true;
			for(;;) {
				cout << "\nZip code: ";
				cin >> temp;
				if(temp.size() != 5) {
					cout << "Must be five digits.\n";
					continue;
				}
				for(int i=0; i<5; i++) {
					c = temp.at(i);
					if(!(c >= '0' && c <= '9')) {
						cout << "Must be five digits.\n";
						valid = false;
						break;
					}
				}
				if(valid) {
					zipCode = temp;
					break;
				}
			}
		}

		cout << "\n";
		return;
	}

	void Voter::passwd() {
		bool specialChar = false;
		bool digit = false;
		string newPass;
		string newPass2;
		string oldPass;
		string temp;
		cout << "Old password: ";
		cin >> oldPass;
		if(oldPass == password) {
			for(;;) {
				cout << "New password: ";
				cin >> temp;
				if(temp.length() < 6) {
					cout << "Password not long enough.\n";
					continue;
				}
				for(int i=0; i<temp.length(); i++) {
					char c = temp.at(i);
					if(c >= '0' && c <= '9') {
						digit = true;
					}
					if((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~')) {
						specialChar = true;
					}
				}
				if(digit == true && specialChar == true) {
					newPass = temp;
					break;
				}
				else {
					cout << "Password must contain at least one digit and character that is not a letter or digit.\n";
					continue;
				}
			}

			cout << "New password again: ";
			cin >> newPass2;
			if(newPass != newPass2)
				cout << "New passwords do not match. Back to menu.\n";
			else {
				password = newPass;
				cout << "New password set.\n";
			}
		}
		else {
			cout << "Password does not match. Back to menu.\n";
		}
		return;
	}

	void Voter::view() {
		cout << "Voter Info\n";
		cout << "User ID: " << userId;
		cout << '\n' << firstName << " " << lastName << ": age " << age << "\n";
		cout << streetNumber << " " << streetName << "\n";
		cout << town << ", ";
		if(state == NY)
			cout << "NY";
		else if(state == PA)
			cout << "PA";
		else if(state == VT)
			cout << "VT";
		else if(state == NH)
			cout << "NH";
		else if(state == MA)
			cout << "MA";
		else if(state == CT)
			cout << "CT";
		else if(state == RI)
			cout << "RI";
		else
			cout << "ME";
		cout << " " << zipCode << "\n";
		cout << "Current amount donated: " << "$" << amountDonated << "\n";
		return;
	}

	void Voter::donate() {
		float newAmount;
		for(;;) {
			cout << "Amount to add: ";
			cin >> newAmount;
			if(newAmount > 2700) {
				cout << "Cannot donate more than $2,700. Try again.\n";
				continue;
			}
			else if(newAmount < 0) {
				cout << "Cannot donate negative value. Try again.\n";
				continue;
			}
			amountDonated += newAmount;
			if(amountDonated > 2700) {
				cout << "Donation stopped at $2,700.\n";
				amountDonated = 2700;
			}
			return;
		}
	}

	void Voter::report() {
		cout << lastName << " $" << fixed << setprecision(2) << amountDonated << "\n";
		return;
	}


	void Voter::secondMenu() {
		int x = 0;
		while(x == 0) {
			string selection;
			cout << "Make a selection (Update, Passwd, View, Donate, Report, Logout): ";
			cin >> selection;
			if(selection.compare("Update") == 0)
				update();
			else if(selection.compare("Passwd") == 0)
				passwd();
			else if(selection.compare("View") == 0)
				view();
			else if(selection.compare("Donate") == 0)
				donate();
			else if(selection.compare("Report") == 0)
				report();
			else if(selection.compare("Logout") == 0) {
				return;
			}
			else
				cout << "Command not recognized. Please enter valid selecion.\n";		
		}
		return;
	}

	string Voter::getUserId() {
		return userId;
	}

	string Voter::getPassword() {
		return password;
	}

	string Voter::getFirstName() {
		return firstName;
	}

	string Voter::getLastName() {
		return lastName;
	}

	int Voter::getAge() {
		return age;
	}

	int Voter::getStreetNumber() {
		return streetNumber;
	}

	string Voter::getStreetName() {
		return streetName;
	}

	string Voter::getTown() {
		return town;
	}

	string Voter::getZipCode() {
		return zipCode;
	}

	string Voter::getState() {
		if(state == NY)
			return "NY";
		else if(state == PA)
			return "PA";
		else if(state == VT)
			return "VT";
		else if(state == NH)
			return "NH";
		else if(state == MA)
			return "MA";
		else if(state == CT)
			return "CT";
		else if(state == RI)
			return "RI";
		else
			return "ME";
	}

	float Voter::getAmountDonated() {
		return amountDonated;
	}

	void Voter::setLastName(string s) {
		lastName = s;
	}

	void Voter::setFirstName(string s) {
		firstName = s;
	}

	void Voter::setUserId(string s) {
		userId = s;
	}

	void Voter::setPassword(string s) {
		password = s;
	}

	void Voter::setAge(int i) {
		age = i;
	}

	void Voter::setStreetNumber(int i) {
		streetNumber = i;
	}

	void Voter::setStreetName(string s) {
		streetName = s;
	}

	void Voter::setTown(string s) {
		town = s;
	}

	void Voter::setState(string s) {
		if(s == "NY")
			state = NY;
		else if(s == "PA")
			state = PA;
		else if(s == "VT")
			state = VT;
		else if(s == "NH")
			state = NH;
		else if(s == "MA")
			state = MA;
		else if(s == "CT")
			state = CT;
		else if(s == "RI")
			state = RI;
		else
			state = ME;
	}

	void Voter::setZipCode(string s) {
		zipCode = s;
	}

	void Voter::setAmountDonated(float f) {
		amountDonated = f;
	}


