#include <vector>
#include <iostream>

static const int INPUT = 347991;
int matrix[50][50] = { 0 };

enum directions {
	RIGHT,
	UP,
	LEFT,
	DOWN
};

void main() {
	int step_length = 1;
	int step_sequence = 0;
	int steps_in_sequence = 0;
	int step_value = 1;
	int param_x = 25;
	int param_y = 25;
	matrix[param_y][param_x] = 1;
	directions direction = RIGHT;
	while (step_value <= INPUT) {
		steps_in_sequence++;
		switch (direction) {
		case RIGHT:
			param_x++;
			break;
		case UP:
			param_y++;
			break;
		case LEFT:
			param_x--;
			break;
		case DOWN:
			param_y--;
			break;
		}
		matrix[param_y][param_x] = matrix[param_y-1][param_x] + matrix[param_y-1][param_x-1] + matrix[param_y][param_x-1] + matrix[param_y+1][param_x-1] + matrix[param_y+1][param_x] + matrix[param_y+1][param_x+1] + matrix[param_y][param_x+1] + matrix[param_y-1][param_x + 1];
		step_value = matrix[param_y][param_x];
		if (steps_in_sequence == step_length) {
			step_sequence++;
			steps_in_sequence = 0;
			switch (direction) {
			case RIGHT:
				direction = UP;
				break;
			case UP:
				direction = LEFT;
				break;
			case LEFT:
				direction = DOWN;
				break;
			case DOWN:
				direction = RIGHT;
				break;
			}
		}
		if (step_sequence == 2) {
			step_sequence = 0;
			step_length++;
		}
	}
	int steps_number = abs(param_x) + abs(param_y);
	std::cout << param_x << param_y << param_x + param_y << std::endl;
}