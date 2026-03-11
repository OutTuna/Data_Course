#include <iostream>
#include <string>

using namespace std;

enum PaymentType { CASH = 1, CARD, BANK_TRANSFER };

union PaymentDetails {
    char receipt_number[20];
    char card_number[20];
    char iban[30];
};

struct Payment {
    int payment_id;
    PaymentType type;
    PaymentDetails details;
};

int main() {
    int n;
    cout << "How many payments u wanna enter? ";
    cin >> n;

    Payment* payments = new Payment[n];
    
    int cash_count = 0, card_count = 0, bank_count = 0;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Payment " << i + 1 << " ---\n";
        cout << "Number of Payment (ID): ";
        cin >> payments[i].payment_id;
        
        cout << "Type of payment (1-Cash, 2-Card, 3-Bank send): ";
        int t;
        cin >> t;
        payments[i].type = static_cast<PaymentType>(t);

        switch (payments[i].type) {
            case CASH:
                cout << "Enter number of reciept: ";
                cin >> payments[i].details.receipt_number;
                cash_count++;
                break;
            case CARD:
                cout << "enter number of card: ";
                cin >> payments[i].details.card_number;
                card_count++;
                break;
            case BANK_TRANSFER:
                cout << "Enter number (IBAN): ";
                cin >> payments[i].details.iban;
                bank_count++;
                break;
        }
    }

    cout << "\n=== List of all payments ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << payments[i].payment_id << " | Type: ";
        switch (payments[i].type) {
            case CASH:
                cout << "Cash | Recipet: " << payments[i].details.receipt_number << endl;
                break;
            case CARD:
                cout << "Card | Number Card: " << payments[i].details.card_number << endl;
                break;
            case BANK_TRANSFER:
                cout << "Send | IBAN: " << payments[i].details.iban << endl;
                break;
        }
    }

    cout << "\n=== Statistics of payment ===\n";
    cout << "Cash: " << cash_count << "\n";
    cout << "Card: " << card_count << "\n";
    cout << "Send: " << bank_count << "\n";

    delete[] payments;
    return 0;
}