#include "Bankomat.h"

void print_menu() 
{
    cout << "�������� ��������:" << endl;
    cout << "1. �������� ������� ���������� ����� � ���������" << endl;
    cout << "2. ������ ������ � ��������" << endl;
    cout << "3. ����� ������ �� ���������" << endl;
    cout << "4. �����" << endl;
}

int main() 
{
    system("chcp 1251");
    Bankomat atm(1, 100, 10000);
    string denominations[NUM_DENOMINATIONS] = { "100", "200", "500", "1000", "2000", "5000", "10000", "20000", "50000", "100000" };
    int counts[NUM_DENOMINATIONS] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    atm.load_money(denominations, counts);

    int choice;
    while (true) {
        print_menu();
        cin >> choice;

        switch (choice) {
        case 1:
            atm.print_current_money();
            break;
        case 2: {
            int added_counts[NUM_DENOMINATIONS];
            cout << "������� ���������� ������ ������ ��� ��������:" << endl;
            for (int i = 0; i < NUM_DENOMINATIONS; ++i) {
                cout << denominations[i] << " ������: ";
                cin >> added_counts[i];
            }
            atm.load_money(denominations, added_counts);
            break;
        }
        case 3: {
            int amount;
            cout << "������� ����� ��� ������: ";
            cin >> amount;
            atm.withdraw_money(amount);
            break;
        }
        case 4:
            cout << "�� ��������!" << endl;
            return 0;
        default:
            cout << "�������� �����. ����������, �������� ������������ ����� ����." << endl;
        }
    }

    return 0;
}

