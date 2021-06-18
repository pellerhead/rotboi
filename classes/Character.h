//
// Created by Tyler on 6/15/2021.
//

#ifndef ROTBOI_CHARACTER_H
#define ROTBOI_CHARACTER_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Character : public Entity{
public:
    bool isShooting;
    char shotDirection;
    bool canShoot;
    float shotTimer;

    bool shot2;
    int goldCount;


    double dexterity;
    int attack;
    int critChance;
    int critDamage;
    float shotSpeed;
    float range;

    char lastDirection;

    bool walk2;
    sf::Clock gClock;
    float walkTimer, walkDelay;



    Character(){

        name = "character";
        isAlive = true;
        walkDelay = 0.2;

        isShooting = false;
        canShoot = false;
        shot2 = false;


        dexterity = 0.2;
        attack = 1;
        shotSpeed = 10;
        range = 5;

        minDamage = 100;
        maxDamage = 115;

        critChance = 100;
        critDamage = 2;



    }

    void update() {
        float walkTime = gClock.getElapsedTime().asSeconds();
        float shootTime = gClock.getElapsedTime().asSeconds();

        gClock.restart();

        walkTimer += walkTime;
        shotTimer += shootTime;

        if (shotTimer > (float(dexterity)/10)){
            canShoot = true;
        } else if (shotTimer > ((float(dexterity) / 10) / 2)){
            shot2 = false;
        }

        if (walkTimer > walkDelay){
            if (walk2) {
                walk2 = false;
            } else {
                walk2 = true;
            }
            walkTimer = 0;
        }
    }

};


#endif //ROTBOI_CHARACTER_H
