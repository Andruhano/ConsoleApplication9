#include "Bankomat.h"

Bankomat::Bankomat(int id, int min_withdrawal, int max_withdrawal) : id(id), min_withdrawal(min_withdrawal), max_withdrawal(max_withdrawal) 
{
    for (int i = 0; i < NUM_DENOMINATIONS; i++) 
    {
        counts[i] = 0;
    }
}

void Bankomat::load_money(string* loaded_denominations, int* loaded_counts) 
{
    for (int i = 0; i < NUM_DENOMINATIONS; i++) 
    {
        denominations[i] = loaded_denominations[i];
        counts[i] += loaded_counts[i];
    }
}

bool Bankomat::withdraw_money(int amount) 
{
    if (amount < min_withdrawal || amount > max_withdrawal) 
    {
        cout << "Ошибка: Сумма для снятия должна быть от " << min_withdrawal << " до " << max_withdrawal << endl;
        return false;
    }

    int remaining_amount = amount;

    for (int i = NUM_DENOMINATIONS - 1; i >= 0; i--) 
    {
        int num_notes_to_withdraw = remaining_amount / stoi(denominations[i]);
        if (num_notes_to_withdraw > counts[i]) 
        {
            num_notes_to_withdraw = counts[i];
        }
        remaining_amount -= num_notes_to_withdraw * stoi(denominations[i]);
    }

    if (remaining_amount != 0) 
    {
        cout << "Ошибка: Недостаточно купюр для снятия данной суммы" << endl;
        return false;
    }

    remaining_amount = amount;
    for (int i = NUM_DENOMINATIONS - 1; i >= 0; i--) 
    {
        int num_notes_to_withdraw = remaining_amount / stoi(denominations[i]);
        counts[i] -= num_notes_to_withdraw;
        remaining_amount -= num_notes_to_withdraw * stoi(denominations[i]);
    }

    cout << "Сумма " << amount << " успешно снята" << endl;
    return true;
}

void Bankomat::print_current_money() 
{
    cout << "Текущая сумма в банкомате:" << endl;
    for (int i = 0; i < NUM_DENOMINATIONS; i++) 
    {
        cout << denominations[i] << " гривен: " << counts[i] << " купюр" << endl;
    }
}