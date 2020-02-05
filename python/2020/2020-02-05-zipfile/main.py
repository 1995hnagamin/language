import zipfile

with zipfile.ZipFile('test.zip', 'w') as z:
    z.write('dir')
