/*
fix this;
include some inertia! so that sprite doesn't stop moving immediately
improve friction; speed up should be slower (maybe a static constant)
check why vel wasn't going up past 6 (with different max vel and friction vals)
implement gravity!
*/

#include "sprite.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//constants
const float ACCELERATION = 1;
const int MAX_VEL = 6;
const float FRICTION = 0.01;
const float INERTIA = 0.5;


void spriteMoveUpdate(Sprite* sprite, SDL_Event* event){
    //handle different sprite movements according to provided event
    //event is only going to be inputted if type == SLD_KEYDOWN or SDLK_KEYUP
    if (event!=NULL && (event->type==SDL_KEYDOWN||event->type==SDL_KEYUP)){

        //change by acceleration when key down
        if (event->type==SDL_KEYDOWN){
            switch (event->key.keysym.sym){
                case SDLK_RIGHT:
                    sprite->vx += ACCELERATION; break;
                case SDLK_LEFT:
                    sprite->vx -= ACCELERATION; break;
                case SDLK_UP:
                    sprite->vy -= ACCELERATION; break;
                case SDLK_DOWN:
                    sprite->vy += ACCELERATION; break;
            }
        }

        //reset velocities when key let up
        else if (event->type==SDL_KEYUP){
            sprite->vx = 0;
            sprite->vy = 0;
        }
        
        //apply friction
        sprite->vx *= (1-FRICTION);
        sprite->vy *= (1-FRICTION);

        //check for velocity overflow
        if (abs(sprite->vx)>MAX_VEL){sprite->vx=MAX_VEL*(abs(sprite->vx)/sprite->vx);}
        if (abs(sprite->vy)>MAX_VEL){sprite->vy=MAX_VEL*(abs(sprite->vy)/sprite->vy);}

        //update position
        sprite->sourceRect->x +=  sprite->vx;
        sprite->sourceRect->y += sprite->vy;

    }
}