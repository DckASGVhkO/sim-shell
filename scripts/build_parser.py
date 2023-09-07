from sys import stderr

import os
import subprocess

def run_cmd(command):
    try:
        result = subprocess.run(command, check=True, shell=True, stderr=subprocess.PIPE,
                                stdout=subprocess.PIPE)
        print(result.stdout.decode())
    except subprocess.CalledProcessError as e:
        print(f"{command}: Command failed\n\n{e.stderr.decode()}", file=stderr)
        exit(1)

def build_parser():
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    parser_dir = os.path.join(root, "src", "shell", "parser")

    os.chdir(parser_dir)

    build_dir = os.path.join(root, "build")
    os.makedirs(build_dir, exist_ok=True)

    run_cmd("ragel -G2 -o " + os.path.join(build_dir, "lexer.c") + " lexer.rl")
    run_cmd("byacc -d -o " + os.path.join(build_dir, "parser.c") + " parser.y")

    os.chdir(build_dir)
    run_cmd("gcc -Wall -Wextra -O3 -flto -o sh_parser lexer.c parser.c -I" + parser_dir)

if __name__ == "__main__":
    build_parser()
