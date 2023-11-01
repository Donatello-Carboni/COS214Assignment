#ifndef Observer_H
#define Observer_H

class Observer {
    public:
        void virtual  update(Table*) = 0;
};

#endif