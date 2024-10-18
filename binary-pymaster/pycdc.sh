set -eux

mkdir -p master

./pycdc/pycdc ./pymaster_extracted/pymaster.pyc -o master/pymaster.py
./pycdc/pycdc ./pymaster_extracted/pyiboot01_bootstrap.pyc -o master/pyiboot01_bootstrap.py
# ./pycdc/pycdc ./pymaster_extracted/pyimod01_archive.pyc -o master/pyimod01_archive.py
./pycdc/pycdc ./pymaster_extracted/pyimod02_importers.pyc -o master/pyimod02_importers.py
./pycdc/pycdc ./pymaster_extracted/pyimod03_ctypes.pyc -o master/pyimod03_ctypes.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_pkgutil.pyc -o master/pyi_rth_pkgutil.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_multiprocessing.pyc -o master/pyi_rth_multiprocessing.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_inspect.pyc -o master/pyi_rth_inspect.py
./pycdc/pycdc ./pymaster_extracted/struct.pyc -o master/struct.py

# python3.8 ./master/pymaster.py
