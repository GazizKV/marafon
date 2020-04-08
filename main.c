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
	/*ft_putchar('\n');*/
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
	int res;

	i  = 0;
	index = 1;
	while (index < 9)
	{
		i = 0;
		while(i < 8)
		{
			if ((check_sign_checks(argv[index][i]) < 0) && (res = check_ckecks_location(index, i) < 0))
			{
				return (-1);
			}
			++i;
		}
		++index;
	}
	return (1);
}

int ft_check_loc(char loc)
{
	char	*a, *b;
       
	a =	"ACEG";
	b =	"BDFH";
	if ((loc == b[0] ) || ())
}

int check_checks_location(char **argv)
{
	int res;

	res = 0;
	++argv;

	if (check_loc(argv) < 0)
	{
		ft_putstr("asdasdasd");
		ft_putstr(*argv);
		res = (-1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	ft_putnbr(argc);
	ft_putchar('\n');
	if (argc == 9)
	{
		if ((check_checks_sign(argv) < 0) || (check_checks_location(argv) < 0))
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
