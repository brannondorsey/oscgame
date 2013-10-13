#OSC Game

##App Size

Server app size: `1920x1080`

##Data formats

Comma-delimited list of values with vertical pipes used to separate values inside of each comma "packet"

###Client to server

Message Types:

1. Indicates that a player has joined or left the game:
	- Message ID: `1`
	- `messageID, isPlaying, playerID`
	
2. Indicates player: 
	- Message ID: `2`
	- `messageID, playerID, size, sped, x1, y1, x2, y2, x3, y3, etc…`

###Server to client

Message Types:

1. Indicates game is finished and winner
	- Message ID: `3`
	- `messageID, firstPlacePlayerID|score, secondPlacePlayer|score, etc...`
	
2. Indicates game start countdown
	- Message ID: `4`
	- `messageID, millisToStart`


