
%tuple([1,2,3,1,2],X).

%tuple(L: Lista, LF: Lista)
%Lista = Intreg*
%Model de flux: (i,i), (i,o)
%L - lista initiala
%LF - multimea formata din L
tuple([],[]).
tuple([H|T],L) :-
    member(H,T),
    tuple(T,L),
    !.
tuple([H|T],[H|L]) :-
    tuple(T,L).
