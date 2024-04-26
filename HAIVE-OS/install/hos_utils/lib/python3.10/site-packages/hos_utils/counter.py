

class Counter():
  def __init__(self) -> None:
    self._count = 0

  def get(self) -> int:
    n = self._count
    self._count += 1
    return n
