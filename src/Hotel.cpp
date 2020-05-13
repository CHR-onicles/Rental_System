#include "Hotel.h"
#include <fstream>

void Hotel::saveToFile()const {
    std::ofstream out_file{ "tenants.txt",std::ios::app};
    if (!out_file) 
        throw MissingFileException();
    if (floors.size() == 0)
        std::cout << "Nothing to display here" << std::endl;
    else {
        for (const auto& val : floors) {
            val.saveToFile();
        }
        out_file.close();
    }
 }

//To add a tenant to a floor
bool Hotel::addTenant(std::string fname, std::string lname, short age, std::string pnumber) {
    /*for (const Tenant& tenants : floors) {
        if (fname == tenants.getfName() && lname == tenants.getlName() && pnumber == tenants.getPnumber())
            return false;
    }*/ //wont work anymore since i popback object after being created so basically vector is always empty
   
        Tenant temp{ fname, lname,age,pnumber };
        floors.push_back(temp);
        saveToFile();
        floors.pop_back();
        return true;
}