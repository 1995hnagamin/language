import glob
import zipfile

with zipfile.ZipFile('test.zip', 'w') as z:
    for fname in glob.glob('dir/**', recursive=True):
        print(fname)
        z.write(fname)
