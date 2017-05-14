#ifndef __VELHA_H__
#define __VELHA_H__

struct _Player{
    char name[256];
    char symbol[1];
};

typedef struct _Player Player;

char scenario[9];

void initialSetup();
void changePlayerName();
void changePlayerSymbol();
void configure();
void drawScenario();
void start();

#endif

