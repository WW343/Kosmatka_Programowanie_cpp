#include "Ulamek.hpp"

Ulamek::Ulamek(int a, int b){
    this -> a = a;
    this -> b = b;
}

Ulamek Ulamek::operator+(const Ulamek& other) const{
    int new_a = (this->a * other.b) + (other.a * this->b);
    int new_b = (this->b * other.a);
    // int sum = ()
    return Ulamek(new_a,new_b);
}

void Ulamek::optimize(){
    // zrób gcd
}