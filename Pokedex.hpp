#pragma once

#include "SetOfPokemon.hpp"

class Pokedex : virtual public SetOfPokemon {
private:

    Pokedex(const std::string &nomFichier);
    static Pokedex * instance ;

public:

    Pokedex()=delete;
    static Pokedex *getInstance();

    Pokemon *getOnePokemonByName(string name) ;

    Pokemon *getOnePokemonById(int id);
    ~Pokedex() override;


};