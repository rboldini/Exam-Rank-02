#include <unistd.h>
#include <stdarg.h>

enum {
	DECIMAL = 10,
	HEXADECIMAL = 16
};

int ft_putstr(char *string) {
	int i = 0;
	if (!string)
		write(1, "(null)", 6);
	while (string[i]) {
		write(1, string + i, 1);
		i++;
	}
	return i;
}

int ft_putnbr(unsigned int d, int base) {
	int count = 0;
	char *base_set = "0123456789abcdef";

	if (d / base > 0)
		count += ft_putnbr(d / base, base);
	count += write(1, &base_set[d % base], 1);
	return count;
}

int ft_printf(char *string, ...) {
	int count = 0;
	va_list args;
	int n;

	va_start(args, string);
	while (*string) {
		if (*string == '%') {
			string++;
			if (*string == 's')
				count += ft_putstr(va_arg(args, char*));
			if (*string == 'd') {
				if ((n = va_arg(args, int)) < 0) {
					count += write(1, "-", 1);
					n *= -1;
				}
				count += ft_putnbr(n, DECIMAL);
			}
			if (*string == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), HEXADECIMAL);
		}
		else
			count += write(1, string, 1);
		string++;
	}
	va_end(args);
	return count;
}
