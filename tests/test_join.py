import unittest

from pystring import pyjoin


class TestJoin(unittest.TestCase):

  def test_0(self):
    words = ['ff', 'gg', 'aa']
    self.assertEqual(pyjoin(words), ' '.join(words))

  def test_1(self):
    words = ['blue', 'red', 'green']
    for sep in [',', ' -- ', ' ']:
      self.assertEqual(pyjoin(words), ' '.join(words))


if __name__ == '__main__':
  unittest.main()
