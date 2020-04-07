#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int amount)
{
	unsigned int denomination = 0;
	int max_allowed_amount = 31999;
	unsigned int notes[NO_OF_NOTES] = NOTES;
	int notes_value[NO_OF_NOTES] = NOTES_VALUE;
	if(amount <= max_allowed_amount)
	{
		for (int index = 0; index < NO_OF_NOTES; index++)
		{
			int no_notes = amount / notes_value[index];
			denomination |= no_notes * notes[index];
			amount -= no_notes * notes_value[index];
		}
	}
	return denomination;
}