#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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

    std::string getCity() {
        return city;
    }

    bool operator<(const Address& other) const {
        return city < other.city; 
    }
};

void sortAddresses(Address** addresses, int size) {
    std::sort(addresses, addresses + size, [](const Address* a, const Address* b) {
        return *a < *b;
    });
}

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

    sortAddresses(addresses, n);

    outfile << n << std::endl;

    for (int i = 0; i < n; i++) {
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