


# ICSP_Pentagol
This is my first serious project in Introduction to Computer Systems and Programming course at university under supervision of [Dr. Manouchehr Moradisabzevar](https://ece.ut.ac.ir/en/~moradih). It's a game like Pentago but with a different rule. You must create L pattern instead of I pattern to win. Check out [here](https://www.ultraboardgames.com/pentago/game-rules.php) to have more information about Pentago.
# What is Pentagol
Actually Pentagol is not a general game and it has defined just for this project. So, it has own rules and own game play.
# Pentagol Game play
There is a 4 twistable 3x3 game blocks in Pentagol. The goal is to put four consecutive marbles and one next to the last one of them (Like L) in the middle row of two adjacent quadrants (three in the middle row of one quadrant, two in the middle row of another quadrant) and then line them up. n the beginning of the game, there will be neutral game blocks, allowing a player to ignore the twist portion of their turn. A neutral game block is one that is empty or has only one marble in the middle of it.
In this picture you can see a real plate of the game.
<img src="https://www.ultraboardgames.com/pentago/gfx/game32.jpg" width="400"/>
# Parts of project
In [CA & Report](https://github.com/mahdimoeini8102/ICSP_Pentagol/tree/main/CA%20%26%20Report) folder you can see the descreption of project and a flowchart that I've drawn it. This project must implemented in two ways. One in terminal environment and one in a graphical environment. So, There are two folder In [Codes](https://github.com/mahdimoeini8102/ICSP_Pentagol/tree/main/Codes) folder. One for the graphical environment and one for the terminal environment.
Also, there is a "BGI2010" zipped file that developed by teacher assistants of the course and we used it to have a graphical environment using C. You can download and use.
# How to run
Just go to [Executable Files](https://github.com/mahdimoeini8102/ICSP_Pentagol/tree/main/Executable%20Files) and download two .exe files. One is the game in terminal environment and another is the game in a graphical environment. You can see these two pictures from them:

<img src="/Images/Graphical Environment.png" height="200"/>
<img src="/Images/Terminal Environment.png" height="200"/>

# How to play
## Terminal Environment
In the terminal you can see a board game and black must start at the beginning. You can see some character in the board that meanings of them are as follow:
|Type| Image|
|--|--|
|Numbers like '1', '2', '3', ...|They show rows and columns of the board.|
|Dot '.'|They show free spaces in the game.|
|Boarders like '--' or '\|' |They are boarders of 4 twistable 3x3 game blocks.|
|'b'|It stands for Black.|
|'w'|It stands for White.|

As I said, in the beginning black player must start. To start, He\She should enter a two-digit number in which, the first digit represents as the row and second one represents as the column. For example 23 means black player wants to put his/her marble in second row and third column. After it, he/she must enter a number together with '+' or '-'. such as "4+". It means clockwise twisting of forth square. The board has been divided to 4 part as follow:
<br>21
<br>
34<br>
After that black player played, it turns white player. The white player must do such as the black player and the game is going on. 

## Graphical Environment
In the graphical environment you have a board game like a real one. Use 'w', 'a', 's', and 'd' to move the square-shaped pointer and press 'f' to submit your action. After that press a number (that represents your intended square to twist). When you choose a square, it will be crosshatched and you can change your opinion. After that press '+' or '-' for twisting.
