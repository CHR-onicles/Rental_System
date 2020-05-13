#pragma once
#include <iostream>
#include <vector>
#include "Tenant.h"
#include "Exceptions.h"

class Hotel{
protected:
	std::vector<Tenant> floors;	//to contain tenants
public:
	Hotel() {}
	~Hotel() = default;

	void saveToFile() const;
	bool addTenant(std::string fname, std::string lname,short age, std::string pnumber);
};