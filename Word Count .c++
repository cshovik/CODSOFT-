#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string word;
    std::string fname;
    int count = 0;

    std::cout << "Enter filename: ";
    std::cin >> fname;

    std::ifstream fin(fname);
    if (!fin) {
        std::cout << fname << " file doesn't exist" << std::endl;
        return 0;
    }

    std::cout << "\nContents of the file: \n\n";

    while (fin >> word) {
        ++count;
        std::cout << word << '\n';
    }

    fin.close();

    std::cout << "\nNumber of words in the file: " << count << std::endl;

    return 0;
}
