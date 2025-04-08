#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <iomanip>

Discipline::Discipline(std::string n, int lc, int comp = 1)
    : name(n), labCount(lc), complexity(comp) {

    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty.");
    }

    if (labCount <= 0) {
        throw std::invalid_argument("Lab count must be greater than zero.");
    }

    if (complexity < 1 || complexity > 10) {
        throw std::out_of_range("Complexity must be in the range [1, 10].");
    }
        
    labGrades = new int[labCount]();
}

class Discipline {
private:
    std::string name;
    int labCount;
    int* labGrades;
    int complexity;

public:
    Discipline(std::string n, int lc, int comp);


    ~Discipline();

    int& operator[](int index);

    int getSignedLabs() const;

    int getUnsignedLabs() const;

    friend std::ostream& operator<<(std::ostream& out, const Discipline& obj);
};

std::ostream& operator<<(std::ostream& out, const Discipline& obj);

int& operator+=(int& sum, const Discipline& obj);
