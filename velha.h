#ifndef VELHA_H
#define VELHA_H

typedef struct Player {
    char name[256];
    char symbol[1];
} Player;

char scenario[9];

void initialSetup();
void changePlayerName();
void changePlayerSymbol();
void configure();
void drawScenario();
void start();

#endif

