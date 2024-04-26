from typing import (List, Tuple)
from dataclasses import dataclass
from enum import Enum


class ContainerDirection(Enum):
    FW = 1
    BW = -1

@dataclass(eq=True, frozen=True)
class Vertex:
  haive_id: str
  slot: int

@dataclass
class Carrier:
  container_id: str
  vertex: Vertex
  is_flipped: bool = False

@dataclass
class HAIVEInfo:
  haive_id: str
  x: int
  y: int

@dataclass
class ContainerInfo:
  container_id: str
  slot: int
  haive_id: str


# TODO: We should check for errors when illegal haive_id or container_id is passed in public interface!
class HAIVEGraph():
  def __init__(self, haive_info_list: List[HAIVEInfo], container_info_list: List[ContainerInfo]):
    self._grid = {
      # (x, y): haive_id
    }
    self._vertices = {
      # (haive_id, slot): vertex
    }
    self._edges = {
      # (vertex, 1): vertex   # 1 means forward from perspective of slot (i.e., container is not flipped)
      # (vertex, -1): vertex  # -1 means backward from perspective of slot (i.e., container is not flipped)
    }
    self._carriers = {
      # container_id: vertex
    }

    self._build_graph(haive_info_list)
    self._init_carriers(container_info_list)

  def _build_graph(self, haive_info_list: List[HAIVEInfo]):
    for haive_info in haive_info_list:
      self._grid[(haive_info.x, haive_info.y)] = haive_info.haive_id

      for slot in [0, 1, 3, 5, 7, 9, 11]:
        self._vertices[(haive_info.haive_id, slot)] = Vertex(haive_info.haive_id, slot)

      self._edges[(self._vertices[(haive_info.haive_id, 0)], 1)] = self._vertices[(haive_info.haive_id, 1)]
      self._edges[(self._vertices[(haive_info.haive_id, 0)], -1)] = self._vertices[(haive_info.haive_id, 7)]
      self._edges[(self._vertices[(haive_info.haive_id, 1)], 1)] = self._vertices[(haive_info.haive_id, 0)]
      self._edges[(self._vertices[(haive_info.haive_id, 7)], 1)] = self._vertices[(haive_info.haive_id, 0)]

    for haive_info in haive_info_list:
      for from_slot, to_haive_id in self._get_grid_neighbours(haive_info.x, haive_info.y):
        to_slot = (from_slot + 6) % 12
        from_vertex = self._vertices[(haive_info.haive_id, from_slot)]
        to_vertex = self._vertices[(to_haive_id, to_slot)]
        self._edges[(from_vertex, -1)] = to_vertex

  def _init_carriers(self, container_info_list: List[ContainerInfo]):
    for container_info in container_info_list:
      vertex = self._vertices[(container_info.haive_id, container_info.slot)]
      self._carriers[container_info.container_id] = Carrier(container_info.container_id, vertex)

  def _get_grid_neighbours(self, x: int, y: int) -> List[Tuple[int, str]]:
    offset_even = [
      [0, -1], [1, 0], [0, 1], [-1, 1], [-1, 0], [-1, -1]
    ]
    offset_odd = [
      [1, -1], [1, 0], [1, 1], [0, 1], [-1, 0], [0, -1]
    ]
    odd = y % 2 == 1
    offset = offset_odd if odd else offset_even

    neighbours = []

    for i in range(6):
      n_x = x + offset[i][0]
      n_y = y + offset[i][1]

      if (n_x, n_y) in self._grid:
        from_slot = 1 + i * 2
        to_haive_id = self._grid[(n_x, n_y)]
        neighbours.append((from_slot, to_haive_id))

    return neighbours

  def move_turntable(self, haive_id: str, to_slot: int):
    v = self._vertices[(haive_id, 0)]
    v1 = self._edges[(v, 1)]
    v2 = self._edges[(v, -1)]
    del self._edges[(v1, 1)]
    del self._edges[(v2, 1)]
    del self._edges[(v, 1)]
    del self._edges[(v, -1)]
    front_slot = to_slot
    back_slot = (to_slot + 6) % 12
    self._edges[(self._vertices[(haive_id, 0)], 1)] = self._vertices[(haive_id, front_slot)]
    self._edges[(self._vertices[(haive_id, 0)], -1)] = self._vertices[(haive_id, back_slot)]
    self._edges[(self._vertices[(haive_id, front_slot)], 1)] = self._vertices[(haive_id, 0)]
    self._edges[(self._vertices[(haive_id, back_slot)], 1)] = self._vertices[(haive_id, 0)]

  def transit(self, container_id: str, container_direction: ContainerDirection) -> str:
    carrier = self._carriers[container_id]

    from_vertex = carrier.vertex
    slot_direction = container_direction.value if not carrier.is_flipped else -container_direction.value
    
    key = (from_vertex, slot_direction)
    
    if key not in self._edges:
      return f"HAIVEGraph.transit: No edge available when moving container {container_id} in direction {container_direction}!"

    to_vertex = self._edges[key]

    if to_vertex.slot == 0:
      carrier.is_flipped = self._edges[(to_vertex, 1)].slot == from_vertex

    if from_vertex.slot == 0:
      carrier.is_flipped = True if container_direction == ContainerDirection.FW else False

    if to_vertex.haive_id != from_vertex.haive_id:
      carrier.is_flipped = not carrier.is_flipped

    carrier.vertex = to_vertex

    return ""

  def get_container_position(self, container_id: str) -> (int, bool, str):
    carrier = self._carriers[container_id]
    return carrier.vertex.slot, carrier.is_flipped, carrier.vertex.haive_id

  def get_neighbour_haive(self, haive_id: str, slot: int) -> Tuple[str, int]:
    k = (self._vertices[(haive_id, slot)], -1)

    if k not in self._edges:
      return None

    n = self._edges[k]
    return (n.haive_id, n.slot)

  def get_vertices(self) -> List[Tuple[str, int]]:
    return list(self._vertices.keys())

  def get_turntable_position(self, haive_id: str) -> int:
    return self._edges[(self._vertices[(haive_id, 0)], 1)].slot
