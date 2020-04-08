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

int print_arr(char **checkboard)
{
	int j;

	j = 0;
	while (j < 9)
	{
		ft_putstr(checkboard[j]);
		++j;
	}
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
	ft_putchar('\n');
}

int check_checks(char **argv)
{
	int i;
	char j;
	int index;

	j = 'a';
	i  = 1;
	index = 1;
	while (index < 9)
	{
		while(i < 9)
		{
			if (argv[index][i] != ("." || "w" || "b"))
				return (-1);
			if (argv[index][i] == ("w" || "b") && (((i != (2 || 4 || 6 || 8)) && (j != ("a" || "c" || "e" || "g"))) || ((i != (1 || 3 || 5 || 7)) && (j != ("b" || "d" || "f" || "h")))))
				return (-1);
			++i;
		}
		ft_putchar(j + 48);
		++index;
	}
	return (1);
}

int main(int argc, char **argv)
{
	char error[5] = "Error";

	if (argc == 9)
	{
		if (check_checks(argv) < 0)
		{
			ft_putstr(error);
		}
		/*ft_putstr("Nfff");*/
	}
	else
	{
		ft_putstr(error);
	}
	return (0);
}
