//
// Created by antotauv on 05/09/2024.
//

#include "Pokemon.hpp"

#include <iostream>

int Pokemon::numberOfPokemon=0;

Pokemon::Pokemon(const string &name, int id, double hitPoint, double attack, double defense, int generation) : name(
        name), id(id), hitPoint(hitPoint), attackValue(attack), defense(defense), generation(generation) {

    numberOfPokemon++;
}

Pokemon::Pokemon(const Pokemon& anotherPokemon) : name(anotherPokemon.name),id(anotherPokemon.id),
        hitPoint(anotherPokemon.hitPoint), attackValue(anotherPokemon.attackValue), defense(anotherPokemon.defense),
        generation(anotherPokemon.generation){

    numberOfPokemon++;
}

void Pokemon::scream(){
    std::cout<<"Grrr ! I'm " << name << std::endl;
}

void Pokemon::displayInfo(){
    std::cout << "*** Pokemon #" << id << " : " << name << ", hitPoint : "
    << hitPoint << std::endl;
}

Pokemon::~Pokemon() {

}

void Pokemon::attack(Pokemon &anotherPokemon) {
    srand(time(NULL));
    if (rand() % 100 >=20){
        anotherPokemon.sustainDamage(int (abs(this->attackValue-anotherPokemon.defense)));
    }
    else{
        std::cout << "Attack missed ! " << std::endl;
    }
}

void Pokemon::sustainDamage(int value) {
    hitPoint=(hitPoint-value)>0?hitPoint-value:0;
    std::cout << "Pokemon " << name << " sustained a " << value <<
    " damage. New hitPoint : " << hitPoint << std::endl;
}

int Pokemon::getNumberOfPokemon(){
    return numberOfPokemon;
}

string Pokemon::getName(){
    return name;
}

int Pokemon::getId(){
    return id;
}

int Pokemon::getHP(){
    return hitPoint;
}