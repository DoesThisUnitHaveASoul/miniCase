#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Relation.h"
using namespace std;

class PlayerCharacter {
        string name;
        list<Relation> Relations;
    public:
        PlayerCharacter(string n);
        string GetPlayerName(PlayerCharacter p);
        void CreateRelation(string name, bool likes);
        Relation GetRelation(string name);
        list<Relation> GetFavorites();

};