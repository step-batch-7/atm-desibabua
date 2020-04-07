#include <stdio.h>
#include "atm.h"

void display_money(unsigned int notes)
{
	int notes_value[NO_OF_NOTES] = NOTES_VALUE;
	int denomination = 0x10000000;
	int note_count;
	for (int index = 0; index < NO_OF_NOTES; index++)
	{
		note_count = notes / denomination;
		if(note_count) printf("	%d notes of Rs %d\n",note_count,notes_value[index]);
		notes <<= 4;
	}
	printf("\n");
}

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