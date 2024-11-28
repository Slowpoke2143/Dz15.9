#include "chat.h"
#include <cstring>
#include <iostream>

Chat::Chat() {}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // �������� ������
    uint* password_hash = sha1(_pass, pass_length);

    // ��������� � ���-�������
    bool inserted = auth_table.insert(_login, password_hash);
    if (!inserted) {
        std::cout << "������: ���-������� �����!" << std::endl;
        delete[] password_hash; // ���� �� ������� ��������, ������� ������
    }
}

bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // �������� ������
    uint* password_hash = sha1(_pass, pass_length);

    // ���� ��� ������ �� ������ � ���-�������
    uint* stored_hash = auth_table.search(_login);
    if (stored_hash != nullptr && memcmp(stored_hash, password_hash, SHA1HASHLENGTHBYTES) == 0) {
        delete[] password_hash; // ������� ������ ����� ��������
        return true; // �������� �����
    }

    delete[] password_hash; // ������� ������
    return false; // ��������� �����
}
