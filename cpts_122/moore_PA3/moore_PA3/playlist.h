/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/02/20
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 3

Description: Implementing a playlist using a circular linked list
*******************************************************************************************/
#ifndef PLAYLIST_H
#define PLAYLIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // For IO functions for users and files
#include <stdlib.h> // For malloc() free()
#include <string.h> // For string functions
#include <conio.h> // For _getch(); so I can pause with a specific prompt
#include <ctype.h> // For tolower()

#define MAX_STR_LEN 100

typedef struct duration
{
	int minutes;
	int seconds;
} Duration;

typedef struct record
{
	char artist[MAX_STR_LEN];
	char albumTitle[MAX_STR_LEN];
	char songTitle[MAX_STR_LEN];
	char genre[MAX_STR_LEN];
	Duration duration;
	int rating; // 1-5
	int timesPlayed;

} Record;

typedef struct node
{
	Record record;
	struct node* pNext;
	struct node* pPrev;
} Node;

typedef struct playlist
{
	Node* pStart; // First item in list
	Node* pCur;  //pCurrent will represent wherever we are at the moment in our circular list
} Playlist;

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
void initRecord(Record* pRecord);

/*
* Function: initPlaylist()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: This will populate the first item in the list and set pStart to that location (well and pCur)
* Input Parameters:
*	Playlist *pList: Pointer to playlist
* Returns:
*	NONE
* Precondition: List is declared
* Postcondition: List has been initialized.
*/
void initPlaylist(Playlist *pList);
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
void mainMenu(void);


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
void displayMenu(void);

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
void sortMenu(void);

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
int yesOrNo(void);

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
int countElements(Node* const pStart);

/*
* Function: makeNode()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Creates node for list by allocating space and assinging data to the fields.
* Input Parameters:
*	Playlist *pList: pointer to our playlist
*	Record record: record that containts the data to be insert into node
* Returns:
*	Node *pMem: this will return the address to the allocated memory (or null if it wasn't successful)
* Precondition: NONE
* Postcondition: Memory allocated and address is returned, or NULL if it failed to allocate memory
*/
Node* makeNode(Record* record);

/*
* Function: insertFront()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Willl insert node at the front of the list, if list was previously empty it will set pStart to the first node created 
* Input Parameters:
*	Node *pList: Playlist pointer
*	Record record: record that contains the data to load into the node
* Returns: INT representing success or failure to insert node
* Precondition: NONE
* Postcondition: Node has been inserted into list, and integer has been returned
*/
int insertFront(Playlist* pList, Record* record);


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
void displayWholeList(const Playlist* pList);


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
void displayArtist(Playlist* pList, char* artistEntry);

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
void loadPlaylist(Playlist *pList, FILE *infile);

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
void storePlaylist(Playlist *pList, FILE *infile);

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
int insertRecord(Playlist* pList);

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
void deleteRecord(Playlist* pList, char* songTitle);

/*
* Function: editRecord()
* Date Created: 2021/02/22
* Last Modified: 2021/02/22
* Description: Will allow user to edit a record based on artist
* Input Parameters:
*	Playlist *pList: Pointer to playlist
*	char *artistEntry: User entered string which is the artists name
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: Record in list has ben set to new user entered data
*/
void editRecord(Playlist *pList, char *artistEntry);

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
void flushDataStream(void);

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
void editRating(Playlist* pList, char* songTitle);

/*
* Function: sortArtist()
* Date Created: 2021/02/23
* Last Modified: 2021/02/23
* Description: Will sort list by artist into ascending order (A-Z)
* Input Parameters:
*	Playlist *pList: Pointer to list
* Returns:
*	NONE
* Precondition: List not empty
* Postcondition: List has been sorted into ascending order
*/
void sortArtist(Playlist *pList);


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
void sortAlbumTitle(Playlist* pList);



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
void sortRating(Playlist* pList);


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
void sortTimesPlayed(Playlist* pList);


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
void play(Playlist* pList, char* songEntry);

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
void shufflePlay(Playlist* pList);

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
* Postcondition: List has been printed to file in a CSV format: <artistName>,<albumTitle>,<songTitle>,<genre>,<pDur->minutes:pDur->seconds>,<numTimesPlayed>,<rating>
*/
void exitProgram(Playlist *pList, FILE *infile);

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/




/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

/*
* Function:
* Date Created:
* Last Modified:
* Description:
* Input Parameters:
* Returns:
* Precondition:
* Postcondition:
*/

#endif // !PLAYLIST_H

