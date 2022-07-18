/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/02/20
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 3

Description: Implementing a playlist using a circular linked list
*******************************************************************************************/
#include "playlist.h"


/*
* Function: initRecord()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will initialize a record to be filled
* Input Parameters:
*	Record *pRecord: pointer to record to be initialized
* Returns:
*	NONE
* Precondition: Record has been declared and passed
* Postcondition: Record initialized
*/
void initRecord(Record* pRecord)
{
	strncpy(pRecord->albumTitle, "", MAX_STR_LEN);
	strncpy(pRecord->artist, "", MAX_STR_LEN);
	strncpy(pRecord->genre, "", MAX_STR_LEN);
	strncpy(pRecord->songTitle, "", MAX_STR_LEN);
	pRecord->duration.minutes = 0;
	pRecord->duration.seconds = 0;
	pRecord->rating = 0;
	pRecord->timesPlayed = 0;
}

/*
* Function: initPlaylist()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: This will set both pCur and pStart to NULL
* Input Parameters:
*	Playlist *pList: Pointer to playlist
* Returns:
*	NONE
* Precondition: List is declared
* Postcondition: List has been initialized
*/
void initPlaylist(Playlist* pList)
{
	pList->pCur = NULL;
	pList->pStart = NULL;
}
/*
* Function: mainMenu()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will print the main menu
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Menu printed to screen
*/
void mainMenu(void)
{
	printf("Welcome! Please enter an integer value to select one of the menu items below!\n");
	printf("(1) Load in playlist from file\n");
	printf("(2) Store current playlist to file\n");
	printf("(3) Display current playlist\n");
	printf("(5) Delete item from playlist\n");
	printf("(6) Edit item in playlist\n");
	printf("(7) Sort playlist\n");
	printf("(8) Rate item in playlist\n");
	printf("(9) Play playlist\n");
	printf("(10) ShufflePlay playlist\n");
	printf("(11) Save and Exit program\n");
}


/*
* Function: displayMenu()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will print the menu for the display menu option
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Menu printed to screen
*/
void displayMenu(void)
{
	printf("Which items would you like to display?\n");
	printf("(1) Print All Items\n");
	printf("(2) Print Artist records.\n");
}

/*
* Function: sortMenu()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Menu for the sorting options will
* Input Parameters: NONE
* Returns: NONE
* Precondition: NONE
* Postcondition: Menu printed to screen
*/
void sortMenu(void)
{
	printf("Please enter sort method:\n");
	printf("(1) Artist (A-Z)\n");
	printf("(1) Album Title (A-Z)\n");
	printf("(1) Rating (1-5)\n");
	printf("(4) Number of Times Played (Most-Least)");
}

/*
* Function: yesOrNo()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will prompt user to select yes or no then return a value based on that choice
* Input Parameters: NONE
* Returns: int representing the users choice; 1 = YES, 0 = NO
* Precondition: NONE
* Postcondition: Integer representation of user choice returned
*/
int yesOrNo(void)
{
	printf("please enter y for yes or n for no:");
	int sentinel = 0, returnVal = 0;
	char tempChar = '\0';
	do {
		sentinel = scanf("%c", &tempChar);
		if (tempChar != 'y' && tempChar != 'n')
		{

		}
	} while (!sentinel || (tempChar != 'y' && tempChar != 'n')); // we both need to have a char return and it be a 'y' or 'n' for us to break out of loop

	return returnVal = (tempChar == 'y') ? (1) : (0); // will return 1 if tempchar is 'y' or 0 if it's not
}

/*
* Function: countElements()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will count the number of items in the list
* Input Parameters:
*	Node *pStart: Playlist pointer
* Returns:
*	int: Number of items in the list
* Precondition: NONE
* Postcondition: number of items returned to user
*/
int countElements(Node* const pStart)
{
	int count = 0;
	if (pStart == NULL)
	{
		return count;
	}
	else
	{
		Node* pTemp = pStart;
		count++;
		while (pTemp->pNext != pStart)
		{
			count++;
			pTemp = pTemp->pNext;
		}
	}
	return count;
}

/*
* Function: makeNode()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Creates node for list by allocating space and assinging data to the fields.
* Input Parameters:
*	Record record: record that containts the data to be insert into node
* Returns:
*	Node *pMem: this will return the address to the allocated memory (or null if it wasn't successful)
* Precondition: NONE
* Postcondition: Memory allocated and address is returned, or NULL if it failed to allocate memory
*/
Node* makeNode(Record *record)
{
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew != NULL)
	{
		pNew->pNext = NULL;
		pNew->pPrev = NULL;
		strncpy(pNew->record.albumTitle, record->albumTitle, MAX_STR_LEN);
		strncpy(pNew->record.artist, record->artist, MAX_STR_LEN);
		strncpy(pNew->record.songTitle, record->songTitle, MAX_STR_LEN);
		strncpy(pNew->record.genre, record->genre, MAX_STR_LEN);
		pNew->record.duration.minutes = record->duration.minutes;
		pNew->record.duration.seconds = record->duration.seconds;
		pNew->record.rating = record->rating;
		pNew->record.timesPlayed = record->timesPlayed;
	}

	return pNew;
}

/*
* Function: insertFront()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Willl insert node at the front of the list, if list was previously empty it will set pStart to the first node created
* Input Parameters:
*	Node *pList: Playlist pointer
*	Record record: record that contains the data to load into the node
* Returns: INT representing success or failure to insert node
* Precondition: List initialized
* Postcondition: Node has been inserted into list, and integer has been returned
*/
int insertFront(Playlist* pList, Record * record)
{
	int success = 0, itemsInList = countElements(pList->pStart);
	Node* pNew = makeNode(record);
	if (pNew != NULL)
	{
		success = 1;
		if (pList->pStart == NULL) // If pStart is NULL pCur is also NULL and this means the list is empty
		{
			pList->pCur = pList->pStart = pNew; // Setting the first item inserted into node as the arbitrary start point (and current point) in list.
			pList->pStart->pNext = pNew;
			pList->pStart->pPrev = pNew; // Linking the end to the begining for a circular linked list
		}
		//else if (itemsInList == 1) // Only one item in paylist
		//{
		//	pNew->pNext = pList->pStart;
		//	pNew->pPrev = pList->pStart; // Pointing at the back of the list (current pStart)
		//	pList->pStart->pNext = pNew; // Second item (current first) pointing to new first
		//	pList->pStart->pPrev = pNew; // pNew will also be the item right behind it when threre's only 2 items in list
		//	pList->pStart = pNew;		 // Setting start pointer to to new node pointer
		//	success = 1;
		//}
		else // list isn't empty
		{
			pNew->pNext = pList->pStart; // New starts next = old start
			pNew->pPrev = pList->pStart->pPrev; // new previous = old starts previos
			pNew->pPrev->pNext = pNew; // old starts previous' next = new start; linking end to begining
			pList->pStart->pPrev = pNew; // old starts previous = new start
			pList->pStart = pNew; // setting new node to new start

		}
	}

	return success;
}


/*
* Function: displayWholeList()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: will display the entire list starting from pStart
* Input Parameters:
*	Playlist *pList: Pointer to playlist to be displayed
* Returns:
*	NONE
* Precondition: List is not empty
* Postcondition: Entire list displayed to screen
*/
void displayWholeList(const Playlist* pList)
{
	Node* pTemp = pList->pStart;
	printf("Playlist:\n");
	do {
		printf("Artist: ");
		puts(pTemp->record.artist);
		printf("Album Title: ");
		puts(pTemp->record.albumTitle);
		printf("Song Title: ");
		puts(pTemp->record.songTitle);
		printf("Genre: ");
		puts(pTemp->record.genre);
		printf("Song Duration: %d:%d\n", pTemp->record.duration.minutes, pTemp->record.duration.seconds);
		printf("Song Rating: %d\nNumber of times played: %d\n", pTemp->record.rating, pTemp->record.timesPlayed);
		putchar('\n');
		// putchar('\n');

		pTemp = pTemp->pNext;
	} while (pTemp!= pList->pStart); // if pTemp = pStart we're back at the start of the list
	printf("\nEnd of playlist. Please press any key to continue...");
	_getch();
}


/*
* Function: displayArtist()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will display all of the records for a particular artist
* Input Parameters:
*	Playlist *pList: pointer to playlist
*	char *artistEntry: string which is the users search term
* Returns:
* Precondition: List not empty
* Postcondition: All records for a valid artist will be print to screen
*/
void displayArtist(Playlist* pList, char* artistEntry) // unfortunately the string must be an exact format match i.e. <lastname>, <firstname>. if you search for an artist with a first/last
{
	Node* pTemp = pList->pStart;
	char tempStringLower[MAX_STR_LEN] = "", lowerArtist[MAX_STR_LEN] = "";
	int i = 0;
	// making the artist entry lowercase
	while (artistEntry[i] != '\0')
	{
		lowerArtist[i] = tolower(artistEntry[i]);
		i++;
	}
	i = 0; // resetting i after loop

	printf("Playlist:\n");
	do {
		strncpy(tempStringLower, pTemp->record.artist, MAX_STR_LEN);
		// ok this is going to be a resource hog but i would like to compare lowercase strings so I need to do a loop where I make them all lowercase
		while (tempStringLower[i] != '\0')
		{
			tempStringLower[i] = tolower(tempStringLower[i]);
			i++;
		}i = 0; // resetting after loop
		if (strncmp(tempStringLower,lowerArtist,MAX_STR_LEN) == 0) // if they're equal strcmp will return 0 and we'll print that particular entry
		{
			printf("Artist: ");
			puts(pTemp->record.artist);
			printf("Album Title: ");
			puts(pTemp->record.albumTitle);
			printf("Song Title: ");
			puts(pTemp->record.songTitle);
			printf("Genre: ");
			puts(pTemp->record.genre);
			printf("Song Duration: %d:%d\n", pTemp->record.duration.minutes, pTemp->record.duration.seconds);
			printf("Song Rating: %d\nNumber of times played: %d\n", pTemp->record.rating, pTemp->record.timesPlayed);
			putchar('\n');
			// putchar('\n');
		} 
		// else advance through list
		pTemp = pTemp->pNext;
	} while (pTemp != pList->pStart); // while we haven't reached the begining yet
	printf("\nEnd of playlist. Please press any key to continue...");
	_getch();
}

/*
* Function: loadPlaylist()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: will fill the playlist will entries from a file
* Input Parameters:
*	Playlist *pList: pointer to playlist
*	File *infile: file to be proccessed
* Returns:
*	NONE
* Precondition: File must be open
* Postcondition: All entries in file have been loaded into the playlist
*/
void loadPlaylist(Playlist* pList, FILE* infile)
{
	Record* pTempRecord = (Record*)malloc(sizeof(Record));
	initRecord(pTempRecord); // initializing our tempRecord
	char* pTempChar, tempString[MAX_STR_LEN] = "", junkChar = '\0';
	
	int counter = 0;

	if (pTempRecord != NULL)
	{ 
		while (!feof(infile))
		{
			pTempChar = '\0';
			fgets(tempString, MAX_STR_LEN, infile); // loading in a line
			
			counter++;

			pTempChar = strtok(tempString, "\"");
			puts(pTempChar);
			strncpy(pTempRecord->artist, pTempChar, MAX_STR_LEN);

			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			strncpy(pTempRecord->albumTitle, pTempChar, MAX_STR_LEN);
		
			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			strncpy(pTempRecord->songTitle, pTempChar, MAX_STR_LEN);
		
 			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			strncpy(pTempRecord->genre, pTempChar, MAX_STR_LEN);

			pTempChar = strtok(NULL, ":");
			puts(pTempChar);
			pTempRecord->duration.minutes = atoi(pTempChar); // Using atoi to conver the strings to INTS for our record
		
			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			pTempRecord->duration.seconds = atoi(pTempChar);

			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			pTempRecord->timesPlayed = atoi(pTempChar);

			pTempChar = strtok(NULL, ",");
			puts(pTempChar);
			pTempRecord->rating = atoi(pTempChar);

			insertFront(pList, pTempRecord); // Puting record into our list
			initRecord(pTempRecord); // Scrubbing temp record (not really necessary I don't think)
		
		} // end while loop
		
	}
	
	free(pTempRecord);
	printf("Loading done...\n");
	system("Pause");

}

/*
* Function: storePlaylist()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will copy current list into the passed file
* Input Parameters:
* 	Playlist *pList: pointer to playlist
*	File *infile: file to be proccessed
* Returns:
*	NONE
* Precondition: File must be open
* Postcondition: Playlist ahs been printed to file in a csv format
*/
void storePlaylist(Playlist* pList, FILE* infile)
{
	int numElements = countElements(pList->pStart);
	Node* pTemp = pList->pStart;
	int counter = 0;
	printf("Playlist:\n");
	do {
		counter++;
		fprintf(infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d", pTemp->record.artist, pTemp->record.albumTitle, pTemp->record.songTitle, pTemp->record.genre, pTemp->record.duration.minutes, pTemp->record.duration.seconds, pTemp->record.timesPlayed, pTemp->record.rating);
		
		if (counter < numElements) // included this so that it wouldn't add a new line to the end of the last line becuase that breaks my load function meaning I can't store then load
		{
			fprintf(infile, "%c", '\n'); // add new line to end
		}
		// putchar('\n');

		pTemp = pTemp->pNext;
	} while (pTemp != pList->pStart); // if pTemp = pStart we're back at the start of the list
}

/*
* Function: insertRecord()
* Date Created: 2021/02/24
* Last Modified: 2021/02/24
* Description: inserts a record into the list
* Input Parameters:
*	Playlist *pList: pointer to playlist
* Returns:
*	int: 1 = successful insertion; 0 = fail
* Precondition: List not empty
* Postcondition: Node with user data inserted into list
*/
int insertRecord(Playlist* pList)
{
	int success = 0, sentinel = 0, status = 0;
	Record* pTemp = (Record*)malloc(sizeof(Record));
	char tempString[MAX_STR_LEN] = "";
	if (pTemp != 0)
	{
		system("cls");
		printf("Entering new record into system:\n");
	
		printf("Pease enter an artists name: "); // Going through one by one to enter data
		scanf("%s", &pTemp->artist);
		printf("Please Enter the Album Title: ");
		scanf("%s", &pTemp->albumTitle);

		printf("Please Enter the Song Title: ");
		scanf("%s", &pTemp->songTitle);
		printf("Please Enter the genre of the song: ");
		scanf("%s", &pTemp->genre);
		
		printf("Please Enter song length\n"); // Prompint for the duration
		printf("Minutes: ");
		scanf("%d", &pTemp->duration.minutes);
		printf("Seconds: ");
		scanf("%d", &pTemp->duration.seconds);
		do // User input validation loop
		{
			printf("Enter the number of times you've played the song: ");
			scanf("%d", &pTemp->timesPlayed);
			if (status < 1)
			{
				flushDataStream(); // Empties input stream
			}
			if (pTemp->timesPlayed < 0) { printf("Please enter an integer greater than zero.\n"); } // If the input is invalid, this will print and loop will run through again.
		} while (pTemp->timesPlayed < 0);
		


		do // User input validation loop
		{
			printf("Enter the rating for the song: ");
			scanf("%d", &pTemp->rating);
			if (status < 1)
			{
				flushDataStream(); // Empties input stream
			}
			if (pTemp->timesPlayed < 1 || pTemp->timesPlayed > 5) { printf("Please enter an integer between 1 and 5 (inclusive).\n"); } // If the input is invalid, this will print and loop will run through again.
		} while (pTemp->timesPlayed < 1 || pTemp->timesPlayed > 5);




		success = 1;

		insertFront(pList, pTemp);
	}
	free(pTemp);
	return success;
}

/*
* Function: deleteRecord()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Deletes a record by song title
* Input Parameters:
*	Playlist *pList: pointer to playlist
*	char *songTitle: user entered song title
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: Node deleted from playlist
*/
void deleteRecord(Playlist* pList, char* songTitle)
{
	Node* pTemp = pList->pStart;
	char tempStringLower[MAX_STR_LEN] = "", lowerSongTitle[MAX_STR_LEN] = "";
	int i = 0;
	// making the artist entry lowercase
	while (songTitle[i] != '\0')
	{
		lowerSongTitle[i] = tolower(songTitle[i]);
		i++;
	}
	i = 0; // resetting i after loop

	do {
		strncpy(tempStringLower, pTemp->record.songTitle, MAX_STR_LEN);
		// ok this is going to be a resource hog but i would like to compare lowercase strings so I need to do a loop where I make them all lowercase
		while (tempStringLower[i] != '\0')
		{
			tempStringLower[i] = tolower(tempStringLower[i]);
			i++;
		}i = 0; // resetting after loop

		if (strncmp(tempStringLower, lowerSongTitle, MAX_STR_LEN) == 0) // if they're equal strcmp will return 0 and we'll print that particular entry
		{
			if (pTemp->pNext == pTemp) // One item in list
			{
				free(pTemp);
				pList->pCur = pList->pStart = NULL; // Setting current pointer and start pointer to NULL
			}
			else
			{
				pTemp->pNext->pPrev = pTemp->pPrev; // Node in front of us is now looking behind us
				pTemp->pPrev->pNext = pTemp->pNext; // Node behind us is now looking in front of us
				if (pTemp == pList->pStart)
				{
					pList->pStart = pTemp->pNext;
					if (pTemp == pList->pCur)
					{
						pList->pCur = pTemp->pNext;
					}
				}
				free(pTemp); // freeing memory
				break;
			}
		}
		pTemp = pTemp->pNext;
	} while (pTemp != pList->pStart);
}

/*
* Function: editRecord()
* Date Created: 2021/02/22
* Last Modified: 2021/02/24
* Description: Will allow user to edit a record based on artist
* Input Parameters:
*	Playlist *pList: Pointer to playlist
*	char *artistEntry: User entered string which is the artists name
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: Record in list has ben set to new user entered data
*/
void editRecord(Playlist* pList, char* artistEntry)
{
	Node* pTemp = pList->pStart;
	char tempStringLower[MAX_STR_LEN] = "", lowerSongTitle[MAX_STR_LEN] = "";
	int i = 0, index = 0, count = 0, positionCount = 0, positionArray[10] = { 0 }, status = 0;
	
	// making the artist entry lowercase
	while (artistEntry[i] != '\0')
	{
		lowerSongTitle[i] = tolower(artistEntry[i]);
		i++;
	}
	i = 0; // resetting i after loop



	
	// counting the number of instances of the artist name in the list
	while (pTemp->pNext != pList->pStart)
	{
		strncpy(tempStringLower, pTemp->record.artist, MAX_STR_LEN);
		while (tempStringLower[i] != '\0')
		{
			tempStringLower[i] = tolower(tempStringLower[i]);
			i++;
		}i = 0; // resetting after loop
		
		positionCount++;
		if (strncmp(tempStringLower, lowerSongTitle, MAX_STR_LEN) == 0)
		{
			// If we match the artist name. Load the position count into the array. we will use this to ask user which entry they would like to edit if there are multiple songs w/ same artist
			positionArray[count++] = positionCount; 
		}
		
		pTemp = pTemp->pNext;
	}
	
	if (count == 0)
	{
		printf("This artist does not exist in the list.\n");
	}
	else if (count == 1)
	{
		pTemp = pList->pStart;
		for (index = 1; index < positionArray[0]; index++)
		{
			pTemp = pTemp->pNext; // moving us to the element to edit
		}
	}
	else
	{
		printf("There is more than one song with that artist name.\nPlease select which song you would like to edit.\n");
		int yesNo = 0, count1 = 0;
		while (yesNo == 0)
		{
			pTemp = pList->pStart; // resetting us to the start of the list for the relative position if I had more time I woul add logic to navigate from this relative location instead
			for (index = 1; index < positionArray[count1]; index++)
			{
				pTemp = pTemp->pNext; // moving us to the element to edit
			}
			count1 = (count1 == 3) ? (0) : (count1 += 1); // if count1 is 3 then reset, else increment
			printf("Would you like to change the song %s?\n", pTemp->record.songTitle);
			yesNo = yesOrNo();
		}

	}

	if (count != 0)
	{
		printf("Entering new record into system:\n");

		printf("Pease enter an artists name: "); // Going through one by one to enter data
		scanf("%s", &pTemp->record.artist);
		printf("Please Enter the Album Title: ");
		scanf("%s", &pTemp->record.albumTitle);

		printf("Please Enter the Song Title: ");
		scanf("%s", &pTemp->record.songTitle);
		printf("Please Enter the genre of the song: ");
		scanf("%s", &pTemp->record.genre);

		printf("Please Enter song length\n"); // Prompint for the duration
		printf("Minutes: ");
		scanf("%d", &pTemp->record.duration.minutes);
		printf("Seconds: ");
		scanf("%d", &pTemp->record.duration.seconds);

		// took this from my PA6 last sememster
		do // User input validation loop
		{
			printf("Enter the number of times you've played the song: ");
			scanf("%d", &pTemp->record.timesPlayed);
			if (status < 1)
			{
				flushDataStream(); // Empties input stream
			}
			if (pTemp->record.timesPlayed < 0) { printf("Please enter an integer greater than zero.\n"); } // If the input is invalid, this will print and loop will run through again.
		} while (pTemp->record.timesPlayed < 0);

		do // User input validation loop
		{
		printf("Enter the rating for the song: ");
		scanf("%d", &pTemp->record.rating);
		if (status < 1)
		{
			flushDataStream(); // Empties input stream
		}
		if (pTemp->record.timesPlayed < 1 || pTemp->record.timesPlayed > 5) { printf("Please enter an integer between 1 and 5 (inclusive).\n"); } // If the input is invalid, this will print and loop will run through again.
	} while (pTemp->record.timesPlayed < 1 || pTemp->record.timesPlayed > 5);
	}
}

// grabbed this from my PA6 last semester
/*
* Function: flushDataStream()
* Date Created:  2020/11/20
* Last Modified: 2020/11/26
* Description: will clear the input stream
* Input Parameters: NONE
* Returns: NONE
* Precondition: User has entered a value that needs to be cleared from the stream
* Postcondition: Stream is empty
*/
void flushDataStream(void)
{
	char tempChar = '\0';
	do { scanf("%c", &tempChar); } while (tempChar != '\n');
}

/*
* Function: editRating()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will allow user to edit a record based on artist
* Input Parameters:
*	Playlist *pList: Pointer to playlist
*	char *songTitle: User entered string which is the songs title to be rated
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: Rating for song has been updated with users rating
*/
void editRating(Playlist* pList, char* songTitle)
{
	Node* pTemp = pList->pStart;
	char tempStringLower[MAX_STR_LEN] = "", lowerSongTitle[MAX_STR_LEN] = "";
	int i = 0, status = 0;
	// making the artist entry lowercase
	while (songTitle[i] != '\0')
	{
		lowerSongTitle[i] = tolower(songTitle[i]);
		i++;
	}
	i = 0; // resetting i after loop

	do {
		strncpy(tempStringLower, pTemp->record.songTitle, MAX_STR_LEN);
		// ok this is going to be a resource hog but i would like to compare lowercase strings so I need to do a loop where I make them all lowercase
		while (tempStringLower[i] != '\0')
		{
			tempStringLower[i] = tolower(tempStringLower[i]);
			i++;
		}i = 0; // resetting after loop

		if (strncmp(tempStringLower, lowerSongTitle, MAX_STR_LEN) == 0) // if they're equal strcmp will return 0 and we'll print that particular entry
		{
			printf("Please enter an integer between 1 and 5 to set the rating for this song");

			do // User input validation loop
			   
			   // took this from my PA6 last sememster
			{
				
				status = scanf("%d", &pTemp->record.rating);
				if (status < 1)
				{
					flushDataStream(); // Empties input stream
				}
				if (pTemp->record.rating < 1 || pTemp->record.rating > 5) { printf("Please enter an integer between 1 and 5\n"); } // If the input is invalid, this will print and loop will run through again.
			} while (pTemp->record.rating < 1 || pTemp->record.rating > 5);
			

		}
		pTemp = pTemp->pNext;
	} while (pTemp != pList->pStart);
}

/*
* Function: sortArtist()
* Date Created: 2021/02/23
* Last Modified: 2021/02/24
* Description: Will sort list by artist into ascending order (A-Z)
* Input Parameters:
*	Playlist *pList: Pointer to list
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has been sorted into ascending order
*/
void sortArtist(Playlist* pList)
{
	Node* pTemp = pList->pStart;
	int numItems = countElements(pList->pStart);

	for (int index = 0; index < numItems; index++)
	{
		pTemp = pList->pStart; // resetting to start + 1
		do
		{
			if (strncmp(pTemp->pPrev->record.artist, pTemp->record.artist, MAX_STR_LEN) < 0) // if the next is less than the current swap their positions
			{
				pTemp->pNext = pTemp->pNext->pNext;
				pTemp->pNext->pPrev->pNext = pTemp;
				pTemp->pPrev->pNext = pTemp->pPrev->pPrev;
				pTemp->pPrev = pTemp->pNext->pPrev;
				pTemp->pNext->pPrev->pPrev = pTemp->pNext;
				pTemp->pNext->pPrev = pTemp; //ugh

			} // Else/then advance through list
			pTemp = pTemp->pNext;
		} while (pTemp != pList->pStart);
	}
}


/*
* Function: sortAlbumTitle()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23* Description: Will sort list by album title into ascending order (A-Z)
* Input Parameters:
*	Playlist *pList: Pointer to list
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has been sorted into ascending order
*/
void sortAlbumTitle(Playlist* pList)
{

}



/*
* Function: sortRating()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will sort list by rating into ascending order (1-5)
* Input Parameters:
*	Playlist *pList: Pointer to list
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has been sorted by rating into ascending order
*/
void sortRating(Playlist* pList)
{

}


/*
* Function: sortTimesPlayed()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will sort list by number of times played into descending order (Most played -> Least played)
* Input Parameters:
*	Playlist *pList: Pointer to list
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has been sorted into Most -to-> Least played.
*/
void sortTimesPlayed(Playlist* pList)
{

}


/*
* Function: play()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will run through the playlist starting from the user selected song
* Input Parameters:
*	Playlist *pList: Pointer to list
*	char *songEntry: User entered song name, and play start point
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has played completely through one time
*/
void play(Playlist* pList, char* songEntry)
{

}

/*
* Function: shufflePlay()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will shuffle the playlist not by actually changing the list but by playing the songs in a particular order by traversing the list
* Input Parameters:
*	Playlist *pList: Pointer to playlist
* Returns: NONE
* Precondition: List not empty
* Postcondition: List has been played in a shuffled order.
*/
void shufflePlay(Playlist* pList)
{

}

/*
* Function: exitProgram()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will exit the program after saving the current list to the passed file overwriting previous data
* Input Parameters:
*	Playlist *pList: Pinter to the playlist
*	FILE *infile: file to be OVERWRITTEN
* Returns: NONE
* Precondition: File is open, and the list is not empty.
* Postcondition: List has been printed to file in a CSV format: <artistName>,<albumTitle>,<songTitle>,<genre>,<duration.minutes:duration.seconds>,<numTimesPlayed>,<rating>
*/
void exitProgram(Playlist* pList, FILE* infile)
{

}