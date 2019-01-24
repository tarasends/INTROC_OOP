//
//  bubblesort.cpp
//
//  Created by Tara McKaskle on 11/29/16.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void bblsort(int[], int);
void deal (int deck[], int playerhand [], int player);
void showhand (int [], int);

int main() {

	int min = 1;
	int max = 52;
	int num = 0;
	bool complete = false;
	bool duplicate = false;

	int array[52];
	int arrayswap[52];
	int count = -1;
    
    int playerhands [4][13];

	srand(8);

	num = (rand() % ((max - min) + 1)) + min;
	array[0] = num;
	arrayswap[0] = num;
	count++;

	while (!complete) {
		num = (rand() % ((max - min) + 1)) + min;
		count++;
		duplicate = false;

		for (int card = 0; card < count; card++) {
			if ((array[card] == num) && (card < count)) {
				duplicate = true;
				count--;
				break;
			}
		} //end of for (card < count)

		if (!duplicate) {
			array[count] = num;
			arrayswap[count] = num;
		}
		if (count != 51)
			complete = false;
		else
			complete = true;
	}//end of while (!complete) now, array of shuffled deck
    
    
    bblsort(arrayswap, 52);
    
    for (int players = 0; players < 4; players++)
        deal (array, playerhands [players], players);
    
    //displays
    cout << endl;
    cout << "  SHUFFLED" << "   " << "UNWRAPPED" << endl;
    for (int cards = 0; cards < 52; cards++)
        cout << "      " << array[cards] << " \t" << arrayswap[cards] << endl;
    
    for (int player = 0; player < 4; player++){
        showhand (playerhands[player], player);

        cout << endl;
    }

	return 0;
} //end of main


void bblsort(int array[], int size) {
	bool swap;
	int temp;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++){
			if (array[count] > array[count + 1]){
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}//end for
	} while (swap); //while swap is true, this'll keep going
}//end bblsort


//void deal([52],[hand dealth to individual player],(represents player offset))
void deal (int deck[52], int playerhand [], int player){
    int phandindex = 0;
    for (int i = 0; i < 52; i++){
        if ( i % 4 == player){
            playerhand [phandindex++] = deck [i];
        }
    }
}

void showhand (int hand[], int player){
    int cardval = 0;
    int cardsuit = 0;
    int card = 0;
    
    cout << "========================" << endl;
    cout << "Player " << player+1 << "'s cards:"<< endl;
    for (int card = 0; card < 13; card++){
        cardval = (( hand[card]-1)% 13) +1 ; // this is # value on card in each suit
        cardsuit = (hand[card]-1)/13 ; // this should be number 0-3 representing suit
        cout << "  " << hand[card] << "\t" ;
        switch(cardval){
            case 0:
                cout << "King ";
                break;
            case 1:
                cout << "Ace ";
                break;
            case 11:
                cout << "Jack ";
                break;
            case 12:
                cout << "Queen ";
                break;
            default:
                cout << cardval << " ";
        }
        cout << "of " ;
     
        switch (cardsuit){
            case 0:
                cout << "Hearts";
                break;
            case 1:
                cout << "Diamonds";
                break;
            case 2:
                cout << "Clubs";
                break;
            case 3:
                cout << "Spades";
                break;
        }
        cout << endl;
     }
}


