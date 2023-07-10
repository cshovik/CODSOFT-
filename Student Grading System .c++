#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Student {
    std::string name;
    double grade;
};

int main() {
    std::vector<Student> students;
    std::string name;
    double grade;

    // Input student names and grades
    while (true) {
        std::cout << "Enter student name (or 'exit' to finish): ";
        std::getline(std::cin, name);

        if (name == "exit")
            break;

        std::cout << "Enter grade for " << name << ": ";
        std::cin >> grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input stream

        students.push_back({name, grade});
    }

    // Calculate average grade
    double sum = 0.0;
    double average = 0.0;
    double highest = 0.0;
    double lowest = 100.0;  // Assuming grades are between 0 and 100

    for (std::size_t i = 0; i < students.size(); ++i) {
        sum += students[i].grade;

        if (students[i].grade > highest)
            highest = students[i].grade;

        if (students[i].grade < lowest)
            lowest = students[i].grade;
    }

    if (!students.empty())
        average = sum / students.size();

    // Display average, highest, and lowest grades
    std::cout << "\nAverage grade: " << average << std::endl;
    std::cout << "Highest grade: " << highest << std::endl;
    std::cout << "Lowest grade: " << lowest << std::endl;

    return 0;
}
