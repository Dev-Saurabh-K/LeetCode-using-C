#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_SHOWN);
    
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000); // Keep window open for 3 seconds
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
