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

bool nipValidate(const std::string nip){
    std::vector<int> weights = {6, 5, 7, 2, 3, 4, 5, 6, 7};
    int sum = 0;
    for(int i = 0; i<9;i++){
        sum += (weights[i]) * (nip[i]-'0');
    };
    sum = sum % 11;
    // if(sum == (nip[9]-'0')) {
    //     return true;
    // }
    // else if (sum == 10) {
    //     return false;
    // }
    // else{
    //     return false;
    // }
    if(sum == 10 ) return false;
    return (sum == (nip[9]-'0'));
}

class Firma{

    public:
        Firma(const std::string &_name,
            const std::string &_nip,
            const std::string &_date,
            const std::string &_mail){
                auto now = getCurrentDate();
                name = _name;
                nip = _nip;
                date = _date;
                mail = _mail;
                auto [currentYear,currentMonth,currentDay] =  getCurrentDate();
                auto [inputYear,inputMonth,inputDay] = parseDate(date);
                static constexpr int dayInEachMonth[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29}; /* the last number is when year is Leap(every 4 years)*/
                int currentDayRange = dayInEachMonth[inputMonth-1];
                // Name
                if (name.length() <3 || name.length() >100){throw std::length_error("String lenght must be between 3 and 100");} /* checking lenght*/
                
                
                // NIP
                if (nip.length() != 10){throw std::length_error("Nip must be 10 digits long");} /*checking nip length*/

                for(char character: nip){
                    if(!isdigit(character)){throw std::invalid_argument("Nip must be all digits only");}  /*checking if nip is digit*/
                }

                if(nipValidate(nip)==false){throw std::domain_error("Incorect nip (from nip validate)");} /*checking if nip is validate*/

                // Date
                if(date.length() != 10){throw std::length_error("Date must be 10 digits long");} /*checking date lenght*/

                for(char character: date){
                    if (character == '-'){continue;}
                    if(!isdigit(character)){throw std::invalid_argument("Date must have YYYY-MM-DD syntax");}  /*checking date syntax*/
                }

                if(date[4] !='-' || date[7] != '-'){ throw std::invalid_argument("Wrong date syntax");} /*checking date syntax*/

                if(inputYear < 2000 || inputYear > currentYear){throw std::domain_error("Wrong date year range");} /*checking year range*/

                if(inputMonth < 1 || inputMonth > 12){throw std::domain_error("Month number must be beetwen 1-12");} /*checking month range*/

                if(inputYear ==currentYear){
                    if(inputMonth>currentMonth){throw std::domain_error("This day hasn't come yet");} /*checking month in current year*/
                }
                if(inputDay > currentDayRange && inputDay >0 ){
                    throw std::domain_error("This day isn't in this month(1)"); /*checking day based on month*/
                    std::cout << currentDayRange << std::endl; 
                }

                if((date[3]-'0')%4 == 0){
                    if(inputDay > dayInEachMonth[13] && inputDay >0 && inputMonth == 2){
                        throw std::domain_error("This day isn't in this month(2)"); /*checking day based on month if year is leap*/
                    }
                }
                if(inputYear == currentYear && inputMonth == currentMonth&& inputDay >0){
                    if(inputDay>currentDay){throw std::domain_error("This day isn't in this month(3)");} /*checking if day ever been */
                }



                // Email
                if(!mail.contains('@')){throw std::invalid_argument("Email must have @ character");}
            }
// Napraw bo źle:
      public:
        std::string name;
        std::string nip;
        std::string date;
        std::string mail;

};



int main(){
    auto now = getCurrentDate();
    // std::cout << std::get<0>(now) << '-'
    //           << std::get<1>(now) << '-'
    //           << std::get<2>(now) << std::endl;
    try{
        Firma struktura_firmy("ABc","1234563218","2025-12-30","m@ojmail.pl");
        // Nip:"1234563218" (valid),"0000000000" (invalid)
    }
    catch( const std::length_error &exception){
        std::cerr<<exception.what()<<std::endl;
    }
    catch(const std::invalid_argument &exception){
        std::cerr<<exception.what()<<std::endl;
    }
    catch(const std::domain_error &exception){
        std::cerr<< exception.what()<< std::endl;
    }

}

// comand to compile in windows: "g++ -o less8.exe .\classes_and_exceptions.cpp -std=c++23"
// -std=c++23  => is to use contains in 112 line and chrono from getCurrentDay() function