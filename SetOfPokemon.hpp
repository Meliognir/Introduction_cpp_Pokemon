# pragma once

#include <string>
#include <vector>
#include "Pokemon.hpp"

class SetOfPokemon {
protected:
    std::vector<Pokemon*> arrayOfPokemon;
    int findOnePokemonByName(const string &name) const;
    int findOnePokemonById(int id) const;
public:
    virtual Pokemon * getOnePokemonByName(string name)=0;
    virtual Pokemon * getOnePokemonById(int id)=0;
    void displayList();
    SetOfPokemon()=default;

    virtual ~SetOfPokemon()=default;
};

