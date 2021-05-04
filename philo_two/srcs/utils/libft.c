#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				neg;
	unsigned int	res;

	neg = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		if ((res > 2147483647 && neg == 1) || (res > 2147483648 && neg == -1))
			return (0);
	}
	return ((int)(res * neg));
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && ft_strlen(str) > 1)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
