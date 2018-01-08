#include <unistd.h>
#include "expertsystem.hpp"

int		brackets(char *s)
{
	char	br[128];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (s[++i])
	{
		(s[i] == '(') ? br[++j] = '(' : 0;
		(s[i] == '{') ? br[++j] = '{' : 0;
		(s[i] == '[') ? br[++j] = '[' : 0;
		if (s[i] == ')')
		{
			if (j < 0)
				break ;
			if (br[j--] == '(');
			else
				break ;
		}
		if (s[i] == '}')
		{
			if (j < 0)
				break ;
			if (br[j--] == '{');
			else
				break ;
		}
		if (s[i] == ']')
		{
			if (j < 0)
				break ;
			if (br[j--] == '[');
			else
				break ;
		}
	}
	return (j == -1 && s[i] == '\0') ? 1 : 0; 
}
