#include "Discipline.h"
#include <iostream>
#include <string>



int main() {

    Discipline math("Mathematics", 5, 3);

    math[0] = 5; // Первая работа сдана на 5
    math[1] = 4; // Вторая работа сдана на 4

    std::cout << math;

    int totalUnsignedLabs = 0;
    totalUnsignedLabs += math;

    std::cout << "Total unsigned labs: " << totalUnsignedLabs << "\n";

    return 0;
}
