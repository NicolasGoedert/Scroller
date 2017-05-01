/*
** nyancat.c for nyancat in /home/jdesmurs/RUSH/RUSH_INFOGRAPHIE/repo/scroller
** 
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
** 
** Started on  Sun Apr  2 17:31:18 2017 jeremy desmurs
** Last update Sun Apr  2 17:31:18 2017 jeremy desmurs
*/

#include "my.h"

t_param_sprite	init_pos_nyancat(t_param_sprite pos_nyancat,
			      t_param_scroller param,
			      char *str)
{
  pos_nyancat.texture = sfTexture_createFromFile(str, NULL);
  pos_nyancat.sprite = sfSprite_create();
  sfSprite_setTexture(pos_nyancat.sprite, pos_nyancat.texture, sfTrue);
  sfTexture_updateFromPixels(pos_nyancat.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_nyancat.pos.x = -300.0f;
  pos_nyancat.pos.y = 0.0f;
  pos_nyancat.scale.x = 5.0f;
  pos_nyancat.scale.y = 5.0f;
  pos_nyancat.rectangle.left = -55;
  pos_nyancat.rectangle.top = 0;
  pos_nyancat.rectangle.width = 64;
  pos_nyancat.rectangle.height = 40;
  return (pos_nyancat);
}

int			timer_nyancat()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 32)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	draw_nyancat(t_param_scroller param, t_param_sprite pos_nyancat)
{
  if (timer_nyancat() == 1)
  {
    pos_nyancat.pos.x = pos_nyancat.pos.x + 30;
    if (pos_nyancat.pos.x >= 1925)
      pos_nyancat.pos.x = -600;
    pos_nyancat.rectangle.left += 64;
    if (pos_nyancat.rectangle.left >= 192)
      pos_nyancat.rectangle.left = 11;
  }
  sfSprite_setTextureRect(pos_nyancat.sprite, pos_nyancat.rectangle);
  sfSprite_setPosition(pos_nyancat.sprite, pos_nyancat.pos);
  sfSprite_setScale(pos_nyancat.sprite, pos_nyancat.scale);
  sfRenderWindow_drawSprite(param.window, pos_nyancat.sprite, NULL);
  return (pos_nyancat);
}
