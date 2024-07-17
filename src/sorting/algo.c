/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:43:03 by rothiery          #+#    #+#             */
/*   Updated: 2024/07/17 12:44:25 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_nsorted(t_list *a, int n)
{
	int	i;

	i = 1;
	while (a->next && i <= n)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

int		l_median(t_list *a, int len)
{
	t_list	*cmp;
	t_list	*cmp2;
	int	i;

	cmp = a;
	i = 0;
	while (i != ((len / 2)))
	{
		cmp2 = a;
		i = 0;
		while (i <= ((len / 2)) && cmp2)
		{
			if (cmp->content > cmp2->content)
				i++;
			cmp2 = cmp2->next;
		}
		if (i != len / 2)
			cmp = cmp->next;
	}
	return(cmp->content);
}

void	l_bsort(t_list *a, t_list *b)
{
	int	i;
	int cmp;

	i = 0;
	cmp = a->content;
	while (b && b->content > cmp)
	{
		pa(&a, &b);
		sa(&a);
		i++;
	}
	while (i >= 0)
	{
		pb(&a, &b);
		i--;
	}
	rra(&a);
	write(1, "1\n", 2);
	printus(a, b);
	write(1, "1\n", 2);
}

void	algo(t_list *a, t_list *b, int len)
{
	int	i;
	int	median;
	int	high_f;

	high_f = 0;
	i = 0;
	median = l_median(a, len);
	printus(a, b);
	if (lst_high(a, high_f) == 1)
	{
		high_f++;
		rra(&a);
		rra(&a);
	}
	while (is_sorted(a) != 0 && i++ < 4)
	{
		if (a->content > a->next->content)
			sa(&a);
		else if (lst_high(a, high_f) == 2)
		{
			high_f++;
			rra(&a);
		}
		else if (a->content < a->next->content && !b)
		{
			pb(&a, &b);
			if (high_f > 0)
				rra(&a);
		}
		else if (a->content < a->next->content && a->content < b->content)
		{
			l_bsort(a, b);
			write(1, "2\n", 2);
			printus(a, b);
			write(1, "2\n", 2);
		}
		else if (a->content < a->next->content && a->content > b->content)
		{
			pb(&a, &b);
			if (high_f > 0)
				rra(&a);
		}
		else 
		{
			write(1, "else\n", 6);
			printus(a, b);
			exit(0);
		}
		printus(a, b);
	}
}



