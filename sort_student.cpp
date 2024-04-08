#include "student.h"
#include "test_runner.h"
#include "profile.h" // Включення файлу для вимірювання часу виконання

#include <algorithm>
#include <vector>

using namespace std;

// Оптимізована функція порівняння
bool Compare(const Student& first, const Student& second) {
    return first.rating > second.rating;
}

void TestComparison() {
    // ... ваші тестові дані
}

void TestSorting() {
    // ... ваші тестові дані
}

int main() {
    // Запуск тестів
    TestRunner tr;
    RUN_TEST(tr, TestComparison);
    RUN_TEST(tr, TestSorting);

    // Генерування великої кількості студентів для вимірювання швидкодії
    vector<Student> students;
    for (int i = 0; i < 25000; ++i) {
        students.push_back({ "Name" + to_string(i), "Surname" + to_string(i), {{"Math", 5.0}}, double(i) });
    }

    // Вимірювання часу виконання сортування
    {
        LOG_DURATION("Sorting time");
        sort(students.begin(), students.end(), Compare);
    }

    // Перевірка відсортованості
    ASSERT(is_sorted(students.begin(), students.end(), [](const Student& first, const Student& second) {
        return Compare(first, second);
        }));

    return 0;
}
