int	comberzor(char *str)
{	char *number;
	int count= 1;
	int ans = 0;

	number = str;
	while (*str >= '0' && *str <= '9')
	{
		*str++;
		count += 10;
	}
	while(count > 1)
	{
		ans += *number * count;
	}
	return ans;
}

int	*ft_atoi_index(char *str)
{
	int atr[4];
	char *number;
	int count;

	number = str;
	if(*str >= '0' && *str <= '9')
		*atr = comberzor(*str);

   return (atr);
}
int main(void)
{
	int *a = ft_atoi_index("123");
}