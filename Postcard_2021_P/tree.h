#ifndef TREE_H
#define TREE_H
#include "consolecolour.h"
using namespace std;

class Tree {
    int height;
    int width;
    char** body;
    int** colour;

public:
    virtual void init( int height);
    virtual ~Tree();

    void set_body( int x, int y, char val);
    void set_colour( int x, int y, int col);
    int get_height();
    int get_width();
    void show();
    void build();
};

#endif // TREE_H
