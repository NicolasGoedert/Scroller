/*
** text.c for text in /home/jdesmurs/RUSH/RUSH_INFOGRAPHIE/repo/scroller
** 
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
** 
** Started on  Sat Apr  1 19:23:59 2017 jeremy desmurs
** Last update Sat Apr  1 19:23:59 2017 jeremy desmurs
*/

#include "my.h"

t_param_sprite	init_pos_text(t_param_sprite pos_text,
			      t_param_scroller param,
			      char *str)
{
  pos_text.texture = sfTexture_createFromFile(str, NULL);
  pos_text.sprite = sfSprite_create();
  sfSprite_setTexture(pos_text.sprite, pos_text.texture, sfTrue);
  sfTexture_updateFromPixels(pos_text.texture, param.pixels,
			     param.screen_size.x, param.screen_size.y, 0, 0);
  pos_text.pos.x = 960.0f;
  pos_text.pos.y = 400.0f;
  pos_text.scale.x = 0.5f;
  pos_text.scale.y = 2.0f;
  pos_text.rectangle.left = 0;
  pos_text.rectangle.top = 0;
  pos_text.rectangle.width = 490;
  pos_text.rectangle.height = 10;
  return (pos_text);
}

int			timer_text()
{
  static struct timeb	tim1;
  struct timeb		tim3;

  ftime(&tim3);
  if (tim1.millitm != tim3.millitm)
    {
      tim1.millitm = tim3.millitm;
      return (1);
    }
  return (0);
}

t_param_sprite	draw_text(t_param_scroller param, t_param_sprite pos_text)
{
  int	i;

  i = 0;
  timer_text();
  while (i != 60)
    {
      pos_text.rectangle.top += 1;
      pos_text.pos.y += 1;
      pos_text.pos.x += 1;
      if (pos_text.pos.y == 460)
	pos_text.pos.y = 400;
      if (pos_text.rectangle.top == 60)
	pos_text.rectangle.top = 0;
      if (pos_text.pos.x == 1020)
	pos_text.pos.x = 960;
      sfSprite_setTextureRect(pos_text.sprite, pos_text.rectangle);
      sfSprite_setPosition(pos_text.sprite, pos_text.pos);
      sfSprite_rotate(pos_text.sprite, 0.01f);
      sfRenderWindow_drawSprite(param.window, pos_text.sprite, NULL);
      i++;
    }
  return (pos_text);
}
