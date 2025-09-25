#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {

private:

    string name, department, bdg;
    int id, age;
    double cgpa;

public:
    void input() {
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, department);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cin.ignore();
        cout << "Enter Blood Group: ";
        getline(cin, bdg);
    }

    void show() {
        cout << "\n--- Student Profile ---\n";
        cout << "Name        : " << name << endl;
        cout << "ID          : " << id << endl;
        cout << "Department  : " << department << endl;
        cout << "Age         : " << age << endl;
        cout << "CGPA        : " << cgpa << endl;
        cout << "Blood Group : " << bdg << endl;
    }

    int getId() { return id; }

    void updateCg() {
        cout << "Enter updated CGPA: ";
        cin >> cgpa;
    }

    void saveToFile(ofstream &out) {
        out << name << "|" << id << "|" << department << "|" << age << "|" << cgpa << "|" << bdg << "\n";
    }
};

class UserAccount {
protected:
    string username, password;

public:
    void signUp() {
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;

        ofstream file("users.txt", ios::app);
        file << username << " " << password << endl;
        file.close();

        cout << "Account created successfully!\n";
    }

    bool signIn(string usn, string pss) {
        ifstream file("users.txt");
        string u, p;
        while (file >> u >> p) {
            if (u == usn && p == pss) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    UserAccount ua;
    Student s[500];
    int count = 0;
    int choice, SID;

    while (true) {
        cout << "\n=== Student Management System ===\n";
        cout << "1. Login\n2. Sign Up\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string usn, pss;
            cout << "Enter username: ";
            cin >> usn;
            cout << "Enter password: ";
            cin >> pss;

            if (ua.signIn(usn, pss)) {
                cout << "Login successful!\n";
                while (true) {
                    cout << "\n--- Student Menu ---\n";
                    cout << "1. Add Student\n2. Show Student Profile\n3. Update CGPA\n4. Search Student\n5. Save & Logout\n";
                    cout << "Enter choice: ";
                    cin >> choice;

                    if (choice == 1) {
                        s[count].input();
                        count++;
                    } else if (choice == 2) {
                        cout << "Enter Student ID: ";
                        cin >> SID;
                        bool found = false;
                        for (int i = 0; i < count; i++) {
                            if (s[i].getId() == SID) {
                                s[i].show();
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Student not found!\n";
                    } else if (choice == 3) {
                        cout << "Enter Student ID: ";
                        cin >> SID;
                        bool found = false;
                        for (int i = 0; i < count; i++) {
                            if (s[i].getId() == SID) {
                                s[i].updateCg();
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Student not found!\n";
                    } else if (choice == 4) {
                        cout << "Enter Student ID: ";
                        cin >> SID;
                        bool found = false;
                        for (int i = 0; i < count; i++) {
                            if (s[i].getId() == SID) {
                                s[i].show();
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Student not found!\n";
                    } else if (choice == 5) {
                        ofstream out("students.txt", ios::app);
                        for (int i = 0; i < count; i++) {
                            s[i].saveToFile(out);
                        }
                        out.close();
                        cout << "Data saved. Logged out!\n";
                        break;
                    }
                }
            } else {
                cout << "Invalid username or password!\n";
            }
        } else if (choice == 2) {
            ua.signUp();
        } else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        }
    }
    return 0;
}
