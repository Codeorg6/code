#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
    int marks[3];
    float averageMarks;
};

void addStudent(Student students[], int &n) {
    cout << "Enter student name: ";
    getline(cin, students[n].name);
    cout << "Enter student age: ";
    cin >> students[n].age;
    cout << "Enter marks for 3 subjects: ";
    for (int i = 0; i < 3; i++) {
        cin >> students[n].marks[i];
    }
    n++;
}

void displayStudents(Student students[], int n) {
    cout << "\nStudent Information:\n";
    cout << "Name\tAge\tMarks\tAverage\n";
    for (int i = 0; i < n; i++) {
        cout << students[i].name << "\t" << students[i].age << "\t";
        for (int j = 0; j < 3; j++) {
            cout << students[i].marks[j] << " ";
        }
        cout << "\t" << students[i].averageMarks << endl;
    }
}

void calculateAverages(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        students[i].averageMarks = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3.0;
    }
}

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].averageMarks < students[j + 1].averageMarks) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void findHighestLowest(Student students[], int n) {
    int highestIndex = 0, lowestIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].averageMarks > students[highestIndex].averageMarks) {
            highestIndex = i;
        }
        if (students[i].averageMarks < students[lowestIndex].averageMarks) {
            lowestIndex = i;
        }
    }
    cout << "\nHighest Average: " << students[highestIndex].name << " (" << students[highestIndex].averageMarks << ")" << endl;
    cout << "Lowest Average: " << students[lowestIndex].name << " (" << students[lowestIndex].averageMarks << ")" << endl;
}

void calculateClassAverage(Student students[], int n) {
    float classAverage = 0;
    for (int i = 0; i < n; i++) {
        classAverage += students[i].averageMarks;
    }
    classAverage /= n;
    cout << "\nClass Average: " << classAverage << endl;
}

int main() {
    Student students[100];
    int n = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Calculate Averages\n";
        cout << "4. Sort Students\n";
        cout << "5. Find Highest/Lowest\n";
        cout << "6. Calculate Class Average\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                calculateAverages(students, n);
                break;
            case 4:
                sortStudents(students, n);
                break;
            case 5:
                findHighestLowest(students, n);
                break;
            case 6:
                calculateClassAverage(students, n);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
