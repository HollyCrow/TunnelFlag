//
// Created by holly on 09/03/23.
//

#include "camera.h"
#include <SDL2/SDL.h>

#include "../game/game.h"
#include "../utils/vector2.h"

extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern Game game;
extern int screen_width;
extern int screen_height;



Camera::Camera(){

}


void Camera::draw_game() {
//    game.local_player.velocity.x = 0.1;

    for (int i = 0; i < 5000; i++){
        Vector2 camera_center(screen_width/2, screen_height/2);
        Vector2 modifier = camera_center.get_minus(game.local_player.position.get_multiple(this->scale));
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, game.local_player.color.r, game.local_player.color.g, game.local_player.color.b, game.local_player.color.a);
        SDL_Rect p; // Player rectangle, replace with texture for player sprite to not be rectangle
        p.x = game.local_player.position.x + modifier.x - game.local_player.scale.x/2;
        p.y = game.local_player.position.y + modifier.y - game.local_player.scale.y/2;
        p.w = game.local_player.scale.x;
        p.h = game.local_player.scale.y;
        SDL_RenderFillRect(renderer, &p);
        SDL_RenderPresent(renderer);
//        game.local_player.update_position();
    }

}


void Camera::rescale_window(int w, int h) {
    SDL_SetWindowSize(window, w, h);
    screen_height = h;
    screen_width = w;
}
