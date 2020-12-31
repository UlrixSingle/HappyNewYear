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

/*
void Postcard::clear() {
    COORD topLeft  = { 0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
} */

void Postcard::show() {
    /*
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colour = rand()%White + Blue;
    SetConsoleTextAttribute( hConsole, (WORD) ((Black << 4) | colour));
    cout << "Hello, " << receipment_name << "\n"; */

    tree.decorating();
    tree.show();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( hConsole, WORD((Black << 4) | Red) );
    cout << "\n\nHappy New Year, " << receipment_name << "!!!\n";
}
