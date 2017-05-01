/*
** plant.c for plant in /home/jdesmurs/RUSH/RUSH_INFOGRAPHIE/repo/scroller
** 
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
** 
** Started on  Sat Apr  1 19:37:25 2017 jeremy desmurs
** Last update Sat Apr  1 19:37:25 2017 jeremy desmurs
*/

#include "my.h"

t_param_sprite	init_pos_plant(t_param_sprite pos_plant,
			       t_param_scroller param,
			       char *str)
{
  pos_plant.texture = sfTexture_createFromFile(str, NULL);
  pos_plant.sprite = sfSprite_create();
  sfSprite_setTexture(pos_plant.sprite, pos_plant.texture, sfTrue);
  sfTexture_updateFromPixels(pos_plant.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_plant.pos.x = 500.0f;
  pos_plant.pos.y = 800.0f;
  pos_plant.scale.x = 4.5f;
  pos_plant.scale.y = 4.5f;
  pos_plant.rectangle.left = -32;
  pos_plant.rectangle.top = 0;
  pos_plant.rectangle.width = 32;
  pos_plant.rectangle.height = 64;
  return (pos_plant);
}

int			timer_plant()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 50)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	draw_plant(t_param_scroller param, t_param_sprite pos_plant)
{
  if (timer_plant() == 1)
    {
      pos_plant.rectangle.left = pos_plant.rectangle.left + 32;
      pos_plant.pos.x = pos_plant.pos.x - 60;
      if (pos_plant.pos.x <= -200)
	pos_plant.pos.x = 1920;
      if (pos_plant.rectangle.left >= 160)
	pos_plant.rectangle.left = 0;
    }
  sfSprite_setPosition(pos_plant.sprite, pos_plant.pos);
  sfSprite_setTextureRect(pos_plant.sprite, pos_plant.rectangle);
  sfSprite_setScale(pos_plant.sprite, pos_plant.scale);
  sfRenderWindow_drawSprite(param.window, pos_plant.sprite, NULL);
  return (pos_plant);
}
