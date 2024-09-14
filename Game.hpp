#pragma once
#include "SetOfPokemon.hpp"
#include <iostream>
#include "PokemonParty.hpp"
class Game {
protected:

public :

    Game()=default;

    void InitGame();

    void choixPokParty();

    void lanceCombatDresseur();

    ~Game();

    };
