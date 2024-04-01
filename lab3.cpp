#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

template<typename T>
class Table {
public:
    Table(size_t rows, size_t cols)
        : data(rows, std::vector<T>(cols)) {}

    const std::vector<T>& operator[](size_t idx) const {
        return data[idx];
    }

    std::vector<T>& operator[](size_t idx) {
        return data[idx];
    }

    void Resize(size_t rows, size_t cols) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(cols);
        }
    }

    std::pair<size_t, size_t> Size() const {
        if (data.empty() || data[0].empty()) {
            return {0, 0};
        }
        return {data.size(), data[0].size()};
    }

private:
    std::vector<std::vector<T>> data;
};

void TestTable() {
    Table<int> t(1, 1);
    assert(t.Size().first == 1u);
    assert(t.Size().second == 1u);
    t[0][0] = 42;
    assert(t[0][0] == 42);
    t.Resize(3, 4);
    assert(t.Size().first == 3u);
    assert(t.Size().second == 4u);
}

int main() {
    TestTable();
    std::cout << "TestTable OK" << std::endl;
    return 0;
}
