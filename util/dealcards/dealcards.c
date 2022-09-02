#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//#include <strings.h>
#include <windows.h>

//int PASCAL WinMain()
int PASCAL WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow )
{
	unsigned int seed;
	time_t tloc;
	FILE *fp;

	int index;

	char CardList[ 128 ][ 128 ];
	char SenatorList[ 128 ][ 128 ];
	char TempList[ 128 ][ 128 ];
	char RedCardList[ 128 ][ 128 ];
	char DeckList[ 128 ][ 128 ];
	char ProvList1[ 128 ][ 128 ];
	char ProvList2[ 128 ][ 128 ];
	char Comment[ 128 ];
	int NumPlayers, SenatorsPerPlayer, CardsPerPlayer, Prov1PerPlayer, Prov2PerPlayer;
	int TotalSenators, NumRedCards1, NumRedCards2, NumRedCards3;
	int SenatorsInForum, SenatorsInCuria;
	int TotalWars, TotalProv1, TotalProv2;
	int TotalRedCards;
	int Key[ 16 ];
	int RandomList[ 128 ];
	int CardsLeft[ 5 ];
	FILE *output;

	int numfound, number, query, player;

	SenatorsInForum = 0;
	SenatorsInCuria = 0;

	output = fopen( "output.txt", "w+" );

	fp = fopen( "cards.txt", "r" );

	fgets( Comment, 128, fp );
	fgets( Comment, 128, fp );
	fscanf( fp, "%d %d %d %d %d\n", &NumPlayers, &SenatorsPerPlayer,
		&CardsPerPlayer, &SenatorsInForum, &SenatorsInCuria );
	fscanf( fp, "%d %d %d %d %d %d %d\n", &TotalSenators,
		&NumRedCards1, &NumRedCards2, &NumRedCards3, &TotalWars,
		&TotalProv1, &TotalProv2 );

	Key[ 0 ] = 0;
	Key[ 1 ] = TotalSenators;
	Key[ 2 ] = Key[ 1 ]  + NumRedCards1;
	Key[ 3 ] = Key[ 2 ]  + NumRedCards3;
	Key[ 4 ] = Key[ 3 ]  + TotalWars;
	Key[ 5 ] = Key[ 4 ]  + TotalProv1;
	Key[ 6 ] = Key[ 5 ]  + TotalProv2;
	TotalRedCards = NumRedCards1 + NumRedCards2;
	Prov1PerPlayer = TotalProv1 / NumPlayers;
	Prov2PerPlayer = TotalProv2 / NumPlayers;

	index = 0;
	while( fgets( CardList[ index ], 128, fp ) )
		index++;

	fclose( fp );

	seed = time( &tloc );
	srand( seed );

	rand(); /* WIN 95 BUG PATCH */

	/* Deal out Senators */
	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	numfound = 0;
	for( ;; )
	{
		if( TotalSenators == 0 )
			break;
		number = rand() * TotalSenators / RAND_MAX + Key[ 0 ];

		for( query = Key[ 0 ]; query < Key[ 1 ]; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == Key[ 1 ]  )
		{
			RandomList[ numfound ] = number;
			strcpy( SenatorList[ numfound ], CardList[ number ] );
			numfound++;
		}
		if( numfound == TotalSenators )
			break;
	}

	/* Deal Provinces */
	for( index = 0; index < TotalProv1; index++ )
	{
		strcpy( TempList[ index ], CardList[ index + Key[ 4 ] ] );
	}

	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	numfound = 0;
	if( TotalProv1 )
	for( ;; )
	{
		number = rand() * TotalProv1 / RAND_MAX;

		for( query = 0; query < TotalProv1; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == TotalProv1  )
		{
			RandomList[ numfound ] = number;
			strcpy( ProvList1[ numfound ], TempList[ number ] );
			numfound++;
		}
		if( numfound == TotalProv1 )
			break;
	}

	for( index = 0; index < TotalProv2; index++ )
	{
		strcpy( TempList[ index ], CardList[ index + Key[ 5 ] ] );
	}

	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	numfound = 0;
	if( TotalProv2 )
	for( ;; )
	{
		number = rand() * TotalProv2 / RAND_MAX;

		for( query = 0; query < TotalProv2; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == TotalProv2  )
		{
			RandomList[ numfound ] = number;
			strcpy( ProvList2[ numfound ], TempList[ number ] );
			numfound++;
		}
		if( numfound == TotalProv2 )
			break;
	}

	/* Deal out Red Cards */

	for( index = 0; index < NumRedCards1; index++ )
	{
		strcpy( TempList[ index ], CardList[ index + Key[ 1 ] ] );
	}

	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	/* Choose the six from previous periods */
	numfound = 0;
	if( NumRedCards2 )
	for( ;; )
	{
		number = rand() * NumRedCards3 / RAND_MAX;

		for( query = 0; query < NumRedCards3; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == NumRedCards3  )
		{
			RandomList[ numfound ] = number;
			strcpy( TempList[ numfound + NumRedCards1 ],
				CardList[ number + Key[ 2 ] ] );
			numfound++;
		}
		if( numfound == NumRedCards2 )
			break;
	}

	/*
	fprintf( output,"Original Reds\n");
	for( index = 0; index < TotalRedCards; index++ )
	{
		fprintf( output,"%2d %s",index+1,TempList[ index ] );
	}
	fprintf( output,"-----------------------\n");
	*/

	/* shuffle all the red cards */
	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	numfound = 0;
	for( ;; )
	{
		number = rand() * TotalRedCards / RAND_MAX;

		for( query = 0; query < TotalRedCards; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == TotalRedCards  )
		{
			RandomList[ numfound ] = number;
			strcpy( RedCardList[ numfound ], TempList[ number ] );
			numfound++;
		}
		if( numfound == TotalRedCards )
			break;
	}

	if( SenatorsPerPlayer )
	{
		for( player = 0; player < NumPlayers; player++ )
		{
			fprintf( output,"Faction %d\n", player+1);
			for( index = 0; index < SenatorsPerPlayer; index++ )
			{
				fprintf( output,"%s",SenatorList[ index * NumPlayers + player ] );
			}

			for( index = 0; index < Prov1PerPlayer; index++ )
			{
				fprintf( output,"%s",ProvList1[ index * NumPlayers + player ] );
			}
			for( index = 0; index < Prov2PerPlayer; index++ )
			{
				fprintf( output,"%s",ProvList2[ index * NumPlayers + player ] );
			}

			for( index = 0; index < CardsPerPlayer; index++ )
			{
				fprintf( output,"%s",RedCardList[ index * NumPlayers + player ] );
			}
			fprintf( output,"\n");
		}
		fprintf( output,"-----------------------\n");
	}

	if( SenatorsInForum )
	{
		fprintf( output, "Senators in the Forum\n" );
		for( index = 0; index < SenatorsInForum; index++ )
		{
			fprintf( output,"%s",SenatorList[ SenatorsPerPlayer * NumPlayers + index ] );
		}
		fprintf( output, "\n" );
	}
	if( SenatorsInCuria )
	{
		fprintf( output, "Senators in the Curia\n" );
		for( index = 0; index < SenatorsInCuria; index++ )
		{
			fprintf( output,"%s",SenatorList[ SenatorsPerPlayer * NumPlayers + 3 + index ] );
		}
	}

	CardsLeft[ 0 ] = TotalSenators - ( NumPlayers * SenatorsPerPlayer ) -
		SenatorsInForum - SenatorsInCuria;
	CardsLeft[ 1 ] = TotalRedCards - ( NumPlayers * CardsPerPlayer );

	CardsLeft[ 3 ] = TotalProv1 - ( NumPlayers * Prov1PerPlayer );
	for( index = 1; index <= CardsLeft[ 3 ]; index++ )
	{
		fprintf( output, "Extra Provinces\n" );
		fprintf( output, "%s", ProvList1[ TotalProv1 - index ] );
		numfound++;
	}
	CardsLeft[ 3 ] = TotalProv2 - ( NumPlayers * Prov2PerPlayer );
	for( index = 1; index <= CardsLeft[ 3 ]; index++ )
	{
		fprintf( output, "%s", ProvList2[ TotalProv2 - index ] );
		numfound++;
	}
	fprintf( output,"-----------------------\n");

	numfound = 0;
	for( index = 1; index <= CardsLeft[ 0 ]; index++ )
	{
		strcpy( TempList[ numfound ], SenatorList[ TotalSenators - index ] );
		numfound++;
	}
	for( index = 1; index <= CardsLeft[ 1 ]; index++ )
	{
		strcpy( TempList[ numfound ], RedCardList[ TotalRedCards - index ] );
		numfound++;
	}
	for( index = 0; index < TotalWars; index++ )
	{
		strcpy( TempList[ numfound ], CardList[ Key[ 3 ] + index ] );
		numfound++;
	}
	CardsLeft[ 2 ] = numfound;

	/*
	fprintf( output,"Unshuffled Deck %d Cards\n",CardsLeft[ 2 ]);
	for( index = 0; index < CardsLeft[ 2 ]; index++ )
	{
		fprintf( output,"%2d %s",index+1,TempList[ index ] );
	}
	fprintf( output,"-----------------------\n");
	*/


	/* Shuffle the play deck */
	for( index = 0; index < 128; index++ )
		RandomList[ index ] = -1;

	numfound = 0;
	for( ;; )
	{
		number = rand() * CardsLeft[ 2 ] / RAND_MAX;
		/*fprintf( output,"number = %d\n",number );*/

		for( query = 0; query < CardsLeft[ 2 ]; query++ )
		{
			if( number == RandomList[ query ] )
				break;
		}
		if( query == CardsLeft[ 2 ]  )
		{
			RandomList[ numfound ] = number;
			strcpy( DeckList[ numfound ], TempList[ number ] );
			numfound++;
		}
		if( numfound == CardsLeft[ 2 ] )
			break;
	}

	fprintf( output,"Shuffled Play Deck\n");
	for( index = 0; index < CardsLeft[ 2 ]; index++ )
	{
		fprintf( output,"%2d %s",index+1,DeckList[ index ] );
	}
	fprintf( output,"-----------------------\n");

	/*
	fprintf( output,"Red Cards\n");
	for( index = 0; index < TotalRedCards; index++ )
	{
		fprintf( output,"%2d %s",index+1,RedCardList[ index ] );
	}
	fprintf( output,"-----------------------\n");
	*/

	/*
	fprintf( output,"Senators \n");
	for( index = 0; index < TotalSenators; index++ )
	{
		fprintf( output,"%2d %s",index+1,SenatorList[ index ] );
	}
	fprintf( output,"-----------------------\n");
	*/

	return( 0 );
	exit( 0 );
}
