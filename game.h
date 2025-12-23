#ifndef GAME_H
#define GAME_H

#define ROWS 20
#define COLS 10

//byte_field
typedef struct{
    int board[ROWS][COLS];
    int score; //punteggio partita
} game_state;

//struttura singolo quadrato
typedef struct{
    int dx;
    int dy;
} Offset;

//struttura di un pezzo
typedef struct {
    Offset shape[4];
    int color_id;
} Piece;

//funzione che inizializza e resetta il campo
void init_game(game_state *game){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            game->board[i][j] = 0;
        }
    }
    game->score = 0;
}

#endif