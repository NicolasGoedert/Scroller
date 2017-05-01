/*
** muse.c for muse.c in /home/Romingo/CGraph/scroller
** 
** Made by romain rousseau
** Login   <Romingo@epitech.net>
** 
** Started on  Sat Apr  1 16:14:44 2017 romain rousseau
** Last update Sat Apr  1 16:14:44 2017 romain rousseau
*/

#include "my.h"

void	muse(int nb)
{
  static sfMusic	*song;

  if (nb == 0)
    {
      song = sfMusic_createFromFile("subfiles/music/Lemmings-Escape.ogg");
      sfMusic_play(song);
    }
  else
    {
      sfMusic_pause(song);
      sfMusic_destroy(song);
    }
}
