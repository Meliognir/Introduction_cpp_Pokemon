#pragma once

#include "SetOfPokemon.hpp"

class Pokeball : virtual public SetOfPokemon{
private:

public:
    Pokeball();
    Pokemon *getOnePokemonByName(string name) ;

    Pokemon *getOnePokemonById(int id);
    void setOnePokemonInPokeball(int id);

    void setOnePokemonInPokeballByName(string name);

    Pokemon *CatchAPokemon(Pokemon * pokemon);



    ~Pokeball()=default;

};

