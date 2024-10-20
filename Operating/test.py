import threading
import time
import random
from colorama import init, Fore, Back, Style

init()

class ProcessManager:
    def __init__(self):
        self.mutex = threading.Lock()
        self.processes = []

    def add_process(self, name, length):
        with self.mutex:
            self.processes.append((name, length))
            print(Fore.WHITE + f'Process {name} (length: {length}) added to the queue.' + Style.RESET_ALL)

    def run_processes(self):
        while True:
            with self.mutex:
                if len(self.processes) == 0:
                    break
                name, length = self.processes.pop(0)
            print(Fore.YELLOW + f'Running process {name} (length: {length})...' + Style.RESET_ALL)
            time.sleep(length)
            print(Fore.GREEN + f'Completed process {name}' + Style.RESET_ALL)

def main():
    process_manager = ProcessManager()

    # Generate processes with different names and lengths
    for i in range(10):
        name = f'P{i}'
        length = random.randint(1, 5)
        process_manager.add_process(name, length)

    # Create four threads to run processes
    threads = []
    for _ in range(4):
        thread = threading.Thread(target=process_manager.run_processes)
        threads.append(thread)

    # Start the threads
    for thread in threads:
        thread.start()

    # Wait for threads to finish
    for thread in threads:
        thread.join()

    print(Back.GREEN + "All processes completed." + Style.RESET_ALL)

if __name__ == "__main__":
    main()
