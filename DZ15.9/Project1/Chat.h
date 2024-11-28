#pragma once
#include "sha1.h"
#include "HashTable.h"
#include <string>

#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
    bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);

private:
    HashTable auth_table; // Хеш-таблица для логинов и хешей паролей
};
