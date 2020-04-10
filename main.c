#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_putstr(char *str)
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

void	ft_putnbr(int nb)
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

int	check_sign_checks(char s)
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

int	check_checks_sign(char **argv)
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

int	cmp_index_loc(char char_index, char *char_loc)
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

int	check_loc(char char_index, int int_index)
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
int	check_checks_location(char **argv)
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

int	check_lenth(char **argv)
{
	int	j;
	int	i;
	int	res;
	int	counter;

	j =		0;
	res =		1;
	counter =	1;
	while (argv[j])
	{
		counter = 1;
		i = 0;
		while (argv[j][i])
		{
			++counter;
			++i;
		}
		if (counter != 9)
			res = -1;
		++j;
	}
	return res;
}

int	check_rows_lenth_and_name(char **argv)
{
	int	res;
	char	*name;
	int	count;

	res =	1;
	count =	0;
	name =	"checkers";
	while (name[count])
	{
		if (name[count] != argv[0][count + 2])
			res = -1;
		++count;
	}
	res = check_lenth(++argv);
	return (res);

}

int	check(int argc, char **argv)
{
	int	res;

	res =	1;
	if (argc == 9)
	{
		if ((check_checks_sign(argv) < 0) || (check_checks_location(argv) < 0) || (check_rows_lenth_and_name(argv) < 0))
		{
			res = -1;
		}
		else
		{
			res = 1;
		}
	}
	else
	{
		res = -1;
	}
	return (res);
}

char *finding_eated_way(int j, int i, char **argv, char *way, int counter_way)
{
	char		*b;
	char		*hyphen;
	char		*char_index;
	char		*int_index;
	char		*dot;

	dot =		".";
	char_index =	"ABCDEFGH";
	int_index =	"12345678";
	b =		"b";
	hyphen =	"-";
	if (!((argv[j + 1][i - 1] != b[0]) || (argv[j + 1][i + 1] != b[0])) && counter_way < 3)
	{
		return (way);
	}
	if (argv[j + 1][i - 1] == b[0])
	{
		argv[j + 1][i - 1] = dot[0];
		ft_putnbr(1);
		j = j + 2;
		i = i - 2;
		if ((i < 0 && i > 7) && (j < 0 && j > 7))
			return (way);
		way[counter_way++] = hyphen[0];
		way[counter_way++] = char_index[j];
		way[counter_way++] = int_index[i];
	}
	if (argv[j + 1][i + 1] == b[0])
	{
		argv[j + 1][i + 1] = dot[0];
		ft_putnbr(1);
		ft_putnbr(2);
		j = j + 2;
		i = i + 2;
		if ((i < 0 && i > 7) && (j < 0 && j > 7))
			return (way);
		way[counter_way++] = hyphen[0];
		way[counter_way++] = char_index[j];
		way[counter_way++] = int_index[j];
	}
	if ((argv[j - 1][i + 1] == b[0]) && (counter_way > 3))
	{
		argv[j - 1][i + 1] = dot[0];
		ft_putnbr(1);
		ft_putnbr(3);
		j = j + 2;
		j = j - 2;
		if ((i < 0 && i > 7) && (j < 0 && j > 7))
			return (way);
		way[counter_way++] = hyphen[0];
		way[counter_way++] = char_index[j];
		way[counter_way++] = int_index[j];
	}
	if ((argv[j - 1][i - 1] == b[0]) && (counter_way > 3))
	{
		argv[j - 1][i - 1] = dot[0];
		ft_putnbr(1);
		ft_putnbr(4);
		j = j + 2;
		j = j - 2;
		if ((i < 0 && i > 7) && (j < 0 && j > 7))
			return (way);
		way[counter_way++] = hyphen[0];
		way[counter_way++] = char_index[j];
		way[counter_way++] = int_index[j];
	}

	return (way);
}

char	*find_w(char **argv, char *int_index, char *char_index, int counter_way)
{
	int	j;
	int	i;
	char	*way;
	char	*white_check;

	white_check =	"w";
	j =		0;
	i =		0;
	way =		(char*)malloc(24 * sizeof(char));
	while (j != 8)
	{
		i = 0;
		while (i != 8)
		{
			if (argv[j][i] == white_check[0])
			{
				way[counter_way++] = char_index[j];
				way[counter_way++] = int_index[i];
				way = finding_eated_way(j, i, argv, way, counter_way);
			}
			++i;
		}
		++j;
	}
	return (way);
}

char	*get_right_way(char **argv)
{
	char		*int_index;
	char		*char_index;
	char		*location_w;
	int		counter_way;

	counter_way =	0;
	int_index =	"12345678";
	char_index =	"ABCDEFGH";
	location_w =	find_w(argv, int_index, char_index, counter_way);
	counter_way = counter_way + 2;
	/*eated_way = finding_eated_way(argv, location_w, int_index, char_index, counter_way);*/
	return (location_w);
}

int		main(int argc, char **argv)
{
	if (check(argc, argv) < 0)
		ft_putstr("Error\0");
	else
		ft_putstr(get_right_way(++argv));
	return (0);
}
