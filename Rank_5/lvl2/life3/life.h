#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_life {
	int x;
	int y;
	int it;
	char **map;
	int pen;
} t_life;
