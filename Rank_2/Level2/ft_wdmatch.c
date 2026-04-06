#include <unistd.h>


int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;

	if (ac == 3)
	{
		while (av[2][j])
		{
			if (av[1][i] == av[2][j])
				i++;
			j++;
		}
		if (av[1][i] == '\0')
		{
			i = 0;
			while (av[1][i])
			{
				write(1, &av[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}

// int main(int ac, char **av)
// {
//     if (ac == 3)
//     {
//         const char *s1 = av[1];
//         const char *s2 = av[2];
//         int len = 0, i = 0;
        
//         while (s1[len])
//             len++;
        
//         // checking all characters of s1 in s2
//         while (i < len && *s2)
//         {
//             // next line checks if current s1 char is
//             // equal to s2 char, after the comparison is
//             // done, we increment the s2 pointer
//             // even if the condition doesn't match
//             // if the condition match, we increment i to
//             // check for next s1 char
//             if (s1[i] == *s2++)
//                 i++;
//         }
//         if (i == len)
//             write(1, s1, len);
//     }
//     write(1, "\n", 1);
//     return (0);
// }