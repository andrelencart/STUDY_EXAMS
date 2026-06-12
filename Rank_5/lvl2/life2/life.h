#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_life {
	int x;
	int y;
	int it;
	char **map;
	int pen;
} t_life;