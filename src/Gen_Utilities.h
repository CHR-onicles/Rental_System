#pragma once
#include <iostream>
#include <conio.h>	//console input/output for _getch()
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include "Exceptions.h"
#include "Hotel_Utilities.h"

//PressEnter feature
void pressEnter() {
	std::cout << "Press Enter to continue..." << std::endl;
	while (_getch() != 13);	//13 is ascii for Enter
	system("cls");
}

//Login feature
void login() {
	std::vector<std::string> pswrds{ "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999", "0000" };
	std::string input;
	bool islogin = false;
	
	do {
		std::cout << "==> WELCOME TO CHR HOTEL SERVICE <==" << std::endl;
		std::cout << "Please enter your PIN: ";
		std::cin >> input;
		for (auto val : pswrds) {
			if (val == input) {
				islogin = true;
			}
		}
		if(islogin ==false)
			std::cerr << "Invalid PIN!" << std::endl;
		std::cout << "\n";
	} while (!islogin);

	std::cout << "Login successful!" << std::endl;
	pressEnter();
}

//Checking RoomPrices feature
void checkPrices() {
	std::ifstream in_file{ "RoomPrices.txt" };
	std::string line;

	if (!in_file) {
		throw MissingFileException();
	}
	std::cout << "\n";
	std::cout << "Below are our current prices in GHC:" << std::endl;
	while (std::getline(in_file, line)) {
		std::cout << line << std::endl;
	}

	in_file.close();
}

//extract user information for registration
void getDetailsForRegsitration() {
	std::string fname;
	std::string lname;
	short age{};
	std::string pnumber;
	std::string entry;
	bool done = false;

	if (cNumberOfTenants() != 10) {
		std::cout << "\nPlease enter your first name: ";
		std::cin >> fname;
		std::cout << "Please enter your last name: ";
		std::cin >> lname;
		do {
			std::cout << "Please enter your age: ";
			std::cin >> entry;
			std::istringstream iss{ entry };
			if ((iss >> age) && (age >= 18 && age <= 120))
				done = true;
			else
				std::cerr << "Invalid age!" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!done);

		//TO-DO: add validation of phone number
		std::cout << "Please enter your phone number: ";
		std::cin >> pnumber;

		std::cout << "\nTo make sure your details were got right:" << std::endl;
		std::cout << "The first name you entered was: " << fname << std::endl;
		std::cout << "The last name you entered was: " << lname << std::endl;
		std::cout << "The age you entered was: " << age << std::endl;
		std::cout << "The phone number you entered was: " << pnumber << std::endl;
		addTenant(groundfloor, fname, lname, age, pnumber);
	}
	else {
		std::cout << "Sorry, there is no more vacancy!" << std::endl;
		std::cout << "Select option 3 for more details." << std::endl;
		pressEnter();
	}
}

//Menu	- NOT FINISHED!
void menu() {
	char choice{};

	do {
		std::cout << "\n=======================================" << std::endl;
		std::cout << "1 - Register for a room " << std::endl;
		std::cout << "2 - Check pricing of rooms " << std::endl;
		std::cout << "3 - Check number of Tenants" << std::endl;
		std::cout << "4 - Display Tenants" << std::endl;
		std::cout << "Esc - Exit " << std::endl;
		std::cout << "========================================" << std::endl;

		std::cout << "Please select an option: ";
		choice = _getch();	//instantly displays event rather than having to press Enter

		switch (choice) {
		case 27:
			std::cout << "\nExiting program..." << std::endl;
			break;

		case '1':
			getDetailsForRegsitration();
			pressEnter();
			break;

		case '2':
			try {
				checkPrices();
				pressEnter();
				menu();
			}
			catch(const MissingFileException& ex){
				std::cout << ex.what() << std::endl;
				menu();
			}
			break;

		case '3':
			showNumOfTenants();
			pressEnter();
			break;
		case '4':
			displayTenants();
			pressEnter();
			break;

		default:
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	} while (choice != 27);	//27 is ascii for Escape
	std::cout << "\nHave a good day!" << std::endl;
	std::exit(1);
	
}