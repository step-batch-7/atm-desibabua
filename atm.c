#include <stdio.h>
#include "atm.h"

void display_money(unsigned notes_denominations)
{
	NOTES;
	unsigned note_count;
	REPEAT(0,8)
	{
		note_count = notes_denominations << index * 4 >> 28;
		note_count &&printf("	%d %s of Rs %d\n", note_count, note_count > 1 ? "notes" : "note", notes[index]);
	}
	EMPTY_LINE;
}

unsigned get_money(unsigned short amount)
{
	NOTES;
	unsigned note_count = 0;
	IF_LESS_THAN_MAX_AMOUNT
	{
		REPEAT(0,8)
		{
			note_count <<= 4;
			note_count |= amount / notes[index];
			amount %= notes[index];
		}
	}
	return note_count;
}