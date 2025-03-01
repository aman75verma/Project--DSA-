#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    int code;
    string surname;
    string name;
    char gender;
    int year;
    float grade;

    void display() const {
        cout << "Code: " << code << "\nName: " << name << " " << surname
             << "\nGender: " << gender << "\nYear: " << year 
             << "\nGrade: " << fixed << setprecision(2) << grade << "\n\n";
    }
};

class StudentDatabase {
private:
    vector<Student> students;
    const string filename = "students.dat";

    int findIndex(int code) const {
        for(size_t i = 0; i < students.size(); i++) {
            if(students[i].code == code) return i;
        }
        return -1;
    }

    void loadFromFile() {
        students.clear();
        ifstream file(filename);
        Student s;
        while(file >> s.code) {
            file.ignore();
            getline(file, s.surname, ',');
            getline(file, s.name, ',');
            file >> s.gender;
            file.ignore();
            file >> s.year;
            file.ignore();
            file >> s.grade;
            file.ignore();
            students.push_back(s);
        }
        file.close();
    }

    void saveToFile() const {
        ofstream file(filename);
        for(const auto& s : students) {
            file << s.code << ","
                 << s.surname << ","
                 << s.name << ","
                 << s.gender << ","
                 << s.year << ","
                 << s.grade << "\n";
        }
        file.close();
    }

public:
    StudentDatabase() {
        loadFromFile();
    }

    void addStudent() {
        Student newStudent;
        cout << "Enter student code: ";
        cin >> newStudent.code;
        
        if(findIndex(newStudent.code) != -1) {
            cout << "Error: Student code already exists!\n";
            return;
        }


        cout << "Enter name: ";
        getline(cin, newStudent.name);

        
        cout << "Enter surname: ";
        cin.ignore();
        getline(cin, newStudent.surname);

        

        cout << "Enter gender (M/F): ";
        cin >> newStudent.gender;
        newStudent.gender = toupper(newStudent.gender);

        cout << "Enter enrollment year: ";
        cin >> newStudent.year;

        cout << "Enter grade (0-20): ";
        cin >> newStudent.grade;
        newStudent.grade = max(0.0f, min(20.0f, newStudent.grade));

        students.push_back(newStudent);
        saveToFile();
        cout << "Student added successfully!\n";
    }

    void searchByCode() const {
        int code;
        cout << "Enter student code: ";
        cin >> code;

        int index = findIndex(code);
        if(index == -1) {
            cout << "Student not found!\n";
            return;
        }
        students[index].display();
    }

    void searchByName() const {
        string query;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for(const auto& s : students) {
            if(s.name.find(query) != string::npos || 
               s.surname.find(query) != string::npos) {
                s.display();
                found = true;
            }
        }
        if(!found) cout << "No matching students found.\n";
    }

    void deleteStudent() {
        int code;
        cout << "Enter student code to delete: ";
        cin >> code;

        int index = findIndex(code);
        if(index == -1) {
            cout << "Student not found!\n";
            return;
        }

        students.erase(students.begin() + index);
        saveToFile();
        cout << "Student deleted successfully!\n";
    }

    void updateStudent() {
        int code;
        cout << "Enter student code to update: ";
        cin >> code;

        int index = findIndex(code);
        if(index == -1) {
            cout << "Student not found!\n";
            return;
        }

        Student& s = students[index];
        cout << "Current details:\n";
        s.display();

        cout << "Enter new surname (current: " << s.surname << "): ";
        cin.ignore();
        string temp;
        getline(cin, temp);
        if(!temp.empty()) s.surname = temp;

        cout << "Enter new name (current: " << s.name << "): ";
        getline(cin, temp);
        if(!temp.empty()) s.name = temp;

        cout << "Enter new gender (current: " << s.gender << "): ";
        char g;
        if(cin.peek() != '\n') {
            cin >> g;
            s.gender = toupper(g);
        }

        cout << "Enter new year (current: " << s.year << "): ";
        if(cin.peek() != '\n') cin >> s.year;

        cout << "Enter new grade (current: " << s.grade << "): ";
        if(cin.peek() != '\n') {
            cin >> s.grade;
            s.grade = max(0.0f, min(20.0f, s.grade));
        }

        saveToFile();
        cout << "Student updated successfully!\n";
    }

    void listAll() const {
        if(students.empty()) {
            cout << "No students in database.\n";
            return;
        }

        cout << "Total students: " << students.size() << "\n";
        for(const auto& s : students) {
            s.display();
        }
    }
};

void displayMenu() {
    cout << "\n===== Student Database Management =====\n"
         << "1. Add New Student\n"
         << "2. Search by Code\n"
         << "3. Search by Name\n"
         << "4. Delete Student\n"
         << "5. Update Student\n"
         << "6. List All Students\n"
         << "7. Exit\n"
         << "Enter your choice: ";
}

int main() {
    StudentDatabase db;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1: db.addStudent(); break;
            case 2: db.searchByCode(); break;
            case 3: db.searchByName(); break;
            case 4: db.deleteStudent(); break;
            case 5: db.updateStudent(); break;
            case 6: db.listAll(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 7);

    return 0;
}
