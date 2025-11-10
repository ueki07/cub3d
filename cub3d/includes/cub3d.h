/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilleu <aguilleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:27:02 by jlepany           #+#    #+#             */
/*   Updated: 2025/11/10 15:56:38 by aguilleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# define HEIGHT 520
# define WIDTH 1080

typedef struct wall_img {
	void	*wall;
	char	*path;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		len;
	int		endian;
}	t_wall;

typedef struct raycasting {
	double	p_x;
	double	p_y;
	double	cplane;
	double	c_plane_x;
	double	c_plane_y;
	double	p_dir_x;
	double	p_dir_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_f_side_x;
	double	ray_f_side_y;
	double	ray_delta_x;
	double	ray_delta_y;
	double	wall_dist;
	int		wall_side;
	char	wall_hit;
	t_wall	*wall_txt;
	int		hit_count;
	int		old_hit_x;
	int		old_hit_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
}			t_engine;

typedef struct screen_img{
	void	*img;
	int		bpp;
	int		len;
	int		endian;
	char	*addr;
}	t_screen;

typedef struct bel_struct {
	int			key[256];
	int			fd_map;
	t_wall		**wall;
	int			colors[2];
	char		**img_name;
	char		**map;
	int			two_start;
	int			p_xy[2];
	char		p_direction;
	double		map_len_x;
	double		map_len_y;
	void		*mlx;
	void		*win;
	char		*weast;
	char		*wwest;
	char		*wsouth;
	char		*wnorth;
	t_screen	*img;
	t_engine	*data;
}			t_struct;

int		error_detected(char *str, char *s);

int		parsing_param(int fd, char *img_name[4], int colors[2]);
int		check_color_binary(char *str);
int		to_decimal(int colors[3], int binary);
int		to_binary(int rgb[3]);
int		parsing_map(t_struct *garbage);
int		nb_lines_gnl(t_struct *garbage);
int		handle_map(t_struct *garbage, char *argv);
char	*ft_strcpy(char *dest, char *src);
void	free_split(char **tot);
int		check_map(t_struct *garbage);

int		end(t_struct *garbage, int i);
int		end_part_two(t_struct *cub);
int		drop_the_garbage(t_struct *garbage);
int		mlx_start(t_struct *garbage);

void	player_first_angle(t_struct *cub, t_engine *data);
int		change_pos(t_engine *data, char **map, double new_x, double new_y);
int		raycasting(t_struct *cub, t_engine *data);
int		raycasting_engine(t_struct *cub);
int		execute_mlx(t_struct *garbage);

int		is_new_wall(t_engine *data, int hit_count);
char	wall_side_hit(t_engine *data, int wall_side);
t_wall	*get_texture_addr(t_struct *cub, char wall_or);
int		print_wall_part(t_struct *cub, double w_dist, int pix_raw, t_wall *txt);

int		auto_move(t_struct *cub);
int		handle_keys(int keys, t_struct *cub);
int		player_move(int keys, t_engine *data, char **map, double move_speed);
int		handle_key_release(int keys, t_struct *cub);

#endif
