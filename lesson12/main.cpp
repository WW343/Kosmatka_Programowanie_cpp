#include <iostream>
#include <curl/curl.h>
#include <string>
#include <unistd.h>

class Curling{
    public:
        Curling(std::string name){
            curl = curl_easy_init(); 
            std::string url = "https://danepubliczne.imgw.pl/api/data/synop/id/" + name + "/format/csv";
            const char *cstr_url = url.c_str();
            curl_easy_setopt(curl, CURLOPT_URL,cstr_url);
        }

        void doing(){
            CURLcode result = curl_easy_perform(curl);
            if(result != CURLE_OK) {
                std::cerr << "CURL error: " << curl_easy_strerror(result) << std::endl;
            } else {
                std::cout << "CURL request successful." << std::endl;
            }
        }

        ~Curling(){
            curl_easy_cleanup(curl);
        }
    private:
        CURL *curl ;
};

int main(int argc,char *argv[]){
    Curling my_curl(argv[1]);
    my_curl.doing();
    // int aflag = 0;
    // int bflag = 0;
    char *tvalue = NULL;
    int index;
    int t;
  
    opterr = 0;
    
    while ((t = getopt (argc, argv, "hlt:")) != -1)
    switch (t)
      {
      case 'h':
        printf("help");
        break;
      case 'l':
      printf("lsit");
        break;
      case 't':
        tvalue = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }

    return 0;
}

// ten while nie działa bo nie nie obsługuje argumentów