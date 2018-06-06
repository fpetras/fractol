# Fract'ol

A fractal explorer

Implemented fractals:
 1. [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set "en.wikipedia.org/wiki/Mandelbrot_set")
 2. [Julia set](https://en.wikipedia.org/wiki/Julia_set "en.wikipedia.org/wiki/Julia_set")
 3. [Burning Ship fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal "en.wikipedia.org/wiki/Burning_Ship_fractal")
 4. [Tricorn](https://en.wikipedia.org/wiki/Tricorn_(mathematics) "en.wikipedia.org/wiki/Tricorn_(mathematics)"), also known as Mandelbar set
 5. Web fractal

## Installation:

`git clone --single-branch -b master --recurse-submodules https://github.com/fpetras/fractol.git`\
`cd fractol`\
`make`

## Usage:

`usage: ./fractol [mandelbrot | julia | burningship | tricorn | web]`

**Keyboard Controls:**

 - [**1 - 5**]: Change fractal
 - [**+**][**-**]: Zoom
 - [**↑**][**↓**][**→**][**←**]: Move
 - [**W**][**A**][**S**][**D**]: Move
 - \[**Spacebar**\]: Lock
 - [**Fn**]: Change color
 - \[**R**\]: Reset
 - \[**Esc**\]: Quit

**Mouse Controls:**

- \[**Wheel**\]: Zoom
- \[**Click & Drag**\]: Move

### In action:

#### Mandelbrot set:

![Screenshot1](../assets/mandelbrot.png)

Zooming in:

![GIF1](../assets/mandelbrot.gif)

#### Julia set:

<img src="../assets/julia.gif" width=86.5% height=86.5% />

Burning Ship fractal:

<img src="../assets/burningship.png" width=86.5% height=86.5% />

#### Tricorn / Mandelbar set:

<img src="../assets/tricorn.png" width=86.5% height=86.5% />

#### Web fractal:

![GIF3](../assets/web.gif)

## Code snippets:

Mandelbrot set:

```C
static void ft_mandelbrot2(t_fract *t)
{
    int         i;
    int         max;
    double      l;
    t_complex   c;

    i = 0;
    max = t->iteration;
    c.c_r = (t->coord.x - WIDTH / 2) / t->zoom_c.x + t->translation.x;
    c.c_i = (t->coord.y - HEIGHT / 2) / t->zoom_c.y + t->translation.y;
    c.z_r = 0;
    c.z_i = 0;
    while ((c.z_r * c.z_r + c.z_i * c.z_i) < 4 && i < max)
    {
        c.tmp_r = c.z_r;
        c.tmp_i = c.z_i;
        c.z_r = c.tmp_r * c.tmp_r - c.tmp_i * c.tmp_i + c.c_r;
        c.z_i = 2 * c.tmp_r * c.tmp_i + c.c_i;
        i++;
    }
    l = ((double)i / max) * t->color_lvl;
    t->image[t->coord.y * WIDTH + t->coord.x] = (i < max) ? ft_color(l) : 0;
}

void        *ft_mandelbrot(void *f)
{
    t_fract *t;

    t = (t_fract*)f;
    t->zoom_c.x = 0.3 * t->zoom * WIDTH;
    t->zoom_c.y = 0.3 * t->zoom * HEIGHT;
    t->translation.x -= 0.5;
    t->coord.y = t->tx;
    while (t->coord.y < t->ty)
    {
        t->coord.x = 0;
        while (t->coord.x < WIDTH)
        {
            ft_mandelbrot2(t);
            t->coord.x++;
        }
        t->coord.y++;
    }
    return (NULL);
}
```

Multithreading implementation:

```C
void    ft_fractals(t_fract *f)
{
    int         i;
    t_fract     t[THREADS];
    pthread_t   thr[THREADS];

    i = -1;
    while (++i < THREADS)
    {
        t[i] = *f;
        t[i].tx = i * (WIDTH / THREADS);
        t[i].ty = (i + 1) * (HEIGHT / THREADS);
        if (f->fractal == MANDELBROT)
            pthread_create(&thr[i], NULL, ft_mandelbrot, &t[i]);
        else if (f->fractal == JULIA)
            pthread_create(&thr[i], NULL, ft_julia, &t[i]);
        else if (f->fractal == BURNINGSHIP)
            pthread_create(&thr[i], NULL, ft_burningship, &t[i]);
        else if (f->fractal == TRICORN)
            pthread_create(&thr[i], NULL, ft_mandelbar, &t[i]);
        else if (f->fractal == WEB)
            pthread_create(&thr[i], NULL, ft_web, &t[i]);
    }
    i = -1;
    while (++i < THREADS)
        pthread_join(thr[i], NULL);
    mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
```

## [Subject](https://github.com/fpetras/42-subjects/blob/master/fract_ol.en.pdf "fract_ol.en.pdf")
