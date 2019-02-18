void reveal(int x, int y)
{
  //CODE
}

void play_reveal(int x, int y)
{
  if(x < 0 || this->width < x || y < 0 || this->height < y || T[x][y].isRevealed())
  {
    return;
  }
  
  reveal(x, y);
  if(T[x][y].isBomb())
  {
    //Lose
  }
  else if(T[x][y].isFlagged())
  {
    //DO NOTHING
  }
  else
  {
    if(T[x][y].neighbourCounter() == 0)
    {
      play_reveal(x - 1, y - 1);
      play_reveal(x, y - 1);
      play_reveal(x + 1, y - 1);
      play_reveal(x - 1, y);
      play_reveal(x + 1, y);
      play_reveal(x - 1, y + 1);
      play_reveal(x, y + 1);
      play_reveal(x + 1, y + 1);
    }
  }
}
// TO DO : ADD TO MAIN CODE