#include <iostream>
#include <vector>
#include <fstream>



struct Product {
    std::string name;
    int price;
    int quantity;
};

void showAll(std::vector<Product> &products){
    for(size_t i = 0;i < products.size();i++){
        std::cout << products[i].name << "\t" << products[i].price << "\t" << products[i].quantity << std::endl;
    }

}
void addProtuct(std::vector<Product> &products,std::string name,int price,int quantity){
    Product p;
    p.name =  name;
    p.price = price;
    p.quantity = quantity;
    products.push_back(p); // ==    // products.push_back({name,price,quantity}); 
}
void deleteProduct(std::vector<Product> &products,std::string name){
    size_t i = 0;
    for(i;i<products.size();i++){
        if(products[i].name == name){
            products.erase(products.begin()+i);
            break;
        }
    }
}
void changeProductQuantity(std::vector<Product> &products,std::string name,int quantity){
    size_t i = 0;
    for(i;i<products.size();i++){
        if(products[i].name == name){
            products[i].quantity = quantity;
            break;
        }
    }
}

void findProduct(std::vector<Product> &products,std::string name){
    size_t i = 0;
    for(i;i<products.size();i++){
        if(products[i].name == name){
            std::cout << products[i].name << "\t" << products[i].price << "\t" << products[i].quantity << std::endl;
            break;
        }
    }
}
void read(std::vector<Product> &products,std::string filename){
    std::ifstream file_in(filename);
    Product new_product;
    while (!file_in.eof())
    {
        file_in>>new_product.name>>new_product.price>>new_product.quantity;
        products.push_back(new_product);
    }
}

void save(std::vector<Product> &products,std::string filename){
    std::ofstream my_file(filename);
    for(size_t i = 0;i < products.size();i++){
        my_file << products[i].name << "\t" << products[i].price << "\t" << products[i].quantity << std::endl;
    }
}

int main(int argc,char *argv[]){


    std::vector<Product> products;
    read(products,argv[1]);
    int option = 0;
    std::string name;
    int price;
    int quantity;

    // addProtuct(products,"jabko",8,32);
    // showAll(products);
    // deleteProduct(products,"marchewka");
    // showAll(products);
    while(true){
        std::cout<<"1.Show all products"<<std::endl; 
        std::cout<<"2.Add product"<<std::endl; 
        std::cout<<"3.Delete product by name"<<std::endl; 
        std::cout<<"4.Change quantity of product by name"<<std::endl; 
        std::cout<<"5.Find product by name"<<std::endl; 
        std::cout<<"6.Exit program"<<std::endl; 
        std::cin >> option;  


        switch(option){
            case 1:
                showAll(products);
                break;
            case 2:
                std::cout<<"Enter name ";
                std::cin>>name;
                std::cout<<"Enter price ";
                std::cin>>price;
                std::cout<<"Enter quantity ";
                std::cin>>quantity;
                addProtuct(products,name,price,quantity);
                break;
            case 3:
             std::cout<<"Enter name ";
                std::cin>>name;
                deleteProduct(products,name);
                break;
            case 4:
                std::cout<<"Enter name ";
                std::cin>>name;
                std::cout<<"Enter quantity ";
                std::cin>>quantity;
                changeProductQuantity(products,name,quantity);
                break;
            case 5:
                std::cout<<"Enter name ";
                std::cin>>name;
                findProduct(products,name);
                break;
            case 6:
                return 0;
                save(products,argv[1]);
            // default:
            //     std::cout<<"Invalid option"<<std::endl;
            //     break;
        }
    }
 
}
