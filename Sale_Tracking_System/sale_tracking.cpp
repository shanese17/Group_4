#include <iostream>
#include <string>
#include <limits> // For numeric_limits
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";

int main() {
    const int MAX_CUSTOMERS = 100;
    int customerNumbers[MAX_CUSTOMERS];
    string names[MAX_CUSTOMERS];
    char sexes[MAX_CUSTOMERS];
    string addresses[MAX_CUSTOMERS];
    int totalSales[MAX_CUSTOMERS] = {0};
    int numPurchases[MAX_CUSTOMERS] = {0};

    int numCustomers = 0;
    int choice;

    do {
        cout << BLUE << "\n1. Add Customer\n2. Record Sale\n3. Customer Details and Sales Report\n4. Search Customer\n5. Summary Report\n6. Exit" << RESET << endl;
        cout << GREEN << "Enter your choice: " << RESET;
        cin >> choice;

        // Handle invalid input for choice
        while (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << RED << "Invalid choice. Please enter a number between 1 and 6: " << RESET;
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the newline character from the input buffer
                cout << GREEN << "Enter customer name: " << RESET;
                getline(cin, names[numCustomers]); // Use getline to capture spaces
                cout << GREEN << "Enter customer sex (M/F): " << RESET;
                cin >> sexes[numCustomers];
                cin.ignore(); // Clear the newline character from the input buffer
                cout << GREEN << "Enter customer address: " << RESET;
                getline(cin, addresses[numCustomers]); // Use getline for address
                customerNumbers[numCustomers] = numCustomers + 1;
                totalSales[numCustomers] = 0;
                numPurchases[numCustomers] = 0;
                numCustomers++;
                cout << CYAN << "Customer added successfully with customer number " << customerNumbers[numCustomers - 1] << RESET << endl;
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
                } else {
                    cout << RED << "Invalid customer number." << RESET << endl;
                }
                break;
            }









            case 5: {
                int totalNumSales = 0;
                int totalItemsSold = 0;
                for (int i = 0; i < numCustomers; i++) {
                    totalNumSales += totalSales[i];
                    totalItemsSold += numPurchases[i];
                }
                cout << "Summary Report" << endl;
                cout << "----------------" << endl;

cout << "Total Number of Customers: " << numCustomers << endl;
                cout << "Total Number of Sales: " << totalNumSales << endl;
                cout << "Total Number of Items Sold: " << totalItemsSold << endl;
                break;
            }

            case 6: {
                cout << "Exiting program..." << endl;
                break;
            }                      
        }
    } while (choice != 6);
    return 0;
}