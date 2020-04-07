#include <stdio.h>
#include "atm.h"

void display_money(unsigned int notes_denomination)
{
	int notes[NO_OF_NOTES] = NOTES;
	int denomination = 0x10000000;
	int note_count;
	for (int i = 0; i < NO_OF_NOTES; i++)
	{
		note_count = notes_denomination / denomination;
		if(note_count) printf("	%d notes of Rs %d\n",note_count,notes[i]);
		notes_denomination <<= 4;
	}
	printf("\n");
}

unsigned int get_money(unsigned short int amount)
{
	unsigned int denomination = 0x00000000;
	int max_allowed_amount = 31999;
	int notes[NO_OF_NOTES] = NOTES;
	if(amount <= max_allowed_amount)
	{
		for (int i = 0; i < NO_OF_NOTES; i++)
		{
			denomination <<= 4;
			int no_notes = amount / notes[i];
			denomination |= no_notes;
			amount -= no_notes * notes[i];
		}
	}
	return denomination;
}