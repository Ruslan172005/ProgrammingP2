#pragma once

#include <sstream>
#include <exception>
#include <iostream>
#include <string>

class TestRunner {
public:
    template <typename TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        }
        catch (const std::exception& e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
        catch (...) {
            ++fail_count;
            std::cerr << test_name << " fail: unknown exception" << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

#define ASSERT_EQUAL(x, y) {            \
  std::ostringstream os;                \
  os << #x << " != " << #y << ", "      \
     << __FILE__ << ":" << __LINE__;    \
  AssertEqual(x, y, os.str());          \
}

template <typename T, typename U>
void AssertEqual(const T& t, const U& u, const std::string& hint) {
    if (t != u) {
        throw std::runtime_error(hint);
    }
}
