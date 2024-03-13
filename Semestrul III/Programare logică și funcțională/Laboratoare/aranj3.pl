
%permutari
inseram(E,[],[E]).
inseram(E,[H|T],[H|R]) :- inseram(E,T,R).

permutare([],[]).
permutare([H|T],R) :- permutare(T,R2) , inseram(H,R2,R).

permut_all(L,R) :- findall( X , permutare(L,X) , R).

%combinari
combinn([H|_],1,[H]).
combinn([_|T],K,R) :- combinn(T,K,R).
combinn([H|T],K,[H|R]) :- K > 1 , K2 is K - 1 , combinn(T,K2,R).

%aranjament
aranjamente(L,K,R) :- combinn(L,K,R2) , permutare(R2,R).

invers([],[]).
invers([H|T],R):-
	is_list(H),
	!,
	invers(H,R1),
	invers(T,R2),
	inseram(R1,R2,R).
invers([H|T],R):-
	invers(T,R2),
	inseram(H,R2,R).


membru(X,[X|_]).
membru(X,[_|T]):-
	membru(X,T).

set([],[]).
set([H|T],R):-
	membru(H,T),
	!,
	set(T,R).
set([H|T],[H|R]):-
	set(T,R).

ins(E,L,[E|L]).
ins(E,[H|T],[H|R]):-
    ins(E,T,R).

perm([],[]).
perm([H|T],R):-
	perm(T,R1),
	ins(H,R1,R).


comb([H|_],1,[H]).
comb([_|T],K,R):-
	comb(T,K,R).
comb([H|T],K,[H|R]):-
	K>1,
	K1 is K-1,
	comb(T,K1,R).

araj(L,K,R):-
	comb(L,K,R1),
	perm(R1,R).

solv(L,K,P,R):-
	findall(X,araj(L,K,X),R1),
	rem(R1,P,R).

pro([],1).
pro([H|T],P):-
	pro(T,P1),
	P is P1 * H.

rem([],_,[]).
rem([H|T],P,[H|R]):-
	pro(H,P1),
	P =:= P1,
	!,
	rem(T,P,R).
rem([_|T],P,R):-
	rem(T,P,R).


subm([],[]).
subm([_|T],R):-
	subm(T,R).
subm([H|T],[H|R]):-
	subm(T,R).


solv1(L,N,R):-
	findall(X,subm(L,X),R1),
	rem2(R1,N,R).

suma([],0).
suma([H|T],R):-
	suma(T,R1),
	R is R1 + H.

lung([],0).
lung([_|T],R):-
	lung(T,R1),
	R is R1 + 1.

rem2([],_,[]).
rem2([H|T],N,[H|R]):-
	lung(H,L),
	L >= N,
	suma(H,S),
	S mod 3 =:= 0,
	!,
	rem2(T,N,R).
rem2([_|T],N,R):-
	rem2(T,N,R).

