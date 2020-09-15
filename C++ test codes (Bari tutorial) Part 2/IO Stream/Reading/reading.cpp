#include<iostream>
#include<fstream>

int main() {

    std :: ifstream ifs("D:\\Shubha\\Test Codes\\C++\\IO Stream\\Writing\\My.txt");
    // ifs.open("My.txt")

    if(!ifs) {
    // if(!ifs.is_open())

        std :: cout << "Couldn't open the file." << std :: endl;
        ifs.close();
        return 0;
    } 

    std :: string name;
    int age;
    char pact;

    while (ifs >> name >> age >> pact) {

        
    std :: cout << "Name : " << name << std :: endl;
    std :: cout << "Age : " << age << std :: endl;
    std :: cout << "Pact : " << pact << std :: endl;
    }
    
    ifs.close();

    return 0;
}