#include <iostream>
#include <string>
#include <list>
#include "Relation.h"
using namespace std;

class PlayerCharacter {
        string name;
        list<Relation> Relations;
    public:
        PlayerCharacter(string n){
            name = n;
        };
        string GetPlayerName(PlayerCharacter p){
            string n = p.name;
            return n;
        };
        void CreateRelation(string name, bool likes){
            struct Relation r = { name, likes};
            Relations.push_front(r);
        };
        Relation GetRelation(string name){
            for(list<Relation>::iterator it=Relations.begin(); it != Relations.end(); ++it){
                if(it -> ActorName == name){
                    return *it;
                }
                else{
                    cout << "Player has no relations!\n";;
                }
            }
        };

        list<Relation> GetFavorites(){
            list<Relation> Favorites;
            for(list<Relation>::iterator it=Relations.begin(); it != Relations.end(); ++it){
                if(it -> PlayerLikesActor){
                    Favorites.push_back(*it);
                }
                if(Favorites.size() == 5){
                    return Favorites;
                }
                if((Relations.end() == it) && Favorites.size() < 5){
                    return Favorites;
                }
            }
        }

};