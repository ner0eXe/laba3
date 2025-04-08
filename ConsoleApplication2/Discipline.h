#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <time.h>

class Discipline {
private:
    std::string name;
    int labCount;
    int* labGrades;
    int complexity;

    static const int DEFAULT_GRADE = -1;

public:
    Discipline(std::string n, int lc, int comp)
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

        labGrades = new int[labCount];
        for (int i = 0; i < labCount; ++i) {
            labGrades[i] = DEFAULT_GRADE;
        }
    }

    ~Discipline();

    int& operator[](int index);

    int getSignedLabs() const;

    int getUnsignedLabs() const;

    friend std::ostream& operator<<(std::ostream& out, const Discipline& obj);
};

std::ostream& operator<<(std::ostream& out, const Discipline& obj);

int& operator+=(int& sum, const Discipline& obj);
