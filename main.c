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

int main(int argc, char **argv)
{
	char error[5] = "Error";

	if (argc == 7)
	{
		print_arr(argv);
		ft_putstr("w");
	}
	else
	{
		ft_putstr(error);
		ft_putstr(argv[2]);
	}
	return (0);
}
