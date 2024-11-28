#include "HashTable.h"
#include <iostream>
#include <cmath>

using namespace std;

HashTable::HashTable() {
    table = new Pair[TABLE_SIZE];
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].password_hash != nullptr) {
            delete[] table[i].password_hash;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(const std::string& login) {
    float A = 0.6180339887; // ��������� ��� ������ ���������
    unsigned long long sum = 0;
    for (char ch : login) {
        sum = sum * 31 + ch; // ���������� ���-������� ��� ������
    }
    return static_cast<int>(TABLE_SIZE * (fmod(sum * A, 1))); // ���������� ������
}

int HashTable::quadraticProbe(int index, int attempt) {
    return (index + attempt * attempt) % TABLE_SIZE; // ������������ ������������
}

bool HashTable::insert(const std::string& login, uint* password_hash) {
    int index = hashFunction(login);
    int attempt = 0;
    while (attempt < TABLE_SIZE) {
        int idx = quadraticProbe(index, attempt);
        if (table[idx].password_hash == nullptr || table[idx].is_deleted) {
            table[idx].login = login;
            table[idx].password_hash = password_hash;
            table[idx].is_deleted = false;
            return true;
        }
        attempt++;
    }
    return false; // ���� ������� �����
}

uint* HashTable::search(const std::string& login) {
    int index = hashFunction(login);
    int attempt = 0;
    while (attempt < TABLE_SIZE) {
        int idx = quadraticProbe(index, attempt);
        if (table[idx].password_hash == nullptr) {
            return nullptr; // �� �������
        }
        if (!table[idx].is_deleted && table[idx].login == login) {
            return table[idx].password_hash; // ���������� ��� ������
        }
        attempt++;
    }
    return nullptr; // �� �������
}
