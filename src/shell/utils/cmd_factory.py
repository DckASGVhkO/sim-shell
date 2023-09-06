from .cat_cmd import CatCmd
from .cd_cmd import CdCmd
from .cp_cmd import CpCommand
from .echo_cmd import EchoCmd
from .grep_cmd import GrepCmd
from .head_cmd import HeadCmd
from .ls_cmd import LsCmd
from .mkdir_cmd import MkdirCommand
from .mv_cmd import MvCommand
from .pwd_cmd import PwdCmd
from .rm_cmd import RmCommand
from .shell_cmd import ShellCmd
from .tail_cmd import TailCmd

class CmdFactory:
    def create(self, user_input) -> ShellCmd:
        if user_input.startswith("cat"):
            return CatCmd()
        elif user_input.startswith("cd"):
            return CdCmd()
        elif user_input.startswith("cp"):
            return CpCommand()
        elif user_input.startswith("echo"):
            return EchoCmd()
        elif user_input.startswith("grep"):
            return GrepCmd()
        elif user_input.startswith("head"):
            return HeadCmd()
        elif user_input.startswith("ls"):
            return LsCmd()
        elif user_input.startswith("mkdir"):
            return MkdirCommand()
        elif user_input.startswith("mv"):
            return MvCommand()
        elif user_input.startswith("pwd"):
            return PwdCmd()
        elif user_input.startswith("rm"):
            return RmCommand()
        elif user_input.startswith("tail"):
            return TailCmd()
        else:
            raise ValueError("Invalid command")
