import math

points = []

def get_radian(source, destination):
    dx = destination[0] - source[0]
    dy = destination[1] - source[1]
    if dy == 0:
        if dx > 0:
            return 0
        else:
            return math.pi
    if dx == 0:
        if dy > 0:
            return math.pi / 2
        else:
            return math.pi * 1.5
    if dy > 0:
        if dx > 0:
            return math.atan(float(dy) / float(dx))
        else:
            return (math.pi / 2.0) + math.atan(float((-1 * dx)) / float(dy))
    else:
        if dx > 0:
            return (2 * math.pi) - math.atan(float((-1 * dy)) / float(dx))
        else:
            return math.pi + math.atan(float(dy) / float(dx))
