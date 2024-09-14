#include <stdlib.h>

typedef struct	s_toto
{
	int	x;
	int	y;
}	t_toto;

typedef struct s_render_tex
{
	int			height;
	int			y0;
	int			ymax;
	int			y;
	int			tex_x;
	int			tex_y;
	double		ftex_y;
	double		ftex_yinc;
	t_toto		*toto;
	int			tex_modulo_m1;
	double		shade;
	int			pixel;
	// wall distance
	double		w_dist;
}	t_render_tex;

int	init(t_render_tex *t)
{
	t->y0 = rand() % 20;
}

int test(int n)
{
	t_render_tex	r;

	init(&r);
	if (r.y0 > 10)
		return (r.y0 * r.y0);
	return r.y0;
}

int	main(void)
{
	return test(10);
}
