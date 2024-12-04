#include <iostream>
using namespace std;

class student {
  public:
    int marks1, marks2, marks3, marks4, marks5;
    int roll, age;

    void info(int roll, int age) {
        this->roll = roll;
        this->age = age;
    }
    void Marks(int m1, int m2, int m3, int m4, int m5) {
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
        marks4 = m4;
        marks5 = m5;
    }
    int totalMarks() {
        return marks1 + marks2 + marks3 + marks4 + marks5;
    }
};

int main() {

    student std1, std2, std3, std4, std5;

    std1.info(1, 19);
    std2.info(2, 20);
    std3.info(3, 21);
    std4.info(4, 20);
    std5.info(5, 19);

    std1.Marks(20, 30, 40, 50, 60);
    std2.Marks(30, 30, 30, 40, 50);
    std3.Marks(40, 40, 40, 40, 40);
    std4.Marks(50, 50, 50, 50, 50);
    std5.Marks(100, 90, 80, 90, 60);

    student *topper = &std1;

    int maxMarks = std1.totalMarks();

    if (std2.totalMarks() > maxMarks) {
        topper = &std2;
        maxMarks = std2.totalMarks();
    }
    if (std3.totalMarks() > maxMarks) {
        topper = &std3;
        maxMarks = std3.totalMarks();
    }
    if (std4.totalMarks() > maxMarks) {
        topper = &std4;
        maxMarks = std4.totalMarks();
    }
    if (std5.totalMarks() > maxMarks) {
        topper = &std5;
        maxMarks = std5.totalMarks();
    }

    cout << "\nroll " << topper->roll;
    cout << "\nage " << topper->age;
    cout << "\nTotal Marks" << topper->totalMarks();
    return 0;
}