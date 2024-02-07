#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string getOutputAddress() {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }
};

int main() {
    std::ifstream infile("in.txt");
    std::ofstream outfile("out.txt");

    int n;
    infile >> n; 

    Address** addresses = new Address*[n];

    for (int i = 0; i < n; i++) {
        std::string city, street;
        int houseNumber, apartmentNumber;
        infile >> city >> street >> houseNumber >> apartmentNumber;
        addresses[i] = new Address(city, street, houseNumber, apartmentNumber);
    }

    outfile << n << std::endl;

    for (int i = n - 1; i >= 0; i--) {
        outfile << addresses[i]->getOutputAddress() << std::endl;
    }

    infile.close();
    outfile.close();

    for (int i = 0; i < n; i++) {
        delete addresses[i];
    }
    delete[] addresses;

    return 0;
}