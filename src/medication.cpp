#include "./../include/medication.hh"
#include "./../include/hospital.hh"
#include "./../include/global.hh"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


Medication::Medication()
{
    this->id = -1;
    this->name = "unknown";
    this->price = 0;
    this->nums = -1;
}

void Medication::fillMap()
{
    fstream f;
    f.open("./data/medication.csv", ios::in);
    string temp;
    //skipping the first row containing column headers;
    getline(f >> ws, temp);
    //analyzing each entry afterwards;
    while (getline(f >> ws, temp))
    {
        Medication m;
        //creating a string stream object to read from string 'temp';
        stringstream s(temp);
        string s1, s5, s6, s7;
        //reading from the string stream object 's';
        getline(s, s1, ',');
        getline(s, s5, ',');
        getline(s, s6, ',');
        getline(s, s7, ',');
        m.setID(strToNum(s1));
        m.setName(s5);
        m.setPrice(strToNum(s6));
        m.setNums(strToNum(s7));
        hospital::medicationsList[m.id] = m;
    }
    f.close();
    return;
}

void Medication::saveMap()
{
    fstream f;
    f.open("./data/temp.csv", ios::out);
    // `le first line conataining column headers:
    //f << "ambulanceId,model,manufacturer,vrn,idle?,headedTowards(ifNotIdle),driverID(ifNotIdle)\n";
    f << "id,name,price,nums\n";
    for (auto i : hospital::medicationsList)
    {
        f << i.second.id<<","<<i.second.name << "," << i.second.price << "," << i.second.nums << endl;
    }
    f.close();
    remove("./data/medication.csv");
    rename("./data/temp.csv", "./data/medication.csv");
    return;
}

void Medication::addMedication()
{
    if (hospital::medicationsList.size() == hospital::medicationsLimit)
    {
        cout<<"\n\nMedications limit reached, can't add more!\n\n";
        return;
    }
    //getting the basic details of the ambulance from the user side;
    cout << "\nEnter Name of the Medication:\n";
    getline(cin >> ws, name);
    cout << "\nEnter Price of the Medication:\n";
    cin>> price;
    cout << "\nEnter Nums of the Medication:\n";
    cin>>nums;
    if (hospital::medicationsList.rbegin() != hospital::medicationsList.rend())
        id = ((hospital::medicationsList.rbegin())->first) + 1;
    else
        id = 1;
    hospital::medicationsList[id] = *this;

    //creating a fstream object to read/write from/to files;
    /*fstream f;
        //creating a record in ambulancesHistory.csv;
    f.open("./data/medicationHistory.csv", ios::app);
    f << name << "," << price << "," << nums << "," << endl;
    f.close();*/

    cout << "\n"
         << name << " priced at " << price << " per unit" << " added successfully!"
         << " The current stock is " << nums << "\n";
    cout << "Its ID is: " << id << "\n";
}

string Medication::getName()
{
    return this->name;
}

double Medication::getPrice()
{
    return this->price;
}

int Medication::getNums()
{
    return this->nums;
}

void Medication::setID(int ID)
{
    this->id = ID;
}

void Medication::setName(string name)
{
    if (this->name != "unknown")
    {
        cout<<"\n\t"<<"you can't rename the medication name."<<"\n";
        return;
    }
    else
    {
        this->name = name;
    }
}

void Medication::setPrice(double price)
{
    if (this->price != 0)
    {
        cout<<"\n\t"<<"you can't reset the medication price."<<"\n";
    }
    else
    {
        this->price = price;
    }
}

void Medication::setNums(int nums)
{
    if (this->nums != -1)
    {
        cout<<"\n\t"<<"you can't reset the medication nums."<<"\n";
    }
    else
    {
        this->nums = nums;
    }
}

void Medication::updateNums(int nums)
{
    this->nums = nums;
}

void Medication::updatePrice(double price)
{
    this->price = price;
}

double Medication::calcTotalPrice()
{
    return price * nums;
}

void Medication::getDetails()
{
    cout << "\nEnter Medication ID:\n";
    cin >> id;
    if (hospital::medicationsList.find(id) == hospital::medicationsList.end())
    {
        cout << "\nMedication with ID " << id << " not found!\n";
        id = -1;
        return;
    }
    *this = hospital::medicationsList[id];
    return;
}

void Medication::printDetails()
{
    cout<<"\n";
    cout<<"the medication named by "<<getName()<<" info:\n";
    cout<<"\tMedication ID: "<<id<<endl;
    cout<<"\tMedication Name: "<<getName()<<endl;
    cout<<"\tPrice per Unit: "<<getPrice()<<endl;
    cout<<"\tQuantity in Stock: "<<getNums()<<endl;
    cout<<"\tTotal Price: "<<calcTotalPrice()<<endl;
    cout<<"\n";
}

bool Medication::reduceStock(int nums)
{
    if (this->nums < nums) return false;
    this->nums -= nums;
    return true;
}

void Medication::removeMedication() {
    cout<<"当前功能暂未实现！\n";
}





