#include "simple_vector.h"
#include "test_runner.h"

void TestConstruction() {
    // Тест для конструктора за замовчуванням
    SimpleVector<int> v_default;
    ASSERT_EQUAL(v_default.Size(), 0u);
    ASSERT_EQUAL(v_default.Capacity(), 0u);

    // Тест для конструктора з параметром size
    SimpleVector<int> v_with_size(5);
    ASSERT_EQUAL(v_with_size.Size(), 5u);
    ASSERT_EQUAL(v_with_size.Capacity(), 5u);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQUAL(v_with_size[i], 0); // Перевіряємо, чи всі елементи дорівнюють 0
    }
}

void TestPushBack() {
    SimpleVector<int> v;

    // Тест додавання елементів за допомогою методу PushBack
    for (int i = 1; i <= 5; ++i) {
        v.PushBack(i);
        ASSERT_EQUAL(v.Size(), i); // Розмір має збільшуватись на 1 після кожного додавання
        ASSERT_EQUAL(v[i - 1], i); // Останній доданий елемент має бути рівним i
    }

    // Перевірка ємності після додавання елементів
    ASSERT(v.Capacity() >= v.Size());

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestPushBack);
    return 0;
}
