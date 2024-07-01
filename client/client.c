#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		numb = numb * 10 + nptr[i] - '0';
		++i;
	}
	return (sign * numb);
}

void	ft_putnbr(unsigned int n)
{
	char	c;

	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	sig_sender(unsigned char c, int id)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & 1) == 0)
			kill(id, SIGUSR1);
		else
			kill(id, SIGUSR2);
		usleep(1000);
		c = c >> 1;
		++i;
	}
}

int	main(int argc, char **argv)
{
	int				i;
	int				id;

	i = 0;
	if (argc <= 2)
	{
		write(1, "Sxal argumentneri qanak\n", 25);
		return (0);
	}
	id = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		sig_sender(argv[2][i], id);
		++i;
	}
	ft_putnbr((unsigned int)i);
	return (0);
}
