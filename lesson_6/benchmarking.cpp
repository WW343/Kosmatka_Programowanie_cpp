

#include <string>
#include <chrono>
#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>

class TimeMeasurement
{
	std::string name;
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	
public:
	TimeMeasurement(std::string _name) : name(_name) {
		start = std::chrono::high_resolution_clock::now();
	}
	
	~TimeMeasurement() {
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		std::cout << name << ": " << duration.count() << " sec" << std::endl;
	}
};

int main()
{
	/* Wydzielamy blok kodu */
	{
		TimeMeasurement t("Krótka pętla wektora");
		/* Tutaj wywołany zostanie automatycznie konstruktor TimeMeasurement */
		std::vector<int> my_vector;
        for(int i = 0 ; i <100000;i++){
            my_vector.insert(my_vector.begin(), 0);
        }
		/* Tutaj wywołany zostanie automatycznie destruktor ~TimeMeasurement */
	}
    {
        TimeMeasurement t("Krótka pętla listy");
        std::list<int> my_list;
        for(int i = 0 ; i <100000;i++){
            my_list.insert(my_list.begin(), 0);
        }
    }

    {
        int n =10000;
        int sum = 0;

        std::vector<int>my_vector;
        my_vector.reserve(n);
        for(int i = 0 ; i <n;i++){
            my_vector.insert(my_vector.begin(), i);
        }
        TimeMeasurement t("Zad2 wektor");

        for(int i = 0 ; i <n;i++){
           sum += my_vector[i];
        }
    }
    {
        int sum = 0;
        int sum2 = 0;
        int n =10000;
        std::list<int> my_list;
        for(int i = 0 ; i <n;i++){
            my_list.push_back(i);
        }
        TimeMeasurement t("Zad2 lista");
        auto it = my_list.begin();
        for(int i = 0 ; i <n;i++){
            it++;
            sum += *it;
        }
        TimeMeasurement d("Zad2 lista wersja 2");
        for(int i : my_list){
            sum2 += i;
        }

    }

	return 0;
}