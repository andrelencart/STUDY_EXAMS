#pragma once

#include <stdlib.h>
#include <unistd.h>

// echo "sxdd" | ./a.out 3 3 0 
// o que quer dizer:
// 3 - width
// 3 - height
// 0 - how many times the game loop is runned
// echo "sxdd" - How the map is firstly draw


typedef struct s_life {
	int x;
	int y;
	int it;
	char **map;
	int pen;

}	t_life;
