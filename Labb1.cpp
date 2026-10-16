// Лабораторная работа №1. Процедурное программирование.
// Студент: Сальников М.А., группа ИТ-5
// Вариант: Нечетные номера задач (1, 3, 5, 7, 9)

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ============================================================================
// ЗАДАНИЕ 1. МЕТОДЫ
// ============================================================================

double fraction(double x) {
    return x - static_cast<int>(x);
}

int charToNum(char x) {
    return x - '0';
}

bool is2Digits(int x) {
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

bool isInRange(int a, int b, int num) {
    int min_val = (a < b) ? a : b;
    int max_val = (a > b) ? a : b;
    return num >= min_val && num <= max_val;
}

bool isEqual(int a, int b, int c) {
    return a == b && b == c;
}

// ============================================================================
// ЗАДАНИЕ 2. УСЛОВИЯ
// ============================================================================

int absVal(int x) {
    return (x < 0) ? -x : x;
}

bool is35(int x) {
    bool div3 = (x % 3 == 0);
    bool div5 = (x % 5 == 0);
    return (div3 || div5) && !(div3 && div5);
}

int max3(int x, int y, int z) {
    int max_val = x;
    if (y > max_val) max_val = y;
    if (z > max_val) max_val = z;
    return max_val;
}

int sum2(int x, int y) {
    int sum = x + y;
    if (sum >= 10 && sum <= 19) {
        return 20;
    }
    return sum;
}

string day(int x) {
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

// ============================================================================
// ЗАДАНИЕ 3. ЦИКЛЫ
// ============================================================================

string listNums(int x) {
    string result;
    for (int i = 0; i <= x; ++i) {
        result += std::to_string(i);
        if (i < x) result += " ";
    }
    return result;
}

string chet(int x) {
    string result;
    for (int i = 0; i <= x; i += 2) {
        result += std::to_string(i);
        if (i + 2 <= x) result += " ";
    }
    return result;
}

int numLen(long x) {
    if (x == 0) return 1;
    int len = 0;
    long temp = (x < 0) ? -x : x;
    while (temp > 0) {
        temp /= 10;
        ++len;
    }
    return len;
}

void square(int x) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) cout << "*";
        cout << endl;
    }
}

void rightTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < x - i; ++j) cout << " ";
        for (int j = 0; j < i; ++j) cout << "*";
        cout << endl;
    }
}

// ============================================================================
// ЗАДАНИЕ 4. МАССИВЫ
// (Добавлен параметр size, так как в C++ размер сырого массива неизвестен)
// ============================================================================

int findFirst(const int arr[], int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int maxAbs(const int arr[], int size) {
    int max_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (absVal(arr[i]) > absVal(max_val)) max_val = arr[i];
    }
    return max_val;
}

int* addArray(const int arr[], int arr_size, const int ins[], int ins_size,
    int pos, int& new_size) {
    new_size = arr_size + ins_size;
    int* result = new int[new_size];
    int idx = 0;
    for (int i = 0; i < pos && i < arr_size; ++i) result[idx++] = arr[i];
    for (int i = 0; i < ins_size; ++i) result[idx++] = ins[i];
    for (int i = pos; i < arr_size; ++i) result[idx++] = arr[i];
    return result;
}

int* reverseBack(const int arr[], int size, int& new_size) {
    new_size = size;
    int* result = new int[size];
    for (int i = 0; i < size; ++i) result[i] = arr[size - 1 - i];
    return result;
}

int* findAll(const int arr[], int size, int x, int& count) {
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

// ============================================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
// ============================================================================

int getValidInt(const string& prompt, int min_val, int max_val) {
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

void printSeparator() {
    cout << "\n========================================\n";
}

// ============================================================================
// ПОДМЕНЮ ДЛЯ КАЖДОГО ЗАДАНИЯ
// ============================================================================

void menuTask1() {
    int choice;
    do {
        printSeparator();
        cout << "ЗАДАНИЕ 1. МЕТОДЫ\n";
        cout << "1. Дробная часть\n3. Букву в число\n5. Двузначное\n";
        cout << "7. Диапазон\n9. Равенство\n0. Назад в главное меню\n";
        choice = getValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);

        switch (choice) {
        case 1: {
            double x;
            cout << "Введите вещественное число: ";
            cin >> x;
            cout << "Дробная часть: " << fraction(x) << endl;
            break;
        }
        case 3: {
            char ch;
            cout << "Введите символ цифры ('0'-'9'): ";
            cin >> ch;
            cout << "Число: " << charToNum(ch) << endl;
            break;
        }
        case 5: {
            int x;
            cout << "Введите целое число: ";
            cin >> x;
            cout << "Двузначное? " << (is2Digits(x) ? "Да" : "Нет") << endl;
            break;
        }
        case 7: {
            int a, b, num;
            cout << "Введите a, b и num: ";
            cin >> a >> b >> num;
            cout << "Входит в диапазон? " << (isInRange(a, b, num) ? "Да" : "Нет") << endl;
            break;
        }
        case 9: {
            int a, b, c;
            cout << "Введите a, b и c: ";
            cin >> a >> b >> c;
            cout << "Все равны? " << (isEqual(a, b, c) ? "Да" : "Нет") << endl;
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void menuTask2() {
    int choice;
    do {
        printSeparator();
        cout << "ЗАДАНИЕ 2. УСЛОВИЯ\n";
        cout << "1. Модуль числа\n3. Тридцать пять\n5. Тройной максимум\n";
        cout << "7. Двойная сумма\n9. День недели\n0. Назад в главное меню\n";
        choice = getValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);

        switch (choice) {
        case 1: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Модуль: " << absVal(x) << endl;
            break;
        }
        case 3: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Делится на 3 или 5 (но не на оба)? "
                << (is35(x) ? "Да" : "Нет") << endl;
            break;
        }
        case 5: {
            int x, y, z;
            cout << "Введите три числа: ";
            cin >> x >> y >> z;
            cout << "Максимум: " << max3(x, y, z) << endl;
            break;
        }
        case 7: {
            int x, y;
            cout << "Введите два числа: ";
            cin >> x >> y;
            cout << "Сумма (с правилом 10-19): " << sum2(x, y) << endl;
            break;
        }
        case 9: {
            int x;
            cout << "Введите номер дня (1-7): ";
            cin >> x;
            cout << "День: " << day(x) << endl;
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void menuTask3() {
    int choice;
    do {
        printSeparator();
        cout << "ЗАДАНИЕ 3. ЦИКЛЫ\n";
        cout << "1. Числа подряд\n3. Четные числа\n5. Длина числа\n";
        cout << "7. Квадрат\n9. Правый треугольник\n0. Назад в главное меню\n";
        choice = getValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);

        switch (choice) {
        case 1: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Результат: " << listNums(x) << endl;
            break;
        }
        case 3: {
            int x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Результат: " << chet(x) << endl;
            break;
        }
        case 5: {
            long x;
            cout << "Введите число: ";
            cin >> x;
            cout << "Длина числа: " << numLen(x) << endl;
            break;
        }
        case 7: {
            int x;
            cout << "Введите размер квадрата: ";
            cin >> x;
            square(x);
            break;
        }
        case 9: {
            int x;
            cout << "Введите высоту треугольника: ";
            cin >> x;
            rightTriangle(x);
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

void menuTask4() {
    // Тестовый массив для демонстрации (чтобы не вводить его каждый раз)
    const int kTestSize = 7;
    int test_arr[kTestSize] = { 1, 2, -7, 4, 2, 2, 5 };

    int choice;
    do {
        printSeparator();
        cout << "ЗАДАНИЕ 4. МАССИВЫ (Тестовый массив: [1, 2, -7, 4, 2, 2, 5])\n";
        cout << "1. Поиск первого значения\n3. Поиск максимального по модулю\n";
        cout << "5. Добавление массива в массив\n7. Возвратный реверс\n";
        cout << "9. Все вхождения\n0. Назад в главное меню\n";
        choice = getValidInt("Выберите задачу (0, 1, 3, 5, 7, 9): ", 0, 9);

        switch (choice) {
        case 1: {
            int x;
            cout << "Какое число искать? ";
            cin >> x;
            cout << "Индекс первого вхождения: " << findFirst(test_arr, kTestSize, x) << endl;
            break;
        }
        case 3: {
            cout << "Максимальный по модулю: " << maxAbs(test_arr, kTestSize) << endl;
            break;
        }
        case 5: {
            const int kInsSize = 2;
            int ins_arr[kInsSize] = { 9, 9 };
            int new_size;
            int* res = addArray(test_arr, kTestSize, ins_arr, kInsSize, 3, new_size);
            cout << "Новый массив: ";
            for (int i = 0; i < new_size; ++i) cout << res[i] << " ";
            cout << endl;
            delete[] res; // Освобождаем память
            break;
        }
        case 7: {
            int new_size;
            int* res = reverseBack(test_arr, kTestSize, new_size);
            cout << "Перевернутый массив: ";
            for (int i = 0; i < new_size; ++i) cout << res[i] << " ";
            cout << endl;
            delete[] res;
            break;
        }
        case 9: {
            int x;
            cout << "Какое число искать? ";
            cin >> x;
            int count;
            int* res = findAll(test_arr, kTestSize, x, count);
            cout << "Индексы вхождений: ";
            for (int i = 0; i < count; ++i) cout << res[i] << " ";
            cout << endl;
            delete[] res;
            break;
        }
        case 0: break;
        default: cout << "Пожалуйста, выберите нечетное число или 0.\n";
        }
    } while (choice != 0);
}

// ============================================================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================================================

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

    int choice;
    do {
        printSeparator();
        cout << "       ЛАБОРАТОРНАЯ РАБОТА №1\n";
        cout << "========================================\n";
        cout << "1. Задание 1: Методы (нечетные)\n";
        cout << "2. Задание 2: Условия (нечетные)\n";
        cout << "3. Задание 3: Циклы (нечетные)\n";
        cout << "4. Задание 4: Массивы (нечетные)\n";
        cout << "0. Выход из программы\n";
        cout << "========================================\n";

        choice = getValidInt("Выберите раздел (0-4): ", 0, 4);

        switch (choice) {
        case 1: menuTask1(); break;
        case 2: menuTask2(); break;
        case 3: menuTask3(); break;
        case 4: menuTask4(); break;
        case 0: cout << "Программа завершена. Удачи!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
