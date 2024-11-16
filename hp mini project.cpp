#include <iostream>
#include <string>
using namespace std;
const int MAX_CONTACTS = 100;
class Contact {
public:
string name;
string phoneNumber;
string email; // New email field
Contact(string n, string p, string e) : name(n), phoneNumber(p), email(e) {}
};
class Stack {
private:
Contact* stack[MAX_CONTACTS]; // Fixed-size array
int top; // Index for the top of the stack
public:
Stack() : top(-1) {} // Initialize stack as empty
void push(Contact* contact) {
if (top < MAX_CONTACTS - 1) {
stack[++top] = contact; // Add contact to stack
} else {
cout << "Contact stack is full!" << endl;
}
}
bool isEmpty() const {
return top == -1; // Check if stack is empty
}
int size() const {
return top + 1; // Return the number of contacts
}
void displayContacts() const {
for (int i = 0; i <= top; ++i) {
cout << "Name: " << stack[i]->name << ", Phone: " << stack[i]->phoneNumber
<< ", Email: " << stack[i]->email << endl;
}
}
Contact* getContact(int index) const {
return stack[index];
}
void removeAtIndex(int index) {
if (index >= 0 && index <= top) {
delete stack[index]; // Free memory
for (int i = index; i < top; ++i) {
stack[i] = stack[i + 1]; // Shift elements left
}
--top; // Reduce stack size
}
}
};
// Class to manage the contact book
class ContactBook {
private:
Stack contacts; // Stack of contacts
public:
void addContact(const string& name, const string& phoneNumber, const string& email) {
if (!isValidPhoneNumber(phoneNumber)) {
cout << "Invalid phone number. It must contain exactly 10 digits." << endl;
return;
}
if (!isValidEmail(email)) {
cout << "Invalid email format. Email must be '@gmail.com'." << endl;
return;
}
Contact* newContact = new Contact(name, phoneNumber, email); // Create new contact
contacts.push(newContact); // Add to stack
cout << "Contact added: " << name << endl;
}
void viewContacts() const {
if (contacts.isEmpty()) {
cout << "No contacts available." << endl;
return;
}
cout << "Contacts:\n";
contacts.displayContacts();
}
void searchContact(const string& name) const {
bool found = false;
for (int i = 0; i < contacts.size(); ++i) {
if (contacts.getContact(i)->name == name) {
cout << "Found contact: " << contacts.getContact(i)->name
<< ", Phone: " << contacts.getContact(i)->phoneNumber
<< ", Email: " << contacts.getContact(i)->email << endl;
found = true;
break;
}
}
if (!found) {
cout << "Contact not found." << endl;
}
}
// Function to modify a contact
void modifyContact(const string& name) {
bool found = false;
for (int i = 0; i < contacts.size(); ++i) {
if (contacts.getContact(i)->name == name) {
found = true;
cout << "Modifying contact: " << contacts.getContact(i)->name << endl;
string newName, newPhone, newEmail;
// Get new name
cout << "Enter new name (leave blank to keep current): ";
getline(cin, newName);
if (!newName.empty()) {
contacts.getContact(i)->name = newName;
}
// Get new phone number
cout << "Enter new phone number (leave blank to keep current): ";
getline(cin, newPhone);
if (!newPhone.empty() && isValidPhoneNumber(newPhone)) {
contacts.getContact(i)->phoneNumber = newPhone;
} else if (!newPhone.empty()) {
cout << "Invalid phone number. Must be 10 digits.\n";
}
// Get new email
cout << "Enter new email (leave blank to keep current): ";
getline(cin, newEmail);
if (!newEmail.empty() && isValidEmail(newEmail)) {
contacts.getContact(i)->email = newEmail;
} else if (!newEmail.empty()) {
cout << "Invalid email format. Must contain '@gmail.com'.\n";
}
cout << "Contact updated successfully.\n";
break;
}
}
if (!found) {
cout << "Contact not found." << endl;
}
}
// Function to delete a contact by name
void deleteContact(const string& name) {
bool found = false;
for (int i = 0; i < contacts.size(); ++i) {
if (contacts.getContact(i)->name == name) {
contacts.removeAtIndex(i); // Remove the contact at this index
cout << "Contact deleted: " << name << endl;
found = true;
break;
}
}
if (!found) {
cout << "Contact not found." << endl;
}
}
// Helper function to validate phone number (must be exactly 10 digits)
bool isValidPhoneNumber(const string& phoneNumber) const {
if (phoneNumber.length() != 10) {
return false; // Must be exactly 10 digits
}
for (int i = 0; i < phoneNumber.length(); ++i) {
if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
return false; // Return false if non-digit character is found
}
}
return true;
}
// Helper function to validate email
bool isValidEmail(const string& email) const {
// Ensure the email contains "@gmail.com"
size_t atPos = email.find('@');
string domain = "@gmail.com";
size_t domainPos = email.find(domain);
// Email must contain '@', and end with 'gmail.com'
return atPos != string::npos && domainPos != string::npos && domainPos == email.length() - domain.length();
}
};
int main() {
ContactBook book; // Create the contact book
int choice;
// Main menu loop
while (true) {
cout << "\n1. Add Contact\n";
cout << "2. View Contacts\n";
cout << "3. Search Contact by Name\n";
cout << "4. Modify Contact\n";
cout << "5. Delete Contact by Name\n";
cout << "6. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
cin.ignore();
switch (choice) {
case 1: {
string name, phoneNumber, email;
cout << "Enter name: ";
getline(cin, name);
cout << "Enter phone number: ";
getline(cin, phoneNumber);
cout << "Enter email: ";
getline(cin, email);
book.addContact(name, phoneNumber, email);
break;
}
case 2:
book.viewContacts();
break;
case 3: {
string name;
cout << "Enter name to search: ";
getline(cin, name);
book.searchContact(name);
break;
}
case 4: {
string name;
cout << "Enter the name of the contact to modify: ";
getline(cin, name);
book.modifyContact(name);
break;
}
case 5: {
string name;
cout << "Enter the name of the contact to delete: ";
getline(cin, name);
book.deleteContact(name);
break;
}
case 6:
cout << "Exiting.\n";
return 0;
default:
cout << "Invalid choice. Please try again.\n";
}
}
return 0;
}