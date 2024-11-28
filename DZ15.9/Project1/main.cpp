#include <iostream>
#include "chat.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Chat chat;

    // ����������� �������������
    char login1[] = "user1";
    char pass1[] = "password123";
    chat.reg(login1, pass1, sizeof(pass1) - 1);  // ������ ������ �� ��������� ����������� ������� ������

    char login2[] = "user2";
    char pass2[] = "securePass";
    chat.reg(login2, pass2, sizeof(pass2) - 1);

    // ������� ������
    std::cout << "�������� ����� ��� user1 � ���������� �������..." << std::endl;
    if (chat.login(login1, pass1, sizeof(pass1) - 1)) {
        std::cout << "�������� ����!" << std::endl;
    }
    else {
        std::cout << "��������� ����!" << std::endl;
    }

    std::cout << "�������� ����� ��� user1 � ������������ �������..." << std::endl;
    char wrongPass1[] = "wrongPass";
    if (chat.login(login1, wrongPass1, sizeof(wrongPass1) - 1)) {
        std::cout << "�������� ����!" << std::endl;
    }
    else {
        std::cout << "��������� ����!" << std::endl;
    }

    std::cout << "�������� ����� ��� user2 � ���������� �������..." << std::endl;
    if (chat.login(login2, pass2, sizeof(pass2) - 1)) {
        std::cout << "�������� ����!" << std::endl;
    }
    else {
        std::cout << "��������� ����!" << std::endl;
    }

    return 0;
}
