import os
import re
import shutil


names = {}
with open("holberton.h", "r") as f:
    for line in f:
        found = re.search(r"_([a-z]+)\(", line)
        if found:
            names[found.group(1) + ".c"] = 1

for root, dirs, files in os.walk("../"):
    for f in files:
        for name in names:
            if names[name] and name in f:
                src = os.path.join(root, f)
                shutil.copy(src, ".")
                names[name] = 0
