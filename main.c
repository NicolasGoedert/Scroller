/*
** test_raytracing.c for test_raytracing in /home/jdesmurs/PROJECTS/RAYTRACKER1/bootstrap/bsraytracker1/src
** 
** Made by jeremy desmurs
** Login   <jdesmurs@epitech.net>
** 
** Started on  Thu Feb  9 14:14:06 2017 jeremy desmurs
** Last update Thu Feb  9 14:14:06 2017 jeremy desmurs
*/

#include "my.h"

sfRenderWindow* create_window(char *name, sfVector2i screen_size)
{
  sfRenderWindow*       window;
  sfVideoMode           mode;

  mode.width = screen_size.x;
  mode.height = screen_size.y;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit(EXIT_FAILURE);
  return (window);
}

sfUint8* create_pixel_buffer(sfVector2i screen_size)
{
  int		i;
  sfUint8*	pixels;

  pixels = malloc(screen_size.x * screen_size.y * 4 * sizeof(*pixels));
  if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < screen_size.x * screen_size.y * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return pixels;
}

void	windows(t_param_scroller param,
		t_tab_sprite sprites)
{
  while (sfRenderWindow_isOpen(param.window))
    {
      while (sfRenderWindow_pollEvent(param.window, &param.event))
	{
	  if (param.event.type == sfEvtClosed)
	    sfRenderWindow_close(param.window);
	}
      sfRenderWindow_clear(param.window, sfBlack);
      sprites.pos_back = draw_back(param, sprites.pos_back);
      sprites.pos_wolf = draw_wolf(param, sprites.pos_wolf);
      sprites.pos_plant = draw_plant(param, sprites.pos_plant);
      sprites.pos_fire = draw_fire(param, sprites.pos_fire);
      sprites.pos_bird = draw_bird(param, sprites.pos_bird);
      sprites.pos_text = draw_text(param, sprites.pos_text);
      sprites.pos_nyancat = draw_nyancat(param, sprites.pos_nyancat);
      sfRenderWindow_display(param.window);
    }
}

int	main(int argc, char **argv)
{
  t_param_scroller	param;
  t_tab_sprite		sprites;

  muse(0);
  if (argc != 8)
    return (0);
  param.screen_size.x = 1920;
  param.screen_size.y = 1080;
  param.window = create_window("SCROLLERRRR", param.screen_size);
  param.pixels = create_pixel_buffer(param.screen_size);
  sprites.pos_wolf = init_pos_wolf(sprites.pos_wolf, param, argv[1]);
  sprites.pos_plant = init_pos_plant(sprites.pos_plant, param, argv[2]);
  sprites.pos_back = init_pos_back(sprites.pos_back, param, argv[3]);
  sprites.pos_text = init_pos_text(sprites.pos_text, param, argv[4]);
  sprites.pos_fire = init_pos_fire(sprites.pos_fire, param, argv[5]);
  sprites.pos_bird = init_pos_bird(sprites.pos_bird, param, argv[6]);
  sprites.pos_nyancat = init_pos_nyancat(sprites.pos_nyancat, param, argv[7]);
  if (!sprites.pos_wolf.texture || !sprites.pos_plant.texture
      || !sprites.pos_back.texture || !sprites.pos_text.texture
      || !sprites.pos_fire.texture || !sprites.pos_bird.texture)
    return (1);
  windows(param, sprites);
  sfRenderWindow_destroy(param.window);
  muse(1);
  return (EXIT_SUCCESS);
}
