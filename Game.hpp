#pragma once
#include "SetOfPokemon.hpp"
#include <iostream>
#include "PokemonParty.hpp"
class Game {
protected:

public :

    Game()=default;

    void InitGame();

    void lanceCombatSauvage(PokemonParty &pokemon_party);

    void choixPokParty();

    void lanceCombatDresseur();

    ~Game();

    };
