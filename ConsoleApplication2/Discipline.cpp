#include "Discipline.h"

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

    labGrades = new int[labCount];
    for (int i = 0; i < labCount; ++i) {
        labGrades[i] = DEFAULT_GRADE;
    }
}

Discipline::~Discipline() {
    delete[] labGrades;
}

int& Discipline::operator[](int index) {
    if (index < 0 || index >= labCount) {
        throw std::out_of_range("Index out of range!");
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
    
    bool first = true;
    for (int i = 0; i < obj.labCount; ++i) {
        if (obj.labGrades[i] > 0) {
            if (!first) {
                out << ", ";
            }
            out << "#" << (i + 1) << " - " << obj.labGrades[i];
            first = false;
        }
    }

    if (first) { // Если ни одна лабораторная не сдана
        out << "No labs have been submitted.";
    }

    out << "\nComplexity: " << obj.complexity << "\n"
        << "Number of laboratory papers handed in: " << obj.getSignedLabs() << "\n";
    return out;
}

int& operator+=(int& sum, const Discipline& obj) {
    sum += obj.getUnsignedLabs();
    return sum;
}
