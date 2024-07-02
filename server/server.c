#include "minitalk.h"

void	ft_putnbr(unsigned int n)
{
	char	c;

	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	handler(int sig)
{
	static int				bit;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c &= ~(1 << bit);
	else if (sig == SIGUSR2)
		c |= (1 << bit);
	++bit;
	if (bit == 8)
	{
		write (1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &da, NULL);
	sigaction(SIGUSR2, &da, NULL);
	ft_putnbr(getpid());
	while (1)
		pause();
	return (0);
}
