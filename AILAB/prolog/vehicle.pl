% Facts
vehicle(car).
vehicle(motorcycle).
vehicle(bicycle).

has_engine(car).
has_engine(motorcycle).

has_wheels(car, 4).
has_wheels(motorcycle, 2).
has_wheels(bicycle, 2).

% Rules
is_motorized_vehicle(Vehicle) :-
    vehicle(Vehicle),
    has_engine(Vehicle).

is_four_wheeler(Vehicle) :-
    vehicle(Vehicle),
    has_wheels(Vehicle, 4),
    is_motorized_vehicle(Vehicle).

is_two_wheeler(Vehicle) :-
    vehicle(Vehicle),
    has_wheels(Vehicle, 2),
    is_motorized_vehicle(Vehicle).

% Identify the type of vehicle based on its characteristics
identify_vehicle_type(Vehicle, Type) :-
    (   is_four_wheeler(Vehicle) ->
        Type = 'Four-wheeled motorized vehicle'
    ;   is_two_wheeler(Vehicle) ->
        Type = 'Two-wheeled motorized vehicle'
    ;   \+ is_motorized_vehicle(Vehicle), has_wheels(Vehicle, 2) ->
        Type = 'Non-motorized two-wheeler'
    ;   Type = 'Other type of vehicle'
    ).


identify_vehicle_type(car,Type).
identify_vehicle_type(motorcycle,Type).
identify_vehicle_type(bicycle,Type).
identify_vehicle_type(truck, Type).