#include "postcard.h"

Postcard::Postcard() {
    receipment_name = "";
    tree.init( 19, 19);
}

void Postcard::get_receipment_name() {
    cout << "Please, enter your name: ";
    cin >> receipment_name;
}

void Postcard::presenting( bool state) {
    while( state) {
        clear();
        show();
        Sleep( 1000);
    }
}

void Postcard::clear() { system( "cls"); }

void Postcard::show() {
    tree.decorating();
    tree.show();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( hConsole, WORD((Black << 4) | Red) );
    cout << "\n\nHappy New Year, " << receipment_name << "!!!\n";
}
