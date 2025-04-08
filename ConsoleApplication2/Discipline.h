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
    Discipline(std::string n, int lc, int comp);

    ~Discipline();

    int& operator[](int index);

    int getSignedLabs() const;

    int getUnsignedLabs() const;

    friend std::ostream& operator<<(std::ostream& out, const Discipline& obj);
};

std::ostream& operator<<(std::ostream& out, const Discipline& obj);

int& operator+=(int& sum, const Discipline& obj);
