#include <iostream>
using namespace std;

void check(int cardInput, int pin) {
    int pinInput;
    cout << "Введи пин-код: ";
    for (int i = 0; i < 3; i++) {
        cin >> pinInput;
        if (pinInput == pin) {
            cout << "Добро пожаловать!";
            break;
            functional(cardInput, pinInput);
        }
        else if (i == 2) {
            cout << "Карта заблокирована";
        }
        else {
            cout << "Пароль не подошел. Введи пин-код заново: ";
        }
    }
}

void functional(int cardInput, int pinInput) {
    int card1 = 123456;
    int card2 = 654321;
    int balance1 = 30000;
    int choice;
    cout << "Выбери действие: " << endl;
    cout << "1 - Показать баланс" << endl;
    cout << "2 - Снять деньги" << endl;
    cout << "3 - Положить деньги" << endl;
    cout << "4 - Пополнить баланс на карту" << endl;
    cin >> choice;
    if (cardInput == card1) {
        selection(balance1, choice);
    }
}

void selection(int balance, int choice) {
    int withdrawMoney;
    int deposit;
    int choice;
    int moneyСards;
    switch (choice) {
    case 1:
        cout << "Ваш баланс: " << balance << " рублей" << endl;
    case 2:
        cout << "Введите сумму, которую хотите снять: " << endl;
        cin >> withdrawMoney;
        checkMoney(withdrawMoney);
        balance - withdrawMoney;
    case 3:
        cout << "Введите сумму, которую хотите положить: " << endl;
        cin >> deposit;
        checkMoney(deposit);
        balance + deposit;
    case 4:
        cout << "Введите сумму, на которую хотите пополнить баланс: " << endl;
        cin >> moneyСards;
    }
}

int checkMoney(int money) {
    while (true) {
        if (money < 5000 && money%1000==0) {
            cout << "Сумма денег должна быть круглой и не меньше 5000" << endl << "Введи сумму денег: ";
            cin >> money;
        }
    }
    return money;
}

int main() {
    setlocale(0, "");
    int card1 = 123456;
    int card2 = 654321;
    int pin = 123;
    int pin2 = 321;
    int balance = 30000;
    int cardInput;
    while (true) {
        cout << "Введи номер карты: ";
        cin >> cardInput;
        if (cardInput == card1) {
            check(cardInput, pin);
        }
        else if (cardInput == card2) {
            check(cardInput, pin2);
        }
        else {
            cout << "Такой карты нет. Попробуй снова. ";
        }
    }
    

    return 0;
}
