//
// Created by holly on 09/03/23.
//

#include "camera.h"
#include <SDL2/SDL.h>
#include <thread>


#include "../game/game.h"
#include "../utils/vector2.h"

using namespace std;

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern Game game;
extern int screen_width;
extern int screen_height;
extern SDL_Texture* background_texture;


Camera::Camera() {

}


void Camera::draw_game() {
    Vector2 offset(-game.local_player.position.x, -game.local_player.position.y);
    offset.add(screen_width/2, screen_height/2);
    offset.minus(game.local_player.scale.x/2, game.local_player.scale.y/2);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,100, 100, 100, 100);
    SDL_Rect p; // Player rectangle, replace with texture for player sprite to not be rectangle


    p.x = 0+offset.x;
    p.y = 0+offset.y;
    p.w = 100;
    p.h = 100;
    SDL_RenderFillRect(renderer, &p);

    SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
//    Vector2 newpos = game.local_player.get_position().get_add(offset).get_minus(game.local_player.scale.x/2, game.local_player.scale.y/2);
    p.x = int(game.local_player.position.x + offset.x);
//    printf("%d\n", p.x);
    p.y = int(game.local_player.position.y + offset.y);
    p.w = int(game.local_player.scale.x);
    p.h = int(game.local_player.scale.y);
    SDL_RenderFillRect(renderer, &p);


//    SDL_RenderCopy( renderer, background_texture, NULL, &p );



    SDL_RenderPresent(renderer);






////    printf(" %f ", game.local_player.position.x);
//    Vector2 modifier;
//    modifier = Vector2(screen_width / 2, screen_height / 2);
//    modifier.minus(game.local_player.position.get_multiple(this->scale));
////    printf(" %f ", (modifier.x));
//    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//    SDL_RenderClear(renderer);
//    SDL_SetRenderDrawColor(renderer,
//                           game.local_player.color.r,
//                           game.local_player.color.g,
//                           game.local_player.color.b,
//                           game.local_player.color.a);
//    SDL_Rect p; // Player rectangle, replace with texture for player sprite to not be rectangle
//    p.x = game.local_player.position.x + modifier.x - (game.local_player.scale.x / 2)*scale;
//    p.y = game.local_player.position.y + modifier.y - (game.local_player.scale.y / 2)*scale;
//    p.w = (game.local_player.scale.x)*scale;
//    p.h = (game.local_player.scale.y)*scale;
//    SDL_RenderFillRect(renderer, &p);
//    SDL_RenderPresent(renderer);
}

void Camera::rescale_window(int w, int h) {
    SDL_SetWindowSize(window, w, h);
    screen_height = h;
    screen_width = w;
}