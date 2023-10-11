#ifndef HOSPITAL_MANAGEMENT_SYSTEM_MEDICATION_HH
#define HOSPITAL_MANAGEMENT_SYSTEM_MEDICATION_HH


#include <string>
#include <iostream>
using namespace std;

class Medication
{
private:
    int id;
    string name;
    double price;
    int nums;

public:
    Medication();
    string getName();
    double getPrice();
    int getNums();
    void setID(int ID);
    void setName(string name);
    void setPrice(double price);
    void setNums(int nums);
    void updateNums(int nums);
    void updatePrice(double price);
    double calcTotalPrice();
    void getDetails();
    void printDetails();
    bool reduceStock(int nums);
    void fillMap();
    void saveMap();
    void addMedication();
    void removeMedication();
};



#endif //HOSPITAL_MANAGEMENT_SYSTEM_MEDICATION_HH
