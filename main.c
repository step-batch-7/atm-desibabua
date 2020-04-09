#include <stdio.h>
#include "atm.h"

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  REPEAT(0,6)
  {
    unsigned notes = get_money(amounts[index]);
    printf("%5u %08x\n", amounts[index], notes);
    display_money(notes);
  }

  return 0;
}
