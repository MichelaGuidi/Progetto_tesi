#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

//Dimensioni finestra
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 600;


int main(int argc, char* args[]){

    //test per vedere se il terminale stampa correttamente
    //game_state game;
    //init_game(&game);

    //printf("il gioco esiste e il punteggio iniziale è: %d\n", game.score);
    
    //inizializzazione di SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Errore di inizializzazione: %s\n", SDL_GetError());
        return 1;
    }

    //Creazione finestra
    SDL_Window* window = SDL_CreateWindow("Progetto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
            SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //SDL_WINDOWPOS_UNDEFINED dice che sarà il SO a decidere dove mettere la finestra
    
    if (window == NULL){
        printf("errore di creazione della finestra %s\n", SDL_GetError());
        return 1;
    }


    //Creazione renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //l'ultimo parametro usa la gpu per rendere il tutto più veloce

    //Loop
    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) != 0){ //check per vedere se ci sono stati eventi
            if (e.type == SDL_QUIT){ //se l'evento è la 'X' per chiudere la finestra
                quit = true;
            } else if(e.type == SDL_KEYDOWN){ 
                if (e.key.keysym.sym == SDLK_ESCAPE) quit = true; //se premi ESC per uscire
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //colore nero
        SDL_RenderClear(renderer); //cancella lo schermo con il colore nero

        SDL_RenderPresent(renderer); //mostra il risultato
    }

    //Pulizia (chiusura e distruzione di window e renderer)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}