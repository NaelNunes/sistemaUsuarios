#include <windows.h>  // Para SetConsoleCursorPosition, GetConsoleScreenBufferInfo
#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>


// Fun��o para movimentar o cursor no terminal
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fun��o para obter o tamanho da janela do console
void getConsoleSize(int &width, int &height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Fun��o para desenhar as bordas do ret�ngulo
void drawBorder(int x1, int y1, int x2, int y2) {
    // Desenha as bordas superior e inferior
    for (int x = x1; x <= x2; ++x) {
        gotoxy(x, y1);
        WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "-", 1, NULL, NULL);
        gotoxy(x, y2);
        WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "-", 1, NULL, NULL);
    }

    // Desenha as bordas esquerda e direita
    for (int y = y1 + 1; y < y2; ++y) {
        gotoxy(x1, y);
        WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "|", 1, NULL, NULL);
        gotoxy(x2, y);
        WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "|", 1, NULL, NULL);
    }
}

// Fun��o para desenhar a interface de login centralizada
void mostrarInterfaceLogin() {
    system("cls");  // Limpa a tela

    int screenWidth, screenHeight;
    getConsoleSize(screenWidth, screenHeight);  // Obt�m o tamanho da janela do console

    // Definindo as dimens�es do ret�ngulo
    int boxWidth = 40;  // Largura do ret�ngulo (�rea do formul�rio de login)
    int boxHeight = 10; // Altura do ret�ngulo

    // Calculando a posi��o para centralizar o ret�ngulo
    int startX = (screenWidth - boxWidth) / 2;
    int startY = (screenHeight - boxHeight) / 2;

    // Desenhando a borda do ret�ngulo
    drawBorder(startX, startY, startX + boxWidth - 1, startY + boxHeight - 1);

    // Adicionando o t�tulo
    gotoxy(startX + 7, startY + 1);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "***** Tela de Login *****", 26, NULL, NULL);

    // Campos de usu�rio e senha
    gotoxy(startX + 2, startY + 3);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "Usuario: ", 8, NULL, NULL);

    gotoxy(startX + 2, startY + 5);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "Senha: ", 7, NULL, NULL);
    
    gotoxy(startX + 12, startY + 3);

    // Mensagem de instru��o
}

int main() {
    mostrarInterfaceLogin();
    getch();
    // Aqui voc� pode adicionar a l�gica de captura de dados e valida��o

    return 0;
}

