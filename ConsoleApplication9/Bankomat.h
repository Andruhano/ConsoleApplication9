#pragma once
#include <string>
#include <iostream>
using namespace std;

const int NUM_DENOMINATIONS = 10;

class Bankomat 
{
int id;
string denominations[NUM_DENOMINATIONS];
int counts[NUM_DENOMINATIONS];
int min_withdrawal;
int max_withdrawal;

public:
    Bankomat(int id, int min_withdrawal, int max_withdrawal);
    void load_money(string* loaded_denominations, int* loaded_counts);
    bool withdraw_money(int amount);
    void print_current_money();
};