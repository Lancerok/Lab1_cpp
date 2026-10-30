#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ЗАДАНИЕ 1. МЕТОДЫ

double Fraction(double x) {
    return x - static_cast<int>(x);
}

int CharToNum(char x) {
    return x - 48;
}

bool Is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

bool IsInRange(int a, int b, int num) {
    int min_val = (a < b) ? a : b;
    int max_val = (a > b) ? a : b;
    return num >= min_val && num <= max_val;
}

bool IsEqual(int a, int b, int c) {
    return a == b && b == c;
}

// ЗАДАНИЕ 2. УСЛОВИЯ

int AbsVal(int x) {
    return (x < 0) ? -x : x;
}

bool Is35(int x) {
    bool div3 = (x % 3 == 0);
    bool div5 = (x % 5 == 0);
    return (div3 || div5) && !(div3 && div5);
}

int Max3(int x, int y, int z) {
    int max_val = x;
    if (y > max_val) max_val = y;
    if (z > max_val) max_val = z;
    return max_val;
}

int Sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

string Day(int x) {
    switch (x) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суббота";
    case 7: return "воскресенье";
    default: return "это не день недели";
    }
}

// ЗАДАНИЕ 3. ЦИКЛЫ

string ListNums(int x) {
    string result;
    for (int i = 0; i <= x; ++i) {
        result += std::to_string(i);
        if (i < x) result += " ";
    }
    return result;
}

string Chet(int x) {
    string result;
    for (int i = 0; i <= x; i += 2) {
        result += std::to_string(i);
        if (i + 2 <= x) result += " ";
    }
    return result;
}

int NumLen(long x) {
    if (x == 0) return 1;
    int len = 0;
    long temp = (x < 0) ? -x : x;
    while (temp > 0) {
        temp /= 10;
        ++len;
    }
    return len;
}

void Square(int x) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) cout << "*";
        cout << endl;
    }
}

void RightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < x - i; ++j) cout << " ";
        for (int j = 0; j < i; ++j) cout << "*";
        cout << endl;
    }
}

// ЗАДАНИЕ 4. МАССИВЫ

int FindFirst(const int* arr, int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int MaxAbs(const int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (AbsVal(arr[i]) > AbsVal(max_val)) max_val = arr[i];
    }
    return max_val;
}

int* AddArray(const int* arr, int arr_size, const int* ins, int ins_size,
                int pos, int& new_size) {
    new_size = arr_size + ins_size;
    int* result = new int[new_size];
    int idx = 0;
    for (int i = 0; i < pos && i < arr_size; ++i) result[idx++] = arr[i];
    for (int i = 0; i < ins_size; ++i) result[idx++] = ins[i];
    for (int i = pos; i < arr_size; ++i) result[idx++] = arr[i];
    return result;
}

int* ReverseBack(const int arr[], int size, int& new_size) {
    new_size = size;
    int* result = new int[size];
    for (int i = 0; i < size; ++i) result[i] = arr[size - 1 - i];
    return result;
}

int* FindAll(const int arr[], int size, int x, int& count) {
    count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) ++count;
    }
    int* result = new int[count];
    int idx = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) result[idx++] = i;
    }
    return result;
}

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

int GetValidInt(const string& prompt, int min_val, int max_val) {
    int value;
    while (true) {
        cout << prompt;
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка: введите корректное целое число.\n";
            continue;
        }
        if (value < min_val || value > max_val) {
            cout << "Ошибка: значение должно быть в диапазоне ["
                << min_val << ", " << max_val << "].\n";
            continue;
        }
        return value;
    }
}

void PrintSeparator() {
    cout << "\n========================================\n";
}

int* InputArray(int& size) {
    cout << "Введите размер массива: ";
    size = GetValidInt("", 1, 1000);  // Ограничим разумным максимумом

    int* arr = new int[size];
    cout << "Введите " << size << " элементов массива:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    return arr;
}

void PrintArray(const int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]\n";
}

// ПОДМЕНЮ

void MenuTask1() {
    int choice;
    do {
        PrintSeparator();
        cout << "ЗАДАНИЕ 1. МЕТОДЫ\n";
        cout << "1. Дробная часть\n3. Букву в число\n5. Двузначное\n";
        cout << "7. Диапазон\n9. Равенство\n0. Назад в главное меню\n";
        choice = GetValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);
        cout << "\n";

        switch (choice) {
        case 1: {
            double x_frac;
            cout << "Введите вещественное число: ";
            cin >> x_frac;
            cout << "Дробная часть: " << Fraction(x_frac) << endl;
            break;
        }
        case 3: {
            char ch;
            cout << "Введите символ цифры ('0'-'9'): ";
            cin >> ch;
            cout << "Число: " << CharToNum(ch) << endl;
            break;
        }
        case 5: {
            int x_digits;
            cout << "Введите целое число: ";
            cin >> x_digits;
            cout << "Результат: "
                << (Is2Digits(x_digits) ? "true" : "false") << endl;
            break;
        }
        case 7: {
            int a, b, num;
            cout << "Введите a: ";
            cin >> a;
            cout << "Введите b: ";
            cin >> b;
            cout << "Введите num: ";
            cin >> num;
            cout << "Результат: "
                << (IsInRange(a, b, num) ? "true" : "false") << endl;
            break;
        }
        case 9: {
            int a, b, c;
            cout << "Введите a, b и c: ";
            cin >> a >> b >> c;
            cout << "Результат: " << (IsEqual(a, b, c) ? "true" : "false") << endl;
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void MenuTask2() {
    int choice;
    do {
        PrintSeparator();
        cout << "ЗАДАНИЕ 2. УСЛОВИЯ\n";
        cout << "1. Модуль числа\n3. Тридцать пять\n5. Тройной максимум\n";
        cout << "7. Двойная сумма\n9. День недели\n0. Назад в главное меню\n";
        choice = GetValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);
        cout << "\n";

        switch (choice) {
        case 1: {
            int x_abs;
            cout << "Введите число: ";
            cin >> x_abs;
            cout << "Результат: " << AbsVal(x_abs) << endl;
            break;
        }
        case 3: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Результат: "
                << (Is35(x) ? "true" : "false") << endl;
            break;
        }
        case 5: {
            int x, y, z;
            cout << "Введите три числа: ";
            cin >> x >> y >> z;
            cout << "Результат: " << Max3(x, y, z) << endl;
            break;
        }
        case 7: {
            int x, y;
            cout << "Введите два числа: ";
            cin >> x >> y;
            cout << "Результат: " << Sum2(x, y) << endl;
            break;
        }
        case 9: {
            int x;
            cout << "Введите номер дня (1-7): ";
            cin >> x;
            cout << "Результат: " << Day(x) << endl;
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void MenuTask3() {
    int choice;
    do {
        PrintSeparator();
        cout << "ЗАДАНИЕ 3. ЦИКЛЫ\n";
        cout << "1. Числа подряд\n3. Четные числа\n5. Длина числа\n";
        cout << "7. Квадрат\n9. Правый треугольник\n0. Назад в главное меню\n";
        choice = GetValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);
        cout << "\n";

        switch (choice) {
        case 1: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Результат: " << ListNums(x) << endl;
            break;
        }
        case 3: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Результат: " << Chet(x) << endl;
            break;
        }
        case 5: {
            long x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Длина числа: " << NumLen(x) << endl;
            break;
        }
        case 7: {
            int x;
            cout << "Введите размер квадрата: ";
            cin >> x;
            Square(x);
            break;
        }
        case 9: {
            int x;
            cout << "Введите высоту треугольника: ";
            cin >> x;
            RightTriangle(x);
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void MenuTask4() {
    int* arr = nullptr;
    int size = 0;

    cout << "\n===== ВВОД МАССИВА =====\n";
    arr = InputArray(size);

    int choice;
    do {
        PrintSeparator();
        cout << "ЗАДАНИЕ 4. МАССИВЫ\n";
        cout << "Текущий массив: ";
        PrintArray(arr, size);
        cout << "\n1. Поиск первого значения\n";
        cout << "3. Поиск максимального по модулю\n";
        cout << "5. Добавление массива в массив\n";
        cout << "7. Возвратный реверс\n";
        cout << "9. Все вхождения\n";
        cout << "0. Назад в главное меню\n";
        choice = GetValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);
        cout << "\n";

        switch (choice) {
        case 1: {
            int x;
            cout << "Какое число искать? ";
            cin >> x;
            int index = FindFirst(arr, size, x);
            if (index != -1) {
                cout << "Индекс первого вхождения: " << index << endl;
            }
            else {
                cout << "Число не найдено в массиве\n";
            }
            break;
        }
        case 3: {
            int max_val = MaxAbs(arr, size);
            cout << "Максимальный по модулю: " << max_val << endl;
            break;
        }
        case 5: {
            cout << "\nВведите размер вставляемого массива: ";
            int ins_size = GetValidInt("", 1, 100);
            int* ins_arr = new int[ins_size];
            cout << "Введите " << ins_size << " элементов:\n";
            for (int i = 0; i < ins_size; ++i) {
                cout << "ins_arr[" << i << "] = ";
                cin >> ins_arr[i];
            }

            cout << "Введите позицию вставки (0-" << size << "): ";
            int pos = GetValidInt("", 0, size);

            int new_size;
            int* res = AddArray(arr, size, ins_arr, ins_size, pos, new_size);

            cout << "Результат: ";
            PrintArray(res, new_size);

            // Освобождение памяти
            delete[] arr;
            delete[] ins_arr;
            arr = res;
            size = new_size;

            break;
        }
        case 7: {
            int new_size;
            int* res = ReverseBack(arr, size, new_size);
            cout << "Перевернутый массив: ";
            PrintArray(res, new_size);

            // Освобождение памяти и замена
            delete[] arr;
            arr = res;

            break;
        }
        case 9: {
            int x;
            cout << "Какое число искать? ";
            cin >> x;

            int count;
            int* res = FindAll(arr, size, x, count);

            if (count > 0) {
                cout << "Индексы вхождений: ";
                PrintArray(res, count);
            }
            else {
                cout << "Число не найдено в массиве\n";
            }

            delete[] res;
            break;
        }
        case 0:
            delete[] arr;  // Освобождаем память при выходе
            break;
        default:
            cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter, чтобы продолжить...";
            cin.ignore(10000, '\n');
            cin.get();
        }
    } while (choice != 0);
}

// ГЛАВНАЯ ФУНКЦИЯ

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;
    do {
        PrintSeparator();
        cout << "       ЛАБОРАТОРНАЯ РАБОТА №1\n";
        cout << "========================================\n";
        cout << "1. Задание 1: Методы (нечетные)\n";
        cout << "2. Задание 2: Условия (нечетные)\n";
        cout << "3. Задание 3: Циклы (нечетные)\n";
        cout << "4. Задание 4: Массивы (нечетные)\n";
        cout << "0. Выход из программы\n";
        cout << "========================================\n";

        choice = GetValidInt("Выберите раздел (0-4): ", 0, 4);
        cout << "\n";

        switch (choice) {
        case 1: MenuTask1(); break;
        case 2: MenuTask2(); break;
        case 3: MenuTask3(); break;
        case 4: MenuTask4(); break;
        case 0: cout << "Программа завершена. Удачи!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
