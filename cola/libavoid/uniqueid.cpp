//
// Created by user on 09.03.24.
//

#include "uniqueid.h"

unsigned int getNewUniqueId() {
    if (counter == (std::numeric_limits<unsigned int>::max() - 1)) {
        // avoid overflow
        counter = 0;
    }
    counter += 1;
    return counter;
}
