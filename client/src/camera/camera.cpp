//
// Created by holly on 16/03/23.
//

#include "camera.h"
#include <SDL2/SDL.h>


#include "../game/game.h"

using namespace std;

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern Game game;
extern int screen_width;
extern int screen_height;
extern SDL_Texture *background_texture;


Camera::Camera() { rect = SDL_Rect(); }

void Camera::set_color(Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Camera::draw_players(Vector2 offset) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    for (int p = 0; p < game.number_of_players; p++) {
//        set_color(game.players[p].color);
        rect.x = (game.players[p].position.x * scale + offset.x) - (game.players[p].scale.x / 2) * scale;
        rect.y = (game.players[p].position.y * scale + offset.y) - (game.players[p].scale.x / 2) * scale;
        rect.w = int((game.players[p].scale.x) * scale);
        rect.h = int((game.players[p].scale.y) * scale);
        SDL_RenderFillRect(renderer, &rect);
    }
}


void Camera::draw_background(Vector2 offset) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100);
    rect.x = 0 + offset.x;
    rect.y = 0 + offset.y;
    rect.w = 10000 * scale;
    rect.h = 5000 * scale;
    SDL_RenderFillRect(renderer, &rect);
//    SDL_RenderCopy(renderer, background_texture, NULL, &rect);
}

void Camera::draw_map(Vector2 offset) {
    for (int h = 0; h < game.map.height; h++) {
        for (int w = 0; w < game.map.width; w++) {
            if (game.map.map[w][h] == 1){
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
            }else {
                SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            }
            rect.x = (w * game.map.scale) * scale + offset.x;
            rect.y = (h * game.map.scale) * scale + offset.y; //wut??
            rect.w = (game.map.scale/2) * scale;
            rect.h = (game.map.scale/2) * scale;
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}


void Camera::draw_game() {
    Vector2 offset(-game.players[game.localPlayerID].position.x * scale, -game.players[game.localPlayerID].position.y *scale);
    offset.add((screen_width / 2), (screen_height / 2));
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    draw_background(offset);
    draw_map(offset);
    draw_players(offset);
//    draw_local_player(offset);

    SDL_RenderPresent(renderer);
}

void Camera::rescale_window(int w, int h) {
    SDL_SetWindowSize(window, w, h);
    screen_height = h;
    screen_width = w;
}