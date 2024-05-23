/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:40:26 by dosokin           #+#    #+#             */
/*   Updated: 2024/05/03 13:08:49 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "map_data.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

typedef enum e_error
{
	INV_ARG,
	INV_FILE,
	EMPTY_FILE,
	BOZO_INFOS,
	NO_MAP,
	DUP_INFO,
	INV_TYPE_ID,
	INV_MAP,
	RGB_ERR,
	MIS_INFOS,
	MISS_INFO,
	WALLS_INT,
	INV_CHAR,
	PLY_NBR,
	MISS_PLAYER,
	INVMAP,
	INV_XPM,
	ERR_OP_XPM,
	OP_MAPFILE,
	MISSING_FILES,
}							t_error;

typedef struct s_lekser_parser
{
	int						end_i;
	char					*value;
	struct s_lekser_parser	*next;
}							t_lp;

int							error_manager(t_error type);

int							bober_parse(char *file_name, t_map_data *map_data);

bool						is_arg_cub(char *argument);

int							ft_strlen(char *s);
int							ft_strcmp(char *a, char *b);
char						*ft_strdup(char *s);
int							ft_atoi(char *s, int *i);

bool						is_whitespace(char c);
bool						is_quote(char c);
bool						is_num(char c);
bool						is_sign(char c);
bool						is_invalid_map_char(char c, bool *found_player);

void						increment_both(int *a, int *b);
char						*get_next_arg(char *s, int *i);

int							lp_to_data(t_lp *lp, t_map_data *data);
int							deinit_lps(t_lp *lp);
int							preliminary_ops(char *s, int *i, int *c);
int							map_manager(t_map_data *data);
int							scraping_main(int argc, char **argv,
								t_map_data *map);
char						*extract(char *to_find, t_lp *lp, int *last_info);
int							extract_rgb(char *to_find, t_lp *lp, int *rgb,
								int *last_info);
int							count_lines(char *not_splitted_map);
char						*create_a_map_line(char *not_splitted_map, int *i,
								int length);
int							get_the_biggest_len(char *s);
char						*create_full_space_line(int line_length);
int							flood_spaced_map(char **spaced);
int							check_flooded(char **flooded);
int							empty_map(char *map);
int							check_chars(char *s);
char						**create_space_map(char **map, int line_count);
char						*map_line_to_spaced(char *map, int line_length);
char						**create_map(char *not_splitted_map,
								u_int32_t *line_count);
int							test_the_file(char *file_name);
int							check_xpm(t_map_data *data);
bool						check_for_all_mandatory_files(void);

#endif
