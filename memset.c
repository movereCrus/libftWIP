#include <stddef.h>
void *ft_memset(void *buf, int ch, size_t count)
{
	unsigned char *ptr;

	ptr = (unsigned char *)buf;
	while (count > 0)
	{
		*ptr = (unsigned char)ch;
		ptr++;
		count--;
	}
	return (buf);
}