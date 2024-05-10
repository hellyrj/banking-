#include <iostream> // Include input-output stream library
#include <string> // Include string manipulation library
#include <chrono> // Include chrono library for time-related operations
#include <ctime> // Include ctime library for time functions
#include <cstdlib> // Include cstdlib library for standard library functions
#include <regex> // Include regex library for regular expressions

using namespace std; // Use standard namespace

const int MAX_ACCOUNTS = 10; // Define maximum number of accounts
int totalUsers = 0; // Initialize total number of users

int main() { // Main function

    string first_Name[10], last_Name[10], bank_PIN[10], account_number[10]; // Declare arrays to store user data
    int array_deposit[10] = {0}; // Initialize array to store user deposits
    const int MAX_TRANSACTIONS = 100; // Define maximum number of transactions
    string transactionHistories[MAX_ACCOUNTS][MAX_TRANSACTIONS]; // Declare array to store transaction history
    int transactionCounts[MAX_ACCOUNTS] = {0}; // Initialize array to store transaction counts per user
    string withdrawalTransaction,emailAddress,phoneNumber; // Declare variables for withdrawal transaction and user contact information
    string depositTransaction; // Declare variable for deposit transaction
    string transferTransaction; // Declare variable for transfer transaction
    string receivedTransaction; // Declare variable for received transaction
    string recipient_name; // Declare variable for recipient's name
    bool isLoggedIn,changeaccountdetail,valid; // Declare boolean variables for login status, account detail change, and input validation
    cout<<"welcome to the online bank system\n"; // Print welcome message

    while (true) { // Start infinite loop for menu

        int choice; // Declare variable to store user choice
        cout << "Enter your choice: \n "; // Prompt user for choice
        cout << "1. Create Account\n"; // Option to create account
        cout << "2. Login\n"; // Option to login
        cout << "3. Exit\n"; // Option to exit
        cin >> choice; // Read user choice
        system("cls"); // Clear screen

        switch (choice) { // Start switch statement based on user choice
            case 1: // Create Account
                if (totalUsers < 10) { // Check if maximum number of users has not been reached
                    cout << "Enter your first name: "; // Prompt user for first name
                    cin >> first_Name[totalUsers]; // Read user's first name

                    bool hasNonAlpha = false; // Declare and initialize variable to check for non-alphabetic characters
                    for (char c : first_Name[totalUsers]) { // Iterate through characters in first name
                        if (!isalpha(c)) { // Check if character is not alphabetic
                            hasNonAlpha = true; // Set flag to true
                            break; // Exit loop
                        }
                    }

                    if (hasNonAlpha) { // Check if first name contains non-alphabetic characters
                        cout << "Invalid input. Please enter a valid first name.\n"; // Print error message
                        continue; // Skip to next iteration of loop
                    }

                    cout << "Enter your last name: "; // Prompt user for last name
                    cin >> last_Name[totalUsers]; // Read user's last name

                    hasNonAlpha = false; // Reset flag for non-alphabetic characters
                    for (char c : last_Name[totalUsers]) { // Iterate through characters in last name
                        if (!isalpha(c)) { // Check if character is not alphabetic
                            hasNonAlpha = true; // Set flag to true
                            break; // Exit loop
                        }
                    }if (hasNonAlpha) { // Check if last name contains non-alphabetic characters
                        cout << "Invalid input. Please enter a valid last name.\n"; // Print error message
                        continue; // Skip to next iteration of loop
                    }



                    valid=false; // Initialize validation flag to false
                    regex pattern(R"(09\d{8})"); // Define regex pattern for phone number validation

                    while (true) { // Start loop for phone number input validation
                        cout << "Enter phone number(+251): "; // Prompt user for phone number
                        cin >> phoneNumber; // Read user's phone number

                        if (phoneNumber.length() != 10) { // Check if phone number length is not 10 digits
                            cout << "Invalid PHONE NUMBER. PHONE NUMBER must be 10 digits.\n"; // Print error message
                        } else if (!regex_match(phoneNumber, pattern)) { // Check if phone number format is invalid
                            cout << "Invalid PHONE NUMBER. PHONE NUMBER must have a format of 09..... .\n"; // Print error message
                        } else { // If phone number is valid
                            break; // Exit loop
                        }
                    }

                    regex emailpattern(R"([\w-]+(?:\.[\w-]+)*@(?:[\w-]+\.)+[a-zA-Z]{2,7})"); // Define regex pattern for email validation

                    while (true) { // Start loop for email address input validation
                        cout << "Enter email address: "; // Prompt user for email address
                        cin >> emailAddress; // Read user's email address

                        if (!regex_match(emailAddress, emailpattern)) { // Check if email address format is invalid
                            cout << "Invalid email address format\n"; // Print error message
                        } else { // If email address is valid
                            break; // Exit loop
                        }
                    }

                    while(!valid){ // Start loop for PIN input validation
                        cout << "set a PIN(it must be length of 6 (you can use special character,number and alphabet)): "; // Prompt user for PIN
                        cin >> bank_PIN[totalUsers]; // Read user's PIN
                        if(bank_PIN[totalUsers].length()==6){ // Check if PIN length is 6 characters
                            valid=true; // Set validation flag to true
                        }
                        else{ // If PIN length is not 6 characters
                            cout << "Invalid PIN! PIN must be 6 characters.\n"; // Print error message
                        }
                    }

                    srand(time(0)); // Seed random number generator
                    int randomNumber = rand() % 900000 + 100000; // Generate random account number
                    cout << "Your account number is: " << randomNumber << '\n'; // Print account number
                    account_number[totalUsers] = to_string(randomNumber); // Store account number as string
                    totalUsers++; // Increment total number of users
                    cout << "Account created successfully!\n"; // Print success message
                } else { // If maximum number of users has been reached
                    cout << "Sorry, new account creation is currently unavailable"; // Print error message
                }
                break; // Exit switch statement

            case 2: { // Login
                int tries = 0; // Declare and initialize variable for login attempts
                bool isAuthenticated = false; // Declare and initialize variable for authentication statuswhile (!isAuthenticated && tries < 3) { // Start loop for login attempts
                    string Bank_PIN, Account_number; // Declare variables for user input
                    cout << "Enter your bank account number: "; // Prompt user for account number
                    cin >> Account_number; // Read user's account number
                    cout << "Enter your bank PIN: "; // Prompt user for PIN
                    cin >> Bank_PIN; // Read user's PIN

                    bool pinFound = false; // Declare and initialize variable to check for PIN match
                    int index = -1; // Declare and initialize variable to store user index

                    for (int i = 0; i < MAX_ACCOUNTS; ++i) { // Iterate through user accounts
                        if (Bank_PIN == bank_PIN[i] && Account_number == account_number[i]) { // Check if PIN and account number match
                            pinFound = true; // Set flag to true
                            index = i; // Store user index
                            break; // Exit loop
                        }
                    }

                    if (pinFound) { // If PIN and account number match
                        isAuthenticated = true; // Set authentication status to true
                        cout << "Login successful; Welcome, " << first_Name[index] << " " << last_Name[index] << "!\n"; // Print login success message
                        isLoggedIn = true; // Set login status to true
                        // Start loop for user actions while logged in
                        while (isLoggedIn) {
                            int choice; // Declare variable to store user choice
                            cout << "enter your choice: "<<endl; // Prompt user for choice
                            cout << "1. Make a deposit" << endl; // Option to make a deposit
                            cout << "2. Make a withdrawal" << endl; // Option to make a withdrawal
                            cout << "3. Make a transfer" << endl; // Option to make a transfer
                            cout << "4. Check your balance" << endl; // Option to check balance
                            cout << "5. Transaction history" <<endl; // Option to view transaction history
                            cout << "6. Change account details" <<endl; // Option to change account details
                            cout << "7. Exit" << endl; // Option to exit
                            cin >> choice; // Read user choice

                            { // Calculate interest
                                double interestRate = 0.3; // Define interest rate
                                double interest = array_deposit[index] * (interestRate / 100); // Calculate interest
                                array_deposit[index] += interest; // Add interest to deposit
                            }

                            switch (choice) { // Start switch statement based on user choice
                                case 1: { // Make a deposit
                                    int depositAmount; // Declare variable for deposit amount
                                    cout << "Enter the amount of money you want to deposit: "; // Prompt user for deposit amount
                                    cin >> depositAmount; // Read deposit amount
                                    array_deposit[index] += depositAmount; // Add deposit amount to account balance
                                    cout << "Deposit successful!" << endl; // Print success message
                                    auto now = chrono::system_clock::now(); // Get current time
                                    time_t now_c = chrono::system_clock::to_time_t(now); // Convert time to time_t format
                                    depositTransaction = std::ctime(&now_c) + to_string(depositAmount) + " Deposited"; // Create deposit transaction messagetransactionHistories[index][transactionCounts[index]] = depositTransaction; // Store deposit transaction
                                    transactionHistories[index][transactionCounts[index]] = depositTransaction; // Store deposit transaction
                                    transactionCounts[index]++; // Increment transaction count
                                    break; // Exit switch statement
                                }
                                case 2: { // Make a withdrawal
                                    int withdrawalAmount; // Declare variable for withdrawal amount
                                    cout << "Enter the amount of money you want to withdraw: "; // Prompt user for withdrawal amount
                                    cin >> withdrawalAmount; // Read withdrawal amount
                                    if (withdrawalAmount > array_deposit[index]) { // Check if withdrawal amount exceeds balance
                                        cout << "You don't have enough balance." << endl; // Print error message
                                    } else { // If withdrawal amount is within balance
                                        array_deposit[index] -= withdrawalAmount; // Deduct withdrawal amount from account balance
                                        cout << "Withdrawal successful!" << endl; // Print success message
                                    }
                                    auto now = chrono::system_clock::now(); // Get current time
                                    time_t now_c = chrono::system_clock::to_time_t(now); // Convert time to time_t format
                                    withdrawalTransaction = std::ctime(&now_c) + to_string(withdrawalAmount) + " withdrawed"; // Create withdrawal transaction message
                                    transactionHistories[index][transactionCounts[index]] = withdrawalTransaction; // Store withdrawal transaction
                                    transactionCounts[index]++; // Increment transaction count
                                    break; // Exit switch statement
                                }
                                case 3: { // Make a transfer
                                    int transferAmount; // Declare variable for transfer amount
                                    cout << "Enter the amount of money you want to transfer: "; // Prompt user for transfer amount
                                    cin >> transferAmount; // Read transfer amount
                                    if (transferAmount > array_deposit[index]) { // Check if transfer amount exceeds balance
                                        cout << "You don't have enough balance." << endl; // Print error message
                                    } else { // If transfer amount is within balance
                                        int recipientIndex; // Declare variable to store recipient's index
                                        cout << "Enter the account number of the recipient: "; // Prompt user for recipient's account number
                                        cin >> Account_number; // Read recipient's account number
                                        bool recipientFound = false; // Declare and initialize variable to check if recipient exists
                                        for (int i = 0; i < MAX_ACCOUNTS; ++i) { // Iterate through user accounts
                                            if (Account_number == account_number[i]) { // Check if recipient's account number matches
                                                recipientIndex = i; // Store recipient's index
                                                recipientFound = true; // Set flag to true
                                                break; // Exit loop
                                            }
                                        }if (recipientFound) { // If recipient exists
                                            array_deposit[index] -= transferAmount; // Deduct transfer amount from sender's balance
                                            array_deposit[recipientIndex] += transferAmount; // Add transfer amount to recipient's balance
                                            cout << "Transfer successful!" << endl; // Print success message
                                            auto now = chrono::system_clock::now(); // Get current time
                                            time_t now_c = chrono::system_clock::to_time_t(now); // Convert time to time_t format
                                            transferTransaction = string(std::ctime(&now_c)) + to_string(transferAmount) + " transfered to account number " + Account_number; // Create transfer transaction message
                                            transactionHistories[index][transactionCounts[index]] = transferTransaction; // Store transfer transaction
                                            transactionCounts[index]++; // Increment transaction count
                                            receivedTransaction = string(std::ctime(&now_c)) +  std::to_string(transferAmount) + "Received from account number " + Account_number; // Create received transaction message
                                            transactionHistories[recipientIndex][transactionCounts[recipientIndex]] = receivedTransaction; // Store received transaction
                                            transactionCounts[recipientIndex]++; // Increment transaction count for recipient
                                        } else { // If recipient does not exist
                                            cout << "Recipient account not found." << endl; // Print error message
                                        }
                                    }


                                    break; // Exit switch statement
                                }
                                case 4: { // Check balance
                                    cout << "Your balance is: " << array_deposit[index] << endl; // Print user's balance
                                    break; // Exit switch statement
                                }
                                case 5: { // View transaction history
                                    cout << "Transaction History:\n"; // Print transaction history header
                                    for (int j = 0; j < transactionCounts[index]; j++) { // Iterate through user's transactions
                                        cout << transactionHistories[index][j] << endl; // Print transaction
                                    }
                                    break; // Exit switch statement
                                }
                                case 6: { // Change account details
                                    changeaccountdetail = true; // Set flag for changing account details
                                    while(changeaccountdetail){ // Start loop for changing account details
                                        int choice; // Declare variable to store user choice
                                        cout<< "enter your choice: "<<endl; // Prompt user for choice
                                        cout << "1. Change name" << endl; // Option to change name
                                        cout << "2. Change password" << endl; // Option to change password
                                        cout << "3. Exit" << endl; // Option to exit
                                        cin >> choice; // Read user choice
                                        switch (choice){ // Start switch statement based on user choice
                                            case 1: { // Change name
                                                cout << "Enter your new first name: "; // Prompt user for new first name
                                                cin >> first_Name[index]; // Read new first name
                                                cout << "Enter your new last name: "; // Prompt user for new last name
                                                cin >> last_Name[index]; // Read new last name
                                                cout << "Name updated successfully!" << endl; // Print success message
                                                break; // Exit switch statement
                                            }
                                            case 2: { // Change password
                                                cout << "Enter your current PIN: "; // Prompt user for current PIN
                                                string currentPIN; // Declare variable to store current PIN
                                                cin >> currentPIN; // Read current PIN
                                                if (currentPIN == bank_PIN[index]) { // Check if current PIN matches
                                                    cout << "Enter your new PIN: "; // Prompt user for new PIN
                                                    cin >> bank_PIN[index]; // Read new PIN
                                                    cout << "PIN updated successfully!" << endl; // Print success message
                                                } else { // If current PIN does not match
                                                    cout << "Invalid PIN. PIN update failed." << endl; // Print error message
                                                }
                                                break; // Exit switch statement
                                            }
                                            case 3: { // Exit
                                                changeaccountdetail = false; // Set flag to exit account detail change loop
                                                break; // Exit switch statement
                                            }
                                            default: // Default case for invalid choice
                                                cout << "Invalid choice" << endl; // Print error message
                                        }
                                    }
                                    break; // Exit switch statement
                                }
                                case 7: { // Exit
                                    isLoggedIn = false; // Set login status to false
                                    break; // Exit switch statement
                                }
                                default: // Default case for invalid choice
                                    cout << "Invalid choice" << endl; // Print error message
                            }
                            if (!isAuthenticated) { // Check if user is not authenticated
                                break; // Exit loop
                            }
                        }
                    } else { // If PIN and account number do not match

                        cout << "Invalid bank PIN or account number. Please try again.\n"; // Print error message}
                }

                break;// Exit switch statement
            }
            case 3: // Exit program
                cout << "Exiting the program...\n"; // Print exit message
                return 0; // Exit program
            default: // Default case for invalid choice
                cout << "Invalid choice. Please try again.\n"; // Print error message
                break; // Exit switch statement
        }
    }
    return 0; // Exit program
}
