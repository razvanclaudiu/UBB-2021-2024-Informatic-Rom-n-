%return list of unique elements in the list
unique([H|T],L) :- 
    member(H,T),
    !,
    unique(T,L).
unique([H|T],[H|L]) :-
    unique(T,L).
unique([],[]).