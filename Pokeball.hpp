#pragma once

#include "SetOfPokemon.hpp"

class Pokeball : virtual public SetOfPokemon{
private:

public:
    Pokeball();
    Pokemon *getOnePokemonByName(string name) ;

    Pokemon *getOnePokemonById(int id);

    void destroyOnePokemonById(int id);

    void captureOnePokemon(Pokemon *pokemon);

    void setOnePokemonInPokeball(int id);

    void setOnePokemonInPokeballByName(string name);

    Pokemon *getOnePokemonByIndex(int i);

    Pokemon *CatchAPokemon(Pokemon * pokemon);



    ~Pokeball()=default;

};

