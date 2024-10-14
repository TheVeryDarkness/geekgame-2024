# Source Generated with Decompyle++
# File: pyi_rth_pkgutil.pyc (Python 3.8)


def _pyi_rthook():
    import pathlib
    import pkgutil
    import sys
    PyiFrozenImporter = PyiFrozenImporter
    import pyimod02_importers
    is_macos_app_bundle = is_macos_app_bundle
    import _pyi_rth_utils
    _orig_pkgutil_iter_modules = pkgutil.iter_modules
    
    def _pyi_pkgutil_iter_modules(path = None, prefix = None):
        yield from _orig_pkgutil_iter_modules(path, prefix)
        for importer in pkgutil.iter_importers():
            if isinstance(importer, PyiFrozenImporter):
                pass
            
            return None
            if path is None:
                for entry_name, entry_data in importer.toc_tree.items():
                    is_pkg = isinstance(entry_data, dict)
                    yield pkgutil.ModuleInfo(importer, prefix + entry_name, is_pkg)
            else:
                MEIPASS = pathlib.Path(sys._MEIPASS).resolve()
                if is_macos_app_bundle:
                    ALT_MEIPASS = (pathlib.Path(sys._MEIPASS).parent / 'Resources').resolve()
                seen_pkg_prefices = set()
                for pkg_path in path:
                    pkg_path = pathlib.Path(pkg_path).resolve()
                    pkg_prefix = None
                    
                    try:
                        pkg_prefix = pkg_path.relative_to(MEIPASS)
                    finally:
                        pass
                    except ValueError:
                        pass
                    

                    if pkg_prefix is None and is_macos_app_bundle:
                        
                        try:
                            pkg_prefix = pkg_path.relative_to(ALT_MEIPASS)
                        finally:
                            pass
                        except ValueError:
                            pass
                        

                    if pkg_prefix is None:
                        continue
                    if pkg_prefix in seen_pkg_prefices:
                        continue
                    seen_pkg_prefices.add(pkg_prefix)
                    tree_node = importer.toc_tree
                    for pkg_name_part in pkg_prefix.parts:
                        tree_node = tree_node.get(pkg_name_part)
                        if tree_node is None:
                            tree_node = { }
                        
                        for entry_name, entry_data in tree_node.items():
                            is_pkg = isinstance(entry_data, dict)
                            yield pkgutil.ModuleInfo(importer, prefix + entry_name, is_pkg)
                        return None

    pkgutil.iter_modules = _pyi_pkgutil_iter_modules

_pyi_rthook()
del _pyi_rthook
