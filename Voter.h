#ifndef VOTER_H
#define VOTER_H



#include <iostream>
#include <string>


using namespace std;

class Voter {

	enum states {NY, PA, VT, ME, MA, CT, RI, NH};
	
	private:

  	string lastName;
	string firstName;
	string userId;
	string password;
	int age;
	int streetNumber;
	string streetName;
	string town;
	int state;
	string zipCode;
	float amountDonated;
	
	public:

	Voter();

	void init();

	void update();

	void passwd();

	void view();

	void donate();

	void report();


	void secondMenu();

	string getUserId();

	string getPassword();

	string getFirstName();

	string getLastName();

	int getAge();

	int getStreetNumber();

	string getStreetName();

	string getTown();

	string getZipCode();

	string getState();

	float getAmountDonated();

	void setLastName(string s);

	void setFirstName(string s);
	
	void setUserId(string s);

	void setPassword(string s);

	void setAge(int i);

	void setStreetNumber(int i);

	void setStreetName(string s);

	void setTown(string s);

	void setState(string s);

	void setZipCode(string s);

	void setAmountDonated(float f);

};

#endif
