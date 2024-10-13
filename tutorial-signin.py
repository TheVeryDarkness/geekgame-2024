import pathlib
import subprocess

for z in pathlib.Path("tutorial-signin").rglob("*.zip"):
    extracted = z.parent / z.stem
    if not extracted.exists():
        print(z, extracted)
        subprocess.call(["7zz", "x", f'{z}', f'-o{extracted}'])

for t in pathlib.Path("tutorial-signin").rglob("*.txt"):
    # print(t.read_text())
    text = t.read_text()
    if "flag{" in text:
        print(text)
