#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>


void showBalance(double balance);
void withdraw(double balance);
void deposit(double balance);
bool pin_login(int pin);
int pin_signup();
int checkdigit(int pin);
void choicemessage();
void in_choice(int choice, double balance);
void Anotheroperation(double balance);
void sendmoney(double balance);
void manualtransfer(double balance);
void paybills(double balance);
void bills(double balance, int choice_1, int choice);
void companies_database(int choice, int choice_1);


int main(){
    double balance = 0;
    int pin = 0;
    int choice = 0;
    pin = pin_signup();
    if (pin_login(pin) == 1)
    choicemessage();
    else
    return 0;
    std::cin >> choice;
    in_choice(choice, balance);
}



int pin_signup(){
    int pinsup = 0;
    std::cout << "Welcome to eBank! Please enter a 6-Digit PIN for registration: ";
    std::cin >> pinsup;
    while (checkdigit(pinsup) != 6){
        std::cout << "You have not entered a 6-digit PIN. \n" ; 
        std::cout << "Please enter a 6-Digit PIN for registration: ";
        std::cin >> pinsup;
    }
    std::cout << "Congratulations! You have successfully created your eBank account! \n";
    return pinsup;
}


int checkdigit(int pin){

    return int(log10(pin) + 1);
}

bool pin_login(int pin){
    int pinlogin = 0, k = 3;
    std::cout << "Please enter your PIN:";
    while (k){
    std::cin >> pinlogin;
    if (pinlogin == pin){
        std::cout << "You have successfully logged in!\n";
        return true;
    }
    else{
        std::cout << "The pin is incorrect. You have " << k-1 << " more attempts:";
        k--;
    }
    }
        std::cout << "\n";
        std::cout << "The account has been blocked! Please contact a bank representative for more information.";
        return false;
}

void choicemessage(){
    int choice = 0;
    std::cout << "*******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "*******************\n";
    std::cout << "1. Show balance\n";
    std::cout << "2. Deposit money\n";
    std::cout << "3. Withdraw money\n";
    std::cout << "4. Transfer money\n";
    std::cout << "5. Exit\n";
}

void in_choice(int choice, double balance){
    switch(choice){
        case 1: showBalance(balance);
                break;
        case 2: deposit(balance);
                break;
        case 3: withdraw(balance);
                break;
        case 4: sendmoney(balance);
                break;
    }
}

void showBalance(double balance){
    std::cout << "Your balance is: " << balance << "€\n";
    Anotheroperation(balance);
    
}

void Anotheroperation(double balance){
    int continue_eb, choice;
    std::cout << "Do you want another operation? (0 = no, 1 = yes) ";
    std::cin >> continue_eb;
    if (continue_eb == 1){
        choicemessage();
        std::cin >> choice;
        in_choice(choice, balance);
    }
    else 
    std:: cout << "Have a nice day!";
}

void deposit(double balance){
    int amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;
    if (amount > 100000)
        std::cout << "You have exceeded the maximum deposit limit. Next time, please enter a value lower than 100000.\n";
    else
        {
            balance += amount;
            std::cout << "You have successfully deposited " << amount << "€\n";

        
        }    
    Anotheroperation(balance);
}

void withdraw(double balance){
    int amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    if (amount > 100000)
        std::cout << "For security reasons, you cannot withdraw an amount greater than or equal to 100000€ in a single operation.\n";
    else if (amount < balance)
        {
            balance -= amount;
            std::cout << "You have successfully withdrawn " << amount << "€\n";
        }
    else
    std::cout << "Insufficient funds.\n";
        
    Anotheroperation(balance);
}

void sendmoney(double balance){
    int choicesend = 0;
    std::cout << "*******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "*******************\n";
    std::cout << "1. Manual Transfer\n";
    std::cout << "2. Pay bills\n";
    std::cout << "3. Exit\n";
    std::cin >> choicesend;
    switch(choicesend){
        case 1: manualtransfer(balance);
                break;
        case 2: paybills(balance);
                break;
        
    }
}


void manualtransfer(double balance){
    std::string iban; // ex = "RO49AAAA1B31007593840000";
    int amount, choice;
    std::cout << "IBAN:";
    std::cin >> iban;
    if (iban.length() == 24){ //RO 24
    std::cout << "Amount:";
    std::cin >> amount;
    if (balance >= amount){
    std::cout << "Your new balance will be " << balance-amount << "€. Is that okay? (0 = no, 1 = yes) ";
    std::cin >> choice;
    if (choice == 1){
        balance = balance-amount;
        std:: cout << "Thank you for the transaction.";
    }
        
    }
    else {
    std:: cout << "Insufficient funds.\n";

     }
    }
    else{
        std::cout << "IBAN is incorrect.";
    }
    Anotheroperation(balance);
}

void paybills(double balance){
    int choice, choice_1;
    std::cout << "*******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "*******************\n";
    std::cout << "1.Insurance, Investment funds, Brokerage\n";
    std::cout << "2.Communications\n";
    std::cout << "3.Energy\n";
    std::cout << "4. Something else\n";
    std::cin >> choice;
    std::cout << "*******************\n";
    std::cout << "Enter your choice:\n";
    std::cout << "*******************\n";
    switch(choice){
        case 1: std::cout << "1.Asiron Tienna - Client\n";
                std::cout << "2.Alias-Tirioc - Life insurance\n";
                std::cout << "3.Omniagis - PAD";
                std::cout << "Enter your choice: ";
                std::cin >> choice_1;
                bills(balance, choice_1, choice);
                break;
        case 2: std::cout << "1.Yellow Romania Communications - payment of bills\n";
                std::cout << "2.RNS & RHS\n";
                std::cout << "3.Vodahome - payment of bills";
                break;
        case 3: std::cout << "1.SEZ\n";
                std::cout << "2.E.OFF\n";
                std::cout << "3.EIGNE";
                break;
        case 4: std::cout << "1.DASSIA / RENULT / NIHHAN (new car)\n";
                std::cout << "2.Owners Association Bucharest 309125\n";
                std::cout << "3.XYZABC Real Estate";
    }
    
}

void companies_database(int choice, int choice_1){
    if (choice == 1 && choice_1 == 1){
        std::cout << "Name of beneficiary: Asiron\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 1 && choice_1 == 2){
        std::cout << "Name of beneficiary: Alias-Tirioc\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
    if (choice == 1 && choice_1 == 3){
        std::cout << "Name of beneficiary: Omniagis\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
    if (choice == 2 && choice_1 == 1){
        std::cout << "Name of beneficiary: Yellow Romania Communications\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
    if (choice == 2 && choice_1 == 2){
        std::cout << "Name of beneficiary: RNS & RHS\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
    if (choice == 2 && choice_1 == 3){
        std::cout << "Name of beneficiary: Vodahome\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 3 && choice_1 == 1){
        std::cout << "Name of beneficiary: SEZ\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 3 && choice_1 == 2){
        std::cout << "Name of beneficiary: E.OFF\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 3 && choice_1 == 3){
        std::cout << "Name of beneficiary: EIGNE\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 4 && choice_1 == 1){
        std::cout << "Name of beneficiary: Renult Comercial Romania\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 4 && choice_1 == 2){
        std::cout << "Name of beneficiary: Owners Association Bucharest\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
     if (choice == 4 && choice_1 == 3){
        std::cout << "Name of beneficiary: XYZABC\n";
        std::cout << "IBAN: RO49AAAA1B31007593840000\n";
    }
}

void bills(double balance, int choice_1, int choice){
    int amount;
    std::string details, series;
    if (choice_1 == 1){
     std::cout << "Amount:";
     std::cin >> amount;
    if (amount > balance && amount > 0){
        std::cout << "Insufficient funds.\n";
        Anotheroperation(balance);
    }
    else {
        std::cout << "Details of the transfer:";
        std::cin >> details;
        std::cout << "Series and policy number:";
        std::cin >> series;
        
        }
       companies_database(choice, choice_1); 
       std::cout << "Amount: " << amount << "\n";
       std::cout << "Total amount in account currency (including commissions): " << amount-(rand()%2+1) << "\n";
       std::cout << "Execution date: ";
       amount < 1000 ? std::cout << "As soon as possible\n" : std:: cout << "Up to 5 business days\n";
       std::cout << "Details of the transfer:";
       std::cout << details << "\n";
       std::cout << "Series and policy number:";
       std::cout << series << "\n";
       int op;
       std::cout << "Is that okay? (0 = no, 1 = yes)\n";
       std::cin >> op;
       if (op){
           if (std::cin.get() == '\n')
           balance-=amount;
           std::cout << "Thank you for the transaction.";
       }
       Anotheroperation(balance);
    }
    

}

