#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

struct disc {
    std::string name;
    size_t size;
    std::vector<std::unique_ptr<disc>> top_discs;
};

std::vector<disc> discs_vector;

int main() {
    std::ifstream input_file;
    std::string single_input;
    input_file.open ("input.txt");
    if (input_file.is_open()) {
        while ( std::getline (input_file, single_input) )
        {
            std::cout << single_input << '\n';
        }
    input_file.close();
    }
}

void parse_name_size(std::string single_input) {
   std::string name = single_input.substr(0, single_input.find(" "));
   std::string size_with_brackets = single_input.substr(1, single_input.find(" "));
   
}

void parse_top_discs(std::string single_input) {

}
