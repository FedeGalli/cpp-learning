#include <iostream>
#include <string>

using namespace std;


float setInitialAmount() {
    string amount = "";

    cout << "Insert your initial amount...\n\n";
    cin >> amount;

    bool hasDot = false;
    for (int i = 0; i < amount.length(); i++) {
        if (amount[i] < '0' or amount[i] > '9') {
            if (amount[i] == '.' and not hasDot){
                hasDot = true;
            }
            else {
                cout << "ERROR INPUT NOT VALID";
                return 0;
            }
        }
    }

    return stof(amount);
}

void bankTransfer(float *accountBalance, float amount) {
    if (*accountBalance + amount < 0) {
        cout << "YOU DONT OWN ENOUGTH MONEY TO TRANSFER : " << amount * -1 << endl;
    }
    else *accountBalance += amount;

    cout << "CURRENT BALANCE: " << *accountBalance;
}

int main() {
    float accountBalance = setInitialAmount();

    bankTransfer(&accountBalance, -50);


    return 0;

}
