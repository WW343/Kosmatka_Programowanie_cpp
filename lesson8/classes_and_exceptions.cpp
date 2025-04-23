#include <iostream>
#include <string>
#include <format>
#include <chrono>
#include <cctype>

using namespace std;
std::tuple<int, int, int> getCurrentDate() {
    const auto now = std::chrono::system_clock::now();
    std::chrono::year_month_day ymd = std::chrono::floor<std::chrono::days>(now);
    return std::make_tuple(int(ymd.year()), unsigned(ymd.month()), unsigned(ymd.day()));
}

/* Przykładowe użycie */
// int main() {
//     auto now = getCurrentDate();
//     std::cout << std::get<0>(now) << '-'
//               << std::get<1>(now) << '-'
//               << std::get<2>(now) << std::endl;
//     return 0;
// }
std::tuple<int, int, int> parseDate(const std::string &date) {
        int year = std::stoi(date);
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        return std::make_tuple(year, month, day);
    }
    
class Firma{
    public:
        Firma(const std::string &_name,
            const std::string &_nip,
            const std::string &_date,
            const std::string &_mail){
                name = _name;
                nip = _nip;
                date = _date;
                mail = _mail;
                if (name.length() <3 || name.length() >100){throw std::length_error("String lenght must be between 3 and 100");} /* checking lenght*/
                
                if (nip.length() != 10){throw std::length_error("Nip must be 10 digits long");}
                for(char character: nip){
                    if(!isdigit(character)){throw std::invalid_argument("Nip must be all digits only");} 
                }

                if(date.length() != 10){throw std::length_error("Date must be 10 digits long");}
                for(char character: date){
                    if (character == '-'){continue;}
                    if(!isdigit(character)){throw std::invalid_argument("Date must have YYYY-MM-DD syntax");} 
                }
                if(date[4] !='-' || date[7] != '-'){ throw std::invalid_argument("Wrong date syntax");}

                if(!mail.contains('@')){throw std::invalid_argument("Email must have @ character");}
            }

      public:
        std::string name;
        std::string nip;
        std::string date;
        std::string mail;

};



int main(){
    auto now = getCurrentDate();
    std::cout << std::get<0>(now) << '-'
              << std::get<1>(now) << '-'
              << std::get<2>(now) << std::endl;
    try{
        Firma struktura_firmy("ABc","1234567890","2026-02-31","m@ojmail.pl");
    }
    catch( const std::length_error &exception){
        std::cerr<<exception.what()<<std::endl;
    }
    catch(const std::invalid_argument &exception){
        std::cerr<<exception.what()<<std::endl;
    }

}