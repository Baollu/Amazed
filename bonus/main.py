#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## map visualizer
## File description:
## map visualizer
##

import pygame
from sys import argv

if len(argv) != 2:
    print("\nYou forgot the map")
    exit(0)


SCREEN_WIDTH = 1280
SCREEN_HEIGHT = 720
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()
running = True
pygame.font.init()
my_font = pygame.font.SysFont('Comic Sans MS', 30)
links = []
rooms = []
robots = []


def room_get_coords(name, rooms):
    for room in rooms:
        if room[0] == name:
            return room[1:3]

with open(argv[1], "r") as file_:
    f = file_.read()
f = f.split("\n")
f = f[2:]

for i in range(len(f)):
    if (f[i][0] == '#'):
        continue
    if (len(f[i].split(" ")) != 3):
        break
    line = list(f[i].split(" "))
    line[1] = int(line[1])
    line[2] = int(line[2])
    if i != 0:
        line.append(f[i-1] == "##start")
        line.append(f[i-1] == "##end")
    else:
        line += [False, False]
    rooms.append(line)

for i in range(i, len(f)):
    line = f[i]
    if (line == "#moves"):
        break
    act_rooms = line.split("-")
    if act_rooms == [""]:
        continue
    links.append([room_get_coords(act_rooms[0], rooms), room_get_coords(act_rooms[1], rooms)])

for i in range(i + 1, len(f)):
    line = f[i]
    act_robots = line.split()
    if act_robots == []:
        continue
    for i in range(len(act_robots)):
        act_robots[i] = act_robots[i][1:].split("-")
    robots.append(act_robots)

MIN_X = min(room[1] for room in rooms)
MIN_Y = min(room[2] for room in rooms)
MAX_X = max(room[1] for room in rooms) - MIN_X
MAX_Y = max(room[2] for room in rooms) - MIN_Y



def convert_coords(pos):
    pos = [pos[0] - MIN_X, pos[1] - MIN_Y]
    pos = [pos[0] * (SCREEN_WIDTH/MAX_X if MAX_X != 0 else 1), pos[1] * (SCREEN_HEIGHT/MAX_Y if MAX_Y != 0 else 1)]
    pos = [pos[0] + 100, pos[1] + 100]
    pos = [pos[0] * 0.8, pos[1] * 0.8]
    return pos

def draw_text(text, pos):
    text_surface = my_font.render(text, False, (0, 0, 0))
    screen.blit(text_surface, pos)

def draw_links(links):
    line_color = pygame.Color(255, 255, 255, 255)
    for link in links:
        start = convert_coords(link[0])
        end = convert_coords(link[1])
        pygame.draw.line(screen, line_color, start, end, width=4)

def draw_rooms(rooms):
    for room in rooms:
        room_color = [pygame.Color(180, 180, 180, 255), pygame.Color(255, 0, 0, 255), pygame.Color(0, 0, 255, 255)][room[3] + room[4]*2]
        pygame.draw.circle(screen, room_color, convert_coords(room_get_coords(room[0], rooms)), 10)

def draw_robots(robots, index_cycle):
    robots = robots[index_cycle]
    room_seen = []
    for robot in robots:
        pos = convert_coords(room_get_coords(robot[1], rooms))
        pos[1] -= 20 + 20 * room_seen.count(robot[1])
        draw_text(robot[0], pos)
        room_seen.append(robot[1])

if len(robots) == 0:
    print("\nNo solution")
    quit(0)
cycle = 0
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                cycle -= 1
            if event.key == pygame.K_RIGHT:
                cycle += 1
            if cycle < 0:
                cycle = 0
            if cycle >= len(robots):
                cycle = len(robots) - 1
    screen.fill("purple")
    draw_links(links)
    draw_rooms(rooms)
    draw_robots(robots, cycle)
    draw_text(str(cycle+1)+"/"+str(len(robots)), (10, 10))
    pygame.display.flip()
    clock.tick(10)

pygame.quit()
