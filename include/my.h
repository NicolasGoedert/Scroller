/*
** my.h for my.H in /home/Romingo/CGraph/scroller/include
** 
** Made by romain rousseau
** Login   <Romingo@epitech.net>
** 
** Started on  Sat Apr  1 15:50:41 2017 romain rousseau
** Last update Sat Apr  1 15:50:41 2017 romain rousseau
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio/Music.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

typedef	struct		s_param_scroller
{
  sfRenderWindow	*window;
  sfUint8		*pixels;
  sfEvent		event;
  sfVector2i		screen_size;
}			t_param_scroller;

typedef struct	s_param_sprite
{
  sfVector2f	pos;
  sfVector2f	scale;
  sfIntRect	rectangle;
  sfTexture	*texture;
  sfSprite	*sprite;
}		t_param_sprite;

typedef struct  s_tab_sprite
{
  t_param_sprite	pos_wolf;
  t_param_sprite	pos_plant;
  t_param_sprite	pos_back;
  t_param_sprite	pos_text;
  t_param_sprite	pos_fire;
  t_param_sprite	pos_bird;
  t_param_sprite	pos_nyancat;
}		t_tab_sprite;

void			muse(int);
t_param_sprite		init_pos_wolf(t_param_sprite pos_wolf,
				      t_param_scroller param,
				      char *str);
t_param_sprite		draw_wolf(t_param_scroller param,
				  t_param_sprite pos_wolf);
t_param_sprite		init_pos_plant(t_param_sprite pos_plant,
				       t_param_scroller param,
				       char *str);
t_param_sprite		draw_plant(t_param_scroller param,
				  t_param_sprite pos_plant);
t_param_sprite		init_pos_back(t_param_sprite pos_back,
				      t_param_scroller param,
				      char *str);
t_param_sprite		draw_back(t_param_scroller param,
				  t_param_sprite pos_back);
t_param_sprite		init_pos_text(t_param_sprite pos_text,
				      t_param_scroller param,
				      char *str);
t_param_sprite		draw_text(t_param_scroller param,
				  t_param_sprite pos_text);
t_param_sprite		init_pos_fire(t_param_sprite pos_fire,
				      t_param_scroller param,
				      char *str);
t_param_sprite		draw_fire(t_param_scroller param,
				  t_param_sprite pos_fire);
t_param_sprite          init_pos_bird(t_param_sprite pos_bird,
				      t_param_scroller param,
				      char *str);
t_param_sprite          draw_bird(t_param_scroller param,
				  t_param_sprite pos_bird);
t_param_sprite	init_pos_nyancat(t_param_sprite pos_nyancat,
				 t_param_scroller param,
				 char *str);
t_param_sprite	draw_nyancat(t_param_scroller param,
			     t_param_sprite pos_nyancat);
#endif /* !MY_H_ */
