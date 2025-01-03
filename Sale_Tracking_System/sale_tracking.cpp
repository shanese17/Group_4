#include <iostream>
#include <string>
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";

const int MAX_CUSTOMERS = 100;
int customerNumbers[MAX_CUSTOMERS];
string names[MAX_CUSTOMERS];
char sexes[MAX_CUSTOMERS];
string addresses[MAX_CUSTOMERS];
int totalSales[MAX_CUSTOMERS] = {0};
int numPurchases[MAX_CUSTOMERS] = {0};
int numCustomers = 0;

void displayMenu() {
    cout << BLUE << "\n1. Add Customer\n2. Record Sale\n3. Customer Details and Sales Report\n4. Search Customer\n"
         << "5. Edit Customer\n6. Delete Customer\n7. Summary Report\n0. Exit" << RESET << endl;
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << GREEN << "Enter your choice: " << RESET;
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 0 || choice > 7) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << RED << "Invalid input. Please enter a number between 0 and 7: " << RESET;
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                if (numCustomers >= MAX_CUSTOMERS) {
                    cout << RED << "Customer limit reached. Cannot add more customers.\n" << RESET;
                    continue;
                }
                do {
                    cin.ignore();
                    cout << GREEN << "Enter customer name: " << RESET;
                    getline(cin, names[numCustomers]);
                    cout << GREEN << "Enter customer sex (M/F): " << RESET;
                    cin >> sexes[numCustomers];
                    cin.ignore();
                    cout << GREEN << "Enter customer address: " << RESET;
                    getline(cin, addresses[numCustomers]);

                    customerNumbers[numCustomers] = numCustomers + 1;
                    totalSales[numCustomers] = 0;
                    numPurchases[numCustomers] = 0;
                    numCustomers++;

                    cout << CYAN << "Customer added successfully with customer number " << customerNumbers[numCustomers - 1] << RESET << endl;

                    char c;
                    cout << "Would you like to add another customer? (Y/N): ";
                    cin >> c;


                    if (c != 'Y' && c != 'y') break;
                } while (true);
                break;
            }
            case 2: {
                int customerNumber, saleAmount;
                cout << GREEN << "Enter customer number: " << RESET;
                cin >> customerNumber;
                if (customerNumber > 0 && customerNumber <= numCustomers) {
                    cout << GREEN << "Enter sale amount: " << RESET;
                    cin >> saleAmount;
                    totalSales[customerNumber - 1] += saleAmount;
                    numPurchases[customerNumber - 1]++;
                    cout << CYAN << "Sale recorded successfully.\n" << RESET;
                } else {
                    cout << RED << "Invalid customer number.\n" << RESET;
                }
                break;
            }
            case 3: {
                cout << BLUE << "Customer Details and Sales Report\n" << RESET;
                cout << "---------------------------------------------------\n";
                cout << "Customer Number | Name | Sex | Address | Total Sales | Num Purchases | Avg Sales\n";
                for (int i = 0; i < numCustomers; i++) {
                    cout << customerNumbers[i] << " | " << names[i] << " | " << sexes[i] << " | " 
                         << addresses[i] << " | " << totalSales[i] << " | " << numPurchases[i] 
                         << " | " << (numPurchases[i] > 0 ? (totalSales[i] / numPurchases[i]) : 0) << endl;
                }
                break;
            }
            case 4: {
                int searchChoice;
                cout << BLUE << "1. Search by Customer Number\n2. Search by Name\n" << RESET;
                cout << GREEN << "Enter your choice: " << RESET;
                cin >> searchChoice;
                if (searchChoice == 1) {
                    int customerNumber;
                    cout << GREEN << "Enter customer number: " << RESET;
                    cin >> customerNumber;
                    if (customerNumber > 0 && customerNumber <= numCustomers) {
                        cout << CYAN << "Customer found with details:\n" << RESET;
                        cout << "Name: " << names[customerNumber - 1] << endl;
                        cout << "Sex: " << sexes[customerNumber - 1] << endl;
                        cout << "Address: " << addresses[customerNumber - 1] << endl;
                        cout << "Total Sales: " << totalSales[customerNumber - 1] << endl;
                        cout << "Num Purchases: " << numPurchases[customerNumber - 1] << endl;
                    } else {
                        cout << RED << "Invalid customer number.\n" << RESET;
                    }
                } else if (searchChoice == 2) {
                    cin.ignore();
                    string name;
                    cout << GREEN << "Enter customer name: " << RESET;
                    getline(cin, name);
                    bool found = false;
                    for (int i = 0; i < numCustomers; i++) {
                        if (names[i] == name) {
                            cout << CYAN << "Customer found with customer number " << customerNumbers[i] << RESET << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << RED << "Customer not found.\n" << RESET;
                    }
                }
                break;
            }
            case 5: {
                int customerNumber;
                cout << GREEN << "Enter customer number to edit: " << RESET;
                cin >> customerNumber;
                if (customerNumber > 0 && customerNumber <= numCustomers) {
                    int index = customerNumber - 1;
                    cin.ignore();
                    cout << GREEN << "Enter new name (current: " << names[index] << "): " << RESET;
                    getline(cin, names[index]);

                    cout << GREEN << "Enter new sex (current: " << sexes[index] << "): " << RESET;
                    cin >> sexes[index];
                    cin.ignore();
                    cout << GREEN << "Enter new address (current: " << addresses[index] << "): " << RESET;
                    getline(cin, addresses[index]);
                    cout << CYAN << "Customer details updated successfully.\n" << RESET;
                } else {
                    cout << RED << "Invalid customer number.\n" << RESET;
                }
                break;
            }
            case 6: {
                int customerNumber;
                cout << GREEN << "Enter customer number to delete: " << RESET;
                cin >> customerNumber;
                if (customerNumber > 0 && customerNumber <= numCustomers) {
                    int index = customerNumber - 1;
                    for (int i = index; i < numCustomers - 1; i++) {
                        customerNumbers[i] = customerNumbers[i + 1];
                        names[i] = names[i + 1];
                        sexes[i] = sexes[i + 1];
                        addresses[i] = addresses[i + 1];
                        totalSales[i] = totalSales[i + 1];
                        numPurchases[i] = numPurchases[i + 1];
                    }
                    numCustomers--;
                    cout << CYAN << "Customer deleted successfully.\n" << RESET;
                } else {
                    cout << RED << "Invalid customer number.\n" << RESET;
                }
                break;
            }
            case 7: {
                int totalNumSales = 0, totalItemsSold = 0;
                for (int i = 0; i < numCustomers; i++) {
                    totalNumSales += totalSales[i];
                    totalItemsSold += numPurchases[i];
                }
                cout << BLUE << "Summary Report\n" << RESET;
                cout << "----------------\n";
                cout << "Total Number of Customers: " << numCustomers << endl;
                cout << "Total Number of Sales: " << totalNumSales << endl;
                cout << "Total Number of Items Sold: " << totalItemsSold << endl;
                break;
            }
            case 0: {
                cout << CYAN << "Exiting program...\n" << RESET;
                break;
            }
            default:
                cout << RED << "Invalid input! Try again.\n" << RESET;
        }

        if (choice != 0) {
            char c;
            cout << GREEN << "Would you like to perform another operation? (Y/N): " << RESET;
            cin >> c;
            if (c != 'Y' && c != 'y') {
                choice = 0; // Exit the loop if user does not want to continue
            }
        }
    } while (choice != 0);

    return 0;
}
