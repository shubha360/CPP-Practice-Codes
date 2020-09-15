#include<iostream>
#include<fstream>

class Item {

    public:

    std :: string name;
    int price;
    int quantity;

    Item() {};
    Item(std :: string name, int price, int quantity);
    friend std :: ofstream & operator << (std :: ofstream &ofs, Item it);
    friend std :: ifstream & operator >> (std :: ifstream &ifs, Item it);
    friend std :: ostream & operator << (std :: ostream &cout, Item it);
};

Item :: Item(std :: string name, int price, int quantity) {

    this -> name = name;
    this -> price = price;
    this -> quantity = quantity;
}

std :: ofstream & operator << (std :: ofstream &ofs, Item it) {

    ofs << it.name << std :: endl;
    ofs << it.price << std :: endl;
    ofs << it.quantity << std :: endl;

    return ofs;
}

std :: ifstream & operator >> (std :: ifstream &ifs, Item it) {

    ifs >> it.name >> it.price >> it.quantity;

    return ifs;
}

std :: ostream & operator << (std :: ostream &c, Item it) {

    c << "Item name : " << it.name << std :: endl;
    c << "Price : " << it.price << std :: endl;
    c << "Quantity : " << it.quantity << std :: endl;

    return c;
}

int main() {

    int n, price, quantity;
    std :: string name;

    std :: cout << "Enter number of items : ";
    std :: cin >> n;

    Item *list[n];

    for (int i = 0; i<n; i++) {

        std :: cout << "Name of item " << i + 1 << " : ";
        std :: cin >> name;
        std :: cout << "Enter price : ";
        std :: cin >> price;
        std :: cout << "Enter quantity : ";
        std :: cin >> quantity;

        list[i] = new Item(name, price, quantity);
    };

    std :: ofstream ofs("ItemList.txt", std :: ios :: trunc);

    for (int i = 0; i<n; i++) {
 
    ofs << (Item) *list[i];
    }

    ofs.close();

    std :: ifstream ifs("ItemList.txt");

    if (!ifs) {

        std :: cout << "Couldn't open the file.";
        return 0;
    }

    Item item;

    for (int i = 0; i<n; i++) {

        ifs >> item;
        std :: cout << item;
    }

    ifs.close();

    return 0;
}