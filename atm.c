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
		note_count &&printf("	%d %s of Rs %d\n", note_count, note_count > 1 ? "notes" : "note", notes[i]);
		notes_denomination <<= 4;
	}
	printf("\n");
}

unsigned int get_money(unsigned short int amount)
{
	unsigned int note_count = 0x00000000;
	int max_allowed_amount = 31999;
	int notes[NO_OF_NOTES] = NOTES;
	if(amount <= max_allowed_amount)
	{
		for (int i = 0; i < NO_OF_NOTES; i++)
		{
			note_count <<= 4;
			note_count |= amount / notes[i];
			amount %= notes[i];
		}
	}
	return note_count;
}