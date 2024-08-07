#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const double INTEREST_RATE = 0.05; // 5% interest rate
const int MIN_BALANCE = 1000;
const int NUM_ACCOUNTS = 100;

struct SavingsAccount {
    string holderName;
    int accountNumber;
    double balance;

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to account " << accountNumber << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance - amount >= MIN_BALANCE) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from account " << accountNumber << endl;
            } else {
                cout << "Insufficient funds. Minimum balance must be maintained." << endl;
            }
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    void addInterest() {
        double interest = balance * INTEREST_RATE;
        deposit(interest);
    }
};

void createAccounts(vector<SavingsAccount>& accounts) {
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        SavingsAccount account;
        account.holderName = "Holder_" + to_string(i + 1);
        account.accountNumber = i + 1;
        account.balance = MIN_BALANCE + rand() % 99001; // Random balance between 1000 and 100000
        accounts.push_back(account);
    }
}

double calculateTotalInterest(vector<SavingsAccount>& accounts) {
    double totalInterest = 0;
    for (auto& account : accounts) {
        double interest = account.balance * INTEREST_RATE;
        account.addInterest();
        totalInterest += interest;
    }
    return totalInterest;
}

int main() {
    vector<SavingsAccount> accounts;
    createAccounts(accounts);

    cout << "Created " << NUM_ACCOUNTS << " accounts." << endl;

    double totalInterest = calculateTotalInterest(accounts);
    cout << "Total interest paid to all accounts in one year: " << totalInterest << endl;

    return 0;
}
