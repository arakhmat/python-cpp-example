import sys
if sys.version_info[0] < 3:
  from pystring import pysplit, pyjoin
else:
  from pystring.pystring import pysplit, pyjoin
