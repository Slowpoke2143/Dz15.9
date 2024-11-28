#include <iostream>
#include "chat.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Chat chat;

    // Регистрация пользователей
    char login1[] = "user1";
    char pass1[] = "password123";
    chat.reg(login1, pass1, sizeof(pass1) - 1);  // Размер пароля не учитывает завершающий нулевой символ

    char login2[] = "user2";
    char pass2[] = "securePass";
    chat.reg(login2, pass2, sizeof(pass2) - 1);

    // Попытки логина
    std::cout << "Пытаемся войти как user1 с правильным паролем..." << std::endl;
    if (chat.login(login1, pass1, sizeof(pass1) - 1)) {
        std::cout << "Успешный вход!" << std::endl;
    }
    else {
        std::cout << "Неудачный вход!" << std::endl;
    }

    std::cout << "Пытаемся войти как user1 с неправильным паролем..." << std::endl;
    char wrongPass1[] = "wrongPass";
    if (chat.login(login1, wrongPass1, sizeof(wrongPass1) - 1)) {
        std::cout << "Успешный вход!" << std::endl;
    }
    else {
        std::cout << "Неудачный вход!" << std::endl;
    }

    std::cout << "Пытаемся войти как user2 с правильным паролем..." << std::endl;
    if (chat.login(login2, pass2, sizeof(pass2) - 1)) {
        std::cout << "Успешный вход!" << std::endl;
    }
    else {
        std::cout << "Неудачный вход!" << std::endl;
    }

    return 0;
}
