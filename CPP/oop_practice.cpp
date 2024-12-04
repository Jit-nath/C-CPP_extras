#include <iostream>

using namespace std;

class employee {
    unsigned int age;
    int basic;
    int yearExp;
    float DA;
    float TA;

  public:
    void SetIncome(int basic, float DA, float TA) {
        this->basic = basic;
        this->DA = DA;
        this->TA = TA;
    }

    void SetExperience(int exp) {
        yearExp = exp;
    }
    void SetAge(unsigned int age) {
        this->age = age;
    }

    float EmployeeTotalIncome() {
        if (yearExp > 5) {
            return DA * basic + TA * basic + basic + 1200;
        } else
            return DA * basic + TA * basic + basic;
    }
};

int main() {
    employee Abhishek, Arpan, Prasun;

    float DA = 0.6;
    float TA = 0.1;

    Abhishek.SetIncome(100000, DA, TA);
    Abhishek.SetExperience(6);
    Abhishek.SetAge(25);

    Arpan.SetIncome(200000, DA, TA);
    Arpan.SetExperience(2);
    Arpan.SetAge(25);

    Prasun.SetIncome(80000, DA, TA);
    Prasun.SetExperience(0);
    Prasun.SetAge(25);

    cout << "Abhishek's income is : " << Abhishek.EmployeeTotalIncome() << endl;
    cout << "Arpan's income is : " << Arpan.EmployeeTotalIncome() << endl;
    cout << "Prasun's income is : " << Prasun.EmployeeTotalIncome() << endl;

    float TotalExpendeture = Abhishek.EmployeeTotalIncome() + Arpan.EmployeeTotalIncome() + Prasun.EmployeeTotalIncome();

    cout << "Total Cost of Employess : " << TotalExpendeture << endl;

    return 0;
}
