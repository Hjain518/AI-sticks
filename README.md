AI STICKS

In AI Sticks Game there is a heap of sticks on a board. On their turn, each player picks up 1 to 3 sticks. The one who has to pick the final stick will be the loser.

For example

The game starts with 10 sticks on the board.
Neal takes 3 sticks, there are 7 sticks remaining.
Ram takes 2 sticks, there are 5 sticks remaining.
Neal takes 1 stick, there are 4 sticks remaining.
Ram takes 2 sticks, there are 2 sticks remaining.
Neal takes 1 stick, there are 1 sticks remaining.
Ram has to take 1 stick ,hence he loses.

This assignment is contains 2 parts:

Adding an AI that can be played against.
Adding an option for AI against another AI.

1.)if case =1
	1.i)n=14
	1.ii)n=21
	1.iii)n=53
2.)if case =2   	game between human and AI
3.)if case =3    	both the players are AI
4.)in each case:
	4.i)game
  		a)fastgame(if n>32)  (description given below)
		  b)chooseBest         (description given below)
5.)Decide winner

Player vs AI

We create an artificial intelligence player for the Game of Sticks and then we make an algorithm (in the code) to figure out the best strategy for the remaining turns.

AI VS AI

Both the AI figures out the best strategy to win the game in each turn or if the win is not possible,it figures out the best possible move to delay that win.

Algorithm

choose to fast calulate best way (if n>32),
	otherwise explore the and or tree with alpha beta pruning
	4.i.a)fastgame :
		if((n-k)%4==1) and k belongs to {1,2,3} then pick k sticks else pick 1 stick
	4.i.b)chooseBest :
		 explore the and or tree with alpha beta pruning
 
