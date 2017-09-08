# Filler
AI project on which I made a player that beats all CPUs on the game Filler.

The player who can't play the given piece is out of the game,

and if the opponent can play his piece he wins.

My player has a defensive strategy for the begining to take position on the map,

then I try to fill the opponent's part of the map.

# Installation
$> make

# Usage
./filler_vm -f MAP -p1 ./P1_NAME -p2 P2_NAME

Example:
$> ./filler_vm -f maps/map01 -p1 ./jyakdi.filler -p2 players/hcao.filler

<img src="https://raw.githubusercontent.com/bluffs/Filler/master/screen_term.png">
<img src="https://raw.githubusercontent.com/bluffs/Filler/master/screen_graphic.png">
