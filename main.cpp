#include <iostream>
#include "Pokemon.hpp"
#include <vector>
#include "Pokedex.hpp"
using std::vector;



int main() {
    std::cout << "******* Pokemon test *******" << std::endl;
    /*Pokemon mew("Mew",5,100,30,70,3);
    Pokemon mew2("Mew2",10,100,100,50,3);

    mew.displayInfo();
    mew2.displayInfo();

    mew.attack(mew2);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);
    mew2.attack(mew);

    std::cout << "Nombre de pokemon en memoire : "<< Pokemon::getNumberOfPokemon() << std::endl;

    Pokedex *pokedexInstance=Pokedex::getInstance();
    pokedexInstance;*/

    Pokemon * test=Pokedex::getInstance()->getOnePokemonById(3);
    Pokemon * test2=Pokedex::getInstance()->getOnePokemonByName("Charizard");

    std::cout << "Nombre de pokemon en memoire : "<< Pokemon::getNumberOfPokemon() << std::endl;



    /*  vector<Pokemon*> pokedex;
      for (int i=0;i<10;i++){
          char * name;
          sprintf(name,"Bullbizarre#%d",i);
          pokedex.push_back(new Pokemon(name));
      }

      for(Pokemon * pp :pokedex){
          pp->scream();
      }

      pokedex[15]->scream();
      //pokedex.at(15)->scream();*/
    return 0;
}

