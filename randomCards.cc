#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define DEBUG 0

#define MAXINPUT  100

#define NCARDS    52
#define NPROPS    2
#define PROP_FACE 0
#define PROP_SUIT 1
#define NSUITS    4
#define NFACES    13

const char * suit [NSUITS] = {"hearts","spades","clubs","diamonds"};
const char * face [NFACES] = {"ace","two","three","four","five","six","seven","eight","nine","ten","jack","queen","king"};

void PrintCard   (int deck[NCARDS][NPROPS], int i);
void InitDeck    (int deck[NCARDS][NPROPS]);
void SwapCards   (int deck[NCARDS][NPROPS], int src, int dest);
void ShuffleDeck (int deck[NCARDS][NPROPS]);
void printDeck   (int deck[NCARDS][NPROPS]);
void dealHand    (int deck[NCARDS][NPROPS], int n);


int main()
{
    int deck[NCARDS][NPROPS];
    int src    = 0;
    int dest   = 0;
    int i      = 0;

    char input[MAXINPUT] = "";
    int length = 0;

    srand(time(NULL));

    printf ( "\nInitializing Deck of Cards" );
    InitDeck(deck);

    if (DEBUG) printDeck(deck);

    printf ( "\nShuffling Cards" );
    ShuffleDeck(deck);

    if (DEBUG) printDeck(deck);

    /*  get # cards to deal 
    */
    printf ("\nEnter Number of cards to deal: ");
    fgets (input, MAXINPUT, stdin);

    dealHand ( deck, atoi (input) ); 

    return 0;
}

void dealHand (int deck[NCARDS][NPROPS], int n)
{   
    int i = 0;

    /* range check
    */
    if ( n < 0 ) { n = 0; }
    if ( n >= NCARDS ) { n = NCARDS; }
    
    for ( i = 0; i < n; i++)
    {   
        PrintCard(deck,i);
    }
}


void printDeck (int deck[NCARDS][NPROPS])
{
    int i = 0;
  
    for ( i = 0; i < NCARDS; i++)
    {
        PrintCard(deck,i);
    }

    printf ("\n");
}

void InitDeck(int deck[NCARDS][NPROPS])
{
    int suit  = 0;
    int face  = 0;
    int row   = 0;

    for (suit = 0; suit < NSUITS; suit++) 
    {
       for (face=0; face < NFACES; face++)
       {
          deck[row][PROP_FACE] = suit;
          deck[row][PROP_SUIT] = face;
          row++;
       }
    }
}

void ShuffleDeck(int deck[NCARDS][NPROPS])
{
    int src  = 0;
    int dest = 0;
    int i    = 0;

    for (i = 0; i < NCARDS; i++)
    {
        src = i;
        dest = rand() % NCARDS;
        SwapCards(deck, src, dest);
    }
}

void SwapCards(int deck[NCARDS][NPROPS], int src, int dest)
{
    int temp = 0;

    temp = deck[src][PROP_FACE];

    deck[src][PROP_FACE]   = deck[dest][PROP_FACE];
    deck[dest][PROP_FACE]  = temp;

    temp = deck[src][PROP_SUIT];

    deck[src][PROP_SUIT]   = deck[dest][PROP_SUIT];
    deck[dest][PROP_SUIT]  = temp;
}

void PrintCard(int deck[NCARDS][NPROPS], int i)
{
    int tempsuit;
    int tempface;
    tempsuit = deck[i][0];
    tempface = deck[i][1];
    printf("\nCard %d = %s of %s", i, face[tempface], suit[tempsuit]);
}
