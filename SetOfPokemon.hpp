# pragma once

#include <string>
#include <vector>
#include "Pokemon.hpp"

class SetOfPokemon {
protected:
    std::vector<Pokemon*> arrayOfPokemon;
    int findOnePokemonByName(string &name);
    int findOnePokemonById(int id);
public:
    virtual Pokemon * getOnePokemonByName(string name)=0;
    virtual Pokemon * getOnePokemonById(int id)=0;
    void displayList();
    SetOfPokemon()=default;

    virtual ~SetOfPokemon()=default;
};

