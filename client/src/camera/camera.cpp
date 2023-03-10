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

void Camera::set_color(Color color) {
    SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);
}

void Camera::draw_players(Vector2 offset) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    for (int p = 0; p < game.player_number; p++){
        set_color(game.players[p].color);
        rect.x = int(game.players[p].position.x + offset.x);
        rect.y = int(game.players[p].position.y + offset.y);
        rect.w = int(game.players[p].scale.x);
        rect.h = int(game.players[p].scale.y);
        SDL_RenderFillRect(renderer, &rect);
    }
}

void Camera::draw_local_player(Vector2 offset) {
    set_color(game.local_player.color);
    rect.x = int(game.local_player.position.x + offset.x);
    rect.y = int(game.local_player.position.y + offset.y);
    rect.w = int(game.local_player.scale.x);
    rect.h = int(game.local_player.scale.y);
    SDL_RenderFillRect(renderer, &rect);
}

void Camera::draw_background(Vector2 offset) {
    SDL_SetRenderDrawColor(renderer,100, 100, 100, 100);
    rect.x = 0+offset.x;
    rect.y = 0+offset.y;
    rect.w = 1920;
    rect.h = 1080;
    SDL_RenderFillRect(renderer, &rect);
//    SDL_RenderCopy(renderer, background_texture, NULL, &rect);
}


void Camera::draw_game() {
    Vector2 offset(-game.local_player.position.x, -game.local_player.position.y);
    offset.add(screen_width/2, screen_height/2);
    offset.minus(game.local_player.scale.x/2, game.local_player.scale.y/2);
    SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
    SDL_RenderClear(renderer);


    draw_background(offset);
    draw_players(offset);
    draw_local_player(offset);


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