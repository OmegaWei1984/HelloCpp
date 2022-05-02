import sys, os
dir_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(dir_path + "/../../bin/")

import pydemo

# help(pydemo)·
pydemo.info()
