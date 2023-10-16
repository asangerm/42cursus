
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%d\n", ft_printf(" %x %x \n", 0, 0));
	printf("%d\n", printf(" %x %x \n", 0, 0));
}
