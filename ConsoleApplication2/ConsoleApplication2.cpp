#include <iostream>  
using namespace std;

float checkMoney(float money) {
    while (money <= 4000 || fmod(money, 100) != 0) {
        cout << "Сумма денег должна быть круглой и не меньше 5000" << endl;
        return 0;
    }
    return money;
}

void selection(float& balance, int choice) {
    float withdrawMoney, deposit, operatorTel, moneyCards, commission;
    switch (choice) {
    case 1:
        cout << "Введите сумму, которую хотите снять: ";
        cin >> withdrawMoney;
        while (withdrawMoney > balance) {
            cout << "Вы не можете снять сумму денег больше вашего баланса" << endl;
            cout << "Введите сумму, которую хотите снять: ";
            cin >> withdrawMoney;
        }
        withdrawMoney = checkMoney(withdrawMoney);
        balance -= withdrawMoney;
        cout << "Снято: " << withdrawMoney << " рублей" << endl;
        break;
    case 2:
        cout << "Введите сумму, которую хотите положить: ";
        cin >> deposit;
        deposit = checkMoney(deposit);
        balance += deposit;
        cout << "Внесено: " << deposit << " рублей" << endl;
        break;
    case 3:
        int numb;
        cout << "Выберите оператора:\n1 - билайн\n2 - мтс\n";
        cin >> operatorTel;
        cout << "Введи номер сим карты: ";
        cin >> numb;
        cout << "Введите сумму, на которую хотите пополнить баланс: ";
        cin >> moneyCards;
        if (operatorTel == 1) {
            commission = moneyCards * 0.05;
        }
        else if (operatorTel == 2) {
            commission = moneyCards * 0.07;
        }
        else {
            cout << "Такого оператора нет." << endl;
            break;
        }
        if (balance < commission + moneyCards) {
            cout << "Недостаточно средств для пополнения." << endl;
            break;
        }
        balance -= (commission + moneyCards);
        cout << "Зачислено " << moneyCards << " рублей." << endl;
        break;
    case 4:
        cout << "Ваш баланс: " << balance << " рублей" << endl;
        break;
    case 5:
        break;
    default:
        cout << "Такого действия нет." << endl;
    }
}

void functional(int cardInput) {
    float balance;
    if (cardInput == 123456) {
        balance = 30000;
    }
    else if (cardInput == 654321) {
        balance = 45000;
    }
    else {
        cout << "Такой карты нет. Попробуйте снова." << endl;
        return;
    }
    int choice;
    while (true) {
        cout << endl;
        cout << "1 - Снять деньги" << endl;
        cout << "2 - Положить деньги" << endl;
        cout << "3 - Пополнить баланс на карту" << endl;
        cout << "4 - Показать баланс" << endl;
        cout << "5 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        if (choice == 5) {
            break;
        }
        selection(balance, choice);
    }
}

void check(int cardInput) {
    int pin, pinInput, attempts = 3, n = 0;
    if (cardInput == 123456) {
        pin = 123;
    }
    else if (cardInput == 654321) {
        pin = 321;
    }
    else {
        cout << "Такой карты нет. Попробуйте снова." << endl;
        return;
    }
    cout << "Введите пин-код: ";
    for (int i = 0; i < attempts; i++) {
        cin >> pinInput;
        if (pinInput == pin) {
            cout << "Добро пожаловать!" << endl;
            functional(cardInput);
            return;
        }
        else {
            n++;
            if (n == attempts) {
                cout << "Карта заблокирована." << endl;
                return;
            }
            else {
                cout << "Пароль не подошел. Введите пин-код заново: ";
            }
        }
    }
}

int main() {
    setlocale(0, "");
    int cardInput;
    while (true) {
        cout << endl << "Введите номер карты: ";
        cin >> cardInput;
        check(cardInput);
    }
    return 0;
}
