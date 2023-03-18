# eBank
"eBank" is a simple C++ project designed as a simple Internet Banking application.<br />
It is not linked to a database or made with a real purpose, it is made as an experiment. 

## Functions
1. Sign up<br />
When you start the program, you will be required to register using a 6-digit pin.
![image](https://user-images.githubusercontent.com/121444745/222973293-6c8402ec-f937-4979-9e79-f0bad76d1aeb.png)
```cpp
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
```
![image](https://user-images.githubusercontent.com/121444745/222973478-067f71b4-a1a1-4ed7-9f2b-9ff5d465c186.png)<br />
Checking the number of digits is done with:
```cpp
int checkdigit(int pin){
    return int(log10(pin) + 1);
}
```
2. Sign in <br />
The connection to the "application" will be made using the pin with which the user registered.<br/>
![image](https://user-images.githubusercontent.com/121444745/224482863-4a7625df-b9f4-4fb1-b202-b27e376863a4.png)<br/>
```cpp
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
```
![image](https://user-images.githubusercontent.com/121444745/224483205-f2a16963-b477-4600-be98-4165d41c6fe5.png)

3. The main menu of the application<br/>
![image](https://user-images.githubusercontent.com/121444745/224483465-b25af482-4a74-4a3e-956f-0e2855c81944.png)
```cpp
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
```
4. Show Balance<br/>
This function is capable of showing the sum that the user has in the application.
![image](https://user-images.githubusercontent.com/121444745/224483667-4c0c65fc-16a7-4653-aecc-b6b239248c1e.png)
```cpp
void showBalance(double balance){
    std::cout << "Your balance is: " << balance << "€\n";
    Anotheroperation(balance);
    
}
```
5. Deposit money<br/>
This function allows you to deposit less than 100000e.<br/>
![image](https://user-images.githubusercontent.com/121444745/226110080-f0323805-4c45-4cc0-9ceb-44c1f1ddeb76.png)
```cpp
void withdraw(double balance){
    int amount = 0;
    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;
    if (amount > 100000)
        std::cout << "For security reasons, you cannot withdraw an amount greater than or equal to 100000€ in a signle operation.\n";
    else if (amount < balance)
        {
            balance -= amount;
            std::cout << "You have successfully withdrawn " << amount << "€\n";
        }
    else
    std::cout << "Insufficient funds.\n";
        
    Anotheroperation(balance);
}
```

![image](https://user-images.githubusercontent.com/121444745/226110495-00c20a0a-6b6e-4ce4-b8eb-a5ec15f1d818.png)

6. Withdraw money<br/>
You can withdraw an amount of money from your current account.<br/>
For "security" reasons, you cannot withdraw an amount greater than or equal to 100000€ in a single operation.
![image](https://user-images.githubusercontent.com/121444745/226110637-8b4040b5-a060-4a6f-a7d1-635901c8e753.png)
```cpp
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
```

7. Transfer money<br/>
7.1. Manual Transfer - function that allows you to transfer an amount of money to an IBAN of your choice (iban.length() == 24)
![image](https://user-images.githubusercontent.com/121444745/226110903-905d30e1-08df-4ef6-a9f1-6f197404bc07.png)
```cpp
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
 ```
7.2. Pay bills - the function allows you to pay an invoice/insurance/others without entering the IBAN<br/>
![image](https://user-images.githubusercontent.com/121444745/226111435-22ddfd3b-e0e2-47bd-b451-7da42db1185f.png)
```cpp
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
 ```
 WIP...
 
## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
