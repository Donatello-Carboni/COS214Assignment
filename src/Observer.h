#ifndef Observer_H
#define Observer_H

#include "Table.h"

class Observer {
    public:
        void virtual  update(Table*) = 0;
};

#endif