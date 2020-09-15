#include<iostream>
#include<vector>

// Function prototypes

int userPromopt();
void printNumbers(const std :: vector<int> &list);
void addNumber(const std :: vector<int> &list);
void search(const std :: vector<int> &list);
void displayAverage(const std :: vector<int> &list);
void displaySmallest(const std :: vector<int> &list);
void displayLargest(const std :: vector<int> &list);
void deleteNumber(std :: vector<int> &list);
void clearList(std :: vector<int> &list);
void exit();

// User promopt
    int userPromopt() {

        int number;

        std :: cout <<  "Enter number : ";
        std :: cin >> number;
        std :: cout << std :: endl;

        return number;
    };

// Print Numbers
    void printNumbers(const std :: vector<int> &list) {

        if (list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            for (int i = 0; i < list.size(); i++)
                std :: cout << list.at(i) << std :: endl;
        }
        std :: cout << std :: endl;
    };

// Add a Number (Don't allow duplicate entries)
    void addNumber(std :: vector<int> &list) {

        int number = userPromopt();

        for (int i = 0; i < list.size(); i++) {

            if (list.at(i) == number) {
                std :: cout << number << " is already in the list." << std :: endl;
                std :: cout << std :: endl;
                return;
            }
        }

        list.push_back(number);

        std :: cout << number << " was added to the list." << std :: endl;
        std :: cout << std :: endl;
    };

// Search for a number
    void search(const std :: vector<int> &list) {

        if(list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            int number = userPromopt();

            for (int i = 0; i < list.size(); i++) {

                if (list.at(i) == number) {

                    std :: cout << "Number found at index " << i << std :: endl;
                    std :: cout << std :: endl;
                    return;
                }
            }
            std :: cout << "Number is not in the list." << std :: endl;
        }

        std :: cout << std :: endl;
    };


// Display average
    void displayAverage(const std :: vector<int> &list) {
        
        if(list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            int total = 0, average;

            for (int i = 0; i < list.size(); i++)
                total += list.at(i);

            average = total / list.size();

            std :: cout << "Average is " << average << std :: endl;
        }

        std :: cout << std :: endl;
    };

// Display smallest
    void displaySmallest(const std :: vector<int> &list) {
        
        if(list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            int smallest = INT_MAX;

            for (int i = 0; i < list.size(); i++) {

                if(smallest > list.at(i))
                    smallest = list.at(i);
            }
            std :: cout << "Smallest number is " << smallest << std :: endl;
        }
        std :: cout << std :: endl;
    };

// Display largest
    void displayLargest(const std :: vector<int> &list) {

        if(list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            int largest = INT_MIN;

            for (int i = 0; i < list.size(); i++) {

                if(largest < list.at(i))
                    largest = list.at(i);
            }
            std :: cout << "Largest number is " << largest << std :: endl;
        }
        std :: cout << std :: endl;
    };

// Delete a number
    void deleteNumber(std :: vector<int> &list) {

        if(list.size() == 0)
        std :: cout << "List is currently empty." << std :: endl;

        else {

            int number = userPromopt();

            for (int i = 0; i < list.size(); i++) {

                if (list.at(i) == number){
                
                    list.erase(list.begin() + i);
                    std :: cout << number << " was deleted from the list." << std :: endl;
                }

                else std :: cout << "Number is not in the list." << std :: endl;
            }
        }
        std :: cout << std :: endl;
    };

// Clear list
    void clearList(std :: vector<int> &list) {

        list.clear();
        
        std :: cout << "List is cleared." << std :: endl;
        std :: cout << std :: endl;
    };

// Exit
    void exit() {

        std :: cout << "Thanks for using." << std :: endl;
        std :: cout << std :: endl;
    };

// Main function

int main() {

    std :: vector<int> numberList;
    int selection;

    while(selection != 9){
    std :: cout << "***Choose an option***" << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "\t1 - Print Numbers" << std :: endl;
    std :: cout << "\t2 - Add a Numbers" << std :: endl;
    std :: cout << "\t3 - Search a Number" << std :: endl;
    std :: cout << "\t4 - Display Average" << std :: endl;
    std :: cout << "\t5 - Display Smallest" << std :: endl;
    std :: cout << "\t6 - Display Largest" << std :: endl;
    std :: cout << "\t7 - Delete a Number" << std :: endl;
    std :: cout << "\t8 - Clear List" << std :: endl;
    std :: cout << "\t9 - Exit" << std :: endl;
    std :: cout << std :: endl;
    std :: cout << "Enter your selection : ";
    std :: cin >> selection;
    std :: cout << std :: endl;

    switch (selection) {

        case 1 :
        printNumbers(numberList);
        break;

        case 2 :
        addNumber(numberList);
        break;

        case 3 :
        search(numberList);
        break;

        case 4 :
        displayAverage(numberList);
        break;

        case 5 :
        displaySmallest(numberList);
        break;

        case 6 :
        displayLargest(numberList);
        break;

        case 7 :
        deleteNumber(numberList);
        break;

        case 8 :
        clearList(numberList);
        break;

        case 9 :
        exit();
        break;

        default :
        std :: cout << "Invalid input! Please try again." << std :: endl;
        std :: cout << std :: endl;
        break;
    }
    }
    return 0;
}