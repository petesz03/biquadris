# Biquadris C++

Welcome to our Biquadris project. Biquadris is a Latinization of the game Tetris, with the main difference being that two players play heada to ahead against each other.

The game is developed in C++, and it follows Object-Oriented Programming design principles, and incorporated a variety of design patterns such as Decorator (levels), Observer (displays), etc... It also follows MVC, where the *Player* class is responsible for the control component, the *Board* and *Block* class are responsible for the model component, and the two display classes are are responsible for the view component.

Please consult `design.pdf` for a complete preparation for our design. Note that actual codes will deviate slightly.

## How to Play:
Clone the current repository, type `make`.
- If playing without graphics, simple type `./biquadris -text`. This will speed up program significantly.
- If playing with graphics, make sure you have **XQuartz** installed on Mac or **XMing** installed on Windows. Type `./biquadris` to get started.

Other commandline arguments:
* `-startlevel n` - Add the command line argment to start in level n.
* `-scriptfile1 xxx` - Use the blocks from xxx as blocks for player 1.
* `-scriptfile2 xxx` - Use the blocks from xxx as blocks for player 2.
* `-seed xxx` - Sets the number random generator's seed to xxx.
* `-text` - Use only text displays.

When started, players take turn dropping blocks. When the blocks are dropped, the players term end.
- `left`, `right`, `down`, `drop` controls the movement of the blocks
- `clockwise` and `counterclockwise` controls the orientation of the blocks
- `levelup` and `leveldown` controls the current level. More on levels to come.
- Append a number *n* to perform an action *n* number of times. Example: `3left`
- Incomplete instructions but unambiguous instructions will be automatically filled to the complete instructions. Example: `3righ` will be mapped to `3right`, but `3l` will not be mapped to anything as l could mean levelup, left, etc...
- `I`, `J`, `L`, `O`, `S`, `Z`, `T` to replace the current block.
  
## Features:
5 Total levels:
- Level 0: takes blocks from text file only
- Level 1: Blocks generate randomly with the following probability. S,Z blocks at 1/12 and I,J,L,O,T each at 1/6.
- Level 2: All blocks have equal probability.
- Level 3: S,Z have probability of 2/9, other blocks have 1/9. Blocks are now **heavy**: every command to rotate or move will cause block to move downward by one.
- Level 4: If you place 5 blocks without clearing a row, a 1x1 block will appear on the middle of screen. It will start splitting your screen into two parts.

**Special Actions:**
Triggered when a player clears 2 or more row simultaneously.
- `blind`: questions mark will cover the playing field for the opponent.
- `heavy`: Every time the opponent moves, blocks drop by 2 rows. If level 3+, heavy actions will drop 3 rows.
- `force`: Change opponent's current block.

