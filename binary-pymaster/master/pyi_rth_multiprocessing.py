# Source Generated with Decompyle++
# File: pyi_rth_multiprocessing.pyc (Python 3.8)


def _pyi_rthook():
    import os
    import sys
    import threading
    import multiprocessing
    import multiprocessing.spawn as multiprocessing
    _args_from_interpreter_flags = _args_from_interpreter_flags
    import subprocess
    multiprocessing.process.ORIGINAL_DIR = None
    
    def _freeze_support():
        if len(sys.argv) >= 2 and sys.argv[-2] == '-c' and sys.argv[-1].startswith(('from multiprocessing.resource_tracker import main', 'from multiprocessing.forkserver import main')) and set(sys.argv[1:-2]) == set(_args_from_interpreter_flags()):
            exec(sys.argv[-1])
            sys.exit()
    # WARNING: Decompyle incomplete

    multiprocessing.freeze_support = multiprocessing.spawn.freeze_support = _freeze_support
    
    def FrozenSupportMixIn():
        '''_pyi_rthook.<locals>.FrozenSupportMixIn'''
        _lock = threading.Lock()
        
        def __init__(self = None, *args, **kw):
            pass
        # WARNING: Decompyle incomplete

        __classcell__ = None

    FrozenSupportMixIn = None(FrozenSupportMixIn, 'FrozenSupportMixIn')
    if sys.platform.startswith('win'):
        popen_spawn_win32 = popen_spawn_win32
        import multiprocessing
        
        class _SpawnPopen(popen_spawn_win32.Popen, FrozenSupportMixIn):
            pass

        popen_spawn_win32.Popen = _SpawnPopen
    else:
        popen_spawn_posix = popen_spawn_posix
        import multiprocessing
        popen_forkserver = popen_forkserver
        import multiprocessing
        
        class _SpawnPopen(popen_spawn_posix.Popen, FrozenSupportMixIn):
            pass

        
        class _ForkserverPopen(popen_forkserver.Popen, FrozenSupportMixIn):
            pass

        popen_spawn_posix.Popen = _SpawnPopen
        popen_forkserver.Popen = _ForkserverPopen

_pyi_rthook()
del _pyi_rthook
