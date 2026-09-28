#include <stdio.h>
//hello world

void	nothing()
{
	return ;
}

int main()
{
	//hello to the world
	nothing();
	char	*str = "#include <stdio.h>%c//hello world%c%cvoid	nothing()%c{%c	return ;%c}%c%cint main()%c{%c	//hello to the world%c	nothing();%c	char	*str = %c%s%c;%c	printf(str, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);%c}%c";
	printf(str, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);
}
