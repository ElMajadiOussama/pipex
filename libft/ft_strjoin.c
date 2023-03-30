#include "libft.h"
#include<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		exit (EXIT_FAILURE);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		printf("\n%c\n", str[i]);
		// write(1, str[i], 1);
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int main()
// {
//     printf("%s\n", ft_strjoin("hello", "hello"));
//     return (0);
// }
