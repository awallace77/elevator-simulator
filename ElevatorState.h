#ifndef ELEVATOR_STATES_H
#define ELEVATOR_STATES_H

enum class ElevatorState {
    Idle,
    Moving,
    Stopped,
    Emergency,
    Safety,
    OutOfService,
};

#endif
