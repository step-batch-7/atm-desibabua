#include <stdio.h>
#include "atm.h"

#define ONE_NOTE  0X1
#define FIVE_NOTE  0X10
#define TEN_NOTE  0X100
#define TWENTY_NOTE  0X1000
#define FIFTY_NOTE  0X10000
#define HUNDRED_NOTE  0X100000
#define FIVE_HUNDRED_NOTE  0X1000000
#define TWO_THOUSAND_NOTE  0X10000000

void get_denomination(unsigned short int *amount,unsigned int *previous_denomination,int note_value,unsigned int hex_value)
{
	int no_of_notes = 0;
	no_of_notes = *amount / note_value;
	*previous_denomination = *previous_denomination | no_of_notes * hex_value;
	*amount = *amount - no_of_notes * note_value;
}

unsigned int get_money(unsigned short int amount)
{
	unsigned int denomination = 0;
	unsigned int notes[8] = {TWO_THOUSAND_NOTE, FIVE_HUNDRED_NOTE, HUNDRED_NOTE, FIFTY_NOTE, TWENTY_NOTE, TEN_NOTE, FIVE_NOTE, ONE_NOTE};
	int notes_value[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
	for (int index = 0; index < 8;index++)
	{
		get_denomination(&amount, &denomination, notes_value[index], notes[index]);
	}
	return denomination;
}