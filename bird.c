/*
** bird.c for wolf in /home/jdesmurs/RUSH/RUSH_INFOGRAPHIE/repo/scroller
**
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
**
** Started on  Sat Apr  1 19:23:59 2017 jeremy desmurs
** Last update Sat Apr  1 19:23:59 2017 jeremy desmurs
*/

#include "my.h"

t_param_sprite	init_pos_bird(t_param_sprite pos_bird,
			      t_param_scroller param,
			      char *str)
{
  pos_bird.texture = sfTexture_createFromFile(str, NULL);
  pos_bird.sprite = sfSprite_create();
  sfSprite_setTexture(pos_bird.sprite, pos_bird.texture, sfTrue);
  sfTexture_updateFromPixels(pos_bird.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_bird.pos.x = 120.0f;
  pos_bird.pos.y = 220.0f;
  pos_bird.scale.x = 1.0f;
  pos_bird.scale.y = 1.0f;
  pos_bird.rectangle.left = -64;
  pos_bird.rectangle.top = 64;
  pos_bird.rectangle.width = 64;
  pos_bird.rectangle.height = 64;
  return (pos_bird);
}

int			timer_bird()
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

t_param_sprite	draw_bird(t_param_scroller param, t_param_sprite pos_bird)
{
  if (timer_bird() == 1)
    {
      pos_bird.pos.x = pos_bird.pos.x + 8;
      if (pos_bird.pos.x >= 1925)
	pos_bird.pos.x = -75;
      pos_bird.rectangle.left = pos_bird.rectangle.left + 64;
      if (pos_bird.rectangle.left >= 256)
	pos_bird.rectangle.left = 0;
    }
  sfSprite_setTextureRect(pos_bird.sprite, pos_bird.rectangle);
  sfSprite_setPosition(pos_bird.sprite, pos_bird.pos);
  sfSprite_setScale(pos_bird.sprite, pos_bird.scale);
  sfRenderWindow_drawSprite(param.window, pos_bird.sprite, NULL);
  return (pos_bird);
}
