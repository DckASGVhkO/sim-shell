from .cmd_parser import CmdParser

def main():
    parser = CmdParser()
    
    while True:
        user_input = input("> ")
        
        if user_input == "exit":
            break
        
        try:
            cmd = parser.parse(user_input)
            cmd.exec()
        except ValueError as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()
