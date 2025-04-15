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

void dump() {
    std::ifstream f("data.json");
    json data = json::parse(f);

    // Wyświetlanie danych w konsoli
    std::cout << data.dump(4) << std::endl;

    // Zapis danych do pliku JSON
    std::ofstream outFile("output.json");
    if (outFile.is_open()) {
        outFile << data.dump(4); // Zapis z wcięciami dla lepszej czytelności
        outFile.close();
        std::cout << "Dane zapisano do pliku output.json" << std::endl;
    } else {
        std::cerr << "Nie udało się otworzyć pliku output.json do zapisu." << std::endl;
    }
}
// void dump(){
//     std::ifstream f("data.json");
//     json data = json::parse(f);
//     std::cout << data.dump() << std::endl;
// }
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