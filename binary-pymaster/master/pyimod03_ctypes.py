# Source Generated with Decompyle++
# File: pyimod03_ctypes.pyc (Python 3.8)

'''
Hooks to make ctypes.CDLL, .PyDLL, etc. look in sys._MEIPASS first.
'''
import sys

def install():
    '''
    Install the hooks.

    This must be done from a function as opposed to at module-level, because when the module is imported/executed,
    the import machinery is not completely set up yet.
    '''
    import os
    
    try:
        import ctypes
    finally:
        pass
    except ImportError:
        return None
    else:
        
        def _frozen_name(name = None):
            if not name and os.path.isfile(name):
                frozen_name = os.path.join(sys._MEIPASS, os.path.basename(name))
                if os.path.isfile(frozen_name):
                    name = frozen_name
            return name

        
        class PyInstallerImportError(OSError):
            
            def __init__(self, name):
                self.msg = 'Failed to load dynlib/dll %r. Most likely this dynlib/dll was not found when the application was frozen.' % name
                self.args = (self.msg,)


        
        def PyInstallerCDLL():
            '''install.<locals>.PyInstallerCDLL'''
            
            def __init__(self = None, name = None, *args, **kwargs):
                name = _frozen_name(name)
            # WARNING: Decompyle incomplete

            __classcell__ = None

        PyInstallerCDLL = None(PyInstallerCDLL, 'PyInstallerCDLL', ctypes.CDLL)
        ctypes.CDLL = PyInstallerCDLL
        ctypes.cdll = ctypes.LibraryLoader(PyInstallerCDLL)
        
        def PyInstallerPyDLL():
            '''install.<locals>.PyInstallerPyDLL'''
            
            def __init__(self = None, name = None, *args, **kwargs):
                name = _frozen_name(name)
            # WARNING: Decompyle incomplete

            __classcell__ = None

        PyInstallerPyDLL = None(PyInstallerPyDLL, 'PyInstallerPyDLL', ctypes.PyDLL)
        ctypes.PyDLL = PyInstallerPyDLL
        ctypes.pydll = ctypes.LibraryLoader(PyInstallerPyDLL)
        if sys.platform.startswith('win'):
            
            def PyInstallerWinDLL():
                '''install.<locals>.PyInstallerWinDLL'''
                
                def __init__(self = None, name = None, *args, **kwargs):
                    name = _frozen_name(name)
                # WARNING: Decompyle incomplete

                __classcell__ = None

            PyInstallerWinDLL = None(PyInstallerWinDLL, 'PyInstallerWinDLL', ctypes.WinDLL)
            ctypes.WinDLL = PyInstallerWinDLL
            ctypes.windll = ctypes.LibraryLoader(PyInstallerWinDLL)
            
            def PyInstallerOleDLL():
                '''install.<locals>.PyInstallerOleDLL'''
                
                def __init__(self = None, name = None, *args, **kwargs):
                    name = _frozen_name(name)
                # WARNING: Decompyle incomplete

                __classcell__ = None

            PyInstallerOleDLL = None(PyInstallerOleDLL, 'PyInstallerOleDLL', ctypes.OleDLL)
            ctypes.OleDLL = PyInstallerOleDLL
            ctypes.oledll = ctypes.LibraryLoader(PyInstallerOleDLL)
            
            try:
                import ctypes.util as ctypes
            finally:
                pass
            except ImportError:
                return None
            else:
                
                def pyinstaller_find_library(name = None):
                    if name in ('c', 'm'):
                        return ctypes.util.find_msvcrt()
                    search_dirs = [
                        None._MEIPASS] + os.environ['PATH'].split(os.pathsep)
                    for directory in search_dirs:
                        fname = os.path.join(directory, name)
                        if os.path.isfile(fname):
                            return fname
                        if None.lower().endswith('.dll'):
                            continue
                        fname = fname + '.dll'
                        if os.path.isfile(fname):
                            return fname
                        return None

                ctypes.util.find_library = pyinstaller_find_library
                return None



if sys.platform.startswith('darwin'):
    
    try:
        from ctypes.macholib import dyld
        dyld.DEFAULT_LIBRARY_FALLBACK.insert(0, sys._MEIPASS)
    finally:
        pass
    except ImportError:
        pass
    

