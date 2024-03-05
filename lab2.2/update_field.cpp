#include "airline_ticket.h"
#include "test_runner.h"
#include <map>
#include <sstream>

#define UPDATE_FIELD(ticket, field, values) \
    {                                        \
        auto it = values.find(#field);       \
        if (it != values.end()) {            \
            std::istringstream is(it->second); \
            is >> ticket.field;              \
        }                                    \
    }

void TestUpdateField() {
    AirlineTicket t;
    t.price = 8000;
    t.from = "LVIV";
    t.to = "Odessa";

    const std::map<std::string, std::string> updates = {
        {"price", "2500"},
        {"from", "KYIV"}
    };

    UPDATE_FIELD(t, price, updates);
    ASSERT_EQUAL(t.price, 2500);

    UPDATE_FIELD(t, from, updates);
    ASSERT_EQUAL(t.from, "KYIV");

    UPDATE_FIELD(t, to, updates);
    ASSERT_EQUAL(t.to, "Odessa");
}

int main() {
    TestRunner tr;
    tr.RunTest(TestUpdateField, "TestUpdateField");
    return 0;
}
