/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbussir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:37:46 by thbussir          #+#    #+#             */
/*   Updated: 2025/11/11 18:37:48 by thbussir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

/*============================================================================*/

int				parse(int ac, char **av, int **values);
int				stack_len(t_stack *stack);
int				find_min(t_stack *stack);
int				find_max(t_stack *stack);
int				find_index(t_stack *stack, int nb);
int				find_pos(t_stack *a, int nb, int size_a);
int				find_best_nb(t_stack *a, t_stack *b, int size_a, int size_b);
int				is_sorted(t_stack *stack);
int				is_decreasing(t_stack *stack);
void			create_stack(t_stack **a, int *values, int nb_val);
void			add_back(t_stack **stack, t_stack *new);
void			free_stack(t_stack *stack, int top);
void			push(t_stack **a, t_stack **b, char *opt);
void			swap(t_stack **a, t_stack **b, char *opt);
void			rotate(t_stack **a, t_stack **b, char *opt);
void			move_nb_to_a(t_stack **a, t_stack **b, int nb, int size_a);
t_stack			*stack_end(t_stack *stack);

/*============================================================================*/

void			checker_push(t_stack **a, t_stack **b, char *opt);
void			checker_swap(t_stack **a, t_stack **b, char *opt);
void			checker_rotate(t_stack **a, t_stack **b, char *opt);
char			*get_next_line(int fd);

/*============================================================================*/

int				ft_printf(char	*format, ...);
int				ft_isdigit(int c);
void			*ft_calloc(size_t nmemb, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *dest, char *src);
char			*ft_strchr(char *str, char c);
size_t			ft_strlen(const char	*str);
long long int	ft_atoi(const char *nptr);

/*============================================================================*/
#endif
