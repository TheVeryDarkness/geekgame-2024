# Source Generated with Decompyle++
# File: pyiboot01_bootstrap.pyc (Python 3.8)

import sys
import pyimod02_importers
pyimod02_importers.install()
import os
if not hasattr(sys, 'frozen'):
    sys.frozen = True
sys.prefix = sys._MEIPASS
sys.exec_prefix = sys.prefix
sys.base_prefix = sys.prefix
sys.base_exec_prefix = sys.exec_prefix
VIRTENV = 'VIRTUAL_ENV'
if VIRTENV in os.environ:
    os.environ[VIRTENV] = ''
    del os.environ[VIRTENV]
python_path = []
for pth in sys.path:
    python_path.append(os.path.abspath(pth))
    sys.path = python_path

try:
    import encodings
finally:
    pass
except ImportError:
    pass


if sys.warnoptions:
    import warnings
import pyimod03_ctypes
pyimod03_ctypes.install()
if sys.platform.startswith('win'):
    import pyimod04_pywin32
    pyimod04_pywin32.install()
for entry in os.listdir(sys._MEIPASS):
    entry = os.path.join(sys._MEIPASS, entry)
    if not os.path.isdir(entry):
        continue
    if entry.endswith('.egg'):
        sys.path.append(entry)
        continue
        return None
