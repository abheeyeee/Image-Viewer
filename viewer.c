#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Hello World!\n");
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
    //SDL_Renderer *renderer = SDL_CreateRenderer(pwindow, -1, 0);
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    SDL_FillRect(psurface, NULL, 0xFF0000);
    SDL_UpdateWindowSurface(pwindow);
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(pwindow);
    SDL_Quit();
}