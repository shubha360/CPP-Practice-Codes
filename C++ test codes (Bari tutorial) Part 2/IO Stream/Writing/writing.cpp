#include<fstream>

int main() {

    // std :: ofstream outfile("My.txt");

    // outfile << "Jon Snow" << std :: endl;
    // outfile << 24 << std :: endl;
    // outfile << 'N' << std :: endl;

    // outfile.close();

    std :: ofstream ofs("My.txt", std :: ios :: app);

    ofs << "Arya Stark" << std :: endl;
    ofs << "Tyrion Lannister" << std :: endl;

    return 0;
}