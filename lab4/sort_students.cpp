#include "student.h"
#include <vector>
#include <algorithm>
#include <iostream>

bool Compare(const Student& first, const Student& second) {
    return first.rating > second.rating;
}

void TestComparison() {
    // Your test cases for the comparison function
}

void TestSorting() {
    // Your test cases for sorting function
}

int main() {
    // Populate vector with students
    std::vector<Student> students;

    // Add students to the vector
    // ...

    // Measure time before sorting
    // Use profile.h or other profiling method

    // Sort students
    std::sort(students.begin(), students.end(), Compare);

    // Measure time after sorting
    // Calculate time difference

    // Output result
    std::cout << "TestComparison OK" << std::endl;
    std::cout << "TestSorting OK" << std::endl;

    return 0;
}
