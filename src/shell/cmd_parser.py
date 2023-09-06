import re
from .shell_cmd import ShellCmd
from .cmd_factory import CmdFactory

class CmdParser:
    def __init__(self):
        self.factory = CmdFactory()

    def parse(self, user_input: str) -> ShellCmd:
        tokens = re.split(r'\s+', user_input.strip())
        cmd = tokens[0]

        if cmd == "ls":
            return self.factory.create("ls")
        elif cmd == "cd":
            return self.factory.create(f"cd {tokens[1]}")
        elif cmd == "echo":
            return self.factory.create(f"echo {' '.join(tokens[1:])}")
        else:
            raise ValueError("Invalid cmd")
