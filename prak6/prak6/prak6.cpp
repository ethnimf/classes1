#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initBalance) {
        accountNumber = accNumber;
        balance = initBalance;
        interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Успешно." << endl;
        }
        else {
            cout << "Ошибка." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Успешно." << endl;
        }
        else {
            cout << "Ошибка." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    bool transfer(BankAccount& to, double amount) {
        if (balance >= amount) {
            balance -= amount;
            to.balance += amount;
            cout << "Успешно." << endl;
            return true;
        }
        else {
            cout << "Ошибка." << endl;
            return false;
        }
    }

    void printAccountNumber() const {
        cout << "Номер счета: " << accountNumber << endl;
    }
    };

    int main() {
        setlocale(LC_ALL, "Russian");
        BankAccount person1(18928819, 100000.0);
        BankAccount person2(92873627, 150200.0);

        int accountChoice;
        cout << "Выберите счет для работы (1 или 2): ";
        cin >> accountChoice;

        BankAccount* selectedAccount;
        if (accountChoice == 1) {
            selectedAccount = &person1;
        }
        else if (accountChoice == 2) {
            selectedAccount = &person2;
        }
        else {
            cout << "Неверный выбор счета." << endl;
            return 1;
        }

        int choice;
        double amount;

        do {
            cout << "Меню:" << endl;
            cout << "1. Внести средства на счет" << endl;
            cout << "2. Снять средства со счета" << endl;
            cout << "3. Проверить баланс" << endl;
            cout << "4. Рассчитать и вернуть сумму процентов, заработанных на счете" << endl;
            cout << "5. Обновить процентную ставку" << endl;
            cout << "6. Вывести номер счета" << endl;
            cout << "7. Перевести средства на другой счет" << endl;
            cout << "8. Выбрать другой счет" << endl;
            cout << "9. Выход" << endl;
            cout << "Введите ваш выбор: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Введите сумму для внесения: $";
                cin >> amount;
                selectedAccount->deposit(amount);
                break;
            case 2:
                cout << "Введите сумму для снятия: $";
                cin >> amount;
                selectedAccount->withdraw(amount);
                break;
            case 3:
                cout << "Баланс: $" << selectedAccount->getBalance() << endl;
                break;
            case 4:
                cout << "Проценты: $" << selectedAccount->getInterest() << endl;
                break;
            case 5:
                cout << "Введите новую процентную ставку: ";
                double newRate;
                cin >> newRate;
                selectedAccount->setInterestRate(newRate);
                break;
            case 6:
                selectedAccount->printAccountNumber();
                break;
            case 7:
                int transferToAccount;
                double transferAmount;
                cout << "Выберите счет для перевода (1 или 2): ";
                cin >> transferToAccount;
                if (transferToAccount == 1) {
                    cout << "Введите сумму для перевода на счет " << person1.getAccountNumber() << ": $";
                    cin >> transferAmount;
                    selectedAccount->transfer(person1, transferAmount);
                }
                else if (transferToAccount == 2) {
                    cout << "Введите сумму для перевода на счет " << person2.getAccountNumber() << ": $";
                    cin >> transferAmount;
                    selectedAccount->transfer(person2, transferAmount);
                }
                else {
                    cout << "Неверный выбор счета для перевода." << endl;
                }
                break;
            case 8:
                cout << "Выберите счет для работы (1 или 2): ";
                cin >> accountChoice;
                if (accountChoice == 1) {
                    selectedAccount = &person1;
                }
                else if (accountChoice == 2) {
                    selectedAccount = &person2;
                }
                else {
                    cout << "Неверный выбор счета." << endl;
                    return 1;
                }
                break;
            case 9:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Неверный выбор. Введите число от 1 до 9." << endl;
            }
        } while (choice != 9);

        return 0;
    }

