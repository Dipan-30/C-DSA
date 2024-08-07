#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int NUM_STUDENTS = 2;

struct Student {
    string name;
    string address;
    int marks[5]; // [Math, Physics, Chemistry, Biology, English]
};

void findPassedAndFailedStudents(Student *students) {
    cout << "Students who have passed and failed in minimum three subjects:" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int failCount = 0;
        for (int j = 0; j < 5; j++) {
            if (students[i].marks[j] < 40) {
                failCount++;
            }
        }
        if (failCount >= 3) {
            cout << students[i].name << " has failed in " << failCount << " subjects." << endl;
        }
    }
}

void showMaxMathsMarks(Student *students) {
    int maxIndex = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (students[i].marks[0] > students[maxIndex].marks[0]) {
            maxIndex = i;
        }
    }
    cout << "Student with maximum marks in Mathematics:" << endl;
    cout << "Name: " << students[maxIndex].name << ", Address: " << students[maxIndex].address << endl;
    cout << "Marks: Math-" << students[maxIndex].marks[0] << ", Physics-" << students[maxIndex].marks[1] 
         << ", Chemistry-" << students[maxIndex].marks[2] << ", Biology-" << students[maxIndex].marks[3] 
         << ", English-" << students[maxIndex].marks[4] << endl;
}

void showMinPhysicsMarks(Student *students) {
    int minIndex = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (students[i].marks[1] < students[minIndex].marks[1]) {
            minIndex = i;
        }
    }
    cout << "Student with minimum marks in Physics:" << endl;
    cout << "Name: " << students[minIndex].name << ", Address: " << students[minIndex].address << endl;
    cout << "Marks: Math-" << students[minIndex].marks[0] << ", Physics-" << students[minIndex].marks[1] 
         << ", Chemistry-" << students[minIndex].marks[2] << ", Biology-" << students[minIndex].marks[3] 
         << ", English-" << students[minIndex].marks[4] << endl;
}

void showMaxAverageMarks(Student *students) {
    int maxIndex = 0;
    double maxAverage = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        double average = 0;
        for (int j = 0; j < 5; j++) {
            average += students[i].marks[j];
        }
        average /= 5;
        if (average > maxAverage) {
            maxAverage = average;
            maxIndex = i;
        }
    }
    cout << "Student with maximum average marks:" << endl;
    cout << "Name: " << students[maxIndex].name << ", Address: " << students[maxIndex].address << endl;
    cout << "Marks: Math-" << students[maxIndex].marks[0] << ", Physics-" << students[maxIndex].marks[1] 
         << ", Chemistry-" << students[maxIndex].marks[2] << ", Biology-" << students[maxIndex].marks[3] 
         << ", English-" << students[maxIndex].marks[4] << endl;
}

void printAllRecords(Student *students) {
    cout << "All student records with total marks:" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += students[i].marks[j];
        }
        cout << "Name: " << students[i].name << ", Total Marks: " << total << endl;
    }
}

int main() {
    Student students[NUM_STUDENTS];

    // Sample data entry
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, students[i].name);
        cout << "Address: ";
        getline(cin, students[i].address);
        cout << "Enter marks for Math, Physics, Chemistry, Biology, English: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].marks[j];
        }
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Find students who have passed and failed in minimum three subjects\n";
        cout << "2. Show record of student with maximum marks in Mathematics\n";
        cout << "3. Show record of student with minimum marks in Physics\n";
        cout << "4. Show record of student with maximum average marks\n";
        cout << "5. Print all student records with total marks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                findPassedAndFailedStudents(students);
                break;
            case 2:
                showMaxMathsMarks(students);
                break;
            case 3:
                showMinPhysicsMarks(students);
                break;
            case 4:
                showMaxAverageMarks(students);
                break;
            case 5:
                printAllRecords(students);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
