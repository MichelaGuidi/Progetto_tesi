#ifndef GAME_H
#define GAME_H

#define ROWS 20
#define COLS 10

//struttura singolo quadrato
typedef struct{
    int dx;
    int dy;
} Offset;

//struttura di un pezzo
typedef struct {
    Offset shape[5]; //cambiato da 4 a 5 per realizzare dei pentamini al posto dei tetramini
    int color_id;
} Piece;

//byte_field
typedef struct{
    int board[ROWS][COLS];
    int score; //punteggio partita

    Piece active_piece; //definiamo il pezzo che deve muoversi
    int active_x; // colonna in cui si trova (l'inizio)
    int active_y; // riga in cui si trova (l'inizio)
} game_state;


//definizione figure (tutte da 5 quadtratini)
static const Piece PIECES[12] = {
    {{{0,0}, {1,0}, {2,0}, {3,0}, {4,0}}, 1}, // lettera I 
    {{{0,0}, {0,1}, {1,1}, {2,1}, {2,0}}, 2}, // lettera U
    {{{0,0}, {1,0}, {2,0}, {1,1}, {1,2}}, 3}, // lettera T
    {{{0,0}, {0,1}, {1,1}, {2,1}, {2,2}}, 4}, // lettera Z
    {{{1,0}, {0,1}, {0,2}, {1,1}, {2,1}}, 5}, // lettera F
    {{{0,0}, {1,0}, {2,0}, {3,0}, {3,1}}, 6}, // lettera L
    {{{1,0}, {2,0}, {3,0}, {0,1}, {1,1}}, 7}, // lettera N
    {{{1,0}, {2,0}, {0,1}, {1,1}, {2,1}}, 8}, // lettera P
    {{{0,0}, {1,0}, {2,0}, {2,1}, {2,2}}, 9}, // lettera V
    {{{0,0}, {1,0}, {1,1}, {2,1}, {2,2}}, 10}, // lettera W
    {{{1,0}, {0,1}, {1,1}, {2,1}, {1,2}}, 11}, // lettera X
    {{{1,0}, {0,1}, {1,1}, {2,1}, {3,1}}, 12}, // lettera Y
};

//funzione che inizializza e resetta il campo
void init_game(game_state *game){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            game->board[i][j] = 0;
        }
    }
    game->score = 0;

    //inizializzazione primo pezzo
    game->active_piece = PIECES[0];
    game->active_x = 3;
    game->active_y = 0;
}

#endif