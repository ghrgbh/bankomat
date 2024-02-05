#include <iostream>
using namespace std;

int checkMoney(int money) {
    while (money < 5000 || money % 1000 != 0) {
        cout << "Сумма денег должна быть круглой и не меньше 5000" << endl << "Введи сумму денег: ";
        cin >> money;
    }
    return money;
}

void selection(int& balance, int choice) {
    int withdrawMoney, deposit, operatorTel, moneyСards;
    while (true) {
        switch (choice) {
        case 1:
            cout << "Ваш баланс: " << balance << " рублей" << endl;
            break;
        case 2:
            cout << "Введите сумму, которую хотите снять: ";
            cin >> withdrawMoney;
            withdrawMoney = checkMoney(withdrawMoney);
            balance -= withdrawMoney;
            break;
        case 3:
            cout << "Введите сумму, которую хотите положить: ";
            cin >> deposit;
            deposit = checkMoney(deposit);
            balance += deposit;
            break;
        case 4:
            cout << "1 - если билайн" << endl << "2 - если мтс" << endl;
            while (true) {
                cin >> operatorTel;
                if (operatorTel == 1) {
                    cout << "Комиссия 5%" << endl << "Введите сумму, на которую хотите пополнить баланс: ";
                    cin >> moneyСards;
                    cout << "Зачислено " << moneyСards * 0.95 << " рублей";
                    break;
                }
                else if (operatorTel == 2) {
                    cout << "Комиссия 7%" << endl << "Введите сумму, на которую хотите пополнить баланс: ";
                    cin >> moneyСards;
                    cout << "Зачислено " << moneyСards * 0.93 << " рублей";
                    break;
                }
                else {
                    cout << "Такого оператора нет. Введите 1 - если билайн и 2 - если мтс: ";
                }
            }
            break;
        case 5:
            return;
        default:
            cout << "Такого действия нет.";
        }
    }
}

void functional(int cardInput, int pinInput) {
    int balance1 = 30000;
    int choice;
    while (true) {
        cout << "Выбери действие: " << endl;
        cout << "1 - Показать баланс" << endl;
        cout << "2 - Снять деньги" << endl;
        cout << "3 - Положить деньги" << endl;
        cout << "4 - Пополнить баланс на карту" << endl;
        cout << "5 - Выход" << endl;
        cin >> choice;

        if (cardInput == 123456) {
            selection(balance1, choice);
        }
    }
}

void check(int cardInput, int pinInput) {
    int pin;
    if (cardInput == 123456) {
        pin = 123;
    }
    else if (cardInput == 654321) {
        pin = 321;
    }
    else {
        cout << "Такой карты нет. Попробуйте снова.";
        return;
    }

    cout << "Введи пин-код: ";
    for (int i = 0; i < 3; i++) {
        cin >> pinInput;
        if (pinInput == pin) {
            cout << "Добро пожаловать!" << endl;
            functional(cardInput, pinInput);
            return;
        }
        else if (i == 2) {
            cout << "Карта заблокирована" << endl;
            return;
        }
        else {
            cout << "Пароль не подошел. Введи пин-код заново: ";
        }
    }
}

int main() {
    setlocale(0, "");

    int cardInput;
    while (true) {
        cout << "Введи номер карты: ";
        cin >> cardInput;
        check(cardInput, 0);
    }

    return 0;
}
