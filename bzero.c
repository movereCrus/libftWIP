#include <stddef.h>
void ft_bzero(void *buf, size_t count)
{
	unsigned char *ptr;

	ptr = (unsigned char *)buf;
	while (count > 0)
	{
		*ptr = '\0';
		ptr++;
		count--;
	}
}