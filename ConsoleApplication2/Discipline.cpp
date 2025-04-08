#include "Discipline.h"

Discipline::~Discipline() {
    delete[] labGrades;
}

int& Discipline::operator[](int index) {
    if (index < 0 || index >= labCount) {
        std::cerr << "Error: Index out of range!" << std::endl;
        exit(1);
    }
    return labGrades[index];
}

int Discipline::getSignedLabs() const {
    int count = 0;
    for (int i = 0; i < labCount; ++i) {
        if (labGrades[i] > 0) count++;
    }
    return count;
}

int Discipline::getUnsignedLabs() const {
    return labCount - getSignedLabs();
}

std::ostream& operator<<(std::ostream& out, const Discipline& obj) {
    out << "Discipline: " << obj.name << "\n"
        << "Lab Count: " << obj.labCount << "\n"
        << "Lab Grades: ";
    for (int i = 0; i < obj.labCount; ++i) {
        out << obj.labGrades[i] << " ";
    }
    out << "\nComplexity: " << obj.complexity << "\n"
        << "Number of laboratory papers handed in: " << obj.getSignedLabs() << "\n";
    return out;
}

int& operator+=(int& sum, const Discipline& obj) {
    sum += obj.getUnsignedLabs();
    return sum;
}
