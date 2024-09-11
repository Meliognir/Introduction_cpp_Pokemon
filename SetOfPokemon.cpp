#include "SetOfPokemon.hpp"
#include <iostream>


void SetOfPokemon::displayList() {
    std::cout<<"*****************************************"<< std::endl;
    for (Pokemon * pokemon : arrayOfPokemon) {
        pokemon->displayInfo();
    }
}

int SetOfPokemon::findOnePokemonByName(string &name) {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if(name==arrayOfPokemon.at(i)->getName()) {
            return i;
        }
    }
}

int SetOfPokemon::findOnePokemonById(int id) {
    for (int i=0;i<arrayOfPokemon.size();i++){
        if(id==arrayOfPokemon.at(i)->getId()) {
            return i;
        }
    }
}

