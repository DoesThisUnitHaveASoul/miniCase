# miniCase

# logical structure of solution

Case: a player likes/dislikes other actors in a game. We want to be able to capture this relation (meta data).

Solution: think of the relation as an object, which keeps all relevant information. This object can then be accessed when needed.

# structure

PLAYER:
- stores a list with relations 
    - minimizes size of lists (vs multiplayer and stored on actor)
    - mimics real world ("I know who I like")
- creates a new relation
- accesses relations in the list as needed

RELATION:
- defines what meta data to store
