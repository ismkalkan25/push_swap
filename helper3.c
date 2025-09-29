static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

long	ft_atoir(const char *nptr)
{
	int				i;
	int				sign;
	long			res;

	i = 0;
	sign = 1;
	res = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i++] - '0');
	}
	return ((res * sign));
}