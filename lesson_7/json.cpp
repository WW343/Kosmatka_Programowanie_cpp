#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include <fstream>
#include <string>

using json = nlohmann::json;

struct Student {
    int id;
    std::string firstName;
    std::string lastName;
    float score;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, id, firstName,lastName,score)
};

void dump(){
    std::ifstream f("data.json");
    json data = json::parse(f);
    std::cout << data.dump() << std::endl;
}
// std::string firstName,std::string lastName,float score
void parse(){
    // srand (time(NULL));
    // int id = 0;
    std::ifstream f("data.json");
    std::stringstream buffer;
    buffer <<f.rdbuf();
    json data = json::parse(buffer.str());
    
    std::vector<Student> v = data;

    for (const auto &item : v)
    {
        std::cout << item.id << ": " << item.firstName<<' '<< item.lastName<<' '<<item.score << std::endl;
    }
}
int main(){
    dump();
    parse();
    return 0;
}