#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <iomanip>

Discipline::Discipline(std::string n, int lc, int comp = 1)
    : name(n), labCount(lc), complexity(comp) {
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
