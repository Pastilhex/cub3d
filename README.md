# Cub3D
Cub3D - My first RayCaster with miniLibX

<p align="center">
  <img src="https://img.shields.io/github/languages/top/pastilhex/cub3d?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/score-125%20%2F%20125-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-finished-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/pastilhex/cub3d?color=#FFFFFF&style=flat-square" />
</p>
<p align="center">
  <img src="https://github.com/Pastilhex/cub3d/blob/main/README/005.gif" width="500" />
</p>

### 🤝 Authorship - Collaborative Work
> This project is based on sharing knowledge and experiences throughout the entire process of understanding the MinilibX library and consecutive implementation in cub3d :)

- [Ivo Marques](https://github.com/Pastilhex) - **ialves-m**
- [João Almeida](https://github.com/joaoalme) - **joaoalme**

## Table of Contents

- [About](#about)
- [Summary](#summary)
- [Features](#features)
- [Maps & Parser](#maps--parser)
- [Drawing](#drawing)
- [Installation](#installation)
- [Usage](#usage)
- [Disclaimer](#disclaimer)

## About

Cub3D is a project that is part of curriculum 42 with the aim of learning the concepts of raycasting. For this project we used the MinilibX library. MinilibX is a small library which implements some basic functions that allow you to quickly open a window and to draw within it. More specifically, it’s an abstraction of the “X Window System” for Unix platforms.

[Click here](https://github.com/Pastilhex/cub3d/blob/main/subject/en.subject.pdf) to access the complete subject of this project.

## Summary

This project was inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. He enabled us to explore ray-casting. Our goal was to make a dynamic view inside a maze, in which we had to find our way.

### Features

- This project’s objectives were similar to all in this first year’s objectives: Rigor, use of C, use of basic algorithms, information research.
- As a graphic design project, cub3D allowed us to improve our skills in controlling and developing windows, colors, events, filling shapes.
- A deep understanding in the development of RayCasting as the first years of 3D gaming evolution.

### Maps && Parser
The maps used in this project are the main root for the graphics design. Based in the map parsed information we can extract the textures, the sky and ground colors and the map structure which will be playable ground.

### Drawing
In Cub3d the main objective it's to translate a string map into a 3D game. With the implementation of miniLibX we were able to design all the pixels requirements for the Raycasting technique. [Raycast](https://en.wikipedia.org/wiki/Ray_casting) 

At first we started with some simple tests to understand how our ft_put_pixel function worked. Pixels are painted according to coordinates.
<img src="https://github.com/Pastilhex/cub3d/blob/main/README/002.png" width="400" />

After some tests, we moved on to the first contact with printing several vertical lines. This is the basic principle of Raycasting. At this stage we draw the first part of the project, which is the sky and the ground.
<img src="https://github.com/Pastilhex/cub3d/blob/main/README/003.png" width="400" />

The image and the space through which we can navigate is generated based on a map of characters that identify the walls, the free space through which we can walk and some sprites spread across the map.
<img src="https://github.com/Pastilhex/cub3d/blob/main/README/006.png" width="400" />

After converting the character map, through the Raytracing process, to a graphical environment, we obtained the first satisfactory results where we were able to apply mobility through the hooks events of the miniLibX library.
<img src="https://github.com/Pastilhex/cub3d/blob/main/README/005.gif" width="400" />



## Installation

To install and run Cub3D, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:Pastilhex/cub3d.git
2. Navigate to the project directory:
   ```bash
   cd cub3d
3. Compile the main program by running the following command:
   ```bash
   make
4. Compile the bonus program by running the following command:
   ```bash
   make bonus

## Usage 
To use Cub3D, follow these steps:

1. Execute the main program
   ```bash
   ./cub3d mandatory/maps/dungeon.cub
2. Execute the bonus program
   ```bash
   ./cub3d_bonus bonus/maps/wolfenstein.cub

Now you can use the following keys to play :) 
  > WASD to move, 
  > <- (left) and -> (right) arrow keys to look


## Disclaimer

Maybe you could notice a different coding style.
At 42 we need to follow some rules according to the coding standard of the school such as:

```bash
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
[Click here](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf) to read the norm file of 42 school. 
