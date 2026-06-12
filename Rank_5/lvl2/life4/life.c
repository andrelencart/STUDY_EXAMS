#include "life.h"

void printmap(t_life life){
	for(int h = 0; h < life.y; h++){
		for(int w = 0; w < life.x; w++){
			putchar(life.map[h][w]);
		}
		putchar('\n');
	}
}

void free_struct(t_life *life) {
	for(int y = 0; y < life->y; y++){
		if (life->map[y])
			free(life->map[y]);
	}
	if (life->map)
		free(life->map);
}

void readmap(t_life life){
	char buf;
	int temp_y = 0;
	int temp_x = 0;

	while(read(0, &buf, 1)){
		switch (buf)
		{
		case 'w':
			if (temp_y - 1 >= 0)
				temp_y--;
			break;
		case 'a':
			if (temp_x - 1 >= 0)
				temp_x--;
			break;
		case 's':
			if (temp_y + 1 < life.y)
				temp_y++;
			break;
		case 'd':
			if (temp_x + 1 < life.x)
				temp_x++;
			break;
		case 'x':
			life.pen = !(life.pen);
			break;
		}
		if (life.pen)
			life.map[temp_y][temp_x] = '0'; 
	}
}

int count_neib(t_life life, int h, int w){
	int neib = 0;

	if (w + 1 < life.x && life.map[h][w + 1] == '0')
		neib++;
	if (w - 1 >= 0 && life.map[h][w - 1] == '0')
		neib++;
	if (h + 1 < life.y && life.map[h + 1][w] == '0')
		neib++;
	if (h - 1 >= 0 && life.map[h - 1][w] == '0')
		neib++;
	if ((h + 1 < life.y && w + 1 < life.x) && life.map[h + 1][w + 1] == '0')
		neib++;
	if ((h - 1 >= 0 && w - 1 >= 0) && life.map[h - 1][w - 1] == '0')
		neib++;
	if ((h + 1 < life.y && w - 1 >= 0) && life.map[h + 1][w - 1] == '0')
		neib++;
	if ((h - 1 >= 0 && w + 1 < life.x) && life.map[h - 1][w + 1] == '0')
		neib++;
	return neib;
}

int play_game(t_life *life) {
	char **temp_map = calloc(sizeof(char **), life->y + 1);
	if (!temp_map)
		return 1;
	for(int h = 0; h < life->y; h++){
		temp_map[h] = calloc(sizeof(char), life->x + 1);
		if (!temp_map[h]){
			free_struct(life);
			return 1;
		}
		for(int w = 0; w < life->x; w++)
			temp_map[h][w] = ' ';
	}
	for(int h = 0; h < life->y; h++){
		for(int w = 0; w < life->x; w++){
			int neib = count_neib(*life, h, w);
			if (life->map[h][w] == '0'){
				if (neib < 2 || neib > 3)
					temp_map[h][w] = ' ';
				else
					temp_map[h][w] = '0';
			}
			else{
				if (neib == 3)
					temp_map[h][w] = '0';
			}
		}
	}
	free_struct(life);
	life->map = temp_map;
	return 0;
}


int main(int ac, char **av) {
	if (ac != 4)
		return 1;
	
	t_life life = {atoi(av[1]), atoi(av[2]), atoi(av[3]), NULL, 0};
	life.map = calloc(sizeof(char **), life.y + 1);
	if (!life.map)
		return 1;
	for(int h = 0; h < life.y; h++){
		life.map[h] = calloc(sizeof(char), life.x + 1);
		if (!life.map[h]){
			free_struct(&life);
			return 1;
		}
		for(int w = 0; w < life.x; w++){
			life.map[h][w] = ' ';
		}
	}
	readmap(life);
	for(int i = 0; i < life.it; i++){
		if (play_game(&life) == 1)
		return 1;
	}
	printmap(life);
	free_struct(&life);
	return 0;
}