import unittest

from pystring import pysplit


class TestSplit(unittest.TestCase):

  def test_0(self):
    s = 'ff gg aa'
    self.assertEqual(pysplit(s), s.split())

  def test_1(self):
    s = 'blue,red,green'
    for sep in [',', 'e', 'r']:
      for maxsplit in range(-5, 10):
        self.assertEqual(pysplit(s, sep, maxsplit), s.split(sep, maxsplit))


if __name__ == '__main__':
  unittest.main()
