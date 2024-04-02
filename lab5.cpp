#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }

    int Q;
    input >> Q;

    vector<int> pagesRead(1001, 0); // Зберігає кількість прочитаних сторінок кожним користувачем
    vector<int> usersCount(1001, 0); // Зберігає кількість користувачів, які прочитали кожну сторінку
    unordered_map<int, int> lastReadPage; // Зберігає останню прочитану сторінку кожним користувачем

    int users = 0; // Загальна кількість користувачів

    for (int i = 0; i < Q; ++i) {
        string query;
        input >> query;

        if (query == "READ") {
            int user, page;
            input >> user >> page;

            // Якщо користувач ще не був зареєстрований, збільшуємо загальну кількість користувачів
            if (lastReadPage.find(user) == lastReadPage.end()) {
                ++users;
            }

            // Оновлюємо кількість прочитаних сторінок користувачем та загальну кількість користувачів, які прочитали цю сторінку
            pagesRead[user] = page;
            ++usersCount[page];

            // Оновлюємо останню прочитану сторінку користувачем
            lastReadPage[user] = page;
        }
        else if (query == "CHEER") {
            int user;
            input >> user;

            // Якщо користувач не мав жодної події READ, він не враховується при обчисленні часток
            if (lastReadPage.find(user) == lastReadPage.end()) {
                cout << "0\n";
                continue;
            }

            // Обчислюємо частку користувачів, які прочитали менше сторінок, ніж user
            int lessPagesUsers = 0;
            for (int j = 1; j <= lastReadPage[user]; ++j) {
                lessPagesUsers += usersCount[j];
            }

            double fraction = (double)lessPagesUsers / users;
            cout << fraction << endl;
        }
    }

    input.close();
    return 0;
}
