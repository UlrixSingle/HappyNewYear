#include "decoratedtree.h"

void DecoratedTree::init( int height, int n_decorations) {
    this->n_decorations = n_decorations;
    decorations_pos.resize( n_decorations);
    srand( time( 0));

    Tree::init( height);

    int tree_middle = get_width()/2 + 1;
    for( int i = 0; i < n_decorations; i++) {
        int y = rand()%(get_height()-2) + 1;
        int branch_len = y/3 + (y%3+1) - 2;
        int x = tree_middle - branch_len + 1 + rand()%( branch_len*2 + 1);

        decorations_pos[i] = {x, y};
        set_body( x, y, decoration_view);
    }
}

void DecoratedTree::decorating() {
    for( int i = 0; i < n_decorations; i++)
        set_colour( decorations_pos[i].first, decorations_pos[i].second, rand()%(White-LightBlue)+LightBlue);
}
