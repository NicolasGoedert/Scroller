/*
** wolf.c for wolf in /home/jdesmurs/RUSH/RUSH_INFOGRAPHIE/repo/scroller
** 
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
** 
** Started on  Sat Apr  1 19:23:59 2017 jeremy desmurs
** Last update Sat Apr  1 19:23:59 2017 jeremy desmurs
*/

#include "my.h"

t_param_sprite	init_pos_wolf(t_param_sprite pos_wolf,
			      t_param_scroller param,
			      char *str)
{
  pos_wolf.texture = sfTexture_createFromFile(str, NULL);
  pos_wolf.sprite = sfSprite_create();
  sfSprite_setTexture(pos_wolf.sprite, pos_wolf.texture, sfTrue);
  sfTexture_updateFromPixels(pos_wolf.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_wolf.pos.x = 500.0f;
  pos_wolf.pos.y = 580.0f;
  pos_wolf.scale.x = 4.0f;
  pos_wolf.scale.y = 3.5f;
  pos_wolf.rectangle.left = -100;
  pos_wolf.rectangle.top = 200;
  pos_wolf.rectangle.width = 100;
  pos_wolf.rectangle.height = 90;
  return (pos_wolf);
}

int			timer_wolf()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 100)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	draw_wolf(t_param_scroller param, t_param_sprite pos_wolf)
{
  static int	i = 0;

  if (timer_wolf() == 1)
    {
      pos_wolf.rectangle.left = pos_wolf.rectangle.left + 100;
      if (pos_wolf.rectangle.left >= 400)
	{
	  pos_wolf.rectangle.left = 0;
	  pos_wolf.rectangle.top = 100;
	  i++;
	  if (i == 3)
	    {
	      pos_wolf.rectangle.top = 200;
	      i = 0;
	    }
	}
    }
  sfSprite_setTextureRect(pos_wolf.sprite, pos_wolf.rectangle);
  sfSprite_setPosition(pos_wolf.sprite, pos_wolf.pos);
  sfSprite_setScale(pos_wolf.sprite, pos_wolf.scale);
  sfRenderWindow_drawSprite(param.window, pos_wolf.sprite, NULL);
  return (pos_wolf);
}
