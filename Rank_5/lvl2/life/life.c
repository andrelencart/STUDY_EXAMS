#include "life.h"

void printmap(t_life life){
	for (int hy = 0; hy < life.y; hy++){
		for(int hx = 0; hx < life.x; hx++){
			write(1, &life.map[hy][hx], 1);
		}
		write(1, "\n", 1);
	}
}

void readmap(t_life life) {
	char buf;
	int temp_y = 0;
	int temp_x = 0;

	while (read(0, &buf, 1)){
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

int count_neib(t_life life, int hy, int hx) {
	int neib = 0;
	if (hx + 1 < life.x && life.map[hy][hx + 1] == '0')
		neib++;
	if (hx - 1 >= 0 && life.map[hy][hx - 1] == '0')
		neib++;
	if (hy + 1 < life.y && life.map[hy + 1][hx] == '0')
		neib++;
	if (hy - 1 >= 0 && life.map[hy - 1][hx] == '0')
		neib++;
	if ((hx + 1 < life.x && hy + 1 < life.y) && life.map[hy + 1][hx + 1] == '0')
		neib++;
	if ((hx - 1 >= 0 && hy - 1 >= 0) && life.map[hy - 1][hx - 1] == '0')
		neib++;
	if ((hy + 1 < life.y && hx - 1 >= 0) && life.map[hy + 1][hx - 1] == '0')
		neib++;
	if ((hy - 1 >= 0 && hx + 1 < life.x) && life.map[hy - 1][hx + 1] == '0')
		neib++;
	return neib;
}

void free_struct(t_life *life){
	for (int y = 0; y < life->y; y++){
		if (life->map[y])
			free(life->map[y]);
	}
	if (life->map)
		free(life->map);
}

int play_game(t_life *life){
	char **temp_map = calloc(sizeof(char **), life->y + 1);
	for (int hy = 0; hy < life->y; hy++){
		temp_map[hy] = calloc(sizeof(char), life->x + 1);
		for(int hx = 0; hx < life->x; hx++){
			temp_map[hy][hx] = ' ';
		}
	}
	for (int hy = 0; hy < life->y; hy++){
		for(int hx = 0; hx < life->x; hx++){
			int neib = count_neib(*life, hy, hx);
			if (life->map[hy][hx] == '0'){
				if (neib < 2 || neib > 3)
					temp_map[hy][hx] = ' ';
				else
					temp_map[hy][hx] = '0';
			}
			else{
				if (neib == 3)
					temp_map[hy][hx] = '0';
			}
		}
	}
	free_struct(life);
	life->map = temp_map;
	return 0;
}


int main(int ac, char **av) { // Needs checks in calloc for allocatio errors
	if (ac != 4){
		return 1;
	}

	t_life life={atoi(av[1]), atoi(av[2]) , atoi(av[3]), NULL, 0};
	life.map = calloc(sizeof(char **), life.y + 1);
	for (int hy = 0; hy < life.y; hy++){
		life.map[hy] = calloc(sizeof(char), life.x + 1);
		for(int hx = 0; hx < life.x; hx++){
			life.map[hy][hx] = ' ';
		}
	}
	readmap(life);
	// printmap(life);
	for (int i = 0; i < life.it; i++){
		play_game(&life);
	}
	printmap(life);
	free_struct(&life);

	return 0;
}