
#include "Ulamek.hpp"

int main(){
    Ulamek moj_ulamek (1,6);
    std::cout<<"jeden"<<std::endl;

    std::cout<<moj_ulamek<<std::endl;

    Ulamek moj_ulamek_2 (4,7);

    std::cout<<"dwa"<<std::endl;

    moj_ulamek = moj_ulamek + moj_ulamek_2;
    std::cout<<moj_ulamek<<std::endl;

}