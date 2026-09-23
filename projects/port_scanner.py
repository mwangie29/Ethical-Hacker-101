import socket
import threading
import argparse
from datetime import datetime


class PortScanner:
    def __init__(self, target):
        self.target = target
        self.lock = threading.Lock()

    def scan_port(self, port):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(1)

        try:
            sock.connect((self.target, port))
            with self.lock:
                message = f"{datetime.now():%Y-%m-%d %H:%M:%S} {self.target}:{port} OPEN"
                print(f"[+] {message}")
                with open("scanner.log", "a") as log:
                    log.write(message + "\n")
        except:
            pass
        finally:
            sock.close()

    def scan(self, start, end):
        threads = []

        for port in range(start, end + 1):
            thread = threading.Thread(target=self.scan_port, args=(port,))
            thread.start()
            threads.append(thread)

        for thread in threads:
            thread.join()


def main():
    parser = argparse.ArgumentParser(description="Simple TCP Port Scanner")
    parser.add_argument("target", help="Target IP address")
    parser.add_argument("-s", "--start", type=int, default=1)
    parser.add_argument("-e", "--end", type=int, default=1024)

    args = parser.parse_args()

    print(f"[*] Scanning {args.target}:{args.start}-{args.end}")
    PortScanner(args.target).scan(args.start, args.end)


if __name__ == "__main__":
    main()
    