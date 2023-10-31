# Cub3D
Cub3D - My first RayCaster with miniLibX

<p align="center">
  <img src="https://img.shields.io/github/languages/top/pastilhex/cub3d?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/score-125%20%2F%20125-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/badge/status-finished-success?color=#FFFFFF&style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/pastilhex/cub3d?color=#FFFFFF&style=flat-square" />
</p>
<p align="center">
  <img src="https://github.com/ziliolu/42_minishell/blob/main/info/42minishell.gif" width="500" />
</p>

### 🤝 Authorship - Collaborative Work
> This project is based on sharing knowledge and experiences throughout the entire process of understanding the MinilibX library and consecutive implementation in cub3d :)

- [Ivo Marques](https://github.com/Pastilhex) - **ialves-m**
- [João Almeida](https://github.com/joaoalme) - **joaoalme**

## Table of Contents

- [About](#about)
- [Lexer](#lexer)
- [Parser](#parser)
- [Pipes](#pipes)
- [Installation](#installation)
- [Usage](#usage)
- [Testers](#testers)
- [Disclaimer](#disclaimer)

## About

Cub3D is a project that is part of curriculum 42 with the aim of learning the concepts of raycasting. For this project we used the MinilibX library. MinilibX is a small library which implements some basic functions that allow you to quickly open a window and to draw within it. More specifically, it’s an abstraction of the “X Window System” for Unix platforms.

[Click here](https://github.com/Pastilhex/cub3d/blob/main/subject/en.subject.pdf) to access the complete subject of this project.

## Summary

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

### Features

- This project’s objectives were similar to all in this first year’s objectives: Rigor, use of C, use of basic algorithms, information research.
- As a graphic design project, cub3D allowed us to improve our skills in controlling and developing windows, colors, events, filling shapes.
- A deep understanding in the development of RayCasting as the first years of 3D gaming evolution.

### Map && Parse
The maps used in this project are the main root for the graphics design. Based in the map parsed information we can extract the textures, the sky and ground colors and the map structure which will be playable ground.

### Draw
In Cub3d the main objective it's to translate a string map into a 3D game. With the implementation of miniLibX we were able to design all the pixels requirements for the Raycasting technique. [Raycast](https://en.wikipedia.org/wiki/Ray_casting) 

Example command:
```bash
ls -l | wc > "file1" >> 'file2' << eof
```
### Identifying Tokens

Lexer looks for specific patterns or special characters that help identify different parts of your command. It groups these parts together to create individual tokens. Let's see how it breaks down the example command:

<img src="https://github.com/ziliolu/42_minishell/blob/main/info/lexer.png?raw=true"/>

### How does tokenization work? 🤔

| Status         | Description                                                                                     | Example                                               |
|----------------|-------------------------------------------------------------------------------------------------|-------------------------------------------------------|
| `general`        | Represents the general/default parsing mode outside any quotes.                                 | Parsing a regular command or options.                |
| `in_dquote`    | Represents the parsing mode when inside double quotes (").                                      | Parsing a string where variables are expanded: "Hello, $name!"  |
| `in_squote`    | Represents the parsing mode when inside single quotes (').                                      | Parsing a string as-is, where variables are not expanded: 'Hello, $name!' |

| Token Type  | Description                                             | Example      |
|-------------|---------------------------------------------------------|--------------|
| `word`        | Represents command names, options, and file names      | 'ls', '-l', 'wc', 'eof' |
| `env`         | Represents environment or local variables              | '$USER', '$HOME', '$name' | 
| `w_space`     | Represents white spaces used for command separation    | N/A          |
| `pipeline`    | Represents the pipe symbol used to connect commands    | ' \| '       |
| `redir_out`   | Represents the output redirection                      | '>'          |
| `d_redir_out` | Represents the double output redirection               | '>>'         |
| `redir_in`    | Represents the input redirection                       | '<'          |
| `heredoc`     | Represents heredoc symbol                              | '<<'         |


### Parser
Once the input is tokenized, the parser's job is to recognize the boundaries between separate commands. In our example, we have three commands: `ls -l`, `grep Make`, `wc`, and the redirects associated with wc.

The parser identifies each command based on the presence of the `pipe symbol '|'`. It groups the tokens before and after each pipe to form individual commands.

For each command, the parser creates a data structure to represent it. In our case, we use a `t_command` structure. Take a look at the table below:

| Command Number | Type       | Command Arguments      | Redirects                             |
|----------------|------------|------------------------|---------------------------------------|
| 0              | CMD        | cmd->args[0] = "ls"    | No redirects                          |
|                |            | cmd->args[1] = "-l"    |                                       |
|                |            |                        |                                       |
| 1              | PIPELINE        | cmd->args[0] = "   \| "  | No redirects                          |
|                |            |                        |                                       |
| 2              | CMD        | cmd->args[0] = "grep"  | No redirects                          |
|                |            | cmd->args[1] = "Make"  |                                       |
|                |            |                        |                                       |
| 3              | PIPELINE        | cmd->args[0] = "  \|  "  | No redirects                          |
|                |            |                        |                                       |
| 4              | CMD        | cmd->args[0] = "wc"    | redir_out - "file1"                   |
|                |            |                        | d_redir_out - 'file2'                 |
|                |            |                        | redir_in - "eof"                      |


> **⚠️** Redirects are elements that belong to the specific command in
> which they are found. In the given example, the redirects are associated
> with the `wc` command.They are not new commands and will be represented
> by the structure's array `t_redirs` found inside `t_command`.

### Pipes

In a shell, `pipes (|)` are a powerful feature that allow you to chain multiple commands together, where the output of one command becomes the input of the next command. This allows for more complex and versatile command executions. In our Minishell project, we've implemented this functionality, and here's how it works:

#### How Pipes Work
Pipes are used to `connect the standard output of one command to the standard input of another command`. This allows you to create a pipeline of commands where the output of the first command is fed as input to the second command, and so on.

For example, consider the following command:
```bash
cat file1.txt | wc
```
> In this command, the output of the `cat file1.txt` command is piped (|)
> as input to `wc` command. The wc command then analyzes this input and
> provides three counts: the number of lines, words, and characters present in the content.

#### How Pipes Connect Commands: An Illustrated Explanation

<p align="center">
  <img src="https://www.codequoi.com/wp-content/uploads/2022/10/shell_pipe_en.drawio.png" width="500" />
</p>

When using pipes (`|`) to connect commands in Minishell, you create a seamless bridge for data flow. Here's a breakdown of how it works using the command sequence `cat file1.txt | wc`:

1. **Pipe Creation:**
   Minishell establishes a "pipe" between the commands. This pipe has two ends: the `write end` (fd[0]) and the `read end` (fd[1]).

2. **Write End of Pipe:**
   - The output of the first command, `cat file1.txt`, is directed to the write end of the pipe.
   - Data flows through the pipe, waiting for the next command.

3. **Read End of Pipe:**
   - The second command, `wc`, reads from the read end of the pipe.
   - It treats the incoming data as if it were entered directly as input.

4. **Data Flow:**
   - As Command 1 executes and generates output, it flows into the write end of the pipe.
   - Command 2 processes this data as input, utilizing the read end of the pipe.

The `dup2` function manages these connections:
- For Command 1, `dup2(pipe_write_end, STDOUT_FILENO)` duplicates the write end to the command's standard output.
- For Command 2, `dup2(pipe_read_end, STDIN_FILENO)` duplicates the read end to the command's standard input.

## Installation

To install and run Minishell, follow these steps:- 

1. Clone the repository:
   ```bash
   git clone git@github.com:ziliolu/42_minishell.git
2. Navigate to the project directory:
   ```bash
   cd 42_minishell
3. Compile the program by running the following command:
   ```bash
   make 
   
## Usage 
To use Minishell, follow these steps:

1. Execute the program
   ```bash
   ./minishell
2. Now you can use as a normal shell and execute the commands you want such as `ls`, `mkdir`, `cd`, `pwd`, `cat`, `echo` and much more :) 

## Testers 

1. [Minishell Test List](https://github.com/ziliolu/42_minishell/blob/main/info/tests.md) provides a detailed list for testing the program with different number of commands, quotes, pipes and redirections.

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

