#include <iostream>
#include <string>
using namespace std;

// Функция, которая проверяет, является ли строка s кратной K
bool IsKPeriodic(const string& s, int k)
{
    // Проверка на валидность параметра K
    if (k <= 0) {
        throw invalid_argument("K должно быть больше 0");
    }

    int length = s.length();

    // Проверяем, что длина строки делится нацело на K
    if (length % k != 0)
    {
        return false;
    }

    // Разделяем строку на подстроки длиной K и проверяем их равенство
    for (int i = 0; i < length; i += k)
    {
        if (s.substr(i, k) != s.substr(0, k))
        {
            return false;
        }
    }

    // Если все подстроки равны, то строка кратна K
    return true;
}

// Основная функция программы
int main()
{
    // Устанавливаем локаль для корректного вывода русских символов
    setlocale(LC_ALL, "Rus");

    string string_example;
    int k_value;

    // Ввод строки с клавиатуры
    cout << "Введите строку для проверки на кратность: ";
    cin >> string_example;

    // Ввод значения K с клавиатуры
    cout << "Введите значение K: ";
    cin >> k_value;

    try {
        // Вызов функции IsKPeriodic и вывод результата
        bool result = IsKPeriodic(string_example, k_value);

        if (result) {
            cout << "Строка " << string_example << " кратна " << k_value << endl;
        }
        else {
            cout << "Строка " << string_example << " не кратна " << k_value << endl;
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}