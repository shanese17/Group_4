```mermaid
flowchart TD
    Start[Start Program] --> DisplayMenu[Display Menu]
    DisplayMenu --> AddCustomer[1. Add Customer]
    DisplayMenu --> RecordSale[2. Record Sale]
    DisplayMenu --> ViewReport[3. Customer Details and Sales Report]
    DisplayMenu --> SearchCustomer[4. Search Customer]
    DisplayMenu --> SummaryReport[5. Summary Report]
    DisplayMenu --> Exit[6. Exit Program]

    AddCustomer --> EnterCustomerDetails[Enter Customer Details]
    EnterCustomerDetails --> SuccessCustomer[Customer Added Successfully]
    SuccessCustomer --> DisplayMenu

    RecordSale --> EnterCustomerNumber[Enter Customer Number]
    EnterCustomerNumber --> CheckCustomerExists{Does Customer Exist?}
    CheckCustomerExists -- Yes --> EnterSaleAmount[Enter Sale Amount]
    EnterSaleAmount --> UpdateSales[Update Customer Sales Data]
    UpdateSales --> DisplayMenu
    CheckCustomerExists -- No --> Error[Display Error Message]
    Error --> DisplayMenu

    ViewReport --> ShowCustomerReport[Display Customer Details and Sales Report]
    ShowCustomerReport --> DisplayMenu

    SearchCustomer --> SearchOption{Search by?}
    SearchOption -- Customer Number --> SearchByNumber[Enter Customer Number]
    SearchByNumber --> CheckCustomerExistsSearch{Does Customer Exist?}
    CheckCustomerExistsSearch -- Yes --> ShowCustomerDetails[Display Customer Details]
    CheckCustomerExistsSearch -- No --> ErrorSearch[Display Error Message]
    SearchOption -- Name --> SearchByName[Enter Customer Name]
    SearchByName --> CheckNameExists{Does Name Exist?}
    CheckNameExists -- Yes --> ShowCustomerDetailsByName[Display Customer Details]
    CheckNameExists -- No --> ErrorName[Display Error Message]
    ShowCustomerDetails --> DisplayMenu
    ShowCustomerDetailsByName --> DisplayMenu
    ErrorSearch --> DisplayMenu
    ErrorName --> DisplayMenu

    SummaryReport --> CalculateSummary[Calculate Summary Data]
    CalculateSummary --> DisplaySummary[Display Summary Report]
    DisplaySummary --> DisplayMenu

    Exit --> End[End Program]
