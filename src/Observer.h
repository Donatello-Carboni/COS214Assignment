#ifndef Observer_H
#define Observer_H

class Table;

class Observer {
    public:
        void virtual update(Table* changedTable) = 0;
};

#endif