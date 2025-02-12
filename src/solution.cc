#include "solution.hpp"
#include <fstream>
#include <sstream>
#include "student.hpp"

Student ReadStudentRecFromStream(std::istream& is) {
  std::string firstName, lastName;
    unsigned int uin;
    double gpa;
    char comma;
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
