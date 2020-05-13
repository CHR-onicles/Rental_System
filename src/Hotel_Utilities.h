#pragma once
#include <iostream>
#include <vector>
#include "Hotel.h"
#include <fstream>
#include <iomanip>

//creating the groundfloor object of type vector, containing the tenants
Hotel groundfloor;

//current number of tenants per what is saved in file(tenants.txt)
int cNumberOfTenants() {
	std::string line;
	int numOfLines{};
	std::ifstream in_file{ "tenants.txt" };
	if (!in_file)
		throw MissingFileException();
	while (std::getline(in_file, line)) {
		numOfLines++;
	}
	in_file.close();
	return (numOfLines / 4);
	//need to refactor and use pointer location for this
}

//displaying number of tenants
void showNumOfTenants() {
	int num{cNumberOfTenants()};
	std::cout << "\nMax number of tenants is 10, and there are " << num << " currently." << std::endl;
}

//adding tenant
void addTenant(Hotel& floor, std::string& fname, std::string& lname, short& age, std::string& pnumber) {
	if (floor.addTenant(fname,lname, age, pnumber)) {
		std::cout << "You have been registered successfully!" << std::endl;
		std::cout << "\nPLEASE TAKE NOTE:" << std::endl;
		std::cout << "You have been assigned the current available room in our system,";
		std::cout << "\nHope you enjoy your stay!" << std::endl;
	}
	else 
		std::cout << "Registration failed!" << std::endl;
}

void displayTenants() {
	std::ifstream in_file{ "tenants.txt" };
	std::string line;
	std::string title{ "=======================> LIST OF TENANTS <=======================" };
	const unsigned int TITLE_LENGTH{ title.length() };

	if (!in_file)
		throw MissingFileException();

	//use as a ruler for margin checking
	//std::cout << "12345678901234567890123456789012345678901234567890123456789012345" << std::endl; 

	//displaying header
	std::cout << "\n\n";
	std::cout << std::setw(TITLE_LENGTH) << std::setfill(' ') << std::left << title << std::endl;
	std::cout << std::setw(20) << std::left  << "FIRST NAME:"
			  << std::setw(20) << std::left  << "LAST NAME:"
			  << std::setw(10) << std::right << "AGE:"
			  << std::setw(15) << std::right << "CONTACT:" << std::endl;
	std::cout << std::setw(TITLE_LENGTH) << std::setfill('-') << "" << std::endl;
	std::cout << std::setfill(' ');
	
	//displaying actual file data
	int lineNumber{};
	int firstLine{ 1 };
	int secondLine{ 2 };
	int thirdLine{ 3 };
	int fourthLine{ 4 };
	while (in_file>> line) {
		lineNumber++;
		if (lineNumber == firstLine) {
			std::cout << std::setw(20) << std::left << line;
			firstLine += 4;
		}
		else if (lineNumber == secondLine) {
			std::cout << std::setw(20) << std::left << line;
			secondLine += 4;
		}
		else if (lineNumber == thirdLine) {
			std::cout << std::setw(8) << std::right << line;
			thirdLine += 4;
		}
		else if (lineNumber == fourthLine) {
			std::cout << std::setw(17) << std::right << line << std::endl;
			fourthLine += 4;
		}
		//not necessary but i added this so i can see when the limit for number of tenants is reached (which is 10)
		//also I'm not sure this is a very efficient way to do this but it works soo...

		//*refactor using pointer location for this*
		//structs design will also make it easier...mini-database project for reference
		if (lineNumber == 40) {
			std::cout << std::setw(TITLE_LENGTH) << std::setfill('-') << "" << std::endl;
			std::cout << std::setfill(' ');
		}
	}
	in_file.close();
}