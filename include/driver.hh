#ifndef DRIVER
#define DRIVER
using namespace std;
#include <string>

#include "./person.hh"

class Ambulance;
class driver : public person
{
private:
    string licenseNumber;
    bool idle;
    friend class Ambulance;

public:
    driver();
    void fillMap();
    void saveMap();
    void addPerson();
    void printDetails();
    void printDetailsFromHistory(string extraDetails = "");
    void getDetails(int rec = 0);
    void getDetailsFromHistory();
    void removePerson();
};
#endif // !DRIVER