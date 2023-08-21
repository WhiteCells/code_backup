#include <iostream>

/*
使用 char 的位，1 byte = 8 bit
选课功能
退课功能
查询功能
 */

#define ALGORITHM_DESIGN                0b00000001
#define COLLEGE_PHYSICS                 0b00000010
#define COLLEGE_ENGLISH                 0b00000100
#define COMPUTER_NETWORK                0b00001000
#define ELECTRONIC_TECHNOLOGY           0b00010000
#define COMPUTER_COMPOSITION            0b00100000
#define COMPUTER_OPERATING_SYSTEM       0b01000000
#define DATA_STRUCTURE_BUDGETING_METHOD 0b10000000

/*
选课
 */
void SelectCourse(char* student, char course) {
    *student |= course;
}

/*
退课
 */
void WithdrawalCourse(char* student, char course) {
    *student &= ~course;
}

/*
查询
 */
bool QueryCourse(char* student, char course) {
    return *student & course;
}

/*
打印已选
 */
void PrintSelectedCourse(char* student) {

}

int main() {
    char student = 0b00000000;
    SelectCourse(&student, ALGORITHM_DESIGN);
    SelectCourse(&student, COLLEGE_ENGLISH);
    SelectCourse(&student, COMPUTER_OPERATING_SYSTEM);
    SelectCourse(&student, ELECTRONIC_TECHNOLOGY);

    if (QueryCourse(&student, COLLEGE_ENGLISH)) {
        std::cout << "the student chose ELECTRONIC_TECHNOLOGY" << '\n';
    }
    else {
        std::cout << "students did not choose ELECTRONIC_TECHNOLOGY" << '\n';
    }

    WithdrawalCourse(&student, COLLEGE_ENGLISH);
    if (QueryCourse(&student, COLLEGE_ENGLISH)) {
        std::cout << "the student chose ELECTRONIC_TECHNOLOGY" << '\n';
    }
    else {
        std::cout << "student did not choose ELECTRONIC_TECHNOLOGY" << '\n';
    }
    PrintSelectedCourse(&student);
    return 0;
}