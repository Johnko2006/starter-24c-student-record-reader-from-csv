#include "solution.hpp"
#include <fstream>
#include "student.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  std::string firstName, lastName;
    unsigned int uin = 0;
    double gpa = 0.0;
    char comma = '\0';
    if (!(is >> firstName >> lastName)) {
        return Student{};
    }
    if (lastName.back() != ',') {
        return Student{};
    }
    lastName.pop_back();
    if (!(is >> uin)) {
        return Student{};
    }
    if (!(is >> comma) || comma != ',') {
        return Student{};
    }
    if (!(is >> gpa)) {
        return Student{};
    }
    return Student{firstName + " " + lastName, uin, gpa};
}
