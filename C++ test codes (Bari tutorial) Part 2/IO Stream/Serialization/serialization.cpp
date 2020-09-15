#include<iostream>
#include<fstream>

class Student {

    public :

    std :: string name;
    int roll;
    char section; 

    friend std :: ofstream & operator << (std :: ofstream &ofs , Student &st);
    friend std :: ifstream & operator >> (std :: ifstream &ifs , Student &st);
};

    std :: ofstream & operator << (std :: ofstream &ofs , Student &st) {

        ofs << st.name << std :: endl;
        ofs << st.roll << std :: endl;
        ofs << st.section << std :: endl;
        
        return ofs;
    }

    std :: ifstream & operator >> (std :: ifstream &ifs , Student &st) {

        ifs >> st.name >> st.roll >> st.section;

        return ifs;
    }

int main() {

    Student st1, st2;

    // st1.name = "Tyrion";
    // st1.roll = 27;
    // st1.section = 'D';

    // st2.name = "Ramsay";
    // st2.roll = 4;
    // st2.section = 'A';


    // std :: ofstream ofs("SerialTest.txt", std :: ios :: trunc);

    // ofs << st1;
    // ofs << st2;

    // ofs.close();

    std :: ifstream ifs("SerialTest.txt");

    ifs >> st1 >> st2;
    ifs.close();

    std :: cout << "Name : " << st1.name << std :: endl;
    std :: cout << "Roll : " << st1.roll << std :: endl;
    std :: cout << "Section : " << st1.section << std :: endl;

    std :: cout << "Name : " << st2.name << std :: endl;
    std :: cout << "Roll : " << st2.roll << std :: endl;
    std :: cout << "Section : " << st2.section << std :: endl;

    return 0;
}