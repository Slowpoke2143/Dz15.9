#include "chat.h"
#include <cstring>
#include <iostream>

Chat::Chat() {}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Хешируем пароль
    uint* password_hash = sha1(_pass, pass_length);

    // Вставляем в хеш-таблицу
    bool inserted = auth_table.insert(_login, password_hash);
    if (!inserted) {
        std::cout << "Ошибка: Хеш-таблица полна!" << std::endl;
        delete[] password_hash; // Если не удалось вставить, очищаем память
    }
}

bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Хешируем пароль
    uint* password_hash = sha1(_pass, pass_length);

    // Ищем хеш пароля по логину в хеш-таблице
    uint* stored_hash = auth_table.search(_login);
    if (stored_hash != nullptr && memcmp(stored_hash, password_hash, SHA1HASHLENGTHBYTES) == 0) {
        delete[] password_hash; // Очищаем память после проверки
        return true; // Успешный логин
    }

    delete[] password_hash; // Очищаем память
    return false; // Неудачный логин
}
