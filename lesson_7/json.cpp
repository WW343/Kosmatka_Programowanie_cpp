// #include <iostream>
// #include <vector>
// #include <fstream>
// #include "json.hpp"
// #include <fstream>
// #include <string>
// #include <algorithm>
// using json = nlohmann::json;

// struct Student {
//     int id;
//     std::string firstName;
//     std::string lastName;
//     float score;

//     NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, id, firstName,lastName,score)
// };

// void dump(){
//     std::ifstream f("data.json");
//     json data = json::parse(f);
//     std::cout << data.dump() << std::endl;
// }
// void parse(std::vector<Student> &v){

//     std::ifstream f("data.json");
//     std::stringstream buffer;
//     buffer <<f.rdbuf();
//     json data = json::parse(buffer.str());
//     *v = data.get<std::vector<Student>>();
// }



// void sortuj(std::vector<Student> *v){
//     std::sort(v->begin(),v->end(),[](const Student& a, const Student& b){ return a.score > b.score; });
        
//     }

// void find(std::vector<Student> &v, int idetifier){
//     auto it = std::find(v.begin(),v.end(),[idetifier](const Student& a){return a.id == idetifier;});
//     if(it != v.end()){
//         std::cout <<"Data of searched student: " << it->firstName << ' '<< it ->lastName << ' ' << it ->id << ' ' << it ->score << std::endl;
//     }
//     else{
//         std::cout<< "Student not found" << std::endl;
//     }
// }


// void display(std::vector<Student> &v){
//     for (const auto& student : v) {
//         std::string grade;
//         if (student.score >= 90) {
//             grade = "5";
//         } else if (student.score >= 80) {
//             grade = "4+";
//         } else if (student.score >= 70) {
//             grade = "4";
//         } else if (student.score >= 60) {
//             grade = "3+";
//         } else if (student.score >= 50) {
//             grade = "3";
//         } else {
//             grade = "2";
//         }
//         std::cout << student.id << ": " << student.firstName << " " 
//                   << student.lastName << " " << student.score 
//                   << " - Ocena: " << grade << std::endl;
//     }
// }

// int main(){
//     std::vector<Student> v ;

//     dump();
//     parse(&v);
//     return 0;
// }
#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include <string>
#include <algorithm>

using json = nlohmann::json;

struct Student {
    int id;
    std::string firstName;
    std::string lastName;
    float score;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, id, firstName, lastName, score)
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
    std::cout << data.dump() << std::endl;
}

void parse(std::vector<Student>& v) {  
    std::ifstream f("data.json");
    std::stringstream buffer;
    buffer << f.rdbuf();
    json data = json::parse(buffer.str());
    
    std::vector<Student> v = data;

    for (const auto &item : v)
    {
        std::cout << item.id << ": " << item.firstName<<' '<< item.lastName<<' ';
        [&](){
            if (item.score<50){std::cout<<'2';};

        
    }
}
int main(){
    dump();
    parse();
    v = data.get<std::vector<Student>>();
}

void sortuj(std::vector<Student>& v) { 
    std::sort(v.begin(), v.end(),
        [](const Student& a, const Student& b) { 
            return a.score > b.score; 
        });
}

void find(std::vector<Student>& v, int identifier) {
    auto it = std::find_if(v.begin(), v.end(), 
        [identifier](const Student& a) { 
            return a.id == identifier; 
        });
    
    if(it != v.end()) {
        std::cout << "Data of searched student: " 
                  << it->firstName << ' ' << it->lastName 
                  << " (ID: " << it->id 
                  << ", Score: " << it->score << ")\n";
    } else {
        std::cout << "Student not found\n";
    }
}

void display(std::vector<Student>& v) {
    for (const auto& student : v) {
        std::string grade;
        if (student.score >= 90)       grade = "5";
        else if (student.score >= 80) grade = "4+";
        else if (student.score >= 70) grade = "4";
        else if (student.score >= 60) grade = "3+";
        else if (student.score >= 50) grade = "3";
        else                          grade = "2";
        
        std::cout << student.id << ": " << student.firstName << " " 
                  << student.lastName << " - " << student.score 
                  << "% (" << grade << ")\n";
    }
}

// int main() {
//     std::vector<Student> students;
    
//     dump();        
//     parse(students); 
    
//     std::cout << "\n=== Przed sortowaniem ===\n";
//     display(students);
    
//     sortuj(students); // Sortuj
//     std::cout << "\n=== Po sortowaniu ===\n";
//     display(students);
    
//     std::cout << "\n=== Wyszukiwanie ===\n";
//     find(students, 123); // Przykładowe ID

//     return 0;
// }
void displayStudent(const Student& s) {
    std::string grade;
    if (s.score >= 90)       grade = "5";
    else if (s.score >= 80) grade = "4+";
    else if (s.score >= 70) grade = "4";
    else if (s.score >= 60) grade = "3+";
    else if (s.score >= 50) grade = "3";
    else                    grade = "2";
    
    std::cout << s.id << ": " << s.firstName << " " << s.lastName 
              << " - " << s.score << "% (" << grade << ")\n";
}

void displayAllStudents(const std::vector<Student>& students) {
    for (const auto& s : students) {
        displayStudent(s);
    }
}

// Główne funkcje
void findStudentById(const std::vector<Student>& students, int id) {
    auto it = std::find_if(students.begin(), students.end(),
        [id](const Student& s) { return s.id == id; });
    
    if (it != students.end()) {
        std::cout << "Znaleziono studenta:\n";
        displayStudent(*it);
    } else {
        std::cout << "Nie znaleziono studenta o ID: " << id << "\n";
    }
}

double calculateAverageScore(const std::vector<Student>& students) {
    if (students.empty()) return 0.0;
    
    double sum = std::accumulate(students.begin(), students.end(), 0.0,
        [](double acc, const Student& s) { return acc + s.score; });
    
    return sum / students.size();
}

void countPassedFailed(const std::vector<Student>& students, 
                      int& passed, int& failed) {
    passed = std::count_if(students.begin(), students.end(),
        [](const Student& s) { return s.score >= 50; });
    failed = students.size() - passed;
}

void removeFailedStudents(std::vector<Student>& students) {
    students.erase(
        std::remove_if(students.begin(), students.end(),
            [](const Student& s) { return s.score < 50; }),
        students.end());
}

void sortStudentsByScore(std::vector<Student>& students, bool descending = true) {
    if (descending) {
        std::sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { 
                return a.score > b.score; 
            });
    } else {
        std::sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) { 
                return a.score < b.score; 
            });
    }
}

void saveToJson(const std::vector<Student>& students, const std::string& filename) {
    json j = students;
    std::ofstream o(filename);
    o << j.dump(4) << std::endl;
}

int main() {
    std::vector<Student> students;
    
    // Wczytanie danych
    try {
        std::ifstream f("data.json");
        json data = json::parse(f);
        students = data.get<std::vector<Student>>();
    } catch (const std::exception& e) {
        std::cerr << "Błąd wczytywania pliku: " << e.what() << std::endl;
        return 1;
    }

    // Menu główne
    while (true) {
        std::cout << "\n===== MENU =====" << std::endl;
        std::cout << "1. Wyświetl wszystkich studentów" << std::endl;
        std::cout << "2. Znajdź studenta po ID" << std::endl;
        std::cout << "3. Oblicz średni wynik" << std::endl;
        std::cout << "4. Statystyki zdawalności" << std::endl;
        std::cout << "5. Usuń niezdających studentów" << std::endl;
        std::cout << "6. Sortuj studentów" << std::endl;
        std::cout << "7. Zapisz dane do pliku" << std::endl;
        std::cout << "8. Wyjście" << std::endl;
        std::cout << "Wybierz opcję: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nLista studentów:\n";
                displayAllStudents(students);
                break;
            }
            case 2: {
                int id;
                std::cout << "Podaj ID studenta: ";
                std::cin >> id;
                findStudentById(students, id);
                break;
            }
            case 3: {
                double avg = calculateAverageScore(students);
                std::cout << "\nŚredni wynik: " << avg << "%\n";
                break;
            }
            case 4: {
                int passed, failed;
                countPassedFailed(students, passed, failed);
                std::cout << "\nStatystyki:\n";
                std::cout << "Zdających: " << passed << "\n";
                std::cout << "Niezdających: " << failed << "\n";
                break;
            }
            case 5: {
                int initialSize = students.size();
                removeFailedStudents(students);
                std::cout << "Usunięto " << initialSize - students.size() 
                          << " niezdających studentów\n";
                break;
            }
            case 6: {
                std::cout << "Sortowanie:\n";
                std::cout << "1. Malejąco\n";
                std::cout << "2. Rosnąco\n";
                int sortChoice;
                std::cin >> sortChoice;
                sortStudentsByScore(students, sortChoice == 1);
                std::cout << "Posortowano studentów\n";
                break;
            }
            case 7: {
                saveToJson(students, "output.json");
                std::cout << "Zapisano dane do pliku output.json\n";
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                std::cout << "Nieprawidłowa opcja!\n";
                break;
            }
        }
    }

    return 0;
}