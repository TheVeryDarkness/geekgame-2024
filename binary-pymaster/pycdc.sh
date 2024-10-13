set -eux

mkdir -p master

./pycdc/pycdc ./pymaster_extracted/pymaster.pyc -o master/pymaster.py
./pycdc/pycdc ./pymaster_extracted/pyiboot01_bootstrap.pyc -o master/pyiboot01_bootstrap.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_pkgutil.pyc -o master/pyi_rth_pkgutil.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_multiprocessing.pyc -o master/pyi_rth_multiprocessing.py
./pycdc/pycdc ./pymaster_extracted/pyi_rth_inspect.pyc -o master/pyi_rth_inspect.py

python3.8 ./master/pymaster.py
