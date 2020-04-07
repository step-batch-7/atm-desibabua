#include <stdio.h>
#include "atm.h"

#define ONE  0X1
#define FIVE  0X10
#define TEN  0X100
#define TWENTY  0X1000
#define FIFTY  0X10000
#define HUNDRED  0X100000
#define FIVE_HUNDRED  0X1000000
#define TWO_THOUSAND  0X10000000

unsigned int get_money(unsigned short int amount)
{
	unsigned int denomination = 0;
	unsigned int notes[8] = {TWO_THOUSAND, FIVE_HUNDRED, HUNDRED, FIFTY, TWENTY, TEN, FIVE, ONE};
	int notes_value[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
	for (int index = 0; index < 8;index++)
	{
		int no_notes = amount / notes_value[index];
		denomination |= no_notes * notes[index];
		amount -= no_notes * notes_value[index];
	}
	return denomination;
}