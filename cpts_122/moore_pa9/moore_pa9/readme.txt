Hello, I worked solo on this project sorry.

font grabbed from here: https://www.fontspace.com/category/ttf?p=2
and here: https://www.1001freefonts.com/montserrat.font
I just liked the way it looked, and it seems to kind of fit the style (if you can say that my artwork has any kind of styling).

I do have polymorphism and inheritance, the plan was for a base game mode that encapsulated every rule and action that all types of mancalah had in common, then have inherited
classes that modified that based on their individual rulesets. Also artowork to accopony the differing rulesets as they have differing amounts of houses per side, and starting stone counts. KalahGraphics inherits the board, which in a more complete program would be one of many board types representing different rulesets, but for my game it's just the NA variant.

Kalah is a game I enjoyed from my youth, it's a common NA variant of an old game that is played competitavely all over the world (not so much this version).
Each player has a side of the board with a number of houses that conain stones. stones are the play pieces, and will be the item you want to accumulate.
The goal of the game is to have the most stones in your store at the end of the game. I'm happy to have had the motivation to code it.

I didn't have time to implement moving graphics, or more fancy things like that, the white buttons above each house will select that house for play, you will need to click a valid house (not empty and on your side) to porgress.

Play goes as follows:
1. Player selects a non-empty house on their side of the board and takes the stones from it.
2. Proceeding counter-clockwise place a single stone in each of the following houses, as well as in your own store, until you run out fo stones in your hand.
3. Check the house your stone landed in:
	a. If the house is your own store
		--> Take another turn.
	
	b. If the house was on your side of the board, and not empty OR you landed on the oppenents side of the boardTurn Ends.
		--> Turn Ends.
	
	c. Capture: If your stone lands in an empty house on YOUR SIDE of the board, then you have the opportunity to capture an opponents house.
		- Capturing an opponents house means that you first add your stone to your store, then you add the stones (if any) in the house directly
		opposite yours to your own house. 
		- Players turn ends after capture.
		
4. Play ends when all of either players houses are completely empty.
3. Any remaining stones on a players side of the board gets added to their own store after game end condition.
5. Winner is the player with the greatest number of stones after adding extra stones from players houses.

P.S. This might help with the screen brightness issue: https://justgetflux.com/
Assuming it's still an issue it basically will automaticallY shift the color of the display, less blue at night/morning. It takes a little getting used to but once you do you don't even notice the shift. This may or may not help at all with the migraine issue. Students getting things in on time might also help with that lol.

In any case I wish you well and thank you,
 
		Devin