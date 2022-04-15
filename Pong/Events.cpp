#include "Events.h"

EventLists Events::read() {
  if (!eventQueue.empty()) {
    auto returnEvent = eventQueue.front();
    eventQueue.erase(eventQueue.begin());
    return returnEvent;
  } else {
    return EventLists::NONE;
  }
}
void Events::add(EventLists event) {}
