#include <iostream>
using namespace std;

int main(int argc,char *argv[],int what_to_do,int which_argument){
    do {
        cout<<"1. Wypisz ilość argumentów programu \n2. Wypisz wybrany argument programu \n3. Wypisz wszystkie argumenty programu \n4. Zakończ program"<<endl;
        cin >> what_to_do;
        switch(what_to_do){
            case 1:
                cout<<"The number of arguments is"<<endl;
                cout << argc <<endl;
                break;
            case 2:
                
                cout<<"Tell me which argument you want to print"<<endl;
                cin >> which_argument;
                if (which_argument < argc){
                        cout<<argv[which_argument]<<endl;
                        }
                else {
                    cout<<"There is not any argument of that id"<<endl;
                    break;
                    }
            case 3:
                for (int i=0;i<argc;i++){
                    cout<<argv[i]<<endl;
                };
                break;

        };

        }
    while(what_to_do<4 and what_to_do>=1);
    std::cerr<<"Invalid option";
    return 0;
};

