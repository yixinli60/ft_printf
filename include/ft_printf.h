/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:15:29 by yli               #+#    #+#             */
/*   Updated: 2017/04/24 14:38:00 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# define LENMOD_H 1
# define LENMOD_HH 2
# define LENMOD_L 3
# define LENMOD_LL 4
# define LENMOD_J 5
# define LENMOD_Z 6

typedef struct	s_flag
{
	int			hash;
	int			minus;
	int			plus;
	int			space;
	int			zero;
}				t_flag;

typedef struct	s_str_fmt
{
	t_flag		flag;
	int			wid;
	int			pre;
	int			length_mod;
	char		conv;
	int			neg_nbr;
}				t_str_fmt;

int				parse_format(char *format, t_str_fmt *fmt_struc);
int				parse_width(char **format, t_str_fmt *fmt_struc);
int				parse_precision(char **format, t_str_fmt *fmt_struc);
int				parse_lm(char **format, t_str_fmt *fmt_struc);
void			parse_conv(va_list ap, char **format, t_str_fmt *fmt_struc);
void			ft_conv_dstr(va_list ap, t_str_fmt *fmt_struc);
char 			*ft_add_pad(char *string, t_str_fmt *fmt_struc, intmax_t nbr);
char			*ft_add_space(char *str, t_str_fmt *fmt_struc);
char 			*ft_mflag(char *str, char *pad, t_str_fmt *fmt_struc);
char			*ft_add_signs(char *str_w_0pad, t_str_fmt *fmt_struc);
int				ft_printf(char *format, ...);
void 			ft_parse_fmt(va_list ap, char **format);
char			*pre_str_zero(t_str_fmt *fmt_struc);
char 			*ft_set_pad(t_str_fmt *fmt_struc, int len);
char			*ft_wid_len_pre(t_str_fmt *fmt_struc, int len, char *str);
void			ft_conv_cstr(va_list ap, t_str_fmt *fmt_struc);

#endif
