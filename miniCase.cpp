#include <iostream>
#include <string>
#include "PlayerCharacter.h"
#include "Relation.h"
using namespace std;

int main()
{
  cout << "Hello World!";
  cout << "hi";

  PlayerCharacter p = PlayerCharacter("Gandalf");
  
  p.CreateRelation("Pippin", false);
  p.CreateRelation("Frodo", true);
  p.CreateRelation("Bilbo", true);
  p.CreateRelation("Thorin", false);
  p.CreateRelation("Merry", true);
  p.CreateRelation("Sam", true);
  p.CreateRelation("Gimli", true);

  Relation r = p.GetRelation("Bilbo");
  cout << p.GetPlayerName(p) << "likes" << r.ActorName;

  list<Relation> f = p.GetFavorites();
  cout <<  p.GetPlayerName(p) << "'s favorite actors are: ";
  
  for(list<Relation>::iterator it=f.begin(); it != f.end(); ++it){
    cout << " " << it -> ActorName;
  };

  cout << "\n";


};