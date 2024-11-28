#pragma once
#include <string>
#include "sha1.h"

#define TABLE_SIZE 10

class HashTable {
public:
    HashTable();
    ~HashTable();

    bool insert(const std::string& login, uint* password_hash);
    uint* search(const std::string& login);

private:
    struct Pair {
        std::string login;
        uint* password_hash;
        bool is_deleted; // Для отмечания удаленных элементов
        Pair() : password_hash(nullptr), is_deleted(false) {}
    };

    Pair* table;

    // Хеш-функция методом умножения
    int hashFunction(const std::string& login);

    // Квадратичное пробирование
    int quadraticProbe(int index, int attempt);
};
