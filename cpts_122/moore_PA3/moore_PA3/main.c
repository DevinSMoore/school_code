/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/02/20
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: PA 3

Description: Implementing a playlist using a circular linked list
*******************************************************************************************/
#include "playlist.h"

int main(int argc, char** argv)
{
	FILE* infile = fopen("musicPlayList.csv", "r"), *outfile = NULL;
	Playlist playlist;
	initPlaylist(&playlist);

	loadPlaylist(&playlist, infile);
	fclose(infile);

	//insertRecord(&playlist);
	displayWholeList(&playlist);
	editRating(&playlist, "pap");
	putchar('\n');
	displayWholeList(&playlist);
	deleteRecord(&playlist, "Trust");
	putchar('\n');
	displayWholeList(&playlist);
	system("cls");
	outfile = fopen("musicPlayList.csv", "w");
	storePlaylist(&playlist, infile);
	fclose(outfile);

	
	return 0;
}