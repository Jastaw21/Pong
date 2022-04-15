#pragma once
#include <vector>

enum class EventLists {
  PLAYER_CONCEDE,
  OPPPONENT_CONCEDE,
  PLAYER_HIT,
  OPPONENT_HIT,
  NONE

};

class Events {
 public:
  std::vector<EventLists> eventQueue{};
  EventLists read();
  void add(EventLists event);
};
