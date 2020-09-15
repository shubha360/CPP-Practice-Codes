#include<iostream>

using namespace std;

class Employee {

    string id;
    string name;

    public:

    Employee() {

        this -> id = "No input";
        this -> name = "No input";
    }

    Employee(string id, string name) {

        setId(id);
        setName(name);
    }

    void setId(string id) {

        this -> id = id;
    }

    void setName(string name) {

        this -> name = name;
    }

    string getId() {

        return this -> id;
    }

    string getName() {

        return this -> name;
    }
};

class FulltimeEmployee : public Employee {

    int salary;
    string department = "";

    public:

    FulltimeEmployee(string id, string name, int departmentCode, int salary) {

        setId(id);
        setName(name);
        setDepartment(departmentCode);
        setSalary(salary);
    }

    public:

    void setSalary(int salary) {

        this -> salary = salary;
    }

    void setDepartment(int departmentCode) {

        switch(departmentCode) {

            case 100 :
            this -> department = "Management";
            break;

            case 200 :
            this -> department = "Accounting";
            break;

            case 300 :
            this -> department = "Marketing";
            break;

            case 400 :
            this -> department = "Development";
            break;

            case 500 :
            this -> department = "Security";
            break;

            default :
            this -> department = "Invalid Department Code";
            break;
        }
    }

    int getSalary() {

        return this -> salary;
    }

    string getDepartment() {

        return this -> department;
    }

    void displayInfo() {

        cout << "Employee Name : " << getName() << endl;
        cout << "ID : " << getId() << endl;
        cout << "Employee Type : Fulltime" << endl;
        cout << "Department : " << getDepartment() << endl;
        cout << "Salary : " << salary << " monthly" << endl;
    }
};

class PartimeEmployee : public Employee {
    int salary;
    string department = "";

    public:

    PartimeEmployee(string id, string name, int departmentCode, int salary) {

        setId(id);
        setName(name);
        setDepartment(departmentCode);
        setSalary(salary);
    }

    public:

    void setSalary(int salary) {

        this -> salary = salary;
    }

    void setDepartment(int departmentCode) {

        switch(departmentCode) {

            case 100 :
            this -> department = "Management";
            break;

            case 200 :
            this -> department = "Accounting";
            break;

            case 300 :
            this -> department = "Marketing";
            break;

            case 400 :
            this -> department = "Development";
            break;

            case 500 :
            this -> department = "Security";
            break;

            default :
            this -> department = "Invalid Department Code";
            break;
        }
    }

    int getSalary() {

        return this -> salary;
    }

    string getDepartment() {

        return this -> department;
    }

    void displayInfo() {


        cout << "Employee Name : " << getName() << endl;
        cout << "ID : " << getId() << endl;
        cout << "Employee Type : Parttime" << endl;
        cout << "Department : " << getDepartment() << endl;
        cout << "Salary : " << salary << " daily" << endl;
    }
};

int main() {
    
    FulltimeEmployee fe1("ABD51389", "Nathan Drake", 400, 60000);
    PartimeEmployee pe1("XZY3930", "Harnan Crespo", 200, 500);

    fe1.displayInfo();

    cout << endl;
    
    pe1.displayInfo();

    return 0;
}