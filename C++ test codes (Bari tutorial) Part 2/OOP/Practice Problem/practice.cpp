// Roll
// Name
// Marks in 3
// Total Marks
// Grade

#include<iostream>

using namespace std;

class StudentInfo {

    int roll;
    string fullName;
    int physicsMarks;
    int chemistryMarks;
    int mathMarks;

    public :

    StudentInfo(int roll, string fullName, int physicsMarks, int chemistryMarks, int mathMarks) {

        this -> roll = roll;
        this -> fullName = fullName;
        this -> physicsMarks = physicsMarks;
        this -> chemistryMarks = chemistryMarks;
        this -> mathMarks = mathMarks;
    }
    
    int totalMarks() {
        
        return physicsMarks + chemistryMarks + mathMarks;
    }

    float average() {

        return totalMarks()/3.0f;
    }

    char grade() {

        return average() >= 60.0 ? 'A' : average() >= 40.0 ? 'B' : 'C';
    }

    string remarks() {

        return grade() == 'A' ? "Congratulations on your excellency! Keep it up." : 
        grade() == 'B' ? "You deserve more. Keep trying." : 
        "Everyone isn't perfect in everything ";
        }

    void showInfo() {

        cout << "Student name : " << fullName << endl;
        cout << "Student roll : " << roll << endl;
        cout << "Total marks : " << totalMarks() << endl;
        cout << "Average : " << average() << endl;
        cout << "Grade : " << grade() << endl;
        cout << "Remarks : " << remarks() << endl;
    }
};

int main() {

    int roll, physics, chemistry, math;
    string fullName;

    cout << "Enter students name : ";
    getline(cin, fullName);

    cout << "Enter students roll : ";
    cin >> roll;

    cout << "Enter marks obtained in physics : ";
    cin >> physics;

    cout << "Enter marks obtained in chemistry : ";
    cin >> chemistry;

    cout << "Enter marks obtained in Math : ";
    cin >> math;

    StudentInfo std1(roll,fullName,physics,chemistry,math);

    std1.showInfo();

    return 0;
}