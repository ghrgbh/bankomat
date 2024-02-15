#include <iostream>    
#include <cmath>  
using namespace std;

void checkBlocked(int cardInput);
void functional(int cardInput);
void checkPin(int cardInput);

void cardtrue(int cardInput) {
    while (true) {
        int card1 = 123456;
        int card2 = 654321;
        cout << endl << "Введите номер карты: ";
        cin >> cardInput;
        if ((cardInput == card1 && cardInput != card2) && (cardInput != card1 && cardInput == card2)) {
            cout << "Такой карты нет или ваша карта заблокирована. Попробуйте снова." << endl;

        }
        else {
            checkPin(cardInput);
        }
    }
}

float checkMoney(float money) {
    while (money <= 4 || fmod(money, 5) != 0) {
        cout << "Сумма денег должна быть круглой и не меньше 5" << endl;
        return 0;
    }
    return money;
}

void selection(float& balance, int choice) {
    float withdrawMoney, deposit, commission;
    int operatorTel, moneyCards;
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
        long long numb;
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

void checkPin(int cardInput) {
    int pin, pinInput, attempts = 3, n = 0;
    bool isCardFound = false;
    if (cardInput == 123456) {
        pin = 123;
        isCardFound = true;
    }
    else if (cardInput == 654321) {
        pin = 321;
        isCardFound = true;
    }
    if (!isCardFound) {
        cardtrue(cardInput);
        cout << "Такой карты не существует." << endl;
        return;
    }
    cout << "Введите пин-код: ";
    while (n < attempts) {
        cin >> pinInput;
        if (pinInput == pin) {
            cout << "Добро пожаловать!" << endl;
            functional(cardInput);
        }
        else {
            n++;
            if (n == attempts) {
                checkBlocked(cardInput);
            }
            else {
                cout << "Пароль не подошел. Введите пин-код заново: ";
            }
        }
    }
}

void functional(int cardInput) {
    float balance;
    int card, pin;
    if (cardInput == 123456) {
        balance = 30000;
        pin = 123;
    }
    else if (cardInput == 654321) {
        balance = 45000;
        pin = 321;
    }
    else {
        cardtrue(cardInput);
    }
    int choice;
    while (true) {
        cout << endl;
        cout << "1 - Снять деньги" << endl;
        cout << "2 - Положить деньги" << endl;
        cout << "3 - Пополнить баланс на сим-карту" << endl;
        cout << "4 - Показать баланс" << endl;
        cout << "5 - Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        if (choice == 5) {
            exit(0);
            break;
        }
        selection(balance, choice);
    }
}

void checkBlocked(int cardInput) {
    int card;
    cout << "Карта заблокирована." << endl;
    cout << endl << "Введите номер карты: ";
    cin >> card;
    while (true) {
        if (card == cardInput) {
            checkBlocked(card);
        }
        else if (card != cardInput) {
            functional(card);
        }
    }
}

int main() {
    setlocale(0, "");
    int cardInput;
    while (true) {
        int card1 = 123456;
        int card2 = 654321;
        cout << endl << "Введите номер карты: ";
        cin >> cardInput;
        if (cardInput == card1) {
            checkPin(cardInput);
        }
        if (cardInput == card2) {
            checkPin(cardInput);
        }
        else {
            cout << "Такой карты нет. Попробуйте снова." << endl;
        }
    }
}
