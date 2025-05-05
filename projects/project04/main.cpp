#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "game.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("Battleship",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1000, 600, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    while (running) {
        Game game;
        game.placeShips();
        game.AIShips(4); //amount of A.I ships

        bool quit = false;
        SDL_Event e;

        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    running = false;
                    quit = true;
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int row = e.button.y / 40;
                    int col = e.button.x < 400 ? e.button.x / 40 : (e.button.x - 500) / 40;
                    if (game.isValidMove(row, col) && game.status() == ONGOING) {
                        game.play(row, col);

                        if (game.status() == ONGOING) {
                            int aiRow, aiCol;
                            do {
                                aiRow = rand() % 10;
                                aiCol = rand() % 10;
                            } while (!game.isValidMove(aiRow, aiCol));

                            game.play(aiRow, aiCol);
                        }

                        if (game.status() != ONGOING) {
                            SDL_RenderPresent(renderer); 
                            SDL_Delay(500);
                            if (game.status() == PLAYER_1_WINS)
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "You win!\n Click again to start again or click the X to quit.", window);
                            else
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "You lose!\n Click again to start again or click the X to quit.", window);
                            quit = true;
                        }
                    }
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            game.draw(renderer);
            SDL_RenderPresent(renderer);
        }

        // Ask to replay or quit
        SDL_Event replayEvent;
        while (SDL_WaitEvent(&replayEvent)) {
            if (replayEvent.type == SDL_QUIT) {
                running = false;
                break;
            }
            else if (replayEvent.type == SDL_KEYDOWN || replayEvent.type == SDL_MOUSEBUTTONDOWN) {
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}