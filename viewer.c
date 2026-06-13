#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

// refer to the sdl documentation for the fucntions used.

int main() {
    FILE *in = stdin;
    char *pthroway = calloc(1000, sizeof(char));
    //reading because we are using ppm image format. 

    // read first line (specifier p3 or p6 -  no need)
    fgets(pthroway,1000 , in);
    // read second line which is a comment
    fgets(pthroway,1000 , in);
    
    //read 3rd line (dimensions-> width and height)
    char *pdimensions = calloc(1000, sizeof(char));
    fgets(pdimensions,1000 , in);
    
    int width = -1;
    int height = -1;
    // parsing image data width & height
    sscanf(pdimensions, "%d %d\n", &width, &height);
    free(pdimensions);
    printf("width= %d, height =%d\n", width, height);

    //read 4th line (max color bits - no need)
    fgets(pthroway, 1000, in);
    free(pthroway);

    
    SDL_Window *pwindow = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,height, 0);
    //SDL_Renderer *renderer = SDL_CreateRenderer(pwindow, -1, 0);

    // creating a sdl surface to fetch the pixel of the window created
    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);


    
    // declare it outside for perfomance, reuse the same SDL_Rect object instead of creating a new one on every iteration.
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};
    Uint32 color = 0;
    //set the color of every pixel indiviually
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            //  read rbg values
            Uint8 r,g,b;
            r=(char) getchar();
            g=(char) getchar();
            b=(char) getchar();
            // map color to the surface layout and get the pixel format of your surface
            color = SDL_MapRGB(psurface->format,r,g,b); 
            pixel.x=x;
            pixel.y=y;
            // fill the surface
            SDL_FillRect(psurface, &pixel, color);
        }
    }
    SDL_UpdateWindowSurface(pwindow);
    // SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);

    
    int viewer_running =1;
    while (viewer_running){
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if(event.type == SDL_QUIT)
            {
                viewer_running = 0;
            }
        }
        SDL_Delay(100);
    }
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(pwindow);
}