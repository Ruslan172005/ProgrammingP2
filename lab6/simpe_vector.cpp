#include "simple_vector.h"
#include "test_runner.h"

void TestConstruction() {
    // ���� ��� ������������ �� �������������
    SimpleVector<int> v_default;
    ASSERT_EQUAL(v_default.Size(), 0u);
    ASSERT_EQUAL(v_default.Capacity(), 0u);

    // ���� ��� ������������ � ���������� size
    SimpleVector<int> v_with_size(5);
    ASSERT_EQUAL(v_with_size.Size(), 5u);
    ASSERT_EQUAL(v_with_size.Capacity(), 5u);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQUAL(v_with_size[i], 0); // ����������, �� �� �������� ��������� 0
    }
}

void TestPushBack() {
    SimpleVector<int> v;

    // ���� ��������� �������� �� ��������� ������ PushBack
    for (int i = 1; i <= 5; ++i) {
        v.PushBack(i);
        ASSERT_EQUAL(v.Size(), i); // ����� �� ������������ �� 1 ���� ������� ���������
        ASSERT_EQUAL(v[i - 1], i); // ������� ������� ������� �� ���� ����� i
    }

    // �������� ������ ���� ��������� ��������
    ASSERT(v.Capacity() >= v.Size());

}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestConstruction);
    RUN_TEST(tr, TestPushBack);
    return 0;
}
