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

        void setOnePokemonInPokeball(int id);

        Pokemon * getOnePokemonById(int id) override;

        Pokemon * getOnePokemonByName(string name) override;

        Pokemon * getOnePokemonByIndex(int i);


        void setOnePokemonInPokemonParty(Pokemon *pokemon);

        ~PokemonParty() override =default;

};