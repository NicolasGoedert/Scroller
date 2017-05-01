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

t_param_sprite	init_pos_fire(t_param_sprite pos_fire,
			       t_param_scroller param,
			       char *str)
{
  pos_fire.texture = sfTexture_createFromFile(str, NULL);
  pos_fire.sprite = sfSprite_create();
  sfSprite_setTexture(pos_fire.sprite, pos_fire.texture, sfTrue);
  sfTexture_updateFromPixels(pos_fire.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_fire.pos.x = 1920.0f;
  pos_fire.pos.y = -660.0f;
  pos_fire.scale.x = 3.1f;
  pos_fire.scale.y = 3.1f;
  pos_fire.rectangle.left = 0;
  pos_fire.rectangle.top = 0;
  pos_fire.rectangle.width = 63;
  pos_fire.rectangle.height = 142;
  return (pos_fire);
}

int			timer_fire()
{
  static struct timeb	tim1;
  static int		nb = 0;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      nb += 1;
      if (nb == 26)
	{
	  nb = 0;
	  return (1);
	}
    }
  return (0);
}

t_param_sprite	draw_fire(t_param_scroller param, t_param_sprite pos_fire)
{
  if (timer_fire() == 1)
    {
      pos_fire.pos.y += 29;
      pos_fire.pos.x -= 4;
      if (pos_fire.pos.y >= 1232)
	pos_fire.pos.y = -322;
      if (pos_fire.pos.x <= -100)
	pos_fire.pos.x = 1920;
      pos_fire.rectangle.left = pos_fire.rectangle.left + 64;
      if (pos_fire.rectangle.left >= 512)
	{
	  pos_fire.rectangle.left = 0;
	  pos_fire.rectangle.top += 128;
	  if (pos_fire.rectangle.top >= 512)
	    pos_fire.rectangle.top = 0;
	}
    }
  sfSprite_setPosition(pos_fire.sprite, pos_fire.pos);
  sfSprite_setTextureRect(pos_fire.sprite, pos_fire.rectangle);
  sfSprite_setScale(pos_fire.sprite, pos_fire.scale);
  sfRenderWindow_drawSprite(param.window, pos_fire.sprite, NULL);
  return (pos_fire);
}
