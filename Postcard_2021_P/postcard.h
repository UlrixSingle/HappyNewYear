#ifndef POSTCARD_H
#define POSTCARD_H
#include "consolecolour.h"
#include "decoratedtree.h"
#include <string.h>

class Postcard {
    DecoratedTree tree;
    string receipment_name;

public:
    Postcard();

    void get_receipment_name();
    void presenting( bool state);

private:
    void clear();
    void show();
};

#endif // POSTCARD_H
