import subprocess
import os

def build_parser():
    flex_command = ["flex", "-o", "src/shell/parser/lex.yy.c", "src/shell/parser/lexer.l"]
    bison_command = ["bison", "-d", "-o", "src/shell/parser/parser.tab.c", "src/shell/parser/parser.y"]

    subprocess.run(flex_command)
    subprocess.run(bison_command)

if __name__ == "__main__":
    build_parser()
