matrix = [[0] * 2187 for _ in range(2187)]

N = int(input())


def print_matrix(n):
    for y in range(n):
        for x in range(n):
            print(matrix[y][x], end="")
        print()


def gen_star_pattern(n, y=0, x=0, is_space=False):
    if n == 1:
        matrix[y][x] = " " if is_space else "*"
        return

    next_n = int(n / 3)

    for current_y in range(3):
        for current_x in range(3):
            gen_star_pattern(
                next_n,
                (current_y * next_n) + y,
                (current_x * next_n) + x,
                (current_x == 1 and current_y == 1) or is_space
            )
        current_y += 1


gen_star_pattern(N)
print_matrix(N)
