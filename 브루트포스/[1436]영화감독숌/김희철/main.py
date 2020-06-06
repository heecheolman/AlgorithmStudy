N = int(input())


def is_title(number):
    if '666' in str(number):
        return True
    return False


def get_movie_title():
    title = 0
    pre_title = 0
    while True:
        pre_title += 1
        if is_title(pre_title):
            title += 1
            if title == N:
                print(pre_title)
                return


get_movie_title()
