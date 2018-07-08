import warnings

import cppstring


def pysplit(s, sep=' ', maxsplit=-1):
  if sep == '':
    raise ValueError("empty separator")

  if len(sep) != 1:
    warnings.warn(
        '(pysplit): If separator has more than one character, it will behave differently than the default python implementation.',
        UserWarning)

  # Copy is necessary to ensure that original string is unaltered
  s_copy = '{}'.format(s)
  return cppstring.split(s_copy, sep, maxsplit)


def pyjoin(words, sep=' '):
  return cppstring.join(words, sep)