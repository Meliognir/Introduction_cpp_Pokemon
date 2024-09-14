cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Pokemon.cpp
        SetOfPokemon.cpp
        Pokedex.cpp
        Pokeball.cpp
        PokemonParty.cpp
        Game.cpp
        Combat.cpp
)
