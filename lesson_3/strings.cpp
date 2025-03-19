#include <iostream>
#include <string>
#include <stdlib.h>     
#include <time.h>
using namespace std;

namespace strutil {
    const int offset = 'a' - 'A'; //32 ::scream::
    std::string toUpper(const std::string &str){
        std::string out;
        for (int i = 0;i < str.length();i++){
            if(str[i]>= 'a' && str[i] <='z'){
                out += str[i] - offset;
            }
            else{
                out +=str[i];
            }
        }
        return out;
    }
    
    std::string rand(int lenght){
        std::string out;
        for (int i = 1; i<= lenght; i++){
            out += 97 + ::rand() % ('z'-'a'+1);

        }
        return out;
    }
    int longestWordLength(const std::string &str){
        int max_length=0;
        int current=0;
        for (int i = 0;i < str.length();i++){
            if(str[i]==32){
                current = 0;
            }
            else{
                current++;
                if (current>max_length){
                    max_length = current;
                }
            }
        
        }
        return max_length;
    }
    void rot13(const std::string &str){
        const int root = 13;
        for (int i = 0;i < str.length();i++){
            if(str)
        }
    }
}

int main(){
    srand (time(NULL));
    std::string hi = "maczUUUUUUUzu";
    hi = strutil::toUpper(hi);
    cout<<hi<<endl;
    std::string random = strutil::rand(9);
    cout<<random<<endl;
    int long_phrase = strutil::longestWordLength("Witam elnruiehgiuefhguifhgfuighfuighfugo czesc siemanko");
    cout<<long_phrase<<endl;
}

