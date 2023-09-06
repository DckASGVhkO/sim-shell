from abc import ABC, abstractmethod

class ShellCmd(ABC):
    @abstractmethod
    def exec(self):
        pass
