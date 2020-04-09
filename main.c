#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
	ft_putchar('\n');
	return (0);
}

void ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar(temp / size + 48);
		temp %= size;
		size /= 10;
	}
}

int check_sign_checks(char s)
{
	char *cmp;
	int res;

	res = 0;
	cmp = ".wb";
	if (s == cmp[0] || s == cmp[1] || s == cmp[2])
	{
		res = 1;
	}
	else
	{
		res = -1;
	}
	return (res);
}

int check_checks_sign(char **argv)
{
	int i;
	int index;

	i  = 0;
	index = 1;
	while (index < 9)
	{
		i = 0;
		while(i < 8)
		{
			if (check_sign_checks(argv[index][i]) < 0)
			{
				return (-1);
			}
			++i;
		}
		++index;
	}
	return (1);
}

int cmp_index_loc(char char_index, char *char_loc)
{
	int	i;
	int	res;

	i =	0;
	res =	-1;
	while (i < 4)
	{
		if (char_index == char_loc[i])
			res = 1;
		++i;
	}
	return (res);
}

int check_loc(char char_index, int int_index)
{
	char	*a, *b;
	int	res;

	a =	"BDFH";
	b =	"ACEG";
	res = 	1;
	if ((cmp_index_loc(char_index, a) > 0) && ((int_index % 2) == 0))
		res = -1;
	if ((cmp_index_loc(char_index, b) > 0) && ((int_index % 2) != 0))
		res = -1;
	return (res);
}

int check_checks_location(char **argv)
{
	int	j;
	int	i;
	int	res;
	char	*char_index;
	char	*checks_color;

	j = 0;
	i = -1;
	res = -1;
	checks_color = "wb";
	char_index = " ABCDEFGH";
	++argv;
	while (j != 8)
	{
		i = 0;
		while (i != 8)
		{
			if (argv[j][i] == checks_color[0] || argv[j][i] == checks_color[1])
			{
				res = check_loc(char_index[j], i);
			}
			++i;
		}
		++j;
	}
	return (res);
}

int check_rows_lenth_and_name(char **argv)
{
	int	res;
	char	*name;
	int	count;

	res =	1;
	count =	0;
	name =	"checkers";
	while (name[count])
	{
		ft_putchar(name[count]);
		ft_putchar(argv[0][count + 2]);
		if (name[count] != argv[0][count + 2])
			res = -1;
		++count;
	}
	res = check_lenth(++argv);
	return (res);

}

int main(int argc, char **argv)
{
	ft_putnbr(argc);
	ft_putchar('\n');
	if (argc == 9)
	{
		if ((check_checks_sign(argv) < 0) || (check_checks_location(argv) < 0) || (check_rows_lenth_and_name(argv) < 0))
		{
			ft_putstr("error_check");
		}
		else
		{
			ft_putstr("Norme_go_toward");
		}
	}
	else
	{
		ft_putstr("error_M");
	}
	return (0);
}
