#pragma once
#include "SetOfPokemon.hpp"
#include<iostream>
#include "Pokeball.hpp"
using std::string;

class PokemonParty : virtual public SetOfPokemon{
    protected:
        std::vector<Pokemon*> combatPokemon;

    public:
        Pokeball * linkedPokeball;

        PokemonParty(const std::vector<int>& combatPokemon, Pokeball * pokeball);

        Pokemon * getOnePokemonById(int id) override;

        Pokemon * getOnePokemonByName(string name) override;

        Pokemon * getOnePokemonByName(int id);

        void setOnePokemonInPokemonParty(Pokemon *pokemon);

        ~PokemonParty() override =default;

};