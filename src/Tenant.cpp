#include "Tenant.h"
#include <iostream>
#include <fstream>

Tenant::Tenant()
    : fname{ def_fname }, lname{def_lname}, age{ def_age }, pnumber{ def_pnumber }{}

Tenant::Tenant(std::string fname, std::string lname, short age, std::string pnumber)
    : fname{ fname }, lname{lname}, age{ age }, pnumber{ pnumber }{}

/*std::ostream& operator<<(std::ostream& os, const Tenant& obj) {
    os << "[Tenant: " << obj.fname << ", " << obj.age << ", " << obj.pnumber << "]" << std::endl;
    return os;
}  */ //add setw and setfill to format display in file and stuff

void Tenant::saveToFile()const {
    std::ofstream out_file{ "tenants.txt",std::ios::app};
    if (!out_file) {
        std::cerr<<"Error opening file" << std::endl;
        throw MissingFileException();   //to be caught in menu()
    }
    out_file << this->getfName() << std::endl;
    out_file << this->getlName() << std::endl;
    out_file << this->getAge() << std::endl;
    out_file << this->getPnumber() << std::endl;
}