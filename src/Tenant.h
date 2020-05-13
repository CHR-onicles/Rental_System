#pragma once
#include <iostream>
#include "Exceptions.h"
class Tenant{
	//friend std::ostream& operator<<(std::ostream& os, const Tenant& obj);
private:
	//default stuff
	static constexpr const char* def_fname = "Unknown Fname";
	static constexpr const char* def_lname = "Unknown Lname";
	static constexpr int def_age = 0;
	static constexpr const char* def_pnumber = "0000000000";
protected:
	std::string fname;
	std::string lname;
	short age;
	std::string pnumber;
	//int ID_num;
	//string room_number;
public:
	Tenant();
	Tenant(std::string fname ,std::string lname, short age, std::string pnumber);
	~Tenant() = default;

	//getters and setters
	std::string getfName()const { return fname; }
	std::string getlName()const { return lname; }
	int getAge()const { return age; }
	std::string getPnumber()const {return pnumber;}

	void setfName(std::string name) { fname = name; }
	void setlName(std::string name) { lname = name; }
	void setAge(short age) { this->age = age; }
	void setPnumber(std::string pnumber) { this->pnumber = pnumber; }

	void saveToFile() const;
};