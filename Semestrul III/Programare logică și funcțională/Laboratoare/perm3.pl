perm([], []).
perm([E|T], P) :-
	perm(T, L),
	insereaza(E, L, P).

insereaza(E, L, [E|L]).
insereaza(E, [H|T], [H|Rez]) :-
	insereaza(E, T, Rez).

perm_list(L,R):-
	findall(X,perm(L,X),R1),
	rem_list(R1,R).

check3([_]).
check3([X,Y|T]):-
	abs(X-Y) =< 3,
	check3([Y|T]).

rem_list([],[]).
rem_list([H|T],R):-
	check3(H),
	!,
	R = [H|NT],
	rem_list(T,NT).
rem_list([_|T],R):-
	rem_list(T,R).
