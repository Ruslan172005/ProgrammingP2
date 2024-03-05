#pragma once

#include "airline_ticket.h"
#include <algorithm>

#define SORT_BY(field) [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
    return lhs.field < rhs.field; \
}
