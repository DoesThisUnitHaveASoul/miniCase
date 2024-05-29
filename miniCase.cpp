#include <iostream>
#include <string>
#include <list>
using namespace std;

class Relation {
    string ActorName;
    bool PlayerLikesActor;
  public:
    Relation(string n, bool likes){
      ActorName = n;
      PlayerLikesActor = likes;
    };
    string GetActorName(){
      return ActorName;
    }
    bool GetPlayerLikesActor(){
      return PlayerLikesActor;
    }
};

class PlayerCharacter{
    string name;
    list<Relation> Relations;
  public:
    PlayerCharacter(string n){
      name = n;
    };
    string GetPlayerName(){
      return name;
    };
    void CreateRelation(string name, bool likes){
      Relation *r = new Relation(name, likes);
      Relations.push_front(*r);
    };
    Relation GetRelation(string name){
      for(list<Relation>::iterator it=Relations.begin(); it != Relations.end(); ++it){
        string n = (*it).GetActorName();
        if(n == name){
          return (*it);
        }
      }
    };
    list<Relation> GetFavorites(){
      list<Relation> Favorites;
      for(list<Relation>::iterator it=Relations.begin(); it != Relations.end(); ++it){
        int num = (*it).GetPlayerLikesActor();
        if(num == 1){
          Favorites.push_back(*it);
        }
        if(Favorites.size() == 5){
          return Favorites;
        }
      }
  };
};

int main()
{
  cout << "NAME OF PLAYER: \n";
  PlayerCharacter p("Gandalf");
  string pname = p.GetPlayerName();
  cout << pname << "\n";

  p.CreateRelation("Pippin", false);
  p.CreateRelation("Frodo", true);
  p.CreateRelation("Bilbo", true);
  p.CreateRelation("Thorin", false);
  p.CreateRelation("Merry", true);
  p.CreateRelation("Sam", true);
  p.CreateRelation("Gimli", true);
  
  cout << "\n";
  cout << "MANUAL TEST1: get one relation and whether or not player likes them" << "\n";

  Relation r1 = p.GetRelation("Pippin");
  cout << r1.GetActorName() << " is a relation." << "\n";
  cout << p.GetPlayerName() << " likes " << r1.GetActorName() << ": " << r1.GetPlayerLikesActor() << "\n";

  cout << "\n";
  cout << "MANUAL TEST2: get another relation and whether or not player likes them" << "\n";

  Relation r2 = p.GetRelation("Merry");
  cout << r2.GetActorName() << " is a relation." << "\n";
  cout << p.GetPlayerName() << " likes " << r2.GetActorName() << ": " << r2.GetPlayerLikesActor() << "\n";

  cout << "\n";
  cout << "MANUAL TEST3: get 5 most recent relations, which the player likes" << "\n";

  list<Relation> f = p.GetFavorites();
  
  for(list<Relation>::iterator it=f.begin(); it != f.end(); ++it){
    cout << " " << (*it).GetActorName();
  };
};