#include "tree.h"

void Tree::init( int height) {
    this->height = height;
    this->width = height + ( height%2 == 0 ? 1:0 );

    body = new char* [this->height];
    colour = new int* [this->height];
    for( int i = 0; i < this->height; i++) {
        body[i] = new char [this->width];
        colour[i] = new int [this->width];
    }

    build();
}

Tree::~Tree() {
    for( int i = 0; i < height; i++) {
        delete [] body[i];
        delete [] colour[i];
    }
}

void Tree::set_body( int x, int y, char val) {
    if( x < 0 || x > width) return;
    if( y < 0 || y > height) return;
    body[y][x] = val;
}

void Tree::set_colour( int x, int y, int col) {
    if( x < 0 || x > width) return;
    if( y < 0 || y > height) return;
    colour[y][x] = col;
}

int Tree::get_height() { return height; }

int Tree::get_width() { return width; }

void Tree::show() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for( int y = 0; y < height; y++) {
        for( int x = 0; x < width; x++) {
            SetConsoleTextAttribute( hConsole, WORD((Black << 4) | colour[y][x]) );
            cout << body[y][x];
        }   cout << "\n";
    }
}

void Tree::build() {
    // Up with star
    for( int x = 0; x < width; x++) {
        if( x == width/2 + 1) body[0][x] = '*';
        else body[0][x] = ' ';

        colour[0][x] = Yellow;
    }

    // body (almost)
    int tree_middle = width/2 + 1;

    for( int y = 1; y < height; y++) {
        for( int x = 0; x < width; x++) {
            if( tree_middle - y/3 - (y%3+1) < x && x < tree_middle)
                body[y][x] = '/';
            else if( x == tree_middle)
                body[y][x] = '|';
            else if( tree_middle < x && x < tree_middle + y/3 + (y%3+1) )
                body[y][x] = '\\';
            else
                body[y][x] = ' ';

            colour[y][x] = Green;
        }
    }

    // Trunk
    int trunk_width = 1+width/19 + ( (1+width/19)%2 == 0 ? 1:0 );
    int trunk_begin = (width-trunk_width)/2; // index of first trunk element
    int trunk_end = trunk_begin + trunk_width + 1; // index of element after last trunk element

    for( int x = 0; x < width; x++) {
        if( x == trunk_begin)
            body[height-1][x] = '[';
        else if( trunk_begin < x && x < trunk_end)
            body[height-1][x] = '|';
        else if( x == trunk_end)
            body[height-1][x] = ']';
        else
            body[height-1][x] = ' ';

        colour[height-1][x] = Brown;
    }
}
