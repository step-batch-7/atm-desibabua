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
	get_denomination(&amount, &denomination, 2000, TWO_THOUSAND_NOTE);
	get_denomination(&amount, &denomination, 500, FIVE_HUNDRED_NOTE);
	get_denomination(&amount, &denomination, 100, HUNDRED_NOTE);
	get_denomination(&amount, &denomination, 50, FIFTY_NOTE);
	get_denomination(&amount, &denomination, 20, TWENTY_NOTE);
	get_denomination(&amount, &denomination, 10, TEN_NOTE);
	get_denomination(&amount, &denomination, 5, FIVE_NOTE);
	get_denomination(&amount, &denomination, 1, ONE_NOTE);
	return denomination;
}