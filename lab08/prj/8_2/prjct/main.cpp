#include <iostream>
#include "C:\Users\Roman\Desktop\staticlib\staticlib\Header.h";
#include <locale>
#include <iomanip>
#include <windows.h>

using namespace std;

void Information() {
    SetConsoleOutputCP(1251);
    cout << "\n ----------------------------------------\n"

        << "|   Sarvadi Roman, CUNTU, Kropyvnickyi   |\n"

        << "|   ������ �����, ����, �������������   |\n"

        << "\n -------- (c) All Rights Reserved --------\n\n";
}

    // ������� ��� ������ ��������
    bool isEqualSum(int a, int b) {
        return (a + 7 == b);
    }

    // ������� ���������� ���� x + y + z
    int s_calculation(int x, int y, int z) {
        return x + y + z;
    }

    int main() {
        setlocale(LC_ALL, "");

        // ��� ������� a � b
        int a, b;
        std::cout << "����i�� �������� ��� a: ";
        std::cin >> a;
        std::cout << "����i�� �������� ��� b: ";
        std::cin >> b;

        // ���� �������� ���������� a + 7 == b
        bool result = isEqualSum(a, b);
        std::cout << "��������� ���i����� ������ (a + 7 == b): " << std::boolalpha << result << std::endl;

        // ��� x, y, z
        int x, y, z;
        std::cout << "\n����i�� �������� x: ";
        std::cin >> x;
        std::cout << "����i�� �������� y: ";
        std::cin >> y;
        std::cout << "����i�� �������� z: ";
        std::cin >> z;

        // ��������� � ��������� ������
        std::cout << "\n��������� �������:\n";
        std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;

        // ��������� � �������������� ������
        std::cout << "�i������������ �������:\n";
        std::cout << "x = 0x" << std::hex << x
            << ", y = 0x" << y
            << ", z = 0x" << z << std::dec << std::endl;

        // ���������� S = x + y + z
        int S = s_calculation(x, y, z);
        std::cout << "\n�������� S = " << S << std::endl;

        // �����
        std::cout << "\n������i�� Enter ��� ����������...";
        std::cin.ignore();
        std::cin.get();

        return 0;
    }




