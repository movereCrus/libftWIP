#include <stddef.h>

int ft_strncmp(char *str1, char *str2, size_t count)
{
	int diff;
	int i;

	diff = 0;
	i = 0;
	while (diff == 0 && count != 0 && (str1[i] != '\0' || str2[i] != '\0'))
	{
		printf("%d\n", i);
		diff = str1[i] - str2[i];
		i++;
		count--;
	}
	return (diff);
}