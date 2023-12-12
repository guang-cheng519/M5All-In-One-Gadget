#include "MdHighAndLow.h"
#include <Arduino.h>

MdHighAndLow::MdHighAndLow()
{
  randomSeed(analogRead(0));
}

void MdHighAndLow::getTrump(int *heart, int *spade)
{
  *heart = random(9);
  do
  {
    *spade = random(9);
  } while (*heart == *spade);
}

bool MdHighAndLow::getWinLose(int *heart, int *spade)
{
  bool winlose;
  if (*heart > *spade)
  {
    winlose = true;
  }
  else
  {
    winlose = false;
  }

  return winlose;
}