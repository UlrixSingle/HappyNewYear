#ifndef DECORATEDTREE_H
#define DECORATEDTREE_H
#include "tree.h"
#include <vector>
#include <ctime>

class DecoratedTree : public Tree {
    int n_decorations;
    vector < pair<int, int> > decorations_pos;

    char decoration_view = 'O';

public:
    void init( int height, int n_decorations);
    void decorating();
};

#endif // DECORATEDTREE_H
