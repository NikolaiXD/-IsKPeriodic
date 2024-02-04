#include <iostream>
#include <string>
using namespace std;

// �������, ������� ���������, �������� �� ������ s ������� K
bool IsKPeriodic(const string& s, int k)
{
    // �������� �� ���������� ��������� K
    if (k <= 0) {
        throw invalid_argument("K ������ ���� ������ 0");
    }

    int length = s.length();

    // ���������, ��� ����� ������ ������� ������ �� K
    if (length % k != 0)
    {
        return false;
    }

    // ��������� ������ �� ��������� ������ K � ��������� �� ���������
    for (int i = 0; i < length; i += k)
    {
        if (s.substr(i, k) != s.substr(0, k))
        {
            return false;
        }
    }

    // ���� ��� ��������� �����, �� ������ ������ K
    return true;
}

// �������� ������� ���������
int main()
{
    // ������������� ������ ��� ����������� ������ ������� ��������
    setlocale(LC_ALL, "Rus");

    string string_example;
    int k_value;

    // ���� ������ � ����������
    cout << "������� ������ ��� �������� �� ���������: ";
    cin >> string_example;

    // ���� �������� K � ����������
    cout << "������� �������� K: ";
    cin >> k_value;

    try {
        // ����� ������� IsKPeriodic � ����� ����������
        bool result = IsKPeriodic(string_example, k_value);

        if (result) {
            cout << "������ " << string_example << " ������ " << k_value << endl;
        }
        else {
            cout << "������ " << string_example << " �� ������ " << k_value << endl;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "������: " << e.what() << endl;
    }

    return 0;
}