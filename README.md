**Sales Tracking Application**
**Overview**
This C++ application is a console-based Sales Tracking System. It allows users to:

1. Add customers to a system.
2. Record sales transactions for customers.
3. Generate customer sales reports.
4. Search for customers by name or customer number.
5. Generate a summary report of all customers and sales.
6. Exit the application.
**Code Description
Features**
1. Adding Customers:

i) Users can input customer details (name, sex, and address).
ii) Each customer is assigned a unique number.
iii) Customer data is stored in arrays.
2. Recording Sales:

i) Sales transactions can be recorded for existing customers using their customer numbers.
ii) The system tracks the total sales amount and the number of purchases for each customer.
3. Viewing Customer Details:

i) Displays a detailed sales report for each customer, including:
     Name, sex, and address.
     Total sales amount.
     Number of purchases.
     Average sales amount per purchase.
4. Searching for Customers:

i) Customers can be searched by:
      Customer Number: Directly fetches their details.
         Name: Searches the customer list and displays matching details.
5. Summary Report:

i) Summarizes overall statistics:
     Total number of customers.
     Total sales amount.
     Total items sold.
6. Exit:

i) Allows users to exit the application gracefully.
**Highlights of the Code**
**1 . Color-Coded User Interface**
- ANSI escape codes are used to add colors to the console output for better readability:
    GREEN: Prompts for input.
    BLUE: Menus and section headers.
    RED: Error messages.
    CYAN: Success messages.
**2. Input Validation**
- Ensures valid input using cin.fail() and clears invalid input with:
  
Copy code
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
**3. Switch Case Logic**
- A switch statement controls the menu functionality for easy navigation between options.
**4. Array-Based Data Storage**
- Arrays are used to store:
     Customer numbers, names, sexes, and addresses.
     Sales data such as total sales and the number of purchases.
**5. Reports and Search Functionality**
- Reports are displayed in tabular format for clarity.
- The search feature supports exact name matching and retrieval by customer number.
**Code Workflow**
1. Main Menu:
- The main menu is displayed in a loop, allowing users to select actions.
2. Adding Customers:
- New customers are appended to the arrays, and their details are saved.
3. Recording Sales:
- The system checks the validity of the customer number before recording the sale.
4. Generating Reports:
- Displays all customer details along with sales data.
5. Searching Customers:
- Supports two modes of searching: by name and by customer number.
6. Summary Report:
- Aggregates and displays overall sales and customer statistics.
7. Exit:
- Ends the loop and terminates the application.
**Example Usage**
1. Add Customer:
    -Input details like name, sex, and address.
    -A unique customer number is generated.
2. Record Sale:
   -Enter the customer number and sale amount.
   -The total sales and purchase count are updated.
3. View Report:
    -Displays a detailed report of all customers and their sales data.
4. Search Customer:
    -Locate a customer using their name or unique number.
5. Summary:
    -Displays overall statistics about sales and customers.
**Technologies Used**
-Language: C++
-Libraries:
     <iostream> for input/output.
     <string> for string operations.
     <limits> for handling input validation.
**Potential Enhancements**
1. Dynamic Data Storage:
    -Replace arrays with dynamic data structures (e.g., vectors or maps) for scalability.
2. Persistent Storage:
    -Save customer and sales data to a file for persistence between program executions.
3. Advanced Search:
    -Add partial or case-insensitive search capabilities.
4. Graphical Interface:
   -Upgrade to a GUI for better user experience.
