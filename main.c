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
		ft_putchar((char)(temp / size));
		temp %= size;
		size /= 10;
	}
}

int main(int argc, char **argv)
{
	char error[5] = "Error";
	int i;

	i = 0;
	while ((argc - i) != 0)
	{
		ft_putnbr(argc);
		ft_putstr("\n");
		++i;
	}
	if (argc == 8)
	{
		print_arr(argv);
		ft_putstr("w");
	}
	else
	{
		ft_putstr(error);
		ft_putstr(argv[0]);
	}
	return (0);
}
