#include "Pokedex.hpp"
#include "SetOfPokemon.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;

Pokedex * Pokedex::instance=nullptr;

Pokedex::Pokedex(const string &nomFichier):SetOfPokemon() {

    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) { // Vérifie si le fichier est bien ouvert
        std::cerr << "Impossible d'ouvrir le fichier : " << nomFichier << std::endl;
        return;
    }

    std::string ligne;
    std::getline(fichier, ligne);
    while (std::getline(fichier, ligne)) {
        // Lit le fichier ligne par ligne
        std::stringstream inputstringstream(ligne); // Utilise un flux pour diviser la ligne
        std::string cellule;
        std::vector<std::string> donneesLigne;
        // Divise la ligne en cellules séparées par des virgules
        while (std::getline(inputstringstream, cellule, ',')) {
            donneesLigne.push_back(cellule); // Ajoute chaque cellule au vecteur

        }
        int id= std::stoi(donneesLigne.at(0));
        double hitPoint= std::stod(donneesLigne.at(5));
        double attack= std::stod(donneesLigne.at(6));
        double defense= std::stod(donneesLigne.at(7));
        //double speAttack= std::stod(donneesLigne.at(8));
        //double speDefense= std::stod(donneesLigne.at(9));
        //double speed= std::stod(donneesLigne.at(10));
        int generation= std::stoi(donneesLigne.at(11));

        arrayOfPokemon.push_back(new Pokemon(donneesLigne.at(1),id,hitPoint,attack,defense,generation));

    }
}


Pokedex *Pokedex::getInstance() {
    if (instance==nullptr) {
        instance=new Pokedex("../pokedex.csv");
    }
    return instance;
}

Pokemon * Pokedex::getOnePokemonByName(string name){
    int indexInList=this->findOnePokemonByName(name);
    if(indexInList!=-1) {
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokemon * Pokedex::getOnePokemonById(int id){
    int indexInList=this->findOnePokemonById(id);
    if(indexInList!=-1) {
        return new Pokemon(*(this->arrayOfPokemon.at(indexInList)));
    }
    return nullptr;
}

Pokedex::~Pokedex() = default;

