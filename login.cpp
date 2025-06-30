#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// File name to store users
const string DATABASE_FILE = "users.txt";

// Encode password (simple method, can be replaced with hash)
string encodePassword(const string& password) {
    string encoded = password;
    for (char& ch : encoded) {
        ch += 1; // Simple shift cipher (not secure)
    }
    return encoded;
}

// Decode password
string decodePassword(const string& encoded) {
    string password = encoded;
    for (char& ch : password) {
        ch -= 1;
    }
    return password;
}

// Check if username already exists
bool usernameExists(const string& username) {
    ifstream infile(DATABASE_FILE);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string fileUser, filePass;
        ss >> fileUser >> filePass;
        if (fileUser == username) {
            return true;
        }
    }
    return false;
}

// Register a new user
void registerUser() {
    string username, password;

    cout << "Register\nUsername: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Error: Username already exists.\n";
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream outfile(DATABASE_FILE, ios::app);
    outfile << username << " " << encodePassword(password) << endl;

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    bool loginSuccess = false;

    cout << "Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream infile(DATABASE_FILE);
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string fileUser, filePass;
        ss >> fileUser >> filePass;

        if (fileUser == username && decodePassword(filePass) == password) {
            loginSuccess = true;
            break;
        }
    }

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Invalid username or password.\n";
    }
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}