#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	if (n == 0 || dst == src)
		return (dst);
	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		i += 1;
	}
	return (dst);
}
